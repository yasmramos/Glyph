#include "ast/Ast.h"

#include <cstdio>
#include <iostream>

namespace glyph::ast {

// Double-dispatch glue: accept() forwards to the matching visit() overload.
void NumberExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void StringExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void IdentifierExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void BinaryExpr::accept(ExprVisitor &v) const { v.visit(*this); }
void UnaryExpr::accept(ExprVisitor &v) const { v.visit(*this); }

void PrintStmt::accept(StmtVisitor &v) const { v.visit(*this); }
void AssignStmt::accept(StmtVisitor &v) const { v.visit(*this); }
void ExprStmt::accept(StmtVisitor &v) const { v.visit(*this); }

namespace {

const char *binOpName(BinOp op) {
    switch (op) {
    case BinOp::Add: return "+";
    case BinOp::Sub: return "-";
    case BinOp::Mul: return "*";
    case BinOp::Div: return "/";
    case BinOp::Mod: return "%";
    case BinOp::Pow: return "^";
    case BinOp::Eq: return "==";
    case BinOp::Ne: return "~=";
    case BinOp::Lt: return "<";
    case BinOp::Le: return "<=";
    case BinOp::Gt: return ">";
    case BinOp::Ge: return ">=";
    case BinOp::And: return "and";
    case BinOp::Or: return "or";
    }
    return "?";
}

// Text-dump visitor used by printAst(); keeps debugging independent of LLVM.
class AstPrinter : public ExprVisitor, public StmtVisitor {
public:
    void print(const Program &program) {
        std::cout << "Program (" << program.loc().file << ")\n";
        for (const auto &stmt : program.stmts) {
            stmt->accept(*this);
        }
    }

    // StmtVisitor interface.
    void visit(const PrintStmt &s) override {
        indent();
        std::cout << "PrintStmt @" << lineCol(s.loc()) << "\n";
        ++depth_;
        s.value()->accept(*this);
        --depth_;
    }

    void visit(const AssignStmt &s) override {
        indent();
        std::cout << (s.isLocal() ? "LocalAssign " : "Assign ") << s.name()
                  << " @" << lineCol(s.loc()) << "\n";
        ++depth_;
        s.value()->accept(*this);
        --depth_;
    }

    void visit(const ExprStmt &s) override {
        indent();
        std::cout << "ExprStmt @" << lineCol(s.loc()) << "\n";
        ++depth_;
        s.expr()->accept(*this);
        --depth_;
    }

    // ExprVisitor interface.
    void visit(const NumberExpr &e) override {
        indent();
        std::cout << "Number " << e.value() << " @" << lineCol(e.loc()) << "\n";
    }

    void visit(const StringExpr &e) override {
        indent();
        std::cout << "String \"" << e.value() << "\" @" << lineCol(e.loc()) << "\n";
    }

    void visit(const IdentifierExpr &e) override {
        indent();
        std::cout << "Identifier " << e.name() << " @" << lineCol(e.loc()) << "\n";
    }

    void visit(const BinaryExpr &e) override {
        indent();
        std::cout << "Binary '" << binOpName(e.op()) << "' @" << lineCol(e.loc())
                  << "\n";
        ++depth_;
        e.lhs()->accept(*this);
        e.rhs()->accept(*this);
        --depth_;
    }

    void visit(const UnaryExpr &e) override {
        indent();
        std::cout << (e.op() == UnOp::Negate ? "Unary '-'" : "Unary 'not'") << " @"
                  << lineCol(e.loc()) << "\n";
        ++depth_;
        e.operand()->accept(*this);
        --depth_;
    }

private:
    void indent() const { std::cout << std::string(depth_ * 2, ' '); }
    static std::string lineCol(const SourceLoc &loc) {
        return std::to_string(loc.line) + ":" + std::to_string(loc.col);
    }
    int depth_ = 1;
};

} // namespace

void printAst(const Program &program) {
    AstPrinter printer;
    printer.print(program);
}

} // namespace glyph::ast
