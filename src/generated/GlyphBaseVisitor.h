
// Generated from /workspace/grammars/Glyph.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "GlyphVisitor.h"


/**
 * This class provides an empty implementation of GlyphVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  GlyphBaseVisitor : public GlyphVisitor {
public:

  virtual std::any visitProgram(GlyphParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrintStatement(GlyphParser::PrintStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignStatement(GlyphParser::AssignStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionStatement(GlyphParser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrintStmt(GlyphParser::PrintStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignStmt(GlyphParser::AssignStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprStmt(GlyphParser::ExprStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndExpr(GlyphParser::AndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringExpr(GlyphParser::StringExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiplicativeExpr(GlyphParser::MultiplicativeExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPowerExpr(GlyphParser::PowerExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqualityExpr(GlyphParser::EqualityExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdditiveExpr(GlyphParser::AdditiveExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumberExpr(GlyphParser::NumberExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparisonExpr(GlyphParser::ComparisonExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifierExpr(GlyphParser::IdentifierExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenExpr(GlyphParser::ParenExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExpr(GlyphParser::UnaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrExpr(GlyphParser::OrExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

