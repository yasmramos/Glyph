#include "parser/Parser.h"

#include <any>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "antlr4-runtime.h"
#include "GlyphBaseVisitor.h"
#include "GlyphLexer.h"
#include "GlyphParser.h"

// AstBuilder converts the ANTLR parse tree into Glyph's own AST.
// Each visit* method returns std::any holding a
// std::unique_ptr<glyph::ast::Expr|Stmt>. It never returns an empty any or a
// null pointer: on failure it throws ParseError, so downstream any_cast is
// always safe (this avoids the classic std::any + nullptr trap).
namespace glyph::parser {
namespace {

SourceLoc locOf(const antlr4::Token *token, const std::string &fileName) {
    return SourceLoc{fileName, static_cast<int>(token->getLine()),
                     static_cast<int>(token->getCharPositionInLine() + 1)};
}

SourceLoc locOf(antlr4::ParserRuleContext *ctx, const std::string &fileName) {
    return locOf(ctx->getStart(), fileName);
}

// Unescape Glyph string literals (\n \t \r \" \' \\; anything else passes
// through unchanged).
std::string unescapeString(const std::string &raw) {
    std::string body = raw.size() >= 2 ? raw.substr(1, raw.size() - 2) : raw;
    std::string out;
    out.reserve(body.size());
    for (size_t i = 0; i < body.size(); ++i) {
        if (body[i] == '\\' && i + 1 < body.size()) {
            ++i;
            switch (body[i]) {
            case 'n': out.push_back('\n'); break;
            case 't': out.push_back('\t'); break;
            case 'r': out.push_back('\r'); break;
            case '"': out.push_back('"'); break;
            case '\'': out.push_back('\''); break;
            case '\\': out.push_back('\\'); break;
            default: out.push_back(body[i]); break;
            }
        } else {
            out.push_back(body[i]);
        }
    }
    return out;
}

/// Thrown by the custom error listener below; caught at the parseSource
/// boundary and rethrown as a ParseError with file/line/column.
struct AbortParse {
    SourceLoc loc;
    std::string message;
};

class ThrowingErrorListener : public antlr4::BaseErrorListener {
public:
    explicit ThrowingErrorListener(std::string fileName)
        : fileName_(std::move(fileName)) {}

    void syntaxError(antlr4::Recognizer *, antlr4::Token *offendingSymbol,
                     size_t line, size_t charPosInLine,
                     const std::string &msg, std::exception_ptr) override {
        // Replace ANTLR's default console output with a hard failure that
        // carries exact position information.
        antlr4::Token *tok = offendingSymbol;
        SourceLoc loc = tok ? locOf(tok, fileName_)
                            : SourceLoc{fileName_, static_cast<int>(line),
                                        static_cast<int>(charPosInLine) + 1};
        throw AbortParse{loc, msg.empty() ? "syntax error" : msg};
    }

private:
    std::string fileName_;
};

class AstBuilder : public GlyphBaseVisitor {
public:
    explicit AstBuilder(std::string fileName) : fileName_(std::move(fileName)) {}

    std::any visitProgram(GlyphParser::ProgramContext *ctx) override {
        auto program = std::make_unique<ast::Program>(SourceLoc{fileName_, 1, 1});
        for (auto *stmtCtx : ctx->statement()) {
            program->stmts.push_back(std::any_cast<std::unique_ptr<ast::Stmt>>(
                stmtCtx->accept(this)));
        }
        return program;
    }

    std::any visitPrintStatement(GlyphParser::PrintStatementContext *ctx) override {
        auto *inner = ctx->printStmt();
        auto value = std::any_cast<std::unique_ptr<ast::Expr>>(
            inner->expr()->accept(this));
        return std::make_unique<ast::PrintStmt>(locOf(inner, fileName_),
                                                std::move(value));
    }

    std::any visitAssignStatement(
        GlyphParser::AssignStatementContext *ctx) override {
        auto *inner = ctx->assignStmt();
        auto value = std::any_cast<std::unique_ptr<ast::Expr>>(
            inner->expr()->accept(this));
        bool isLocal = inner->LOCAL() != nullptr;
        return std::make_unique<ast::AssignStmt>(
            locOf(inner, fileName_), inner->ID()->getText(), std::move(value),
            isLocal);
    }

    std::any visitExpressionStatement(
        GlyphParser::ExpressionStatementContext *ctx) override {
        auto *inner = ctx->exprStmt();
        auto expr = std::any_cast<std::unique_ptr<ast::Expr>>(
            inner->expr()->accept(this));
        return std::make_unique<ast::ExprStmt>(locOf(inner, fileName_),
                                               std::move(expr));
    }

    // Binary alternatives: children are expr(0) (lhs) and expr(1) (rhs).
    std::any visitOrExpr(GlyphParser::OrExprContext *ctx) override {
        return buildBinary(ctx, ast::BinOp::Or);
    }
    std::any visitAndExpr(GlyphParser::AndExprContext *ctx) override {
        return buildBinary(ctx, ast::BinOp::And);
    }
    std::any visitEqualityExpr(GlyphParser::EqualityExprContext *ctx) override {
        return buildBinary(ctx, ctx->EQ() ? ast::BinOp::Eq : ast::BinOp::Ne);
    }
    std::any visitComparisonExpr(
        GlyphParser::ComparisonExprContext *ctx) override {
        ast::BinOp op = ast::BinOp::Lt;
        if (ctx->LE()) op = ast::BinOp::Le;
        else if (ctx->GT()) op = ast::BinOp::Gt;
        else if (ctx->GE()) op = ast::BinOp::Ge;
        return buildBinary(ctx, op);
    }
    std::any visitAdditiveExpr(GlyphParser::AdditiveExprContext *ctx) override {
        return buildBinary(ctx, ctx->PLUS() ? ast::BinOp::Add : ast::BinOp::Sub);
    }
    std::any visitMultiplicativeExpr(
        GlyphParser::MultiplicativeExprContext *ctx) override {
        ast::BinOp op = ast::BinOp::Mul;
        if (ctx->SLASH()) op = ast::BinOp::Div;
        else if (ctx->PERCENT()) op = ast::BinOp::Mod;
        return buildBinary(ctx, op);
    }
    std::any visitPowerExpr(GlyphParser::PowerExprContext *ctx) override {
        return buildBinary(ctx, ast::BinOp::Pow);
    }

    std::any visitUnaryExpr(GlyphParser::UnaryExprContext *ctx) override {
        auto operand = std::any_cast<std::unique_ptr<ast::Expr>>(
            ctx->expr()->accept(this));
        ast::UnOp op = ctx->NOT() ? ast::UnOp::Not : ast::UnOp::Negate;
        return std::make_unique<ast::UnaryExpr>(locOf(ctx, fileName_), op,
                                                std::move(operand));
    }

    std::any visitNumberExpr(GlyphParser::NumberExprContext *ctx) override {
        double value = std::stod(ctx->NUMBER()->getText());
        return std::make_unique<ast::NumberExpr>(locOf(ctx, fileName_), value);
    }

    std::any visitStringExpr(GlyphParser::StringExprContext *ctx) override {
        std::string text = unescapeString(ctx->STRING()->getText());
        return std::make_unique<ast::StringExpr>(locOf(ctx, fileName_),
                                                 std::move(text));
    }

    std::any visitIdentifierExpr(
        GlyphParser::IdentifierExprContext *ctx) override {
        return std::make_unique<ast::IdentifierExpr>(locOf(ctx, fileName_),
                                                     ctx->ID()->getText());
    }

    std::any visitParenExpr(GlyphParser::ParenExprContext *ctx) override {
        // Parentheses only group; drop the wrapper node entirely.
        return ctx->expr()->accept(this);
    }

private:
    // All labeled binary alternatives expose expr(size_t) via their own
    // generated classes; templating keeps one shared implementation.
    template <typename CtxT>
    std::any buildBinary(CtxT *ctx, ast::BinOp op) {
        auto lhs = std::any_cast<std::unique_ptr<ast::Expr>>(
            ctx->expr(0)->accept(this));
        auto rhs = std::any_cast<std::unique_ptr<ast::Expr>>(
            ctx->expr(1)->accept(this));
        return std::make_unique<ast::BinaryExpr>(locOf(ctx, fileName_), op,
                                                 std::move(lhs), std::move(rhs));
    }

    std::string fileName_;
};

// Parses text with the given lexer/parser pair; returns the root context.
// Throws AbortParse on the first syntax error.
antlr4::tree::ParseTree *runParser(GlyphParser &parser) {
    parser.removeErrorListeners();
    return parser.program();
}

} // namespace

std::unique_ptr<ast::Program> parseSource(const std::string &text,
                                          const std::string &fileName) {
    antlr4::ANTLRInputStream input(text);
    GlyphLexer lexer(&input);
    lexer.removeErrorListeners();

    antlr4::CommonTokenStream tokens(&lexer);
    GlyphParser parser(&tokens);

    ThrowingErrorListener errorListener(fileName);
    lexer.addErrorListener(&errorListener);
    parser.addErrorListener(&errorListener);

    try {
        tokens.fill();
        GlyphParser::ProgramContext *tree = parser.program();
        // Guard against the implicit-EOF trap: if the parser stopped before
        // consuming EOF, report it as a syntax error at the offending token.
        if (tree->children.empty() ||
            parser.getCurrentToken()->getType() != antlr4::Token::EOF) {
            throw AbortParse{locOf(parser.getCurrentToken(), fileName),
                             "unexpected end of input"};
        }
        AstBuilder builder(fileName);
        auto program = std::any_cast<std::unique_ptr<ast::Program>>(
            tree->accept(&builder));
        if (!program) {
            throw AbortParse{SourceLoc{fileName, 1, 1},
                             "internal error: empty program node"};
        }
        return program;
    } catch (const AbortParse &e) {
        throw ParseError(e.loc, e.message);
    }
}

} // namespace glyph::parser
