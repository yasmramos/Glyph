#include "codegen/CodeGen.h"

#include <cmath>
#include <memory>
#include <string>
#include <unordered_map>

#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

// CodeGen walks Glyph's own AST (never the ANTLR tree) and emits LLVM IR.
// Strategy for locals: alloca + load/store, letting mem2reg promote them to
// SSA later — this avoids hand-rolled PHI nodes at milestone stage.
namespace glyph::codegen {
namespace {

class ExprEmitter; // fwd

/// Compile-time constant folding so `print(1+2)` does not need an optimizer
/// pass to look sane in --emit-ir output. Returns null when not foldable.
const llvm::Constant *tryFold(ast::BinOp op, const llvm::APFloat &a,
                              const llvm::APFloat &b, llvm::LLVMContext &ctx) {
    using ast::BinOp;
    double x = a.convertToDouble();
    double y = b.convertToDouble();
    switch (op) {
    case BinOp::Add: return llvm::ConstantFP::get(ctx, llvm::APFloat(x + y));
    case BinOp::Sub: return llvm::ConstantFP::get(ctx, llvm::APFloat(x - y));
    case BinOp::Mul: return llvm::ConstantFP::get(ctx, llvm::APFloat(x * y));
    case BinOp::Div:
        if (y == 0.0) return nullptr;
        return llvm::ConstantFP::get(ctx, llvm::APFloat(x / y));
    case BinOp::Mod: {
        if (y == 0.0) return nullptr;
        double r = std::fmod(x, y);
        // Lua-style modulo: sign follows the divisor.
        if ((r != 0.0) && ((r < 0.0) != (y < 0.0))) r += y;
        return llvm::ConstantFP::get(ctx, llvm::APFloat(r));
    }
    case BinOp::Pow: return llvm::ConstantFP::get(ctx, llvm::APFloat(std::pow(x, y)));
    default: return nullptr; // comparisons/logic emitted at runtime
    }
}

class ModuleBuilder {
public:
    ModuleBuilder(llvm::Module &module, const std::string &moduleName)
        : module_(module), ctx_(module.getContext()),
          builder_(ctx_), moduleName_(moduleName) {
        doubleTy_ = llvm::Type::getDoubleTy(ctx_);
        voidTy_ = llvm::Type::getVoidTy(ctx_);
        i8Ty_ = llvm::Type::getInt8Ty(ctx_);
        i32Ty_ = llvm::Type::getInt32Ty(ctx_);
        i8PtrTy_ = i8Ty_->getPointerTo();

        // Declare the runtime externals with exact signatures — never let
        // LLVM infer them implicitly.
        auto *printNumTy = llvm::FunctionType::get(voidTy_, {doubleTy_}, false);
        printNumFn_ = llvm::Function::Create(
            printNumTy, llvm::Function::ExternalLinkage, "glyph_print_num",
            &module_);
        auto *printStrTy = llvm::FunctionType::get(voidTy_, {i8PtrTy_}, false);
        printStrFn_ = llvm::Function::Create(
            printStrTy, llvm::Function::ExternalLinkage, "glyph_print_str",
            &module_);
        auto *printNlTy = llvm::FunctionType::get(voidTy_, {}, false);
        printNlFn_ = llvm::Function::Create(printNlTy,
                                            llvm::Function::ExternalLinkage,
                                            "glyph_print_nl", &module_);
        // The runtime only reads its arguments and never unwinds.
        printNumFn_->addParamAttr(0, llvm::Attribute::ReadOnly);
        printStrFn_->addParamAttr(0, llvm::Attribute::ReadOnly);
        printStrFn_->addParamAttr(0, llvm::Attribute::NoAlias);
        printStrFn_->addFnAttr(llvm::Attribute::NoUnwind);
        printNumFn_->addFnAttr(llvm::Attribute::NoUnwind);
        printNlFn_->addFnAttr(llvm::Attribute::NoUnwind);
    }

    llvm::LLVMContext &ctx() { return ctx_; }
    llvm::Module &module() { return module_; }
    llvm::IRBuilder<> &builder() { return builder_; }
    llvm::Type *doubleTy() const { return doubleTy_; }
    llvm::Type *voidTy() const { return voidTy_; }
    llvm::Type *i32Ty() const { return i32Ty_; }
    llvm::PointerType *i8PtrTy() const { return i8PtrTy_; }
    llvm::Function *printNumFn() const { return printNumFn_; }
    llvm::Function *printStrFn() const { return printStrFn_; }
    llvm::Function *printNlFn() const { return printNlFn_; }

    /// Materializes a string literal as a private global byte array.
    llvm::Value *getStringConst(const std::string &text, const SourceLoc &loc) {
        std::string key = text;
        auto it = stringCache_.find(key);
        if (it != stringCache_.end()) return it->second;
        llvm::Constant *data =
            llvm::ConstantDataArray::getString(ctx_, text, /*AddNull=*/true);
        auto *gv = new llvm::GlobalVariable(
            module_, data->getType(), true, llvm::GlobalValue::PrivateLinkage,
            data, "str." + std::to_string(stringCounter_++));
        gv->setUnnamedAddr(llvm::GlobalValue::UnnamedAddr::Global);
        llvm::Value *ptr = llvm::ConstantExpr::getBitCast(
            gv, i8PtrTy_);
        stringCache_[key] = ptr;
        (void)loc;
        return ptr;
    }

private:
    llvm::Module &module_;
    llvm::LLVMContext &ctx_;
    llvm::IRBuilder<> builder_;
    std::string moduleName_;
    llvm::Type *doubleTy_ = nullptr;
    llvm::Type *voidTy_ = nullptr;
    llvm::Type *i8Ty_ = nullptr;
    llvm::Type *i32Ty_ = nullptr;
    llvm::PointerType *i8PtrTy_ = nullptr;
    llvm::Function *printNumFn_ = nullptr;
    llvm::Function *printStrFn_ = nullptr;
    llvm::Function *printNlFn_ = nullptr;
    std::unordered_map<std::string, llvm::Value *> stringCache_;
    int stringCounter_ = 0;
};

/// Typed result of evaluating a Glyph expression at codegen time.
struct Value {
    enum class Kind { Number, String } kind;
    llvm::Value *value = nullptr;
};

class ExprEmitter : public ast::ExprVisitor {
public:
    ExprEmitter(ModuleBuilder &mb,
                std::unordered_map<std::string, llvm::Value *> &locals)
        : mb_(mb), locals_(locals) {}

    Value emit(const ast::Expr *expr) {
        expr_ = expr;
        expr->accept(*this);
        return result_;
    }

    // ast::ExprVisitor interface.
    void visit(const ast::NumberExpr &e) override {
        result_ = {Value::Kind::Number,
                   llvm::ConstantFP::get(mb_.ctx(), llvm::APFloat(e.value()))};
    }

    void visit(const ast::StringExpr &e) override {
        result_ = {Value::Kind::String,
                   mb_.getStringConst(e.value(), e.loc())};
    }

    void visit(const ast::IdentifierExpr &e) override {
        auto it = locals_.find(e.name());
        if (it == locals_.end()) {
            throw CodeGenError(e.loc(), "undefined variable '" + e.name() + "'");
        }
        // Locals are stored as alloca slots; load from them here.
        llvm::Value *slot = it->second;
        auto *ptrTy = static_cast<llvm::PointerType *>(slot->getType());
        auto *loaded = mb_.builder().CreateLoad(ptrTy->getElementType(), slot,
                                                e.name());
        result_ = {Value::Kind::Number, loaded};
    }

    void visit(const ast::BinaryExpr &e) override {
        using ast::BinOp;
        Value lhs = emitRec(e.lhs());
        Value rhs = emitRec(e.rhs());

        // Short-circuit logic needs control flow; keep it simple for now by
        // requiring both operands to be numbers for arithmetic.
        if (e.op() == BinOp::And || e.op() == BinOp::Or) {
            throw CodeGenError(e.loc(),
                               "'and'/'or' are not supported yet (milestone 3)");
        }

        if (lhs.kind != Value::Kind::Number ||
            rhs.kind != Value::Kind::Number) {
            throw CodeGenError(e.loc(),
                               "arithmetic operands must be numbers");
        }

        // Fold constants eagerly (documented golden-IR benefit).
        if (auto *la = llvm::dyn_cast<llvm::ConstantFP>(lhs.value)) {
            if (auto *ra = llvm::dyn_cast<llvm::ConstantFP>(rhs.value)) {
                if (const llvm::Constant *folded =
                        tryFold(e.op(), la->getValueAPF(), ra->getValueAPF(),
                                mb_.ctx())) {
                    result_ = {Value::Kind::Number,
                               const_cast<llvm::Constant *>(folded)};
                    return;
                }
            }
        }

        llvm::Value *out = nullptr;
        llvm::IRBuilder<> &b = mb_.builder();
        switch (e.op()) {
        case BinOp::Add: out = b.CreateFAdd(lhs.value, rhs.value, "addtmp"); break;
        case BinOp::Sub: out = b.CreateFSub(lhs.value, rhs.value, "subtmp"); break;
        case BinOp::Mul: out = b.CreateFMul(lhs.value, rhs.value, "multmp"); break;
        case BinOp::Div: out = b.CreateFDiv(lhs.value, rhs.value, "divtmp"); break;
        case BinOp::Mod: out = b.CreateFRem(lhs.value, rhs.value, "modtmp"); break;
        case BinOp::Pow: {
            // pow via libm declaration created on demand.
            auto *&powFnRef = powFn_;
            if (!powFnRef) {
                auto *ty = llvm::FunctionType::get(
                    mb_.doubleTy(), {mb_.doubleTy(), mb_.doubleTy()}, false);
                powFnRef = llvm::Function::Create(
                    ty, llvm::Function::ExternalLinkage, "llvm.pow.f64",
                    &mb_.module());
            }
            out = b.CreateCall(powFnRef, {lhs.value, rhs.value}, "powtmp");
            break;
        }
        default:
            throw CodeGenError(e.loc(),
                               "comparison operators are not supported yet "
                               "(milestone 3)");
        }
        result_ = {Value::Kind::Number, out};
    }

    void visit(const ast::UnaryExpr &e) override {
        if (e.op() == ast::UnOp::Not) {
            throw CodeGenError(e.loc(), "'not' is not supported yet "
                                        "(milestone 3)");
        }
        Value operand = emitRec(e.operand());
        if (operand.kind != Value::Kind::Number) {
            throw CodeGenError(e.loc(), "cannot negate a string");
        }
        llvm::Value *out = mb_.builder().CreateFNeg(operand.value, "negtmp");
        result_ = {Value::Kind::Number, out};
    }

private:
    Value emitRec(const ast::Expr *e) { return emit(e); }

    ModuleBuilder &mb_;
    std::unordered_map<std::string, llvm::Value *> &locals_;
    const ast::Expr *expr_ = nullptr;
    Value result_{Value::Kind::Number, nullptr};
    llvm::Function *powFn_ = nullptr;
};

class StmtEmitter : public ast::StmtVisitor {
public:
    StmtEmitter(ModuleBuilder &mb) : mb_(mb), emitter_(mb, locals_) {}

    void run(const ast::Program &program) {
        auto *entryTy = llvm::FunctionType::get(mb_.i32Ty(), false);
        function_ = llvm::Function::Create(
            entryTy, llvm::Function::ExternalLinkage, "main", &mb_.module());
        auto *entry = llvm::BasicBlock::Create(mb_.ctx(), "entry", function_);
        mb_.builder().SetInsertPoint(entry);

        for (const auto &stmt : program.stmts) {
            stmt->accept(*this);
        }
        mb_.builder().CreateRet(llvm::ConstantInt::get(mb_.i32Ty(), 0));
    }

    // ast::StmtVisitor interface.
    void visit(const ast::PrintStmt &s) override {
        Value v = emitter_.emit(s.value());
        if (v.kind == Value::Kind::Number) {
            mb_.builder().CreateCall(mb_.printNumFn(), {v.value});
        } else {
            mb_.builder().CreateCall(mb_.printStrFn(), {v.value});
        }
        mb_.builder().CreateCall(mb_.printNlFn(), {});
    }

    void visit(const ast::AssignStmt &s) override {
        Value v = emitter_.emit(s.value());
        auto it = locals_.find(s.name());
        if (it == locals_.end()) {
            // First assignment: create an alloca slot in the entry block.
            llvm::IRBuilder<> entryBuilder(
                &function_->getEntryBlock(),
                function_->getEntryBlock().begin());
            llvm::Value *slot = entryBuilder.CreateAlloca(typeOf(v), nullptr,
                                                          s.name());
            locals_[s.name()] = slot;
            mb_.builder().CreateStore(v.value, slot);
        } else {
            mb_.builder().CreateStore(v.value, it->second);
        }
    }

    void visit(const ast::ExprStmt &s) override {
        // Expression statements evaluate for side effects only.
        emitter_.emit(s.expr());
    }

private:
    llvm::Type *typeOf(const Value &v) {
        return v.kind == Value::Kind::Number ? mb_.doubleTy() : mb_.i8PtrTy();
    }

    ModuleBuilder &mb_;
    llvm::Function *function_ = nullptr;
    std::unordered_map<std::string, llvm::Value *> locals_;
    ExprEmitter emitter_;
};

} // namespace

std::unique_ptr<llvm::Module> generateModule(const ast::Program &program,
                                             llvm::LLVMContext &ctx,
                                             const std::string &moduleName) {
    auto module = std::make_unique<llvm::Module>(moduleName, ctx);
    ModuleBuilder mb(*module, moduleName);
    StmtEmitter stmts(mb);
    stmts.run(program);
    return module;
}

} // namespace glyph::codegen
