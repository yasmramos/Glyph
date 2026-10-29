#pragma once

#include <memory>
#include <string>
#include <vector>

#include "ast/SourceLoc.h"

// The Glyph AST is intentionally free of any ANTLR or LLVM types.
// It is a pure, ownable data structure that every later stage consumes.
namespace glyph::ast {

// ---------------------------------------------------------------------------
// Expressions
// ---------------------------------------------------------------------------

class ExprVisitor;

class Expr {
public:
    explicit Expr(SourceLoc loc) : loc_(std::move(loc)) {}
    virtual ~Expr() = default;
    const SourceLoc &loc() const { return loc_; }

private:
    SourceLoc loc_;
};

class NumberExpr : public Expr {
public:
    NumberExpr(SourceLoc loc, double value) : Expr(std::move(loc)), value_(value) {}
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

class IdentifierExpr : public Expr {
public:
    IdentifierExpr(SourceLoc loc, std::string name)
        : Expr(std::move(loc)), name_(std::move(name)) {}
    const std::string &name() const { return name_; }
    void accept(ExprVisitor &v) const;

private:
    std::string name_;
};

enum class BinOp { Add, Sub, Mul, Div, Mod, Pow, Eq, Ne, Lt, Le, Gt, Ge, And, Or };

class BinaryExpr : public Expr {
public:
    BinaryExpr(SourceLoc loc, BinOp op, std::unique_ptr<Expr> lhs,
               std::unique_ptr<Expr> rhs)
        : Expr(std::move(loc)), op_(op), lhs_(std::move(lhs)), rhs_(std::move(rhs)) {}
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

// ---------------------------------------------------------------------------
// Statements
// ---------------------------------------------------------------------------

class StmtVisitor;

class Stmt {
public:
    explicit Stmt(SourceLoc loc) : loc_(std::move(loc)) {}
    virtual ~Stmt() = default;
    const SourceLoc &loc() const { return loc_; }

private:
    SourceLoc loc_;
};

class PrintStmt : public Stmt {
public:
    PrintStmt(SourceLoc loc, std::unique_ptr<Expr> value)
        : Stmt(std::move(loc)), value_(std::move(value)) {}
    const Expr *value() const { return value_.get(); }
    void accept(StmtVisitor &v) const;

private:
    std::unique_ptr<Expr> value_;
};

class AssignStmt : public Stmt {
public:
    AssignStmt(SourceLoc loc, std::string name, std::unique_ptr<Expr> value,
               bool isLocal)
        : Stmt(std::move(loc)), name_(std::move(name)), value_(std::move(value)),
          isLocal_(isLocal) {}
    const std::string &name() const { return name_; }
    const Expr *value() const { return value_.get(); }
    bool isLocal() const { return isLocal_; }
    void accept(StmtVisitor &v) const;

private:
    std::string name_;
    std::unique_ptr<Expr> value_;
    bool isLocal_;
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

class Program {
public:
    explicit Program(SourceLoc loc) : loc_(std::move(loc)) {}
    const SourceLoc &loc() const { return loc_; }
    std::vector<std::unique_ptr<Stmt>> stmts;
};

// ---------------------------------------------------------------------------
// Visitors (double dispatch over the AST)
// ---------------------------------------------------------------------------

class ExprVisitor {
public:
    virtual ~ExprVisitor() = default;
    virtual void visit(const NumberExpr &e) = 0;
    virtual void visit(const StringExpr &e) = 0;
    virtual void visit(const IdentifierExpr &e) = 0;
    virtual void visit(const BinaryExpr &e) = 0;
    virtual void visit(const UnaryExpr &e) = 0;
};

class StmtVisitor {
public:
    virtual ~StmtVisitor() = default;
    virtual void visit(const PrintStmt &s) = 0;
    virtual void visit(const AssignStmt &s) = 0;
    virtual void visit(const ExprStmt &s) = 0;
};

// Debug helper: pretty-prints the AST to stdout without needing LLVM.
void printAst(const Program &program);

} // namespace glyph::ast
