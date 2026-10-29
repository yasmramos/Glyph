
// Generated from /workspace/grammars/Glyph.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  GlyphLexer : public antlr4::Lexer {
public:
  enum {
    PRINT = 1, LOCAL = 2, AND = 3, OR = 4, NOT = 5, NUMBER = 6, STRING = 7, 
    ID = 8, EQ = 9, NE = 10, LE = 11, GE = 12, LT = 13, GT = 14, ASSIGN = 15, 
    PLUS = 16, MINUS = 17, STAR = 18, SLASH = 19, PERCENT = 20, CARET = 21, 
    LPAREN = 22, RPAREN = 23, LINE_COMMENT = 24, BLOCK_COMMENT = 25, WS = 26
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

