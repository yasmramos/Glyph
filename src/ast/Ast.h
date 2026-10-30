#pragma once

#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "ast/SourceLoc.h"

// The Glyph AST is intentionally free of any ANTLR or LLVM types.
// It is a pure, ownable data structure that every later stage consumes.
//
// Draft 0.2: mirrors the static-typing grammar (structs, classes, interfaces,
// generics, Option/Result, pattern matching). See grammars/Glyph.g4.
namespace glyph::ast {

// ---------------------------------------------------------------------------
// Types
// ---------------------------------------------------------------------------

enum class TypeKind { Int, Long, Double, Bool, Str, List, Option, Result, Fn, Named };

class Type {
public:
    explicit Type(TypeKind kind) : kind_(kind) {}
    virtual ~Type() = default;
    TypeKind kind() const { return kind_; }

private:
    TypeKind kind_;
};

class ListType : public Type {
public:
    ListType(std::unique_ptr<Type> element)
        : Type(TypeKind::List), element_(std::move(element)) {}
    const Type *element() const { return element_.get(); }

private:
    std::unique_ptr<Type> element_;
};

class OptionType : public Type {
public:
    OptionType(std::unique_ptr<Type> inner)
        : Type(TypeKind::Option), inner_(std::move(inner)) {}
    const Type *inner() const { return inner_.get(); }

private:
    std::unique_ptr<Type> inner_;
};

class ResultType : public Type {
public:
    ResultType(std::unique_ptr<Type> okType)
        : Type(TypeKind::Result), ok_(std::move(okType)) {}
    const Type *ok() const { return ok_.get(); }

private:
    std::unique_ptr<Type> ok_;
};

class FnType : public Type {
public:
    FnType(std::vector<std::unique_ptr<Type>> params,
           std::unique_ptr<Type> ret)
        : Type(TypeKind::Fn), params_(std::move(params)), ret_(std::move(ret)) {}
    const std::vector<std::unique_ptr<Type>> &params() const { return params_; }
    const Type *ret() const { return ret_.get(); }

private:
    std::vector<std::unique_ptr<Type>> params_;
    std::unique_ptr<Type> ret_;
};

class NamedType : public Type {
public:
    NamedType(std::string name, std::vector<std::unique_ptr<Type>> genericArgs)
        : Type(TypeKind::Named), name_(std::move(name)),
          genericArgs_(std::move(genericArgs)) {}
    const std::string &name() const { return name_; }
    const std::vector<std::unique_ptr<Type>> &genericArgs() const {
        return genericArgs_;
    }

private:
    std::string name_;
    std::vector<std::unique_ptr<Type>> genericArgs_;
};

using TypePtr = std::unique_ptr<Type>;

// ---------------------------------------------------------------------------
// Expressions
// ---------------------------------------------------------------------------

class ExprVisitor;

class Expr {
public:
    explicit Expr(SourceLoc loc) : loc_(std::move(loc)) {}
    virtual ~Expr() = default;
    const SourceLoc &loc() const { return loc_; }
    /// Double dispatch into an ExprVisitor (defined in Ast.cpp).
    void accept(ExprVisitor &v) const;

private:
    SourceLoc loc_;
};

class IntExpr : public Expr {
public:
    IntExpr(SourceLoc loc, long long value)
        : Expr(std::move(loc)), value_(value) {}
    long long value() const { return value_; }
    void accept(ExprVisitor &v) const;

private:
    long long value_;
};

class DoubleExpr : public Expr {
public:
    DoubleExpr(SourceLoc loc, double value)
        : Expr(std::move(loc)), value_(value) {}
    double value() const { return value_; }
    void accept(ExprVisitor &v) const;

private:
    double value_;
};

class StringExpr : public Expr {
public:
    StringExpr(SourceLoc loc, std::string value)
        : Expr(std::move(loc)), value_(std::move(value)) {}
    const std::string &value() const { return value_; }
    void accept(ExprVisitor &v) const;

private:
    std::string value_;
};

class BoolExpr : public Expr {
public:
    BoolExpr(SourceLoc loc, bool value)
        : Expr(std::move(loc)), value_(value) {}
    bool value() const { return value_; }
    void accept(ExprVisitor &v) const;

private:
    bool value_;
};

class NoneExpr : public Expr {
public:
    explicit NoneExpr(SourceLoc loc) : Expr(std::move(loc)) {}
    void accept(ExprVisitor &v) const;
};

/// some(e) / ok(e) / err(e) — Option and Result constructors.
enum class CtorKind { Some, Ok, Err };

class CtorExpr : public Expr {
public:
    CtorExpr(SourceLoc loc, CtorKind kind, std::unique_ptr<Expr> arg)
        : Expr(std::move(loc)), kind_(kind), arg_(std::move(arg)) {}
    CtorKind kind() const { return kind_; }
    const Expr *arg() const { return arg_.get(); }
    void accept(ExprVisitor &v) const;

private:
    CtorKind kind_;
    std::unique_ptr<Expr> arg_;
};

class IdentifierExpr : public Expr {
public:
    IdentifierExpr(SourceLoc loc, std::string name)
        : Expr(std::move(loc)), name_(std::move(name)) {}
    const std::string &name() const { return name_; }
    void accept(ExprVisitor &v) const;

private:
    std::string name_;
};

enum class BinOp {
    Add, Sub, Mul, Div, Mod, Eq, Ne, Lt, Le, Gt, Ge, And, Or, Concat
};

class BinaryExpr : public Expr {
public:
    BinaryExpr(SourceLoc loc, BinOp op, std::unique_ptr<Expr> lhs,
               std::unique_ptr<Expr> rhs)
        : Expr(std::move(loc)), op_(op), lhs_(std::move(lhs)),
          rhs_(std::move(rhs)) {}
    BinOp op() const { return op_; }
    const Expr *lhs() const { return lhs_.get(); }
    const Expr *rhs() const { return rhs_.get(); }
    void accept(ExprVisitor &v) const;

private:
    BinOp op_;
    std::unique_ptr<Expr> lhs_;
    std::unique_ptr<Expr> rhs_;
};

enum class UnOp { Negate, Not };

class UnaryExpr : public Expr {
public:
    UnaryExpr(SourceLoc loc, UnOp op, std::unique_ptr<Expr> operand)
        : Expr(std::move(loc)), op_(op), operand_(std::move(operand)) {}
    UnOp op() const { return op_; }
    const Expr *operand() const { return operand_.get(); }
    void accept(ExprVisitor &v) const;

private:
    UnOp op_;
    std::unique_ptr<Expr> operand_;
};

/// e as T
class CastExpr : public Expr {
public:
    CastExpr(SourceLoc loc, std::unique_ptr<Expr> operand, TypePtr target)
        : Expr(std::move(loc)), operand_(std::move(operand)),
          target_(std::move(target)) {}
    const Expr *operand() const { return operand_.get(); }
    const Type *target() const { return target_.get(); }
    void accept(ExprVisitor &v) const;

private:
    std::unique_ptr<Expr> operand_;
    TypePtr target_;
};

/// try e — propagate Option/Result errors from an expression.
class TryExpr : public Expr {
public:
    TryExpr(SourceLoc loc, std::unique_ptr<Expr> operand)
        : Expr(std::move(loc)), operand_(std::move(operand)) {}
    const Expr *operand() const { return operand_.get(); }
    void accept(ExprVisitor &v) const;

private:
    std::unique_ptr<Expr> operand_;
};

/// cond ? then : else
class TernaryExpr : public Expr {
public:
    TernaryExpr(SourceLoc loc, std::unique_ptr<Expr> cond,
                std::unique_ptr<Expr> thenExpr, std::unique_ptr<Expr> elseExpr)
        : Expr(std::move(loc)), cond_(std::move(cond)),
          then_(std::move(thenExpr)), else_(std::move(elseExpr)) {}
    const Expr *cond() const { return cond_.get(); }
    const Expr *thenExpr() const { return then_.get(); }
    const Expr *elseExpr() const { return else_.get(); }
    void accept(ExprVisitor &v) const;

private:
    std::unique_ptr<Expr> cond_, then_, else_;
};

/// [a, b, c]
class ListExpr : public Expr {
public:
    ListExpr(SourceLoc loc, std::vector<std::unique_ptr<Expr>> elements)
        : Expr(std::move(loc)), elements_(std::move(elements)) {}
    const std::vector<std::unique_ptr<Expr>> &elements() const {
        return elements_;
    }
    void accept(ExprVisitor &v) const;

private:
    std::vector<std::unique_ptr<Expr>> elements_;
};

/// Name { field: expr, ... }
struct FieldInit {
    std::string name;
    std::unique_ptr<Expr> value;
};

class StructLitExpr : public Expr {
public:
    StructLitExpr(SourceLoc loc, std::string typeName,
                  std::vector<FieldInit> fields)
        : Expr(std::move(loc)), typeName_(std::move(typeName)),
          fields_(std::move(fields)) {}
    const std::string &typeName() const { return typeName_; }
    const std::vector<FieldInit> &fields() const { return fields_; }
    void accept(ExprVisitor &v) const;

private:
    std::string typeName_;
    std::vector<FieldInit> fields_;
};

/// fn(params) -> T { body } or short form fn(params) expr
class LambdaExpr : public Expr {
public:
    struct Param {
        std::string name;
        TypePtr type; // optional annotation, null when absent
    };
    LambdaExpr(SourceLoc loc, std::vector<Param> params, TypePtr ret,
               std::unique_ptr<BlockStmt> body)
        : Expr(std::move(loc)), params_(std::move(params)),
          ret_(std::move(ret)), body_(std::move(body)) {}
    const std::vector<Param> &params() const { return params_; }
    const Type *ret() const { return ret_.get(); }
    const BlockStmt *body() const { return body_.get(); }
    void accept(ExprVisitor &v) const;

private:
    std::vector<Param> params_;
    TypePtr ret_;
    std::unique_ptr<BlockStmt> body_;
};

/// Postfix chain base + operations applied left to right.
enum class PostKind { Field, Static, Index, Call, Propagate };

struct PostfixOp {
    PostKind kind;
    std::string name;                    // Field / Static member name
    std::vector<std::unique_ptr<Expr>> args; // Call arguments (empty otherwise)
};

class PostfixExpr : public Expr {
public:
    PostfixExpr(SourceLoc loc, std::unique_ptr<Expr> base,
                std::vector<PostfixOp> ops)
        : Expr(std::move(loc)), base_(std::move(base)), ops_(std::move(ops)) {}
    const Expr *base() const { return base_.get(); }
    const std::vector<PostfixOp> &ops() const { return ops_; }
    void accept(ExprVisitor &v) const;

private:
    std::unique_ptr<Expr> base_;
    std::vector<PostfixOp> ops_;
};

/// Assignment expressions (exprOrAssign): x = e | x op= e
class AssignExpr : public Expr {
public:
    AssignExpr(SourceLoc loc, std::unique_ptr<Expr> target,
               std::optional<BinOp> compoundOp, std::unique_ptr<Expr> value)
        : Expr(std::move(loc)), target_(std::move(target)),
          compoundOp_(compoundOp), value_(std::move(value)) {}
    const Expr *target() const { return target_.get(); }
    /// Present for `+=`-style assignments; plain `=` leaves it empty.
    const std::optional<BinOp> &compoundOp() const { return compoundOp_; }
    const Expr *value() const { return value_.get(); }
    void accept(ExprVisitor &v) const;

private:
    std::unique_ptr<Expr> target_;
    std::optional<BinOp> compoundOp_;
    std::unique_ptr<Expr> value_;
};

// ---------------------------------------------------------------------------
// Statements
// ---------------------------------------------------------------------------

class StmtVisitor;

class Stmt {
public:
    explicit Stmt(SourceLoc loc) : loc_(std::move(loc)) {}
    virtual ~Stmt() = default;
    const SourceLoc &loc() const { return loc_; }
    /// Double dispatch into a StmtVisitor (defined in Ast.cpp).
    void accept(StmtVisitor &v) const;

private:
    SourceLoc loc_;
};

class BlockStmt : public Stmt {
public:
    BlockStmt(SourceLoc loc, std::vector<std::unique_ptr<Stmt>> stmts)
        : Stmt(std::move(loc)), stmts_(std::move(stmts)) {}
    const std::vector<std::unique_ptr<Stmt>> &stmts() const { return stmts_; }
    void accept(StmtVisitor &v) const;

private:
    std::vector<std::unique_ptr<Stmt>> stmts_;
};

/// let/const/var bindings. `isVar` marks mutable `var` declarations,
/// `isConst` marks compile-time constants.
class BindStmt : public Stmt {
public:
    BindStmt(SourceLoc loc, std::string name, TypePtr type,
             std::unique_ptr<Expr> value, bool isVar, bool isConst)
        : Stmt(std::move(loc)), name_(std::move(name)), type_(std::move(type)),
          value_(std::move(value)), isVar_(isVar), isConst_(isConst) {}
    const std::string &name() const { return name_; }
    const Type *type() const { return type_.get(); } // may be null (inferred)
    const Expr *value() const { return value_.get(); } // null for bare `var x: T`
    bool isVar() const { return isVar_; }
    bool isConst() const { return isConst_; }
    void accept(StmtVisitor &v) const;

private:
    std::string name_;
    TypePtr type_;
    std::unique_ptr<Expr> value_;
    bool isVar_;
    bool isConst_;
};

class ExprStmt : public Stmt {
public:
    ExprStmt(SourceLoc loc, std::unique_ptr<Expr> expr)
        : Stmt(std::move(loc)), expr_(std::move(expr)) {}
    const Expr *expr() const { return expr_.get(); }
    void accept(StmtVisitor &v) const;

private:
    std::unique_ptr<Expr> expr_;
};

class IfStmt : public Stmt {
public:
    IfStmt(SourceLoc loc, std::unique_ptr<Expr> cond,
           std::unique_ptr<BlockStmt> thenBlock,
           std::unique_ptr<Stmt> elseBranch /* IfStmt or BlockStmt or null */)
        : Stmt(std::move(loc)), cond_(std::move(cond)),
          then_(std::move(thenBlock)), else_(std::move(elseBranch)) {}
    const Expr *cond() const { return cond_.get(); }
    const BlockStmt *thenBlock() const { return then_.get(); }
    const Stmt *elseBranch() const { return else_.get(); }
    void accept(StmtVisitor &v) const;

private:
    std::unique_ptr<Expr> cond_;
    std::unique_ptr<BlockStmt> then_;
    std::unique_ptr<Stmt> else_;
};

class WhileStmt : public Stmt {
public:
    WhileStmt(SourceLoc loc, std::unique_ptr<Expr> cond,
              std::unique_ptr<BlockStmt> body)
        : Stmt(std::move(loc)), cond_(std::move(cond)), body_(std::move(body)) {}
    const Expr *cond() const { return cond_.get(); }
    const BlockStmt *body() const { return body_.get(); }
    void accept(StmtVisitor &v) const;

private:
    std::unique_ptr<Expr> cond_;
    std::unique_ptr<BlockStmt> body_;
};

/// Two forms: `for x in expr {}` (iteration) and numeric `for i;cond;update {}`.
class ForStmt : public Stmt {
public:
    ForStmt(SourceLoc loc, std::string varName, std::unique_ptr<Expr> iterable)
        : Stmt(std::move(loc)), varName_(std::move(varName)),
          iterable_(std::move(iterable)) {}
    ForStmt(SourceLoc loc, std::unique_ptr<Stmt> init,
            std::unique_ptr<Expr> cond, std::unique_ptr<Expr> update,
            std::unique_ptr<BlockStmt> body)
        : Stmt(std::move(loc)), init_(std::move(init)), cond_(std::move(cond)),
          update_(std::move(update)), body_(std::move(body)) {}
    bool isForEach() const { return iterable_ != nullptr; }
    const std::string &varName() const { return varName_; }
    const Expr *iterable() const { return iterable_.get(); }
    const Stmt *init() const { return init_.get(); }
    const Expr *cond() const { return cond_.get(); }
    const Expr *update() const { return update_.get(); }
    const BlockStmt *body() const { return body_.get(); }
    void accept(StmtVisitor &v) const;

private:
    std::string varName_;
    std::unique_ptr<Expr> iterable_;
    std::unique_ptr<Stmt> init_;
    std::unique_ptr<Expr> cond_;
    std::unique_ptr<Expr> update_;
    std::unique_ptr<BlockStmt> body_;
};

enum class PatKind { Wildcard, Some, None, Ok, Err, IntLit, StrLit };

struct Pattern {
    PatKind kind = PatKind::Wildcard;
    std::string binding;   // variable captured by some(x)/ok(x)/err(x)
    long long intValue = 0; // IntLit patterns
    std::string strValue;   // StrLit patterns
};

struct MatchArm {
    Pattern pattern;
    std::unique_ptr<Expr> guard;      // optional `if cond`
    std::unique_ptr<Stmt> body;       // BlockStmt or ExprStmt
};

class MatchStmt : public Stmt {
public:
    MatchStmt(SourceLoc loc, std::unique_ptr<Expr> subject,
              std::vector<MatchArm> arms)
        : Stmt(std::move(loc)), subject_(std::move(subject)),
          arms_(std::move(arms)) {}
    const Expr *subject() const { return subject_.get(); }
    const std::vector<MatchArm> &arms() const { return arms_; }
    void accept(StmtVisitor &v) const;

private:
    std::unique_ptr<Expr> subject_;
    std::vector<MatchArm> arms_;
};

class ReturnStmt : public Stmt {
public:
    ReturnStmt(SourceLoc loc, std::unique_ptr<Expr> value)
        : Stmt(std::move(loc)), value_(std::move(value)) {}
    const Expr *value() const { return value_.get(); } // null for bare return
    void accept(StmtVisitor &v) const;

private:
    std::unique_ptr<Expr> value_;
};

// ---------------------------------------------------------------------------
// Top-level declarations
// ---------------------------------------------------------------------------

struct Param {
    std::string name;
    TypePtr type;
    bool isVar = false; // `var self`-style mutable receiver
};

struct FieldDecl {
    std::string name;
    TypePtr type;
    bool isConst = false;
    bool isVar = false;
};

struct FnDecl {
    std::string name;
    std::vector<std::string> genericParams;
    std::vector<Param> params;
    TypePtr returnType; // null when the function returns nothing
    std::unique_ptr<BlockStmt> body; // null for interface signatures
    bool overrideFlag = false;
};

struct StructDecl {
    std::string name;
    std::vector<std::string> genericParams;
    std::vector<FieldDecl> fields;
};

struct InterfaceDecl {
    std::string name;
    std::vector<FnDecl> methods; // bodies are always null
};

struct ClassDecl {
    std::string name;
    std::vector<std::string> genericParams;
    std::string parent;                 // `extends X`, empty when absent
    std::vector<std::string> interfaces; // `implements A, B`
    std::vector<FieldDecl> fields;
    std::vector<FnDecl> methods;
};

struct ConstDecl {
    std::string name;
    std::unique_ptr<Expr> value;
};

struct ImportDecl {
    std::string path; // qualified dotted name, e.g. "std.io"
};

class Program {
public:
    explicit Program(SourceLoc loc) : loc(std::move(loc)) {}
    const SourceLoc &programLoc() const { return loc; }

    std::string moduleName;
    std::vector<ImportDecl> imports;
    std::vector<std::unique_ptr<ConstDecl>> consts;
    std::vector<std::unique_ptr<StructDecl>> structs;
    std::vector<std::unique_ptr<InterfaceDecl>> interfaces;
    std::vector<std::unique_ptr<ClassDecl>> classes;
    std::vector<std::unique_ptr<FnDecl>> functions;

private:
    SourceLoc loc;
};

// ---------------------------------------------------------------------------
// Visitors (double dispatch over the AST)
// ---------------------------------------------------------------------------

class ExprVisitor {
public:
    virtual ~ExprVisitor() = default;
    virtual void visit(const IntExpr &e) = 0;
    virtual void visit(const DoubleExpr &e) = 0;
    virtual void visit(const StringExpr &e) = 0;
    virtual void visit(const BoolExpr &e) = 0;
    virtual void visit(const NoneExpr &e) = 0;
    virtual void visit(const CtorExpr &e) = 0;
    virtual void visit(const IdentifierExpr &e) = 0;
    virtual void visit(const BinaryExpr &e) = 0;
    virtual void visit(const UnaryExpr &e) = 0;
    virtual void visit(const CastExpr &e) = 0;
    virtual void visit(const TryExpr &e) = 0;
    virtual void visit(const TernaryExpr &e) = 0;
    virtual void visit(const ListExpr &e) = 0;
    virtual void visit(const StructLitExpr &e) = 0;
    virtual void visit(const LambdaExpr &e) = 0;
    virtual void visit(const PostfixExpr &e) = 0;
    virtual void visit(const AssignExpr &e) = 0;
};

class StmtVisitor {
public:
    virtual ~StmtVisitor() = default;
    virtual void visit(const BlockStmt &s) = 0;
    virtual void visit(const BindStmt &s) = 0;
    virtual void visit(const ExprStmt &s) = 0;
    virtual void visit(const IfStmt &s) = 0;
    virtual void visit(const WhileStmt &s) = 0;
    virtual void visit(const ForStmt &s) = 0;
    virtual void visit(const MatchStmt &s) = 0;
    virtual void visit(const ReturnStmt &s) = 0;
};

// Debug helper: pretty-prints the AST to stdout without needing LLVM.
void printAst(const Program &program);

} // namespace glyph::ast
