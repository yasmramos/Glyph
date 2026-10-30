
// Generated from /workspace/grammars/Glyph.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  GlyphParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, DOUBLE_LITERAL = 35, INT_LITERAL = 36, STRING = 37, 
    ID = 38, PLUS_ASSIGN = 39, MINUS_ASSIGN = 40, STAR_ASSIGN = 41, SLASH_ASSIGN = 42, 
    PERCENT_ASSIGN = 43, EQ = 44, NE = 45, LE = 46, GE = 47, LT = 48, GT = 49, 
    AND_AND = 50, OR_OR = 51, NOT_OP = 52, ASSIGN = 53, DOT_DOT = 54, PLUS = 55, 
    MINUS = 56, STAR = 57, SLASH = 58, PERCENT = 59, LPAREN = 60, RPAREN = 61, 
    LBRACKET = 62, RBRACKET = 63, LBRACE = 64, RBRACE = 65, COLONCOLON = 66, 
    SEMICOLON = 67, COMMA = 68, DOT = 69, COLON = 70, QUEST = 71, AT = 72, 
    UNDERSCORE = 73, LINE_COMMENT = 74, BLOCK_COMMENT = 75, WS = 76
  };

  enum {
    RuleProgram = 0, RuleModuleDecl = 1, RuleImportDecl = 2, RuleTopLevelDecl = 3, 
    RuleConstDecl = 4, RuleStructDecl = 5, RuleInterfaceDecl = 6, RuleClassDecl = 7, 
    RuleFieldDecl = 8, RuleSigDecl = 9, RuleMemberDecl = 10, RuleAttrDecl = 11, 
    RuleParamList = 12, RuleParam = 13, RuleFnDecl = 14, RuleType = 15, 
    RuleTypeName = 16, RuleQualifiedName = 17, RuleGenericParams = 18, RuleGenericArgs = 19, 
    RuleTypeList = 20, RuleBlock = 21, RuleStmt = 22, RuleConstStmt = 23, 
    RuleLetStmt = 24, RuleVarStmt = 25, RuleExprStmt = 26, RuleIfStmt = 27, 
    RuleWhileStmt = 28, RuleForStmt = 29, RuleForInit = 30, RuleForUpdate = 31, 
    RuleMatchStmt = 32, RuleMatchArm = 33, RulePattern = 34, RuleReturnStmt = 35, 
    RuleExpr = 36, RuleExprOrAssign = 37, RuleTernaryExpr = 38, RuleOrExpr = 39, 
    RuleAndExpr = 40, RuleEqualityExpr = 41, RuleComparisonExpr = 42, RuleAdditiveExpr = 43, 
    RuleMultiplicativeExpr = 44, RuleCastExpr = 45, RulePrimitiveKw = 46, 
    RuleUnaryExpr = 47, RulePostfixExpr = 48, RulePostfixOp = 49, RulePrimaryExpr = 50, 
    RuleFieldInit = 51, RuleLambdaParams = 52, RuleArgList = 53
  };

  explicit GlyphParser(antlr4::TokenStream *input);

  GlyphParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~GlyphParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class ModuleDeclContext;
  class ImportDeclContext;
  class TopLevelDeclContext;
  class ConstDeclContext;
  class StructDeclContext;
  class InterfaceDeclContext;
  class ClassDeclContext;
  class FieldDeclContext;
  class SigDeclContext;
  class MemberDeclContext;
  class AttrDeclContext;
  class ParamListContext;
  class ParamContext;
  class FnDeclContext;
  class TypeContext;
  class TypeNameContext;
  class QualifiedNameContext;
  class GenericParamsContext;
  class GenericArgsContext;
  class TypeListContext;
  class BlockContext;
  class StmtContext;
  class ConstStmtContext;
  class LetStmtContext;
  class VarStmtContext;
  class ExprStmtContext;
  class IfStmtContext;
  class WhileStmtContext;
  class ForStmtContext;
  class ForInitContext;
  class ForUpdateContext;
  class MatchStmtContext;
  class MatchArmContext;
  class PatternContext;
  class ReturnStmtContext;
  class ExprContext;
  class ExprOrAssignContext;
  class TernaryExprContext;
  class OrExprContext;
  class AndExprContext;
  class EqualityExprContext;
  class ComparisonExprContext;
  class AdditiveExprContext;
  class MultiplicativeExprContext;
  class CastExprContext;
  class PrimitiveKwContext;
  class UnaryExprContext;
  class PostfixExprContext;
  class PostfixOpContext;
  class PrimaryExprContext;
  class FieldInitContext;
  class LambdaParamsContext;
  class ArgListContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    ModuleDeclContext *moduleDecl();
    std::vector<ImportDeclContext *> importDecl();
    ImportDeclContext* importDecl(size_t i);
    std::vector<TopLevelDeclContext *> topLevelDecl();
    TopLevelDeclContext* topLevelDecl(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  ModuleDeclContext : public antlr4::ParserRuleContext {
  public:
    ModuleDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QualifiedNameContext *qualifiedName();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModuleDeclContext* moduleDecl();

  class  ImportDeclContext : public antlr4::ParserRuleContext {
  public:
    ImportDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QualifiedNameContext *qualifiedName();
    antlr4::tree::TerminalNode *ID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImportDeclContext* importDecl();

  class  TopLevelDeclContext : public antlr4::ParserRuleContext {
  public:
    TopLevelDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TopLevelDeclContext() = default;
    void copyFrom(TopLevelDeclContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  TopStructContext : public TopLevelDeclContext {
  public:
    TopStructContext(TopLevelDeclContext *ctx);

    StructDeclContext *structDecl();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TopClassContext : public TopLevelDeclContext {
  public:
    TopClassContext(TopLevelDeclContext *ctx);

    ClassDeclContext *classDecl();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TopConstContext : public TopLevelDeclContext {
  public:
    TopConstContext(TopLevelDeclContext *ctx);

    ConstDeclContext *constDecl();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TopInterfaceContext : public TopLevelDeclContext {
  public:
    TopInterfaceContext(TopLevelDeclContext *ctx);

    InterfaceDeclContext *interfaceDecl();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TopFnContext : public TopLevelDeclContext {
  public:
    TopFnContext(TopLevelDeclContext *ctx);

    FnDeclContext *fnDecl();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TopLevelDeclContext* topLevelDecl();

  class  ConstDeclContext : public antlr4::ParserRuleContext {
  public:
    ConstDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstDeclContext* constDecl();

  class  StructDeclContext : public antlr4::ParserRuleContext {
  public:
    StructDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    GenericParamsContext *genericParams();
    std::vector<FieldDeclContext *> fieldDecl();
    FieldDeclContext* fieldDecl(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructDeclContext* structDecl();

  class  InterfaceDeclContext : public antlr4::ParserRuleContext {
  public:
    InterfaceDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<SigDeclContext *> sigDecl();
    SigDeclContext* sigDecl(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InterfaceDeclContext* interfaceDecl();

  class  ClassDeclContext : public antlr4::ParserRuleContext {
  public:
    ClassDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    GenericParamsContext *genericParams();
    TypeNameContext *typeName();
    TypeListContext *typeList();
    std::vector<MemberDeclContext *> memberDecl();
    MemberDeclContext* memberDecl(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassDeclContext* classDecl();

  class  FieldDeclContext : public antlr4::ParserRuleContext {
  public:
    FieldDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldDeclContext* fieldDecl();

  class  SigDeclContext : public antlr4::ParserRuleContext {
  public:
    SigDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ParamListContext *paramList();
    TypeContext *type();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SigDeclContext* sigDecl();

  class  MemberDeclContext : public antlr4::ParserRuleContext {
  public:
    MemberDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    MemberDeclContext() = default;
    void copyFrom(MemberDeclContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MemberFieldContext : public MemberDeclContext {
  public:
    MemberFieldContext(MemberDeclContext *ctx);

    FieldDeclContext *fieldDecl();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MemberFnContext : public MemberDeclContext {
  public:
    MemberFnContext(MemberDeclContext *ctx);

    FnDeclContext *fnDecl();
    antlr4::tree::TerminalNode *ID();
    AttrDeclContext *attrDecl();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  MemberDeclContext* memberDecl();

  class  AttrDeclContext : public antlr4::ParserRuleContext {
  public:
    AttrDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AT();
    antlr4::tree::TerminalNode *ID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AttrDeclContext* attrDecl();

  class  ParamListContext : public antlr4::ParserRuleContext {
  public:
    ParamListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParamContext *> param();
    ParamContext* param(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamListContext* paramList();

  class  ParamContext : public antlr4::ParserRuleContext {
  public:
    ParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamContext* param();

  class  FnDeclContext : public antlr4::ParserRuleContext {
  public:
    FnDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    BlockContext *block();
    GenericParamsContext *genericParams();
    ParamListContext *paramList();
    TypeContext *type();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FnDeclContext* fnDecl();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypeContext() = default;
    void copyFrom(TypeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  BuiltinTypeContext : public TypeContext {
  public:
    BuiltinTypeContext(TypeContext *ctx);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NamedTypeContext : public TypeContext {
  public:
    NamedTypeContext(TypeContext *ctx);

    TypeNameContext *typeName();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ListTypeContext : public TypeContext {
  public:
    ListTypeContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *LBRACKET();
    TypeContext *type();
    antlr4::tree::TerminalNode *RBRACKET();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ResultTypeContext : public TypeContext {
  public:
    ResultTypeContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *NOT_OP();
    TypeContext *type();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FnTypeContext : public TypeContext {
  public:
    FnTypeContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    TypeListContext *typeList();
    TypeContext *type();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OptionTypeContext : public TypeContext {
  public:
    OptionTypeContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *QUEST();
    TypeContext *type();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeContext* type();

  class  TypeNameContext : public antlr4::ParserRuleContext {
  public:
    TypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    QualifiedNameContext *qualifiedName();
    GenericArgsContext *genericArgs();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeNameContext* typeName();

  class  QualifiedNameContext : public antlr4::ParserRuleContext {
  public:
    QualifiedNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QualifiedNameContext* qualifiedName();

  class  GenericParamsContext : public antlr4::ParserRuleContext {
  public:
    GenericParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *GT();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GenericParamsContext* genericParams();

  class  GenericArgsContext : public antlr4::ParserRuleContext {
  public:
    GenericArgsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    antlr4::tree::TerminalNode *GT();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GenericArgsContext* genericArgs();

  class  TypeListContext : public antlr4::ParserRuleContext {
  public:
    TypeListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeListContext* typeList();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StmtContext() = default;
    void copyFrom(StmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StmtReturnContext : public StmtContext {
  public:
    StmtReturnContext(StmtContext *ctx);

    ReturnStmtContext *returnStmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StmtMatchContext : public StmtContext {
  public:
    StmtMatchContext(StmtContext *ctx);

    MatchStmtContext *matchStmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StmtVarContext : public StmtContext {
  public:
    StmtVarContext(StmtContext *ctx);

    VarStmtContext *varStmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StmtBlockContext : public StmtContext {
  public:
    StmtBlockContext(StmtContext *ctx);

    BlockContext *block();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StmtExprContext : public StmtContext {
  public:
    StmtExprContext(StmtContext *ctx);

    ExprStmtContext *exprStmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StmtWhileContext : public StmtContext {
  public:
    StmtWhileContext(StmtContext *ctx);

    WhileStmtContext *whileStmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StmtForContext : public StmtContext {
  public:
    StmtForContext(StmtContext *ctx);

    ForStmtContext *forStmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StmtIfContext : public StmtContext {
  public:
    StmtIfContext(StmtContext *ctx);

    IfStmtContext *ifStmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StmtConstContext : public StmtContext {
  public:
    StmtConstContext(StmtContext *ctx);

    ConstStmtContext *constStmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StmtLetContext : public StmtContext {
  public:
    StmtLetContext(StmtContext *ctx);

    LetStmtContext *letStmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StmtContext* stmt();

  class  ConstStmtContext : public antlr4::ParserRuleContext {
  public:
    ConstStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstStmtContext* constStmt();

  class  LetStmtContext : public antlr4::ParserRuleContext {
  public:
    LetStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LetStmtContext* letStmt();

  class  VarStmtContext : public antlr4::ParserRuleContext {
  public:
    VarStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *COLON();
    TypeContext *type();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarStmtContext* varStmt();

  class  ExprStmtContext : public antlr4::ParserRuleContext {
  public:
    ExprStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprOrAssignContext *exprOrAssign();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprStmtContext* exprStmt();

  class  IfStmtContext : public antlr4::ParserRuleContext {
  public:
    IfStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    IfStmtContext *ifStmt();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStmtContext* ifStmt();

  class  WhileStmtContext : public antlr4::ParserRuleContext {
  public:
    WhileStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStmtContext* whileStmt();

  class  ForStmtContext : public antlr4::ParserRuleContext {
  public:
    ForStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ForStmtContext() = default;
    void copyFrom(ForStmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NumericForContext : public ForStmtContext {
  public:
    NumericForContext(ForStmtContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    BlockContext *block();
    ForInitContext *forInit();
    ExprContext *expr();
    ForUpdateContext *forUpdate();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ForEachContext : public ForStmtContext {
  public:
    ForEachContext(ForStmtContext *ctx);

    antlr4::tree::TerminalNode *ID();
    ExprContext *expr();
    BlockContext *block();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ForStmtContext* forStmt();

  class  ForInitContext : public antlr4::ParserRuleContext {
  public:
    ForInitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LetStmtContext *letStmt();
    VarStmtContext *varStmt();
    ConstStmtContext *constStmt();
    ExprOrAssignContext *exprOrAssign();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForInitContext* forInit();

  class  ForUpdateContext : public antlr4::ParserRuleContext {
  public:
    ForUpdateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprOrAssignContext *exprOrAssign();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForUpdateContext* forUpdate();

  class  MatchStmtContext : public antlr4::ParserRuleContext {
  public:
    MatchStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();
    antlr4::tree::TerminalNode *LBRACE();
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<MatchArmContext *> matchArm();
    MatchArmContext* matchArm(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MatchStmtContext* matchStmt();

  class  MatchArmContext : public antlr4::ParserRuleContext {
  public:
    MatchArmContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PatternContext *pattern();
    BlockContext *block();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *COMMA();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MatchArmContext* matchArm();

  class  PatternContext : public antlr4::ParserRuleContext {
  public:
    PatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PatternContext() = default;
    void copyFrom(PatternContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SomePatContext : public PatternContext {
  public:
    SomePatContext(PatternContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *RPAREN();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntPatContext : public PatternContext {
  public:
    IntPatContext(PatternContext *ctx);

    antlr4::tree::TerminalNode *INT_LITERAL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NonePatContext : public PatternContext {
  public:
    NonePatContext(PatternContext *ctx);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ErrPatContext : public PatternContext {
  public:
    ErrPatContext(PatternContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *RPAREN();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WildcardPatContext : public PatternContext {
  public:
    WildcardPatContext(PatternContext *ctx);

    antlr4::tree::TerminalNode *UNDERSCORE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StrPatContext : public PatternContext {
  public:
    StrPatContext(PatternContext *ctx);

    antlr4::tree::TerminalNode *STRING();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OkPatContext : public PatternContext {
  public:
    OkPatContext(PatternContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *RPAREN();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PatternContext* pattern();

  class  ReturnStmtContext : public antlr4::ParserRuleContext {
  public:
    ReturnStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprContext *expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnStmtContext* returnStmt();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TernaryExprContext *ternaryExpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();

  class  ExprOrAssignContext : public antlr4::ParserRuleContext {
  public:
    ExprOrAssignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprOrAssignContext() = default;
    void copyFrom(ExprOrAssignContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SimpleAssignContext : public ExprOrAssignContext {
  public:
    SimpleAssignContext(ExprOrAssignContext *ctx);

    UnaryExprContext *unaryExpr();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PlainExprContext : public ExprOrAssignContext {
  public:
    PlainExprContext(ExprOrAssignContext *ctx);

    ExprContext *expr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CompoundAssignContext : public ExprOrAssignContext {
  public:
    CompoundAssignContext(ExprOrAssignContext *ctx);

    antlr4::Token *op = nullptr;
    UnaryExprContext *unaryExpr();
    ExprContext *expr();
    antlr4::tree::TerminalNode *PLUS_ASSIGN();
    antlr4::tree::TerminalNode *MINUS_ASSIGN();
    antlr4::tree::TerminalNode *STAR_ASSIGN();
    antlr4::tree::TerminalNode *SLASH_ASSIGN();
    antlr4::tree::TerminalNode *PERCENT_ASSIGN();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprOrAssignContext* exprOrAssign();

  class  TernaryExprContext : public antlr4::ParserRuleContext {
  public:
    TernaryExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OrExprContext *> orExpr();
    OrExprContext* orExpr(size_t i);
    antlr4::tree::TerminalNode *QUEST();
    antlr4::tree::TerminalNode *COLON();
    TernaryExprContext *ternaryExpr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TernaryExprContext* ternaryExpr();

  class  OrExprContext : public antlr4::ParserRuleContext {
  public:
    OrExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AndExprContext *> andExpr();
    AndExprContext* andExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OR_OR();
    antlr4::tree::TerminalNode* OR_OR(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OrExprContext* orExpr();

  class  AndExprContext : public antlr4::ParserRuleContext {
  public:
    AndExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EqualityExprContext *> equalityExpr();
    EqualityExprContext* equalityExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND_AND();
    antlr4::tree::TerminalNode* AND_AND(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AndExprContext* andExpr();

  class  EqualityExprContext : public antlr4::ParserRuleContext {
  public:
    EqualityExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ComparisonExprContext *> comparisonExpr();
    ComparisonExprContext* comparisonExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EQ();
    antlr4::tree::TerminalNode* EQ(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NE();
    antlr4::tree::TerminalNode* NE(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EqualityExprContext* equalityExpr();

  class  ComparisonExprContext : public antlr4::ParserRuleContext {
  public:
    ComparisonExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AdditiveExprContext *> additiveExpr();
    AdditiveExprContext* additiveExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LT();
    antlr4::tree::TerminalNode* LT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LE();
    antlr4::tree::TerminalNode* LE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GT();
    antlr4::tree::TerminalNode* GT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GE();
    antlr4::tree::TerminalNode* GE(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ComparisonExprContext* comparisonExpr();

  class  AdditiveExprContext : public antlr4::ParserRuleContext {
  public:
    AdditiveExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<MultiplicativeExprContext *> multiplicativeExpr();
    MultiplicativeExprContext* multiplicativeExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AdditiveExprContext* additiveExpr();

  class  MultiplicativeExprContext : public antlr4::ParserRuleContext {
  public:
    MultiplicativeExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<CastExprContext *> castExpr();
    CastExprContext* castExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> STAR();
    antlr4::tree::TerminalNode* STAR(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SLASH();
    antlr4::tree::TerminalNode* SLASH(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PERCENT();
    antlr4::tree::TerminalNode* PERCENT(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MultiplicativeExprContext* multiplicativeExpr();

  class  CastExprContext : public antlr4::ParserRuleContext {
  public:
    CastExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    CastExprContext() = default;
    void copyFrom(CastExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AsCastContext : public CastExprContext {
  public:
    AsCastContext(CastExprContext *ctx);

    UnaryExprContext *unaryExpr();
    PrimitiveKwContext *primitiveKw();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TryExprContext : public CastExprContext {
  public:
    TryExprContext(CastExprContext *ctx);

    UnaryExprContext *unaryExpr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CastOperandContext : public CastExprContext {
  public:
    CastOperandContext(CastExprContext *ctx);

    UnaryExprContext *unaryExpr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  CastExprContext* castExpr();

  class  PrimitiveKwContext : public antlr4::ParserRuleContext {
  public:
    PrimitiveKwContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimitiveKwContext* primitiveKw();

  class  UnaryExprContext : public antlr4::ParserRuleContext {
  public:
    UnaryExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    UnaryExprContext() = default;
    void copyFrom(UnaryExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UnaryOperandContext : public UnaryExprContext {
  public:
    UnaryOperandContext(UnaryExprContext *ctx);

    PostfixExprContext *postfixExpr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryOpContext : public UnaryExprContext {
  public:
    UnaryOpContext(UnaryExprContext *ctx);

    UnaryExprContext *unaryExpr();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *NOT_OP();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  UnaryExprContext* unaryExpr();

  class  PostfixExprContext : public antlr4::ParserRuleContext {
  public:
    PostfixExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimaryExprContext *primaryExpr();
    std::vector<PostfixOpContext *> postfixOp();
    PostfixOpContext* postfixOp(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PostfixExprContext* postfixExpr();

  class  PostfixOpContext : public antlr4::ParserRuleContext {
  public:
    PostfixOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PostfixOpContext() = default;
    void copyFrom(PostfixOpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CallContext : public PostfixOpContext {
  public:
    CallContext(PostfixOpContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    ArgListContext *argList();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StaticAccessContext : public PostfixOpContext {
  public:
    StaticAccessContext(PostfixOpContext *ctx);

    antlr4::tree::TerminalNode *COLONCOLON();
    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IndexContext : public PostfixOpContext {
  public:
    IndexContext(PostfixOpContext *ctx);

    antlr4::tree::TerminalNode *LBRACKET();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RBRACKET();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PropagateContext : public PostfixOpContext {
  public:
    PropagateContext(PostfixOpContext *ctx);

    antlr4::tree::TerminalNode *QUEST();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FieldAccessContext : public PostfixOpContext {
  public:
    FieldAccessContext(PostfixOpContext *ctx);

    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PostfixOpContext* postfixOp();

  class  PrimaryExprContext : public antlr4::ParserRuleContext {
  public:
    PrimaryExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PrimaryExprContext() = default;
    void copyFrom(PrimaryExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StructLitInferredContext : public PrimaryExprContext {
  public:
    StructLitInferredContext(PrimaryExprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LBRACE();
    std::vector<FieldInitContext *> fieldInit();
    FieldInitContext* fieldInit(size_t i);
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DoubleLitContext : public PrimaryExprContext {
  public:
    DoubleLitContext(PrimaryExprContext *ctx);

    antlr4::tree::TerminalNode *DOUBLE_LITERAL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OkCtorContext : public PrimaryExprContext {
  public:
    OkCtorContext(PrimaryExprContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAREN();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ErrCtorContext : public PrimaryExprContext {
  public:
    ErrCtorContext(PrimaryExprContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAREN();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LambdaExprShortContext : public PrimaryExprContext {
  public:
    LambdaExprShortContext(PrimaryExprContext *ctx);

    LambdaParamsContext *lambdaParams();
    ExprContext *expr();
    TypeContext *type();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LambdaExprContext : public PrimaryExprContext {
  public:
    LambdaExprContext(PrimaryExprContext *ctx);

    LambdaParamsContext *lambdaParams();
    BlockContext *block();
    TypeContext *type();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FalseLitContext : public PrimaryExprContext {
  public:
    FalseLitContext(PrimaryExprContext *ctx);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ListLitContext : public PrimaryExprContext {
  public:
    ListLitContext(PrimaryExprContext *ctx);

    antlr4::tree::TerminalNode *LBRACKET();
    antlr4::tree::TerminalNode *RBRACKET();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SomeCtorContext : public PrimaryExprContext {
  public:
    SomeCtorContext(PrimaryExprContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAREN();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringLitContext : public PrimaryExprContext {
  public:
    StringLitContext(PrimaryExprContext *ctx);

    std::vector<antlr4::tree::TerminalNode *> STRING();
    antlr4::tree::TerminalNode* STRING(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NoneLitContext : public PrimaryExprContext {
  public:
    NoneLitContext(PrimaryExprContext *ctx);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StructLitNamedContext : public PrimaryExprContext {
  public:
    StructLitNamedContext(PrimaryExprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *LBRACE();
    std::vector<FieldInitContext *> fieldInit();
    FieldInitContext* fieldInit(size_t i);
    antlr4::tree::TerminalNode *RBRACE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdentifierContext : public PrimaryExprContext {
  public:
    IdentifierContext(PrimaryExprContext *ctx);

    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TrueLitContext : public PrimaryExprContext {
  public:
    TrueLitContext(PrimaryExprContext *ctx);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenExprContext : public PrimaryExprContext {
  public:
    ParenExprContext(PrimaryExprContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RPAREN();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntLitContext : public PrimaryExprContext {
  public:
    IntLitContext(PrimaryExprContext *ctx);

    antlr4::tree::TerminalNode *INT_LITERAL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PrimaryExprContext* primaryExpr();

  class  FieldInitContext : public antlr4::ParserRuleContext {
  public:
    FieldInitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *COLON();
    ExprContext *expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FieldInitContext* fieldInit();

  class  LambdaParamsContext : public antlr4::ParserRuleContext {
  public:
    LambdaParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LambdaParamsContext* lambdaParams();

  class  ArgListContext : public antlr4::ParserRuleContext {
  public:
    ArgListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgListContext* argList();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

