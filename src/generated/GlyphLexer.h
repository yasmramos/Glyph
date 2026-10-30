
// Generated from /workspace/grammars/Glyph.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  GlyphLexer : public antlr4::Lexer {
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

  explicit GlyphLexer(antlr4::CharStream *input);

  ~GlyphLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

