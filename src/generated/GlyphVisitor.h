
// Generated from /workspace/grammars/Glyph.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "GlyphParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by GlyphParser.
 */
class  GlyphVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by GlyphParser.
   */
    virtual std::any visitProgram(GlyphParser::ProgramContext *context) = 0;

    virtual std::any visitPrintStatement(GlyphParser::PrintStatementContext *context) = 0;

    virtual std::any visitAssignStatement(GlyphParser::AssignStatementContext *context) = 0;

    virtual std::any visitExpressionStatement(GlyphParser::ExpressionStatementContext *context) = 0;

    virtual std::any visitPrintStmt(GlyphParser::PrintStmtContext *context) = 0;

    virtual std::any visitAssignStmt(GlyphParser::AssignStmtContext *context) = 0;

    virtual std::any visitExprStmt(GlyphParser::ExprStmtContext *context) = 0;

    virtual std::any visitAndExpr(GlyphParser::AndExprContext *context) = 0;

    virtual std::any visitStringExpr(GlyphParser::StringExprContext *context) = 0;

    virtual std::any visitMultiplicativeExpr(GlyphParser::MultiplicativeExprContext *context) = 0;

    virtual std::any visitPowerExpr(GlyphParser::PowerExprContext *context) = 0;

    virtual std::any visitEqualityExpr(GlyphParser::EqualityExprContext *context) = 0;

    virtual std::any visitAdditiveExpr(GlyphParser::AdditiveExprContext *context) = 0;

    virtual std::any visitNumberExpr(GlyphParser::NumberExprContext *context) = 0;

    virtual std::any visitComparisonExpr(GlyphParser::ComparisonExprContext *context) = 0;

    virtual std::any visitIdentifierExpr(GlyphParser::IdentifierExprContext *context) = 0;

    virtual std::any visitParenExpr(GlyphParser::ParenExprContext *context) = 0;

    virtual std::any visitUnaryExpr(GlyphParser::UnaryExprContext *context) = 0;

    virtual std::any visitOrExpr(GlyphParser::OrExprContext *context) = 0;


};

