
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

  virtual std::any visitModuleDecl(GlyphParser::ModuleDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportDecl(GlyphParser::ImportDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTopConst(GlyphParser::TopConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTopStruct(GlyphParser::TopStructContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTopInterface(GlyphParser::TopInterfaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTopClass(GlyphParser::TopClassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTopFn(GlyphParser::TopFnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDecl(GlyphParser::ConstDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructDecl(GlyphParser::StructDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterfaceDecl(GlyphParser::InterfaceDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassDecl(GlyphParser::ClassDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFieldDecl(GlyphParser::FieldDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSigDecl(GlyphParser::SigDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemberField(GlyphParser::MemberFieldContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemberFn(GlyphParser::MemberFnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAttrDecl(GlyphParser::AttrDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParamList(GlyphParser::ParamListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam(GlyphParser::ParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFnDecl(GlyphParser::FnDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBuiltinType(GlyphParser::BuiltinTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListType(GlyphParser::ListTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOptionType(GlyphParser::OptionTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitResultType(GlyphParser::ResultTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFnType(GlyphParser::FnTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNamedType(GlyphParser::NamedTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeName(GlyphParser::TypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitQualifiedName(GlyphParser::QualifiedNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGenericParams(GlyphParser::GenericParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGenericArgs(GlyphParser::GenericArgsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeList(GlyphParser::TypeListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(GlyphParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtConst(GlyphParser::StmtConstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtLet(GlyphParser::StmtLetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtVar(GlyphParser::StmtVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtExpr(GlyphParser::StmtExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtBlock(GlyphParser::StmtBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtIf(GlyphParser::StmtIfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtWhile(GlyphParser::StmtWhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtFor(GlyphParser::StmtForContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtMatch(GlyphParser::StmtMatchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtReturn(GlyphParser::StmtReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstStmt(GlyphParser::ConstStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLetStmt(GlyphParser::LetStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarStmt(GlyphParser::VarStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprStmt(GlyphParser::ExprStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStmt(GlyphParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStmt(GlyphParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForEach(GlyphParser::ForEachContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumericFor(GlyphParser::NumericForContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForInit(GlyphParser::ForInitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForUpdate(GlyphParser::ForUpdateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatchStmt(GlyphParser::MatchStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatchArm(GlyphParser::MatchArmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWildcardPat(GlyphParser::WildcardPatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSomePat(GlyphParser::SomePatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNonePat(GlyphParser::NonePatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOkPat(GlyphParser::OkPatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitErrPat(GlyphParser::ErrPatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntPat(GlyphParser::IntPatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStrPat(GlyphParser::StrPatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStmt(GlyphParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(GlyphParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCompoundAssign(GlyphParser::CompoundAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSimpleAssign(GlyphParser::SimpleAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPlainExpr(GlyphParser::PlainExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTernaryExpr(GlyphParser::TernaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrExpr(GlyphParser::OrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndExpr(GlyphParser::AndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqualityExpr(GlyphParser::EqualityExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitComparisonExpr(GlyphParser::ComparisonExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdditiveExpr(GlyphParser::AdditiveExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiplicativeExpr(GlyphParser::MultiplicativeExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAsCast(GlyphParser::AsCastContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTryExpr(GlyphParser::TryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCastOperand(GlyphParser::CastOperandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrimitiveKw(GlyphParser::PrimitiveKwContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryOp(GlyphParser::UnaryOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryOperand(GlyphParser::UnaryOperandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPostfixExpr(GlyphParser::PostfixExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFieldAccess(GlyphParser::FieldAccessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStaticAccess(GlyphParser::StaticAccessContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndex(GlyphParser::IndexContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCall(GlyphParser::CallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropagate(GlyphParser::PropagateContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntLit(GlyphParser::IntLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDoubleLit(GlyphParser::DoubleLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTrueLit(GlyphParser::TrueLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFalseLit(GlyphParser::FalseLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNoneLit(GlyphParser::NoneLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSomeCtor(GlyphParser::SomeCtorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOkCtor(GlyphParser::OkCtorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitErrCtor(GlyphParser::ErrCtorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringLit(GlyphParser::StringLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitListLit(GlyphParser::ListLitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructLitNamed(GlyphParser::StructLitNamedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStructLitInferred(GlyphParser::StructLitInferredContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenExpr(GlyphParser::ParenExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambdaExpr(GlyphParser::LambdaExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambdaExprShort(GlyphParser::LambdaExprShortContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifier(GlyphParser::IdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFieldInit(GlyphParser::FieldInitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambdaParams(GlyphParser::LambdaParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgList(GlyphParser::ArgListContext *ctx) override {
    return visitChildren(ctx);
  }


};

