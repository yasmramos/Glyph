#include "ast/Ast.h"

#include <iostream>
#include <string>

namespace glyph::ast {

// Double-dispatch glue: accept() forwards to the matching visit() overload.
void IntExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void DoubleExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void StringExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void BoolExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void NoneExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void CtorExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void IdentifierExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void BinaryExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void UnaryExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void CastExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void TryExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void TernaryExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void ListExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void StructLitExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void LambdaExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void PostfixExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void AssignExpr::accept(ExprVisitor &v) const { v.visit(*this); }

void BlockStmt::accept(StmtVisitor &v) const { v.visit(*this); }
void BindStmt::accept(StmtVisitor &v) const { v.visit(*this); }
void ExprStmt::accept(StmtVisitor &v) const { v.visit(*this); }
void IfStmt::accept(StmtVisitor &v) const { v.visit(*this); }
void WhileStmt::accept(StmtVisitor &v) const { v.visit(*this); }
void ForStmt::accept(StmtVisitor &v) const { v.visit(*this); }
void MatchStmt::accept(StmtVisitor &v) const { v.visit(*this); }
void ReturnStmt::accept(StmtVisitor &v) const { v.visit(*this); }

namespace {

const char *binOpName(BinOp op) {
    switch (op) {
    case BinOp::Add: return "+";
    case BinOp::Sub: return "-";
    case BinOp::Mul: return "*";
    case BinOp::Div: return "/";
    case BinOp::Mod: return "%";
    case BinOp::Eq: return "==";
    case BinOp::Ne: return "!=";
    case BinOp::Lt: return "<";
    case BinOp::Le: return "<=";
    case BinOp::Gt: return ">";
    case BinOp::Ge: return ">=";
    case BinOp::And: return "&&";
    case BinOp::Or: return "||";
    case BinOp::Concat: return "+";
    }
    return "?";
}

std::string typeToString(const Type *t) {
    if (!t) return "?";
    switch (t->kind()) {
    case TypeKind::Int: return "int";
    case TypeKind::Long: return "long";
    case TypeKind::Double: return "double";
    case TypeKind::Bool: return "bool";
    case TypeKind::Str: return "str";
    case TypeKind::List: return "[" + typeToString(static_cast<const ListType *>(t)->element()) + "]";
    case TypeKind::Option: return "?" + typeToString(static_cast<const OptionType *>(t)->inner());
    case TypeKind::Result: return "!" + typeToString(static_cast<const ResultType *>(t)->ok());
    case TypeKind::Fn: return "fn";
    case TypeKind::Named: {
        auto *n = static_cast<const NamedType *>(t);
        std::string s = n->name();
        if (!n->genericArgs().empty()) {
            s += "<";
            for (size_t i = 0; i < n->genericArgs().size(); ++i) {
                if (i) s += ", ";
                s += typeToString(n->genericArgs()[i].get());
            }
            s += ">";
        }
        return s;
    }
    }
    return "?";
}

// Text-dump printer used by printAst(); keeps debugging independent of LLVM.
class AstPrinter : public ExprVisitor, public StmtVisitor {
public:
    void print(const Program &program) {
        std::cout << "Program (" << program.programLoc().file << ")\n";
        if (!program.moduleName.empty())
            std::cout << "module " << program.moduleName << "\n";
        for (const auto &imp : program.imports)
            std::cout << "import " << imp.path << "\n";
        for (const auto &c : program.consts)
            std::cout << "const " << c->name << " =\n";
        for (const auto &s : program.structs)
            std::cout << "struct " << s->name << " {\n";
        for (const auto &i : program.interfaces)
            std::cout << "interface " << i->name << " {\n";
        for (const auto &c : program.classes)
            std::cout << "class " << c->name << " {\n";
        for (const auto &f : program.functions)
            std::cout << "fn " << f->name << " -> "
                      << typeToString(f->returnType.get()) << " {\n";
        // Dump only top-level function bodies for now; class/struct methods
        // are printed as summaries to keep the output manageable.
        for (const auto &f : program.functions) {
            ++depth_;
            if (f->body) f->body->accept(*this);
            --depth_;
        }
    }

    // StmtVisitor interface.
    void visit(const BlockStmt &s) override {
        indentLine("Block");
        ++depth_;
        for (const auto &stmt : s.stmts()) stmt->accept(*this);
        --depth_;
    }

    void visit(const BindStmt &s) override {
        indentLine(std::string(s.isConst() ? "const " : s.isVar() ? "var " : "let ") +
                   s.name() + ": " + typeToString(s.type()));
        if (s.value()) {
            ++depth_;
            s.value()->accept(*this);
            --depth_;
        }
    }

    void visit(const ExprStmt &s) override {
        indentLine("ExprStmt");
        ++depth_;
        s.expr()->accept(*this);
        --depth_;
    }

    void visit(const IfStmt &s) override {
        indentLine("If");
        ++depth_;
        s.cond()->accept(*this);
        s.thenBlock()->accept(*this);
        if (s.elseBranch()) s.elseBranch()->accept(*this);
        --depth_;
    }

    void visit(const WhileStmt &s) override {
        indentLine("While");
        ++depth_;
        s.cond()->accept(*this);
        s.body()->accept(*this);
        --depth_;
    }

    void visit(const ForStmt &s) override {
        indentLine(s.isForEach() ? "ForEach " + s.varName() : "NumericFor");
        ++depth_;
        if (s.isForEach()) {
            s.iterable()->accept(*this);
        } else {
            if (s.init()) s.init()->accept(*this);
            if (s.cond()) s.cond()->accept(*this);
            if (s.update()) s.update()->accept(*this);
        }
        if (s.body()) s.body()->accept(*this);
        --depth_;
    }

    void visit(const MatchStmt &s) override {
        indentLine("Match");
        ++depth_;
        s.subject()->accept(*this);
        for (const auto &arm : s.arms()) {
            arm.body->accept(*this);
        }
        --depth_;
    }

    void visit(const ReturnStmt &s) override {
        indentLine("Return");
        if (s.value()) {
            ++depth_;
            s.value()->accept(*this);
            --depth_;
        }
    }

    // ExprVisitor interface.
    void visit(const IntExpr &e) override { indentLine("Int " + std::to_string(e.value())); }
    void visit(const DoubleExpr &e) override { indentLine("Double " + std::to_string(e.value())); }
    void visit(const StringExpr &e) override { indentLine("String \"" + e.value() + "\""); }
    void visit(const BoolExpr &e) override { indentLine(std::string("Bool ") + (e.value() ? "true" : "false")); }
    void visit(const NoneExpr &) override { indentLine("None"); }
    void visit(const CtorExpr &e) override {
        const char *k = e.kind() == CtorKind::Some ? "Some" : e.kind() == CtorKind::Ok ? "Ok" : "Err";
        indentLine(k);
        ++depth_;
        e.arg()->accept(*this);
        --depth_;
    }
    void visit(const IdentifierExpr &e) override { indentLine("Ident " + e.name()); }
    void visit(const BinaryExpr &e) override {
        indentLine(std::string("Binary ") + binOpName(e.op()));
        ++depth_;
        e.lhs()->accept(*this);
        e.rhs()->accept(*this);
        --depth_;
    }
    void visit(const UnaryExpr &e) override {
        indentLine(std::string("Unary ") + (e.op() == UnOp::Negate ? "-" : "!"));
        ++depth_;
        e.operand()->accept(*this);
        --depth_;
    }
    void visit(const CastExpr &e) override {
        indentLine("Cast " + typeToString(e.target()));
        ++depth_;
        e.operand()->accept(*this);
        --depth_;
    }
    void visit(const TryExpr &e) override {
        indentLine("Try");
        ++depth_;
        e.operand()->accept(*this);
        --depth_;
    }
    void visit(const TernaryExpr &e) override {
        indentLine("Ternary");
        ++depth_;
        e.cond()->accept(*this);
        e.thenExpr()->accept(*this);
        e.elseExpr()->accept(*this);
        --depth_;
    }
    void visit(const ListExpr &e) override {
        indentLine("List");
        ++depth_;
        for (const auto &el : e.elements()) el->accept(*this);
        --depth_;
    }
    void visit(const StructLitExpr &e) override {
        indentLine("StructLit " + e.typeName());
        ++depth_;
        for (const auto &f : e.fields()) {
            indentLine(f.name + ":");
            f.value->accept(*this);
        }
        --depth_;
    }
    void visit(const LambdaExpr &e) override {
        indentLine("Lambda -> " + typeToString(e.ret()));
        ++depth_;
        if (e.body()) e.body->accept(*this);
        --depth_;
    }
    void visit(const PostfixExpr &e) override {
        indentLine("Postfix");
        ++depth_;
        e.base()->accept(*this);
        for (const auto &op : e.ops()) {
            switch (op.kind) {
            case PostKind::Field: indentLine(". " + op.name); break;
            case PostKind::Static: indentLine(":: " + op.name); break;
            case PostKind::Index: indentLine("[]"); break;
            case PostKind::Call: indentLine("()"); break;
            case PostKind::Propagate: indentLine("?"); break;
            }
        }
        --depth_;
    }
    void visit(const AssignExpr &e) override {
        indentLine(e.compoundOp() ? std::string("AssignOp ") + binOpName(*e.compoundOp()) : "Assign");
        ++depth_;
        e.target()->accept(*this);
        e.value()->accept(*this);
        --depth_;
    }

private:
    void indentLine(const std::string &text) {
        for (int i = 0; i < depth_; ++i) std::cout << "  ";
        std::cout << text << "\n";
    }
    int depth_ = 0;
};

} // namespace

void printAst(const Program &program) {
    AstPrinter printer;
    printer.print(program);
}

} // namespace glyph::ast
