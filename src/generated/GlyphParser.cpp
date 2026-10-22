
// Generated from /workspace/grammars/Glyph.g4 by ANTLR 4.13.1


#include "GlyphVisitor.h"

#include "GlyphParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct GlyphParserStaticData final {
  GlyphParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  GlyphParserStaticData(const GlyphParserStaticData&) = delete;
  GlyphParserStaticData(GlyphParserStaticData&&) = delete;
  GlyphParserStaticData& operator=(const GlyphParserStaticData&) = delete;
  GlyphParserStaticData& operator=(GlyphParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag glyphParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
GlyphParserStaticData *glyphParserStaticData = nullptr;

void glyphParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (glyphParserStaticData != nullptr) {
    return;
  }
#else
  assert(glyphParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<GlyphParserStaticData>(
    std::vector<std::string>{
      "program", "statement", "printStmt", "assignStmt", "exprStmt", "expr"
    },
    std::vector<std::string>{
      "", "'print'", "'local'", "'and'", "'or'", "'not'", "", "", "", "'=='", 
      "'~='", "'<='", "'>='", "'<'", "'>'", "'='", "'+'", "'-'", "'*'", 
      "'/'", "'%'", "'^'", "'('", "')'"
    },
    std::vector<std::string>{
      "", "PRINT", "LOCAL", "AND", "OR", "NOT", "NUMBER", "STRING", "ID", 
      "EQ", "NE", "LE", "GE", "LT", "GT", "ASSIGN", "PLUS", "MINUS", "STAR", 
      "SLASH", "PERCENT", "CARET", "LPAREN", "RPAREN", "LINE_COMMENT", "BLOCK_COMMENT", 
      "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,26,78,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,5,0,14,
  	8,0,10,0,12,0,17,9,0,1,0,1,0,1,1,1,1,1,1,3,1,24,8,1,1,2,1,2,1,2,1,2,1,
  	2,1,3,3,3,32,8,3,1,3,1,3,1,3,1,3,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,3,5,50,8,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,5,5,73,8,5,10,5,12,5,76,9,5,1,5,
  	0,1,10,6,0,2,4,6,8,10,0,5,2,0,5,5,17,17,1,0,9,10,1,0,11,14,1,0,16,17,
  	1,0,18,20,86,0,15,1,0,0,0,2,23,1,0,0,0,4,25,1,0,0,0,6,31,1,0,0,0,8,37,
  	1,0,0,0,10,49,1,0,0,0,12,14,3,2,1,0,13,12,1,0,0,0,14,17,1,0,0,0,15,13,
  	1,0,0,0,15,16,1,0,0,0,16,18,1,0,0,0,17,15,1,0,0,0,18,19,5,0,0,1,19,1,
  	1,0,0,0,20,24,3,4,2,0,21,24,3,6,3,0,22,24,3,8,4,0,23,20,1,0,0,0,23,21,
  	1,0,0,0,23,22,1,0,0,0,24,3,1,0,0,0,25,26,5,1,0,0,26,27,5,22,0,0,27,28,
  	3,10,5,0,28,29,5,23,0,0,29,5,1,0,0,0,30,32,5,2,0,0,31,30,1,0,0,0,31,32,
  	1,0,0,0,32,33,1,0,0,0,33,34,5,8,0,0,34,35,5,15,0,0,35,36,3,10,5,0,36,
  	7,1,0,0,0,37,38,3,10,5,0,38,9,1,0,0,0,39,40,6,5,-1,0,40,41,7,0,0,0,41,
  	50,3,10,5,5,42,50,5,6,0,0,43,50,5,7,0,0,44,50,5,8,0,0,45,46,5,22,0,0,
  	46,47,3,10,5,0,47,48,5,23,0,0,48,50,1,0,0,0,49,39,1,0,0,0,49,42,1,0,0,
  	0,49,43,1,0,0,0,49,44,1,0,0,0,49,45,1,0,0,0,50,74,1,0,0,0,51,52,10,12,
  	0,0,52,53,5,4,0,0,53,73,3,10,5,13,54,55,10,11,0,0,55,56,5,3,0,0,56,73,
  	3,10,5,12,57,58,10,10,0,0,58,59,7,1,0,0,59,73,3,10,5,11,60,61,10,9,0,
  	0,61,62,7,2,0,0,62,73,3,10,5,10,63,64,10,8,0,0,64,65,7,3,0,0,65,73,3,
  	10,5,9,66,67,10,7,0,0,67,68,7,4,0,0,68,73,3,10,5,8,69,70,10,6,0,0,70,
  	71,5,21,0,0,71,73,3,10,5,7,72,51,1,0,0,0,72,54,1,0,0,0,72,57,1,0,0,0,
  	72,60,1,0,0,0,72,63,1,0,0,0,72,66,1,0,0,0,72,69,1,0,0,0,73,76,1,0,0,0,
  	74,72,1,0,0,0,74,75,1,0,0,0,75,11,1,0,0,0,76,74,1,0,0,0,6,15,23,31,49,
  	72,74
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  glyphParserStaticData = staticData.release();
}

}

GlyphParser::GlyphParser(TokenStream *input) : GlyphParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

GlyphParser::GlyphParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  GlyphParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *glyphParserStaticData->atn, glyphParserStaticData->decisionToDFA, glyphParserStaticData->sharedContextCache, options);
}

GlyphParser::~GlyphParser() {
  delete _interpreter;
}

const atn::ATN& GlyphParser::getATN() const {
  return *glyphParserStaticData->atn;
}

std::string GlyphParser::getGrammarFileName() const {
  return "Glyph.g4";
}

const std::vector<std::string>& GlyphParser::getRuleNames() const {
  return glyphParserStaticData->ruleNames;
}

const dfa::Vocabulary& GlyphParser::getVocabulary() const {
  return glyphParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView GlyphParser::getSerializedATN() const {
  return glyphParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

GlyphParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::ProgramContext::EOF() {
  return getToken(GlyphParser::EOF, 0);
}

std::vector<GlyphParser::StatementContext *> GlyphParser::ProgramContext::statement() {
  return getRuleContexts<GlyphParser::StatementContext>();
}

GlyphParser::StatementContext* GlyphParser::ProgramContext::statement(size_t i) {
  return getRuleContext<GlyphParser::StatementContext>(i);
}


size_t GlyphParser::ProgramContext::getRuleIndex() const {
  return GlyphParser::RuleProgram;
}


std::any GlyphParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::ProgramContext* GlyphParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, GlyphParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(15);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4325862) != 0)) {
      setState(12);
      statement();
      setState(17);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(18);
    match(GlyphParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

GlyphParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GlyphParser::StatementContext::getRuleIndex() const {
  return GlyphParser::RuleStatement;
}

void GlyphParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExpressionStatementContext ------------------------------------------------------------------

GlyphParser::ExprStmtContext* GlyphParser::ExpressionStatementContext::exprStmt() {
  return getRuleContext<GlyphParser::ExprStmtContext>(0);
}

GlyphParser::ExpressionStatementContext::ExpressionStatementContext(StatementContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::ExpressionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitExpressionStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrintStatementContext ------------------------------------------------------------------

GlyphParser::PrintStmtContext* GlyphParser::PrintStatementContext::printStmt() {
  return getRuleContext<GlyphParser::PrintStmtContext>(0);
}

GlyphParser::PrintStatementContext::PrintStatementContext(StatementContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::PrintStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitPrintStatement(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignStatementContext ------------------------------------------------------------------

GlyphParser::AssignStmtContext* GlyphParser::AssignStatementContext::assignStmt() {
  return getRuleContext<GlyphParser::AssignStmtContext>(0);
}

GlyphParser::AssignStatementContext::AssignStatementContext(StatementContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::AssignStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitAssignStatement(this);
  else
    return visitor->visitChildren(this);
}
GlyphParser::StatementContext* GlyphParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, GlyphParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(23);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<GlyphParser::PrintStatementContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(20);
      printStmt();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<GlyphParser::AssignStatementContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(21);
      assignStmt();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<GlyphParser::ExpressionStatementContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(22);
      exprStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintStmtContext ------------------------------------------------------------------

GlyphParser::PrintStmtContext::PrintStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::PrintStmtContext::PRINT() {
  return getToken(GlyphParser::PRINT, 0);
}

tree::TerminalNode* GlyphParser::PrintStmtContext::LPAREN() {
  return getToken(GlyphParser::LPAREN, 0);
}

GlyphParser::ExprContext* GlyphParser::PrintStmtContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

tree::TerminalNode* GlyphParser::PrintStmtContext::RPAREN() {
  return getToken(GlyphParser::RPAREN, 0);
}


size_t GlyphParser::PrintStmtContext::getRuleIndex() const {
  return GlyphParser::RulePrintStmt;
}


std::any GlyphParser::PrintStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitPrintStmt(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::PrintStmtContext* GlyphParser::printStmt() {
  PrintStmtContext *_localctx = _tracker.createInstance<PrintStmtContext>(_ctx, getState());
  enterRule(_localctx, 4, GlyphParser::RulePrintStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(25);
    match(GlyphParser::PRINT);
    setState(26);
    match(GlyphParser::LPAREN);
    setState(27);
    expr(0);
    setState(28);
    match(GlyphParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignStmtContext ------------------------------------------------------------------

GlyphParser::AssignStmtContext::AssignStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::AssignStmtContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

tree::TerminalNode* GlyphParser::AssignStmtContext::ASSIGN() {
  return getToken(GlyphParser::ASSIGN, 0);
}

GlyphParser::ExprContext* GlyphParser::AssignStmtContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

tree::TerminalNode* GlyphParser::AssignStmtContext::LOCAL() {
  return getToken(GlyphParser::LOCAL, 0);
}


size_t GlyphParser::AssignStmtContext::getRuleIndex() const {
  return GlyphParser::RuleAssignStmt;
}


std::any GlyphParser::AssignStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitAssignStmt(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::AssignStmtContext* GlyphParser::assignStmt() {
  AssignStmtContext *_localctx = _tracker.createInstance<AssignStmtContext>(_ctx, getState());
  enterRule(_localctx, 6, GlyphParser::RuleAssignStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::LOCAL) {
      setState(30);
      match(GlyphParser::LOCAL);
    }
    setState(33);
    match(GlyphParser::ID);
    setState(34);
    match(GlyphParser::ASSIGN);
    setState(35);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprStmtContext ------------------------------------------------------------------

GlyphParser::ExprStmtContext::ExprStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GlyphParser::ExprContext* GlyphParser::ExprStmtContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}


size_t GlyphParser::ExprStmtContext::getRuleIndex() const {
  return GlyphParser::RuleExprStmt;
}


std::any GlyphParser::ExprStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitExprStmt(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::ExprStmtContext* GlyphParser::exprStmt() {
  ExprStmtContext *_localctx = _tracker.createInstance<ExprStmtContext>(_ctx, getState());
  enterRule(_localctx, 8, GlyphParser::RuleExprStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(37);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

GlyphParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GlyphParser::ExprContext::getRuleIndex() const {
  return GlyphParser::RuleExpr;
}

void GlyphParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AndExprContext ------------------------------------------------------------------

std::vector<GlyphParser::ExprContext *> GlyphParser::AndExprContext::expr() {
  return getRuleContexts<GlyphParser::ExprContext>();
}

GlyphParser::ExprContext* GlyphParser::AndExprContext::expr(size_t i) {
  return getRuleContext<GlyphParser::ExprContext>(i);
}

tree::TerminalNode* GlyphParser::AndExprContext::AND() {
  return getToken(GlyphParser::AND, 0);
}

GlyphParser::AndExprContext::AndExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::AndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitAndExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringExprContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::StringExprContext::STRING() {
  return getToken(GlyphParser::STRING, 0);
}

GlyphParser::StringExprContext::StringExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::StringExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitStringExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultiplicativeExprContext ------------------------------------------------------------------

std::vector<GlyphParser::ExprContext *> GlyphParser::MultiplicativeExprContext::expr() {
  return getRuleContexts<GlyphParser::ExprContext>();
}

GlyphParser::ExprContext* GlyphParser::MultiplicativeExprContext::expr(size_t i) {
  return getRuleContext<GlyphParser::ExprContext>(i);
}

tree::TerminalNode* GlyphParser::MultiplicativeExprContext::STAR() {
  return getToken(GlyphParser::STAR, 0);
}

tree::TerminalNode* GlyphParser::MultiplicativeExprContext::SLASH() {
  return getToken(GlyphParser::SLASH, 0);
}

tree::TerminalNode* GlyphParser::MultiplicativeExprContext::PERCENT() {
  return getToken(GlyphParser::PERCENT, 0);
}

GlyphParser::MultiplicativeExprContext::MultiplicativeExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::MultiplicativeExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PowerExprContext ------------------------------------------------------------------

std::vector<GlyphParser::ExprContext *> GlyphParser::PowerExprContext::expr() {
  return getRuleContexts<GlyphParser::ExprContext>();
}

GlyphParser::ExprContext* GlyphParser::PowerExprContext::expr(size_t i) {
  return getRuleContext<GlyphParser::ExprContext>(i);
}

tree::TerminalNode* GlyphParser::PowerExprContext::CARET() {
  return getToken(GlyphParser::CARET, 0);
}

GlyphParser::PowerExprContext::PowerExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::PowerExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitPowerExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualityExprContext ------------------------------------------------------------------

std::vector<GlyphParser::ExprContext *> GlyphParser::EqualityExprContext::expr() {
  return getRuleContexts<GlyphParser::ExprContext>();
}

GlyphParser::ExprContext* GlyphParser::EqualityExprContext::expr(size_t i) {
  return getRuleContext<GlyphParser::ExprContext>(i);
}

tree::TerminalNode* GlyphParser::EqualityExprContext::EQ() {
  return getToken(GlyphParser::EQ, 0);
}

tree::TerminalNode* GlyphParser::EqualityExprContext::NE() {
  return getToken(GlyphParser::NE, 0);
}

GlyphParser::EqualityExprContext::EqualityExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::EqualityExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitEqualityExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AdditiveExprContext ------------------------------------------------------------------

std::vector<GlyphParser::ExprContext *> GlyphParser::AdditiveExprContext::expr() {
  return getRuleContexts<GlyphParser::ExprContext>();
}

GlyphParser::ExprContext* GlyphParser::AdditiveExprContext::expr(size_t i) {
  return getRuleContext<GlyphParser::ExprContext>(i);
}

tree::TerminalNode* GlyphParser::AdditiveExprContext::PLUS() {
  return getToken(GlyphParser::PLUS, 0);
}

tree::TerminalNode* GlyphParser::AdditiveExprContext::MINUS() {
  return getToken(GlyphParser::MINUS, 0);
}

GlyphParser::AdditiveExprContext::AdditiveExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::AdditiveExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberExprContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::NumberExprContext::NUMBER() {
  return getToken(GlyphParser::NUMBER, 0);
}

GlyphParser::NumberExprContext::NumberExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::NumberExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitNumberExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ComparisonExprContext ------------------------------------------------------------------

std::vector<GlyphParser::ExprContext *> GlyphParser::ComparisonExprContext::expr() {
  return getRuleContexts<GlyphParser::ExprContext>();
}

GlyphParser::ExprContext* GlyphParser::ComparisonExprContext::expr(size_t i) {
  return getRuleContext<GlyphParser::ExprContext>(i);
}

tree::TerminalNode* GlyphParser::ComparisonExprContext::LT() {
  return getToken(GlyphParser::LT, 0);
}

tree::TerminalNode* GlyphParser::ComparisonExprContext::LE() {
  return getToken(GlyphParser::LE, 0);
}

tree::TerminalNode* GlyphParser::ComparisonExprContext::GT() {
  return getToken(GlyphParser::GT, 0);
}

tree::TerminalNode* GlyphParser::ComparisonExprContext::GE() {
  return getToken(GlyphParser::GE, 0);
}

GlyphParser::ComparisonExprContext::ComparisonExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::ComparisonExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitComparisonExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentifierExprContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::IdentifierExprContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

GlyphParser::IdentifierExprContext::IdentifierExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::IdentifierExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitIdentifierExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExprContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::ParenExprContext::LPAREN() {
  return getToken(GlyphParser::LPAREN, 0);
}

GlyphParser::ExprContext* GlyphParser::ParenExprContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

tree::TerminalNode* GlyphParser::ParenExprContext::RPAREN() {
  return getToken(GlyphParser::RPAREN, 0);
}

GlyphParser::ParenExprContext::ParenExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::ParenExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitParenExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryExprContext ------------------------------------------------------------------

GlyphParser::ExprContext* GlyphParser::UnaryExprContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

tree::TerminalNode* GlyphParser::UnaryExprContext::MINUS() {
  return getToken(GlyphParser::MINUS, 0);
}

tree::TerminalNode* GlyphParser::UnaryExprContext::NOT() {
  return getToken(GlyphParser::NOT, 0);
}

GlyphParser::UnaryExprContext::UnaryExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::UnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrExprContext ------------------------------------------------------------------

std::vector<GlyphParser::ExprContext *> GlyphParser::OrExprContext::expr() {
  return getRuleContexts<GlyphParser::ExprContext>();
}

GlyphParser::ExprContext* GlyphParser::OrExprContext::expr(size_t i) {
  return getRuleContext<GlyphParser::ExprContext>(i);
}

tree::TerminalNode* GlyphParser::OrExprContext::OR() {
  return getToken(GlyphParser::OR, 0);
}

GlyphParser::OrExprContext::OrExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::ExprContext* GlyphParser::expr() {
   return expr(0);
}

GlyphParser::ExprContext* GlyphParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  GlyphParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  GlyphParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, GlyphParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(49);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GlyphParser::NOT:
      case GlyphParser::MINUS: {
        _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(40);
        _la = _input->LA(1);
        if (!(_la == GlyphParser::NOT

        || _la == GlyphParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(41);
        expr(5);
        break;
      }

      case GlyphParser::NUMBER: {
        _localctx = _tracker.createInstance<NumberExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(42);
        match(GlyphParser::NUMBER);
        break;
      }

      case GlyphParser::STRING: {
        _localctx = _tracker.createInstance<StringExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(43);
        match(GlyphParser::STRING);
        break;
      }

      case GlyphParser::ID: {
        _localctx = _tracker.createInstance<IdentifierExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(44);
        match(GlyphParser::ID);
        break;
      }

      case GlyphParser::LPAREN: {
        _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(45);
        match(GlyphParser::LPAREN);
        setState(46);
        expr(0);
        setState(47);
        match(GlyphParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(74);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(72);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(51);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(52);
          match(GlyphParser::OR);
          setState(53);
          expr(13);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(54);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(55);
          match(GlyphParser::AND);
          setState(56);
          expr(12);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<EqualityExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(57);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(58);
          _la = _input->LA(1);
          if (!(_la == GlyphParser::EQ

          || _la == GlyphParser::NE)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(59);
          expr(11);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ComparisonExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(60);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(61);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 30720) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(62);
          expr(10);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<AdditiveExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(63);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(64);
          _la = _input->LA(1);
          if (!(_la == GlyphParser::PLUS

          || _la == GlyphParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(65);
          expr(9);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<MultiplicativeExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(66);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(67);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 1835008) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(68);
          expr(8);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<PowerExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(69);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(70);
          match(GlyphParser::CARET);
          setState(71);
          expr(7);
          break;
        }

        default:
          break;
        } 
      }
      setState(76);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool GlyphParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 5: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool GlyphParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 12);
    case 1: return precpred(_ctx, 11);
    case 2: return precpred(_ctx, 10);
    case 3: return precpred(_ctx, 9);
    case 4: return precpred(_ctx, 8);
    case 5: return precpred(_ctx, 7);
    case 6: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

void GlyphParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  glyphParserInitialize();
#else
  ::antlr4::internal::call_once(glyphParserOnceFlag, glyphParserInitialize);
#endif
}
