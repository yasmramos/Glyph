
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

    virtual std::any visitModuleDecl(GlyphParser::ModuleDeclContext *context) = 0;

    virtual std::any visitImportDecl(GlyphParser::ImportDeclContext *context) = 0;

    virtual std::any visitTopConst(GlyphParser::TopConstContext *context) = 0;

    virtual std::any visitTopStruct(GlyphParser::TopStructContext *context) = 0;

    virtual std::any visitTopInterface(GlyphParser::TopInterfaceContext *context) = 0;

    virtual std::any visitTopClass(GlyphParser::TopClassContext *context) = 0;

    virtual std::any visitTopFn(GlyphParser::TopFnContext *context) = 0;

    virtual std::any visitConstDecl(GlyphParser::ConstDeclContext *context) = 0;

    virtual std::any visitStructDecl(GlyphParser::StructDeclContext *context) = 0;

    virtual std::any visitInterfaceDecl(GlyphParser::InterfaceDeclContext *context) = 0;

    virtual std::any visitClassDecl(GlyphParser::ClassDeclContext *context) = 0;

    virtual std::any visitFieldDecl(GlyphParser::FieldDeclContext *context) = 0;

    virtual std::any visitSigDecl(GlyphParser::SigDeclContext *context) = 0;

    virtual std::any visitMemberField(GlyphParser::MemberFieldContext *context) = 0;

    virtual std::any visitMemberFn(GlyphParser::MemberFnContext *context) = 0;

    virtual std::any visitAttrDecl(GlyphParser::AttrDeclContext *context) = 0;

    virtual std::any visitParamList(GlyphParser::ParamListContext *context) = 0;

    virtual std::any visitParam(GlyphParser::ParamContext *context) = 0;

    virtual std::any visitFnDecl(GlyphParser::FnDeclContext *context) = 0;

    virtual std::any visitBuiltinType(GlyphParser::BuiltinTypeContext *context) = 0;

    virtual std::any visitListType(GlyphParser::ListTypeContext *context) = 0;

    virtual std::any visitOptionType(GlyphParser::OptionTypeContext *context) = 0;

    virtual std::any visitResultType(GlyphParser::ResultTypeContext *context) = 0;

    virtual std::any visitFnType(GlyphParser::FnTypeContext *context) = 0;

    virtual std::any visitNamedType(GlyphParser::NamedTypeContext *context) = 0;

    virtual std::any visitTypeName(GlyphParser::TypeNameContext *context) = 0;

    virtual std::any visitQualifiedName(GlyphParser::QualifiedNameContext *context) = 0;

    virtual std::any visitGenericParams(GlyphParser::GenericParamsContext *context) = 0;

    virtual std::any visitGenericArgs(GlyphParser::GenericArgsContext *context) = 0;

    virtual std::any visitTypeList(GlyphParser::TypeListContext *context) = 0;

    virtual std::any visitBlock(GlyphParser::BlockContext *context) = 0;

    virtual std::any visitStmtConst(GlyphParser::StmtConstContext *context) = 0;

    virtual std::any visitStmtLet(GlyphParser::StmtLetContext *context) = 0;

    virtual std::any visitStmtVar(GlyphParser::StmtVarContext *context) = 0;

    virtual std::any visitStmtExpr(GlyphParser::StmtExprContext *context) = 0;

    virtual std::any visitStmtBlock(GlyphParser::StmtBlockContext *context) = 0;

    virtual std::any visitStmtIf(GlyphParser::StmtIfContext *context) = 0;

    virtual std::any visitStmtWhile(GlyphParser::StmtWhileContext *context) = 0;

    virtual std::any visitStmtFor(GlyphParser::StmtForContext *context) = 0;

    virtual std::any visitStmtMatch(GlyphParser::StmtMatchContext *context) = 0;

    virtual std::any visitStmtReturn(GlyphParser::StmtReturnContext *context) = 0;

    virtual std::any visitConstStmt(GlyphParser::ConstStmtContext *context) = 0;

    virtual std::any visitLetStmt(GlyphParser::LetStmtContext *context) = 0;

    virtual std::any visitVarStmt(GlyphParser::VarStmtContext *context) = 0;

    virtual std::any visitExprStmt(GlyphParser::ExprStmtContext *context) = 0;

    virtual std::any visitIfStmt(GlyphParser::IfStmtContext *context) = 0;

    virtual std::any visitWhileStmt(GlyphParser::WhileStmtContext *context) = 0;

    virtual std::any visitForEach(GlyphParser::ForEachContext *context) = 0;

    virtual std::any visitNumericFor(GlyphParser::NumericForContext *context) = 0;

    virtual std::any visitForInit(GlyphParser::ForInitContext *context) = 0;

    virtual std::any visitForUpdate(GlyphParser::ForUpdateContext *context) = 0;

    virtual std::any visitMatchStmt(GlyphParser::MatchStmtContext *context) = 0;

    virtual std::any visitMatchArm(GlyphParser::MatchArmContext *context) = 0;

    virtual std::any visitWildcardPat(GlyphParser::WildcardPatContext *context) = 0;

    virtual std::any visitSomePat(GlyphParser::SomePatContext *context) = 0;

    virtual std::any visitNonePat(GlyphParser::NonePatContext *context) = 0;

    virtual std::any visitOkPat(GlyphParser::OkPatContext *context) = 0;

    virtual std::any visitErrPat(GlyphParser::ErrPatContext *context) = 0;

    virtual std::any visitIntPat(GlyphParser::IntPatContext *context) = 0;

    virtual std::any visitStrPat(GlyphParser::StrPatContext *context) = 0;

    virtual std::any visitReturnStmt(GlyphParser::ReturnStmtContext *context) = 0;

    virtual std::any visitExpr(GlyphParser::ExprContext *context) = 0;

    virtual std::any visitCompoundAssign(GlyphParser::CompoundAssignContext *context) = 0;

    virtual std::any visitSimpleAssign(GlyphParser::SimpleAssignContext *context) = 0;

    virtual std::any visitPlainExpr(GlyphParser::PlainExprContext *context) = 0;

    virtual std::any visitTernaryExpr(GlyphParser::TernaryExprContext *context) = 0;

    virtual std::any visitOrExpr(GlyphParser::OrExprContext *context) = 0;

    virtual std::any visitAndExpr(GlyphParser::AndExprContext *context) = 0;

    virtual std::any visitEqualityExpr(GlyphParser::EqualityExprContext *context) = 0;

    virtual std::any visitComparisonExpr(GlyphParser::ComparisonExprContext *context) = 0;

    virtual std::any visitAdditiveExpr(GlyphParser::AdditiveExprContext *context) = 0;

    virtual std::any visitMultiplicativeExpr(GlyphParser::MultiplicativeExprContext *context) = 0;

    virtual std::any visitAsCast(GlyphParser::AsCastContext *context) = 0;

    virtual std::any visitTryExpr(GlyphParser::TryExprContext *context) = 0;

    virtual std::any visitCastOperand(GlyphParser::CastOperandContext *context) = 0;

    virtual std::any visitPrimitiveKw(GlyphParser::PrimitiveKwContext *context) = 0;

    virtual std::any visitUnaryOp(GlyphParser::UnaryOpContext *context) = 0;

    virtual std::any visitUnaryOperand(GlyphParser::UnaryOperandContext *context) = 0;

    virtual std::any visitPostfixExpr(GlyphParser::PostfixExprContext *context) = 0;

    virtual std::any visitFieldAccess(GlyphParser::FieldAccessContext *context) = 0;

    virtual std::any visitStaticAccess(GlyphParser::StaticAccessContext *context) = 0;

    virtual std::any visitIndex(GlyphParser::IndexContext *context) = 0;

    virtual std::any visitCall(GlyphParser::CallContext *context) = 0;

    virtual std::any visitPropagate(GlyphParser::PropagateContext *context) = 0;

    virtual std::any visitIntLit(GlyphParser::IntLitContext *context) = 0;

    virtual std::any visitDoubleLit(GlyphParser::DoubleLitContext *context) = 0;

    virtual std::any visitTrueLit(GlyphParser::TrueLitContext *context) = 0;

    virtual std::any visitFalseLit(GlyphParser::FalseLitContext *context) = 0;

    virtual std::any visitNoneLit(GlyphParser::NoneLitContext *context) = 0;

    virtual std::any visitSomeCtor(GlyphParser::SomeCtorContext *context) = 0;

    virtual std::any visitOkCtor(GlyphParser::OkCtorContext *context) = 0;

    virtual std::any visitErrCtor(GlyphParser::ErrCtorContext *context) = 0;

    virtual std::any visitStringLit(GlyphParser::StringLitContext *context) = 0;

    virtual std::any visitListLit(GlyphParser::ListLitContext *context) = 0;

    virtual std::any visitStructLitNamed(GlyphParser::StructLitNamedContext *context) = 0;

    virtual std::any visitStructLitInferred(GlyphParser::StructLitInferredContext *context) = 0;

    virtual std::any visitParenExpr(GlyphParser::ParenExprContext *context) = 0;

    virtual std::any visitLambdaExpr(GlyphParser::LambdaExprContext *context) = 0;

    virtual std::any visitLambdaExprShort(GlyphParser::LambdaExprShortContext *context) = 0;

    virtual std::any visitIdentifier(GlyphParser::IdentifierContext *context) = 0;

    virtual std::any visitFieldInit(GlyphParser::FieldInitContext *context) = 0;

    virtual std::any visitLambdaParams(GlyphParser::LambdaParamsContext *context) = 0;

    virtual std::any visitArgList(GlyphParser::ArgListContext *context) = 0;


};

