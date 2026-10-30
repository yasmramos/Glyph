
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
      "program", "moduleDecl", "importDecl", "topLevelDecl", "constDecl", 
      "structDecl", "interfaceDecl", "classDecl", "fieldDecl", "sigDecl", 
      "memberDecl", "attrDecl", "paramList", "param", "fnDecl", "type", 
      "typeName", "qualifiedName", "genericParams", "genericArgs", "typeList", 
      "block", "stmt", "constStmt", "letStmt", "varStmt", "exprStmt", "ifStmt", 
      "whileStmt", "forStmt", "forInit", "forUpdate", "matchStmt", "matchArm", 
      "pattern", "returnStmt", "expr", "exprOrAssign", "ternaryExpr", "orExpr", 
      "andExpr", "equalityExpr", "comparisonExpr", "additiveExpr", "multiplicativeExpr", 
      "castExpr", "primitiveKw", "unaryExpr", "postfixExpr", "postfixOp", 
      "primaryExpr", "fieldInit", "lambdaParams", "argList"
    },
    std::vector<std::string>{
      "", "'module'", "'import'", "'as'", "'const'", "'struct'", "'interface'", 
      "'class'", "'extends'", "'implements'", "'var'", "'fn'", "'->'", "'int'", 
      "'long'", "'double'", "'bool'", "'str'", "'let'", "'if'", "'else'", 
      "'while'", "'for'", "'in'", "'match'", "'=>'", "'some'", "'none'", 
      "'ok'", "'err'", "'return'", "'try'", "'not'", "'true'", "'false'", 
      "", "", "", "", "'+='", "'-='", "'*='", "'/='", "'%='", "'=='", "'!='", 
      "'<='", "'>='", "'<'", "'>'", "'&&'", "'||'", "'!'", "'='", "'..'", 
      "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'", "'['", "']'", "'{'", 
      "'}'", "'::'", "';'", "','", "'.'", "':'", "'\\u003F'", "'@'", "'_'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "DOUBLE_LITERAL", "INT_LITERAL", "STRING", "ID", "PLUS_ASSIGN", 
      "MINUS_ASSIGN", "STAR_ASSIGN", "SLASH_ASSIGN", "PERCENT_ASSIGN", "EQ", 
      "NE", "LE", "GE", "LT", "GT", "AND_AND", "OR_OR", "NOT_OP", "ASSIGN", 
      "DOT_DOT", "PLUS", "MINUS", "STAR", "SLASH", "PERCENT", "LPAREN", 
      "RPAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "COLONCOLON", 
      "SEMICOLON", "COMMA", "DOT", "COLON", "QUEST", "AT", "UNDERSCORE", 
      "LINE_COMMENT", "BLOCK_COMMENT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,76,704,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,1,0,3,0,110,8,0,1,0,5,0,113,
  	8,0,10,0,12,0,116,9,0,1,0,5,0,119,8,0,10,0,12,0,122,9,0,1,0,1,0,1,1,1,
  	1,1,1,1,2,1,2,1,2,1,2,3,2,133,8,2,1,3,1,3,1,3,1,3,1,3,3,3,140,8,3,1,4,
  	1,4,1,4,1,4,1,4,1,5,1,5,1,5,3,5,150,8,5,1,5,1,5,5,5,154,8,5,10,5,12,5,
  	157,9,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,5,6,167,8,6,10,6,12,6,170,9,6,
  	1,6,3,6,173,8,6,1,6,1,6,1,7,1,7,1,7,3,7,180,8,7,1,7,1,7,3,7,184,8,7,1,
  	7,1,7,3,7,188,8,7,1,7,1,7,5,7,192,8,7,10,7,12,7,195,9,7,1,7,1,7,1,8,3,
  	8,200,8,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,3,9,210,8,9,1,9,1,9,1,9,3,9,
  	215,8,9,1,10,1,10,3,10,219,8,10,1,10,3,10,222,8,10,1,10,3,10,225,8,10,
  	1,11,1,11,1,11,1,12,1,12,1,12,5,12,233,8,12,10,12,12,12,236,9,12,1,12,
  	3,12,239,8,12,1,13,3,13,242,8,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,3,
  	14,251,8,14,1,14,1,14,3,14,255,8,14,1,14,1,14,1,14,3,14,260,8,14,1,14,
  	1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,
  	276,8,15,1,15,1,15,1,15,3,15,281,8,15,1,15,3,15,284,8,15,1,16,1,16,3,
  	16,288,8,16,1,17,1,17,1,17,5,17,293,8,17,10,17,12,17,296,9,17,1,18,1,
  	18,1,18,1,18,5,18,302,8,18,10,18,12,18,305,9,18,1,18,1,18,1,19,1,19,1,
  	19,1,19,5,19,313,8,19,10,19,12,19,316,9,19,1,19,1,19,1,20,1,20,1,20,5,
  	20,323,8,20,10,20,12,20,326,9,20,1,20,3,20,329,8,20,1,21,1,21,5,21,333,
  	8,21,10,21,12,21,336,9,21,1,21,1,21,1,22,1,22,1,22,1,22,1,22,1,22,1,22,
  	1,22,1,22,1,22,3,22,350,8,22,1,23,1,23,1,23,1,23,3,23,356,8,23,1,23,1,
  	23,1,23,1,24,1,24,1,24,1,24,3,24,365,8,24,1,24,1,24,1,24,1,25,1,25,1,
  	25,1,25,3,25,374,8,25,1,25,1,25,3,25,378,8,25,1,26,1,26,1,27,1,27,1,27,
  	1,27,1,27,1,27,1,27,3,27,389,8,27,1,28,1,28,1,28,1,28,1,29,1,29,1,29,
  	1,29,1,29,1,29,1,29,1,29,3,29,403,8,29,1,29,1,29,3,29,407,8,29,1,29,1,
  	29,3,29,411,8,29,1,29,3,29,414,8,29,1,30,1,30,1,30,1,30,3,30,420,8,30,
  	1,31,1,31,1,32,1,32,1,32,1,32,5,32,428,8,32,10,32,12,32,431,9,32,1,32,
  	1,32,1,33,1,33,1,33,3,33,438,8,33,1,33,1,33,1,33,3,33,443,8,33,1,33,3,
  	33,446,8,33,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,
  	34,1,34,1,34,1,34,1,34,3,34,464,8,34,1,35,1,35,3,35,468,8,35,1,36,1,36,
  	1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,3,37,481,8,37,1,38,1,38,
  	1,38,1,38,1,38,1,38,3,38,489,8,38,1,39,1,39,1,39,5,39,494,8,39,10,39,
  	12,39,497,9,39,1,40,1,40,1,40,5,40,502,8,40,10,40,12,40,505,9,40,1,41,
  	1,41,1,41,5,41,510,8,41,10,41,12,41,513,9,41,1,42,1,42,1,42,5,42,518,
  	8,42,10,42,12,42,521,9,42,1,43,1,43,1,43,5,43,526,8,43,10,43,12,43,529,
  	9,43,1,44,1,44,1,44,5,44,534,8,44,10,44,12,44,537,9,44,1,45,1,45,1,45,
  	1,45,1,45,1,45,1,45,3,45,546,8,45,1,46,1,46,1,47,1,47,1,47,3,47,553,8,
  	47,1,48,1,48,5,48,557,8,48,10,48,12,48,560,9,48,1,49,1,49,1,49,1,49,1,
  	49,1,49,1,49,1,49,1,49,1,49,3,49,572,8,49,1,49,1,49,3,49,576,8,49,1,50,
  	1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,
  	1,50,1,50,1,50,1,50,1,50,1,50,4,50,599,8,50,11,50,12,50,600,1,50,1,50,
  	1,50,1,50,5,50,607,8,50,10,50,12,50,610,9,50,3,50,612,8,50,1,50,1,50,
  	1,50,1,50,1,50,1,50,1,50,5,50,621,8,50,10,50,12,50,624,9,50,1,50,3,50,
  	627,8,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,4,50,636,8,50,11,50,12,50,
  	637,1,50,3,50,641,8,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,
  	50,3,50,653,8,50,1,50,1,50,1,50,1,50,1,50,1,50,3,50,661,8,50,1,50,1,50,
  	1,50,3,50,666,8,50,1,51,1,51,1,51,1,51,1,52,1,52,1,52,1,52,3,52,676,8,
  	52,1,52,1,52,1,52,1,52,3,52,682,8,52,5,52,684,8,52,10,52,12,52,687,9,
  	52,3,52,689,8,52,1,52,1,52,1,53,1,53,1,53,5,53,696,8,53,10,53,12,53,699,
  	9,53,1,53,3,53,702,8,53,1,53,0,0,54,0,2,4,6,8,10,12,14,16,18,20,22,24,
  	26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,
  	72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,0,8,2,0,4,4,
  	10,10,1,0,13,17,1,0,39,43,1,0,44,45,1,0,46,49,1,0,55,56,1,0,57,59,3,0,
  	32,32,52,52,56,56,772,0,109,1,0,0,0,2,125,1,0,0,0,4,128,1,0,0,0,6,139,
  	1,0,0,0,8,141,1,0,0,0,10,146,1,0,0,0,12,160,1,0,0,0,14,176,1,0,0,0,16,
  	199,1,0,0,0,18,205,1,0,0,0,20,224,1,0,0,0,22,226,1,0,0,0,24,229,1,0,0,
  	0,26,241,1,0,0,0,28,247,1,0,0,0,30,283,1,0,0,0,32,285,1,0,0,0,34,289,
  	1,0,0,0,36,297,1,0,0,0,38,308,1,0,0,0,40,319,1,0,0,0,42,330,1,0,0,0,44,
  	349,1,0,0,0,46,351,1,0,0,0,48,360,1,0,0,0,50,369,1,0,0,0,52,379,1,0,0,
  	0,54,381,1,0,0,0,56,390,1,0,0,0,58,413,1,0,0,0,60,419,1,0,0,0,62,421,
  	1,0,0,0,64,423,1,0,0,0,66,434,1,0,0,0,68,463,1,0,0,0,70,465,1,0,0,0,72,
  	469,1,0,0,0,74,480,1,0,0,0,76,482,1,0,0,0,78,490,1,0,0,0,80,498,1,0,0,
  	0,82,506,1,0,0,0,84,514,1,0,0,0,86,522,1,0,0,0,88,530,1,0,0,0,90,545,
  	1,0,0,0,92,547,1,0,0,0,94,552,1,0,0,0,96,554,1,0,0,0,98,575,1,0,0,0,100,
  	665,1,0,0,0,102,667,1,0,0,0,104,671,1,0,0,0,106,692,1,0,0,0,108,110,3,
  	2,1,0,109,108,1,0,0,0,109,110,1,0,0,0,110,114,1,0,0,0,111,113,3,4,2,0,
  	112,111,1,0,0,0,113,116,1,0,0,0,114,112,1,0,0,0,114,115,1,0,0,0,115,120,
  	1,0,0,0,116,114,1,0,0,0,117,119,3,6,3,0,118,117,1,0,0,0,119,122,1,0,0,
  	0,120,118,1,0,0,0,120,121,1,0,0,0,121,123,1,0,0,0,122,120,1,0,0,0,123,
  	124,5,0,0,1,124,1,1,0,0,0,125,126,5,1,0,0,126,127,3,34,17,0,127,3,1,0,
  	0,0,128,129,5,2,0,0,129,132,3,34,17,0,130,131,5,3,0,0,131,133,5,38,0,
  	0,132,130,1,0,0,0,132,133,1,0,0,0,133,5,1,0,0,0,134,140,3,8,4,0,135,140,
  	3,10,5,0,136,140,3,12,6,0,137,140,3,14,7,0,138,140,3,28,14,0,139,134,
  	1,0,0,0,139,135,1,0,0,0,139,136,1,0,0,0,139,137,1,0,0,0,139,138,1,0,0,
  	0,140,7,1,0,0,0,141,142,5,4,0,0,142,143,5,38,0,0,143,144,5,53,0,0,144,
  	145,3,72,36,0,145,9,1,0,0,0,146,147,5,5,0,0,147,149,5,38,0,0,148,150,
  	3,36,18,0,149,148,1,0,0,0,149,150,1,0,0,0,150,151,1,0,0,0,151,155,5,64,
  	0,0,152,154,3,16,8,0,153,152,1,0,0,0,154,157,1,0,0,0,155,153,1,0,0,0,
  	155,156,1,0,0,0,156,158,1,0,0,0,157,155,1,0,0,0,158,159,5,65,0,0,159,
  	11,1,0,0,0,160,161,5,6,0,0,161,162,5,38,0,0,162,168,5,64,0,0,163,164,
  	3,18,9,0,164,165,5,68,0,0,165,167,1,0,0,0,166,163,1,0,0,0,167,170,1,0,
  	0,0,168,166,1,0,0,0,168,169,1,0,0,0,169,172,1,0,0,0,170,168,1,0,0,0,171,
  	173,3,18,9,0,172,171,1,0,0,0,172,173,1,0,0,0,173,174,1,0,0,0,174,175,
  	5,65,0,0,175,13,1,0,0,0,176,177,5,7,0,0,177,179,5,38,0,0,178,180,3,36,
  	18,0,179,178,1,0,0,0,179,180,1,0,0,0,180,183,1,0,0,0,181,182,5,8,0,0,
  	182,184,3,32,16,0,183,181,1,0,0,0,183,184,1,0,0,0,184,187,1,0,0,0,185,
  	186,5,9,0,0,186,188,3,40,20,0,187,185,1,0,0,0,187,188,1,0,0,0,188,189,
  	1,0,0,0,189,193,5,64,0,0,190,192,3,20,10,0,191,190,1,0,0,0,192,195,1,
  	0,0,0,193,191,1,0,0,0,193,194,1,0,0,0,194,196,1,0,0,0,195,193,1,0,0,0,
  	196,197,5,65,0,0,197,15,1,0,0,0,198,200,7,0,0,0,199,198,1,0,0,0,199,200,
  	1,0,0,0,200,201,1,0,0,0,201,202,5,38,0,0,202,203,5,70,0,0,203,204,3,30,
  	15,0,204,17,1,0,0,0,205,206,5,11,0,0,206,207,5,38,0,0,207,209,5,60,0,
  	0,208,210,3,24,12,0,209,208,1,0,0,0,209,210,1,0,0,0,210,211,1,0,0,0,211,
  	214,5,61,0,0,212,213,5,12,0,0,213,215,3,30,15,0,214,212,1,0,0,0,214,215,
  	1,0,0,0,215,19,1,0,0,0,216,225,3,16,8,0,217,219,5,38,0,0,218,217,1,0,
  	0,0,218,219,1,0,0,0,219,221,1,0,0,0,220,222,3,22,11,0,221,220,1,0,0,0,
  	221,222,1,0,0,0,222,223,1,0,0,0,223,225,3,28,14,0,224,216,1,0,0,0,224,
  	218,1,0,0,0,225,21,1,0,0,0,226,227,5,72,0,0,227,228,5,38,0,0,228,23,1,
  	0,0,0,229,234,3,26,13,0,230,231,5,68,0,0,231,233,3,26,13,0,232,230,1,
  	0,0,0,233,236,1,0,0,0,234,232,1,0,0,0,234,235,1,0,0,0,235,238,1,0,0,0,
  	236,234,1,0,0,0,237,239,5,68,0,0,238,237,1,0,0,0,238,239,1,0,0,0,239,
  	25,1,0,0,0,240,242,5,10,0,0,241,240,1,0,0,0,241,242,1,0,0,0,242,243,1,
  	0,0,0,243,244,5,38,0,0,244,245,5,70,0,0,245,246,3,30,15,0,246,27,1,0,
  	0,0,247,248,5,11,0,0,248,250,5,38,0,0,249,251,3,36,18,0,250,249,1,0,0,
  	0,250,251,1,0,0,0,251,252,1,0,0,0,252,254,5,60,0,0,253,255,3,24,12,0,
  	254,253,1,0,0,0,254,255,1,0,0,0,255,256,1,0,0,0,256,259,5,61,0,0,257,
  	258,5,12,0,0,258,260,3,30,15,0,259,257,1,0,0,0,259,260,1,0,0,0,260,261,
  	1,0,0,0,261,262,3,42,21,0,262,29,1,0,0,0,263,284,7,1,0,0,264,265,5,62,
  	0,0,265,266,3,30,15,0,266,267,5,63,0,0,267,284,1,0,0,0,268,269,5,71,0,
  	0,269,284,3,30,15,0,270,271,5,52,0,0,271,284,3,30,15,0,272,273,5,11,0,
  	0,273,275,5,60,0,0,274,276,3,40,20,0,275,274,1,0,0,0,275,276,1,0,0,0,
  	276,277,1,0,0,0,277,280,5,61,0,0,278,279,5,12,0,0,279,281,3,30,15,0,280,
  	278,1,0,0,0,280,281,1,0,0,0,281,284,1,0,0,0,282,284,3,32,16,0,283,263,
  	1,0,0,0,283,264,1,0,0,0,283,268,1,0,0,0,283,270,1,0,0,0,283,272,1,0,0,
  	0,283,282,1,0,0,0,284,31,1,0,0,0,285,287,3,34,17,0,286,288,3,38,19,0,
  	287,286,1,0,0,0,287,288,1,0,0,0,288,33,1,0,0,0,289,294,5,38,0,0,290,291,
  	5,69,0,0,291,293,5,38,0,0,292,290,1,0,0,0,293,296,1,0,0,0,294,292,1,0,
  	0,0,294,295,1,0,0,0,295,35,1,0,0,0,296,294,1,0,0,0,297,298,5,48,0,0,298,
  	303,5,38,0,0,299,300,5,68,0,0,300,302,5,38,0,0,301,299,1,0,0,0,302,305,
  	1,0,0,0,303,301,1,0,0,0,303,304,1,0,0,0,304,306,1,0,0,0,305,303,1,0,0,
  	0,306,307,5,49,0,0,307,37,1,0,0,0,308,309,5,48,0,0,309,314,3,30,15,0,
  	310,311,5,68,0,0,311,313,3,30,15,0,312,310,1,0,0,0,313,316,1,0,0,0,314,
  	312,1,0,0,0,314,315,1,0,0,0,315,317,1,0,0,0,316,314,1,0,0,0,317,318,5,
  	49,0,0,318,39,1,0,0,0,319,324,3,30,15,0,320,321,5,68,0,0,321,323,3,30,
  	15,0,322,320,1,0,0,0,323,326,1,0,0,0,324,322,1,0,0,0,324,325,1,0,0,0,
  	325,328,1,0,0,0,326,324,1,0,0,0,327,329,5,68,0,0,328,327,1,0,0,0,328,
  	329,1,0,0,0,329,41,1,0,0,0,330,334,5,64,0,0,331,333,3,44,22,0,332,331,
  	1,0,0,0,333,336,1,0,0,0,334,332,1,0,0,0,334,335,1,0,0,0,335,337,1,0,0,
  	0,336,334,1,0,0,0,337,338,5,65,0,0,338,43,1,0,0,0,339,350,3,46,23,0,340,
  	350,3,48,24,0,341,350,3,50,25,0,342,350,3,52,26,0,343,350,3,42,21,0,344,
  	350,3,54,27,0,345,350,3,56,28,0,346,350,3,58,29,0,347,350,3,64,32,0,348,
  	350,3,70,35,0,349,339,1,0,0,0,349,340,1,0,0,0,349,341,1,0,0,0,349,342,
  	1,0,0,0,349,343,1,0,0,0,349,344,1,0,0,0,349,345,1,0,0,0,349,346,1,0,0,
  	0,349,347,1,0,0,0,349,348,1,0,0,0,350,45,1,0,0,0,351,352,5,4,0,0,352,
  	355,5,38,0,0,353,354,5,70,0,0,354,356,3,30,15,0,355,353,1,0,0,0,355,356,
  	1,0,0,0,356,357,1,0,0,0,357,358,5,53,0,0,358,359,3,72,36,0,359,47,1,0,
  	0,0,360,361,5,18,0,0,361,364,5,38,0,0,362,363,5,70,0,0,363,365,3,30,15,
  	0,364,362,1,0,0,0,364,365,1,0,0,0,365,366,1,0,0,0,366,367,5,53,0,0,367,
  	368,3,72,36,0,368,49,1,0,0,0,369,370,5,10,0,0,370,373,5,38,0,0,371,372,
  	5,70,0,0,372,374,3,30,15,0,373,371,1,0,0,0,373,374,1,0,0,0,374,377,1,
  	0,0,0,375,376,5,53,0,0,376,378,3,72,36,0,377,375,1,0,0,0,377,378,1,0,
  	0,0,378,51,1,0,0,0,379,380,3,74,37,0,380,53,1,0,0,0,381,382,5,19,0,0,
  	382,383,3,72,36,0,383,388,3,42,21,0,384,385,5,20,0,0,385,389,3,54,27,
  	0,386,387,5,20,0,0,387,389,3,42,21,0,388,384,1,0,0,0,388,386,1,0,0,0,
  	388,389,1,0,0,0,389,55,1,0,0,0,390,391,5,21,0,0,391,392,3,72,36,0,392,
  	393,3,42,21,0,393,57,1,0,0,0,394,395,5,22,0,0,395,396,5,38,0,0,396,397,
  	5,23,0,0,397,398,3,72,36,0,398,399,3,42,21,0,399,414,1,0,0,0,400,402,
  	5,22,0,0,401,403,3,60,30,0,402,401,1,0,0,0,402,403,1,0,0,0,403,404,1,
  	0,0,0,404,406,5,67,0,0,405,407,3,72,36,0,406,405,1,0,0,0,406,407,1,0,
  	0,0,407,408,1,0,0,0,408,410,5,67,0,0,409,411,3,62,31,0,410,409,1,0,0,
  	0,410,411,1,0,0,0,411,412,1,0,0,0,412,414,3,42,21,0,413,394,1,0,0,0,413,
  	400,1,0,0,0,414,59,1,0,0,0,415,420,3,48,24,0,416,420,3,50,25,0,417,420,
  	3,46,23,0,418,420,3,74,37,0,419,415,1,0,0,0,419,416,1,0,0,0,419,417,1,
  	0,0,0,419,418,1,0,0,0,420,61,1,0,0,0,421,422,3,74,37,0,422,63,1,0,0,0,
  	423,424,5,24,0,0,424,425,3,72,36,0,425,429,5,64,0,0,426,428,3,66,33,0,
  	427,426,1,0,0,0,428,431,1,0,0,0,429,427,1,0,0,0,429,430,1,0,0,0,430,432,
  	1,0,0,0,431,429,1,0,0,0,432,433,5,65,0,0,433,65,1,0,0,0,434,437,3,68,
  	34,0,435,436,5,19,0,0,436,438,3,72,36,0,437,435,1,0,0,0,437,438,1,0,0,
  	0,438,439,1,0,0,0,439,442,5,25,0,0,440,443,3,42,21,0,441,443,3,72,36,
  	0,442,440,1,0,0,0,442,441,1,0,0,0,443,445,1,0,0,0,444,446,5,68,0,0,445,
  	444,1,0,0,0,445,446,1,0,0,0,446,67,1,0,0,0,447,464,5,73,0,0,448,449,5,
  	26,0,0,449,450,5,60,0,0,450,451,5,38,0,0,451,464,5,61,0,0,452,464,5,27,
  	0,0,453,454,5,28,0,0,454,455,5,60,0,0,455,456,5,38,0,0,456,464,5,61,0,
  	0,457,458,5,29,0,0,458,459,5,60,0,0,459,460,5,38,0,0,460,464,5,61,0,0,
  	461,464,5,36,0,0,462,464,5,37,0,0,463,447,1,0,0,0,463,448,1,0,0,0,463,
  	452,1,0,0,0,463,453,1,0,0,0,463,457,1,0,0,0,463,461,1,0,0,0,463,462,1,
  	0,0,0,464,69,1,0,0,0,465,467,5,30,0,0,466,468,3,72,36,0,467,466,1,0,0,
  	0,467,468,1,0,0,0,468,71,1,0,0,0,469,470,3,76,38,0,470,73,1,0,0,0,471,
  	472,3,94,47,0,472,473,7,2,0,0,473,474,3,72,36,0,474,481,1,0,0,0,475,476,
  	3,94,47,0,476,477,5,53,0,0,477,478,3,72,36,0,478,481,1,0,0,0,479,481,
  	3,72,36,0,480,471,1,0,0,0,480,475,1,0,0,0,480,479,1,0,0,0,481,75,1,0,
  	0,0,482,488,3,78,39,0,483,484,5,71,0,0,484,485,3,78,39,0,485,486,5,70,
  	0,0,486,487,3,76,38,0,487,489,1,0,0,0,488,483,1,0,0,0,488,489,1,0,0,0,
  	489,77,1,0,0,0,490,495,3,80,40,0,491,492,5,51,0,0,492,494,3,80,40,0,493,
  	491,1,0,0,0,494,497,1,0,0,0,495,493,1,0,0,0,495,496,1,0,0,0,496,79,1,
  	0,0,0,497,495,1,0,0,0,498,503,3,82,41,0,499,500,5,50,0,0,500,502,3,82,
  	41,0,501,499,1,0,0,0,502,505,1,0,0,0,503,501,1,0,0,0,503,504,1,0,0,0,
  	504,81,1,0,0,0,505,503,1,0,0,0,506,511,3,84,42,0,507,508,7,3,0,0,508,
  	510,3,84,42,0,509,507,1,0,0,0,510,513,1,0,0,0,511,509,1,0,0,0,511,512,
  	1,0,0,0,512,83,1,0,0,0,513,511,1,0,0,0,514,519,3,86,43,0,515,516,7,4,
  	0,0,516,518,3,86,43,0,517,515,1,0,0,0,518,521,1,0,0,0,519,517,1,0,0,0,
  	519,520,1,0,0,0,520,85,1,0,0,0,521,519,1,0,0,0,522,527,3,88,44,0,523,
  	524,7,5,0,0,524,526,3,88,44,0,525,523,1,0,0,0,526,529,1,0,0,0,527,525,
  	1,0,0,0,527,528,1,0,0,0,528,87,1,0,0,0,529,527,1,0,0,0,530,535,3,90,45,
  	0,531,532,7,6,0,0,532,534,3,90,45,0,533,531,1,0,0,0,534,537,1,0,0,0,535,
  	533,1,0,0,0,535,536,1,0,0,0,536,89,1,0,0,0,537,535,1,0,0,0,538,539,3,
  	94,47,0,539,540,5,3,0,0,540,541,3,92,46,0,541,546,1,0,0,0,542,543,5,31,
  	0,0,543,546,3,94,47,0,544,546,3,94,47,0,545,538,1,0,0,0,545,542,1,0,0,
  	0,545,544,1,0,0,0,546,91,1,0,0,0,547,548,7,1,0,0,548,93,1,0,0,0,549,550,
  	7,7,0,0,550,553,3,94,47,0,551,553,3,96,48,0,552,549,1,0,0,0,552,551,1,
  	0,0,0,553,95,1,0,0,0,554,558,3,100,50,0,555,557,3,98,49,0,556,555,1,0,
  	0,0,557,560,1,0,0,0,558,556,1,0,0,0,558,559,1,0,0,0,559,97,1,0,0,0,560,
  	558,1,0,0,0,561,562,5,69,0,0,562,576,5,38,0,0,563,564,5,66,0,0,564,576,
  	5,38,0,0,565,566,5,62,0,0,566,567,3,72,36,0,567,568,5,63,0,0,568,576,
  	1,0,0,0,569,571,5,60,0,0,570,572,3,106,53,0,571,570,1,0,0,0,571,572,1,
  	0,0,0,572,573,1,0,0,0,573,576,5,61,0,0,574,576,5,71,0,0,575,561,1,0,0,
  	0,575,563,1,0,0,0,575,565,1,0,0,0,575,569,1,0,0,0,575,574,1,0,0,0,576,
  	99,1,0,0,0,577,666,5,36,0,0,578,666,5,35,0,0,579,666,5,33,0,0,580,666,
  	5,34,0,0,581,666,5,27,0,0,582,583,5,26,0,0,583,584,5,60,0,0,584,585,3,
  	72,36,0,585,586,5,61,0,0,586,666,1,0,0,0,587,588,5,28,0,0,588,589,5,60,
  	0,0,589,590,3,72,36,0,590,591,5,61,0,0,591,666,1,0,0,0,592,593,5,29,0,
  	0,593,594,5,60,0,0,594,595,3,72,36,0,595,596,5,61,0,0,596,666,1,0,0,0,
  	597,599,5,37,0,0,598,597,1,0,0,0,599,600,1,0,0,0,600,598,1,0,0,0,600,
  	601,1,0,0,0,601,666,1,0,0,0,602,611,5,62,0,0,603,608,3,72,36,0,604,605,
  	5,68,0,0,605,607,3,72,36,0,606,604,1,0,0,0,607,610,1,0,0,0,608,606,1,
  	0,0,0,608,609,1,0,0,0,609,612,1,0,0,0,610,608,1,0,0,0,611,603,1,0,0,0,
  	611,612,1,0,0,0,612,613,1,0,0,0,613,666,5,63,0,0,614,615,5,38,0,0,615,
  	616,5,70,0,0,616,617,5,64,0,0,617,622,3,102,51,0,618,619,5,68,0,0,619,
  	621,3,102,51,0,620,618,1,0,0,0,621,624,1,0,0,0,622,620,1,0,0,0,622,623,
  	1,0,0,0,623,626,1,0,0,0,624,622,1,0,0,0,625,627,5,68,0,0,626,625,1,0,
  	0,0,626,627,1,0,0,0,627,628,1,0,0,0,628,629,5,65,0,0,629,666,1,0,0,0,
  	630,631,5,38,0,0,631,632,5,64,0,0,632,635,3,102,51,0,633,634,5,68,0,0,
  	634,636,3,102,51,0,635,633,1,0,0,0,636,637,1,0,0,0,637,635,1,0,0,0,637,
  	638,1,0,0,0,638,640,1,0,0,0,639,641,5,68,0,0,640,639,1,0,0,0,640,641,
  	1,0,0,0,641,642,1,0,0,0,642,643,5,65,0,0,643,666,1,0,0,0,644,645,5,60,
  	0,0,645,646,3,72,36,0,646,647,5,61,0,0,647,666,1,0,0,0,648,649,5,11,0,
  	0,649,652,3,104,52,0,650,651,5,12,0,0,651,653,3,30,15,0,652,650,1,0,0,
  	0,652,653,1,0,0,0,653,654,1,0,0,0,654,655,3,42,21,0,655,666,1,0,0,0,656,
  	657,5,11,0,0,657,660,3,104,52,0,658,659,5,12,0,0,659,661,3,30,15,0,660,
  	658,1,0,0,0,660,661,1,0,0,0,661,662,1,0,0,0,662,663,3,72,36,0,663,666,
  	1,0,0,0,664,666,5,38,0,0,665,577,1,0,0,0,665,578,1,0,0,0,665,579,1,0,
  	0,0,665,580,1,0,0,0,665,581,1,0,0,0,665,582,1,0,0,0,665,587,1,0,0,0,665,
  	592,1,0,0,0,665,598,1,0,0,0,665,602,1,0,0,0,665,614,1,0,0,0,665,630,1,
  	0,0,0,665,644,1,0,0,0,665,648,1,0,0,0,665,656,1,0,0,0,665,664,1,0,0,0,
  	666,101,1,0,0,0,667,668,5,38,0,0,668,669,5,70,0,0,669,670,3,72,36,0,670,
  	103,1,0,0,0,671,688,5,60,0,0,672,675,5,38,0,0,673,674,5,70,0,0,674,676,
  	3,30,15,0,675,673,1,0,0,0,675,676,1,0,0,0,676,685,1,0,0,0,677,678,5,68,
  	0,0,678,681,5,38,0,0,679,680,5,70,0,0,680,682,3,30,15,0,681,679,1,0,0,
  	0,681,682,1,0,0,0,682,684,1,0,0,0,683,677,1,0,0,0,684,687,1,0,0,0,685,
  	683,1,0,0,0,685,686,1,0,0,0,686,689,1,0,0,0,687,685,1,0,0,0,688,672,1,
  	0,0,0,688,689,1,0,0,0,689,690,1,0,0,0,690,691,5,61,0,0,691,105,1,0,0,
  	0,692,697,3,72,36,0,693,694,5,68,0,0,694,696,3,72,36,0,695,693,1,0,0,
  	0,696,699,1,0,0,0,697,695,1,0,0,0,697,698,1,0,0,0,698,701,1,0,0,0,699,
  	697,1,0,0,0,700,702,5,68,0,0,701,700,1,0,0,0,701,702,1,0,0,0,702,107,
  	1,0,0,0,81,109,114,120,132,139,149,155,168,172,179,183,187,193,199,209,
  	214,218,221,224,234,238,241,250,254,259,275,280,283,287,294,303,314,324,
  	328,334,349,355,364,373,377,388,402,406,410,413,419,429,437,442,445,463,
  	467,480,488,495,503,511,519,527,535,545,552,558,571,575,600,608,611,622,
  	626,637,640,652,660,665,675,681,685,688,697,701
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

GlyphParser::ModuleDeclContext* GlyphParser::ProgramContext::moduleDecl() {
  return getRuleContext<GlyphParser::ModuleDeclContext>(0);
}

std::vector<GlyphParser::ImportDeclContext *> GlyphParser::ProgramContext::importDecl() {
  return getRuleContexts<GlyphParser::ImportDeclContext>();
}

GlyphParser::ImportDeclContext* GlyphParser::ProgramContext::importDecl(size_t i) {
  return getRuleContext<GlyphParser::ImportDeclContext>(i);
}

std::vector<GlyphParser::TopLevelDeclContext *> GlyphParser::ProgramContext::topLevelDecl() {
  return getRuleContexts<GlyphParser::TopLevelDeclContext>();
}

GlyphParser::TopLevelDeclContext* GlyphParser::ProgramContext::topLevelDecl(size_t i) {
  return getRuleContext<GlyphParser::TopLevelDeclContext>(i);
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
    setState(109);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::T__0) {
      setState(108);
      moduleDecl();
    }
    setState(114);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GlyphParser::T__1) {
      setState(111);
      importDecl();
      setState(116);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(120);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2288) != 0)) {
      setState(117);
      topLevelDecl();
      setState(122);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(123);
    match(GlyphParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModuleDeclContext ------------------------------------------------------------------

GlyphParser::ModuleDeclContext::ModuleDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GlyphParser::QualifiedNameContext* GlyphParser::ModuleDeclContext::qualifiedName() {
  return getRuleContext<GlyphParser::QualifiedNameContext>(0);
}


size_t GlyphParser::ModuleDeclContext::getRuleIndex() const {
  return GlyphParser::RuleModuleDecl;
}


std::any GlyphParser::ModuleDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitModuleDecl(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::ModuleDeclContext* GlyphParser::moduleDecl() {
  ModuleDeclContext *_localctx = _tracker.createInstance<ModuleDeclContext>(_ctx, getState());
  enterRule(_localctx, 2, GlyphParser::RuleModuleDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    match(GlyphParser::T__0);
    setState(126);
    qualifiedName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportDeclContext ------------------------------------------------------------------

GlyphParser::ImportDeclContext::ImportDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GlyphParser::QualifiedNameContext* GlyphParser::ImportDeclContext::qualifiedName() {
  return getRuleContext<GlyphParser::QualifiedNameContext>(0);
}

tree::TerminalNode* GlyphParser::ImportDeclContext::ID() {
  return getToken(GlyphParser::ID, 0);
}


size_t GlyphParser::ImportDeclContext::getRuleIndex() const {
  return GlyphParser::RuleImportDecl;
}


std::any GlyphParser::ImportDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitImportDecl(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::ImportDeclContext* GlyphParser::importDecl() {
  ImportDeclContext *_localctx = _tracker.createInstance<ImportDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, GlyphParser::RuleImportDecl);
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
    setState(128);
    match(GlyphParser::T__1);
    setState(129);
    qualifiedName();
    setState(132);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::T__2) {
      setState(130);
      match(GlyphParser::T__2);
      setState(131);
      match(GlyphParser::ID);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TopLevelDeclContext ------------------------------------------------------------------

GlyphParser::TopLevelDeclContext::TopLevelDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GlyphParser::TopLevelDeclContext::getRuleIndex() const {
  return GlyphParser::RuleTopLevelDecl;
}

void GlyphParser::TopLevelDeclContext::copyFrom(TopLevelDeclContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- TopStructContext ------------------------------------------------------------------

GlyphParser::StructDeclContext* GlyphParser::TopStructContext::structDecl() {
  return getRuleContext<GlyphParser::StructDeclContext>(0);
}

GlyphParser::TopStructContext::TopStructContext(TopLevelDeclContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::TopStructContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitTopStruct(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TopClassContext ------------------------------------------------------------------

GlyphParser::ClassDeclContext* GlyphParser::TopClassContext::classDecl() {
  return getRuleContext<GlyphParser::ClassDeclContext>(0);
}

GlyphParser::TopClassContext::TopClassContext(TopLevelDeclContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::TopClassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitTopClass(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TopConstContext ------------------------------------------------------------------

GlyphParser::ConstDeclContext* GlyphParser::TopConstContext::constDecl() {
  return getRuleContext<GlyphParser::ConstDeclContext>(0);
}

GlyphParser::TopConstContext::TopConstContext(TopLevelDeclContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::TopConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitTopConst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TopInterfaceContext ------------------------------------------------------------------

GlyphParser::InterfaceDeclContext* GlyphParser::TopInterfaceContext::interfaceDecl() {
  return getRuleContext<GlyphParser::InterfaceDeclContext>(0);
}

GlyphParser::TopInterfaceContext::TopInterfaceContext(TopLevelDeclContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::TopInterfaceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitTopInterface(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TopFnContext ------------------------------------------------------------------

GlyphParser::FnDeclContext* GlyphParser::TopFnContext::fnDecl() {
  return getRuleContext<GlyphParser::FnDeclContext>(0);
}

GlyphParser::TopFnContext::TopFnContext(TopLevelDeclContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::TopFnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitTopFn(this);
  else
    return visitor->visitChildren(this);
}
GlyphParser::TopLevelDeclContext* GlyphParser::topLevelDecl() {
  TopLevelDeclContext *_localctx = _tracker.createInstance<TopLevelDeclContext>(_ctx, getState());
  enterRule(_localctx, 6, GlyphParser::RuleTopLevelDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(139);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GlyphParser::T__3: {
        _localctx = _tracker.createInstance<GlyphParser::TopConstContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(134);
        constDecl();
        break;
      }

      case GlyphParser::T__4: {
        _localctx = _tracker.createInstance<GlyphParser::TopStructContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(135);
        structDecl();
        break;
      }

      case GlyphParser::T__5: {
        _localctx = _tracker.createInstance<GlyphParser::TopInterfaceContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(136);
        interfaceDecl();
        break;
      }

      case GlyphParser::T__6: {
        _localctx = _tracker.createInstance<GlyphParser::TopClassContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(137);
        classDecl();
        break;
      }

      case GlyphParser::T__10: {
        _localctx = _tracker.createInstance<GlyphParser::TopFnContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(138);
        fnDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

GlyphParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::ConstDeclContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

tree::TerminalNode* GlyphParser::ConstDeclContext::ASSIGN() {
  return getToken(GlyphParser::ASSIGN, 0);
}

GlyphParser::ExprContext* GlyphParser::ConstDeclContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}


size_t GlyphParser::ConstDeclContext::getRuleIndex() const {
  return GlyphParser::RuleConstDecl;
}


std::any GlyphParser::ConstDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitConstDecl(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::ConstDeclContext* GlyphParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, GlyphParser::RuleConstDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    match(GlyphParser::T__3);
    setState(142);
    match(GlyphParser::ID);
    setState(143);
    match(GlyphParser::ASSIGN);
    setState(144);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructDeclContext ------------------------------------------------------------------

GlyphParser::StructDeclContext::StructDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::StructDeclContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

tree::TerminalNode* GlyphParser::StructDeclContext::LBRACE() {
  return getToken(GlyphParser::LBRACE, 0);
}

tree::TerminalNode* GlyphParser::StructDeclContext::RBRACE() {
  return getToken(GlyphParser::RBRACE, 0);
}

GlyphParser::GenericParamsContext* GlyphParser::StructDeclContext::genericParams() {
  return getRuleContext<GlyphParser::GenericParamsContext>(0);
}

std::vector<GlyphParser::FieldDeclContext *> GlyphParser::StructDeclContext::fieldDecl() {
  return getRuleContexts<GlyphParser::FieldDeclContext>();
}

GlyphParser::FieldDeclContext* GlyphParser::StructDeclContext::fieldDecl(size_t i) {
  return getRuleContext<GlyphParser::FieldDeclContext>(i);
}


size_t GlyphParser::StructDeclContext::getRuleIndex() const {
  return GlyphParser::RuleStructDecl;
}


std::any GlyphParser::StructDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitStructDecl(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::StructDeclContext* GlyphParser::structDecl() {
  StructDeclContext *_localctx = _tracker.createInstance<StructDeclContext>(_ctx, getState());
  enterRule(_localctx, 10, GlyphParser::RuleStructDecl);
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
    setState(146);
    match(GlyphParser::T__4);
    setState(147);
    match(GlyphParser::ID);
    setState(149);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::LT) {
      setState(148);
      genericParams();
    }
    setState(151);
    match(GlyphParser::LBRACE);
    setState(155);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 274877907984) != 0)) {
      setState(152);
      fieldDecl();
      setState(157);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(158);
    match(GlyphParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterfaceDeclContext ------------------------------------------------------------------

GlyphParser::InterfaceDeclContext::InterfaceDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::InterfaceDeclContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

tree::TerminalNode* GlyphParser::InterfaceDeclContext::LBRACE() {
  return getToken(GlyphParser::LBRACE, 0);
}

tree::TerminalNode* GlyphParser::InterfaceDeclContext::RBRACE() {
  return getToken(GlyphParser::RBRACE, 0);
}

std::vector<GlyphParser::SigDeclContext *> GlyphParser::InterfaceDeclContext::sigDecl() {
  return getRuleContexts<GlyphParser::SigDeclContext>();
}

GlyphParser::SigDeclContext* GlyphParser::InterfaceDeclContext::sigDecl(size_t i) {
  return getRuleContext<GlyphParser::SigDeclContext>(i);
}

std::vector<tree::TerminalNode *> GlyphParser::InterfaceDeclContext::COMMA() {
  return getTokens(GlyphParser::COMMA);
}

tree::TerminalNode* GlyphParser::InterfaceDeclContext::COMMA(size_t i) {
  return getToken(GlyphParser::COMMA, i);
}


size_t GlyphParser::InterfaceDeclContext::getRuleIndex() const {
  return GlyphParser::RuleInterfaceDecl;
}


std::any GlyphParser::InterfaceDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitInterfaceDecl(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::InterfaceDeclContext* GlyphParser::interfaceDecl() {
  InterfaceDeclContext *_localctx = _tracker.createInstance<InterfaceDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, GlyphParser::RuleInterfaceDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(160);
    match(GlyphParser::T__5);
    setState(161);
    match(GlyphParser::ID);
    setState(162);
    match(GlyphParser::LBRACE);
    setState(168);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(163);
        sigDecl();
        setState(164);
        match(GlyphParser::COMMA); 
      }
      setState(170);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
    setState(172);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::T__10) {
      setState(171);
      sigDecl();
    }
    setState(174);
    match(GlyphParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDeclContext ------------------------------------------------------------------

GlyphParser::ClassDeclContext::ClassDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::ClassDeclContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

tree::TerminalNode* GlyphParser::ClassDeclContext::LBRACE() {
  return getToken(GlyphParser::LBRACE, 0);
}

tree::TerminalNode* GlyphParser::ClassDeclContext::RBRACE() {
  return getToken(GlyphParser::RBRACE, 0);
}

GlyphParser::GenericParamsContext* GlyphParser::ClassDeclContext::genericParams() {
  return getRuleContext<GlyphParser::GenericParamsContext>(0);
}

GlyphParser::TypeNameContext* GlyphParser::ClassDeclContext::typeName() {
  return getRuleContext<GlyphParser::TypeNameContext>(0);
}

GlyphParser::TypeListContext* GlyphParser::ClassDeclContext::typeList() {
  return getRuleContext<GlyphParser::TypeListContext>(0);
}

std::vector<GlyphParser::MemberDeclContext *> GlyphParser::ClassDeclContext::memberDecl() {
  return getRuleContexts<GlyphParser::MemberDeclContext>();
}

GlyphParser::MemberDeclContext* GlyphParser::ClassDeclContext::memberDecl(size_t i) {
  return getRuleContext<GlyphParser::MemberDeclContext>(i);
}


size_t GlyphParser::ClassDeclContext::getRuleIndex() const {
  return GlyphParser::RuleClassDecl;
}


std::any GlyphParser::ClassDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitClassDecl(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::ClassDeclContext* GlyphParser::classDecl() {
  ClassDeclContext *_localctx = _tracker.createInstance<ClassDeclContext>(_ctx, getState());
  enterRule(_localctx, 14, GlyphParser::RuleClassDecl);
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
    setState(176);
    match(GlyphParser::T__6);
    setState(177);
    match(GlyphParser::ID);
    setState(179);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::LT) {
      setState(178);
      genericParams();
    }
    setState(183);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::T__7) {
      setState(181);
      match(GlyphParser::T__7);
      setState(182);
      typeName();
    }
    setState(187);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::T__8) {
      setState(185);
      match(GlyphParser::T__8);
      setState(186);
      typeList();
    }
    setState(189);
    match(GlyphParser::LBRACE);
    setState(193);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 274877910032) != 0) || _la == GlyphParser::AT) {
      setState(190);
      memberDecl();
      setState(195);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(196);
    match(GlyphParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldDeclContext ------------------------------------------------------------------

GlyphParser::FieldDeclContext::FieldDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::FieldDeclContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

tree::TerminalNode* GlyphParser::FieldDeclContext::COLON() {
  return getToken(GlyphParser::COLON, 0);
}

GlyphParser::TypeContext* GlyphParser::FieldDeclContext::type() {
  return getRuleContext<GlyphParser::TypeContext>(0);
}


size_t GlyphParser::FieldDeclContext::getRuleIndex() const {
  return GlyphParser::RuleFieldDecl;
}


std::any GlyphParser::FieldDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitFieldDecl(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::FieldDeclContext* GlyphParser::fieldDecl() {
  FieldDeclContext *_localctx = _tracker.createInstance<FieldDeclContext>(_ctx, getState());
  enterRule(_localctx, 16, GlyphParser::RuleFieldDecl);
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
    setState(199);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::T__3

    || _la == GlyphParser::T__9) {
      setState(198);
      _la = _input->LA(1);
      if (!(_la == GlyphParser::T__3

      || _la == GlyphParser::T__9)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(201);
    match(GlyphParser::ID);
    setState(202);
    match(GlyphParser::COLON);
    setState(203);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SigDeclContext ------------------------------------------------------------------

GlyphParser::SigDeclContext::SigDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::SigDeclContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

tree::TerminalNode* GlyphParser::SigDeclContext::LPAREN() {
  return getToken(GlyphParser::LPAREN, 0);
}

tree::TerminalNode* GlyphParser::SigDeclContext::RPAREN() {
  return getToken(GlyphParser::RPAREN, 0);
}

GlyphParser::ParamListContext* GlyphParser::SigDeclContext::paramList() {
  return getRuleContext<GlyphParser::ParamListContext>(0);
}

GlyphParser::TypeContext* GlyphParser::SigDeclContext::type() {
  return getRuleContext<GlyphParser::TypeContext>(0);
}


size_t GlyphParser::SigDeclContext::getRuleIndex() const {
  return GlyphParser::RuleSigDecl;
}


std::any GlyphParser::SigDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitSigDecl(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::SigDeclContext* GlyphParser::sigDecl() {
  SigDeclContext *_localctx = _tracker.createInstance<SigDeclContext>(_ctx, getState());
  enterRule(_localctx, 18, GlyphParser::RuleSigDecl);
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
    setState(205);
    match(GlyphParser::T__10);
    setState(206);
    match(GlyphParser::ID);
    setState(207);
    match(GlyphParser::LPAREN);
    setState(209);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::T__9

    || _la == GlyphParser::ID) {
      setState(208);
      paramList();
    }
    setState(211);
    match(GlyphParser::RPAREN);
    setState(214);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::T__11) {
      setState(212);
      match(GlyphParser::T__11);
      setState(213);
      type();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MemberDeclContext ------------------------------------------------------------------

GlyphParser::MemberDeclContext::MemberDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GlyphParser::MemberDeclContext::getRuleIndex() const {
  return GlyphParser::RuleMemberDecl;
}

void GlyphParser::MemberDeclContext::copyFrom(MemberDeclContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MemberFieldContext ------------------------------------------------------------------

GlyphParser::FieldDeclContext* GlyphParser::MemberFieldContext::fieldDecl() {
  return getRuleContext<GlyphParser::FieldDeclContext>(0);
}

GlyphParser::MemberFieldContext::MemberFieldContext(MemberDeclContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::MemberFieldContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitMemberField(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberFnContext ------------------------------------------------------------------

GlyphParser::FnDeclContext* GlyphParser::MemberFnContext::fnDecl() {
  return getRuleContext<GlyphParser::FnDeclContext>(0);
}

tree::TerminalNode* GlyphParser::MemberFnContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

GlyphParser::AttrDeclContext* GlyphParser::MemberFnContext::attrDecl() {
  return getRuleContext<GlyphParser::AttrDeclContext>(0);
}

GlyphParser::MemberFnContext::MemberFnContext(MemberDeclContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::MemberFnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitMemberFn(this);
  else
    return visitor->visitChildren(this);
}
GlyphParser::MemberDeclContext* GlyphParser::memberDecl() {
  MemberDeclContext *_localctx = _tracker.createInstance<MemberDeclContext>(_ctx, getState());
  enterRule(_localctx, 20, GlyphParser::RuleMemberDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(224);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<GlyphParser::MemberFieldContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(216);
      fieldDecl();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<GlyphParser::MemberFnContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(218);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GlyphParser::ID) {
        setState(217);
        match(GlyphParser::ID);
      }
      setState(221);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GlyphParser::AT) {
        setState(220);
        attrDecl();
      }
      setState(223);
      fnDecl();
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

//----------------- AttrDeclContext ------------------------------------------------------------------

GlyphParser::AttrDeclContext::AttrDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::AttrDeclContext::AT() {
  return getToken(GlyphParser::AT, 0);
}

tree::TerminalNode* GlyphParser::AttrDeclContext::ID() {
  return getToken(GlyphParser::ID, 0);
}


size_t GlyphParser::AttrDeclContext::getRuleIndex() const {
  return GlyphParser::RuleAttrDecl;
}


std::any GlyphParser::AttrDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitAttrDecl(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::AttrDeclContext* GlyphParser::attrDecl() {
  AttrDeclContext *_localctx = _tracker.createInstance<AttrDeclContext>(_ctx, getState());
  enterRule(_localctx, 22, GlyphParser::RuleAttrDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(226);
    match(GlyphParser::AT);
    setState(227);
    match(GlyphParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamListContext ------------------------------------------------------------------

GlyphParser::ParamListContext::ParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GlyphParser::ParamContext *> GlyphParser::ParamListContext::param() {
  return getRuleContexts<GlyphParser::ParamContext>();
}

GlyphParser::ParamContext* GlyphParser::ParamListContext::param(size_t i) {
  return getRuleContext<GlyphParser::ParamContext>(i);
}

std::vector<tree::TerminalNode *> GlyphParser::ParamListContext::COMMA() {
  return getTokens(GlyphParser::COMMA);
}

tree::TerminalNode* GlyphParser::ParamListContext::COMMA(size_t i) {
  return getToken(GlyphParser::COMMA, i);
}


size_t GlyphParser::ParamListContext::getRuleIndex() const {
  return GlyphParser::RuleParamList;
}


std::any GlyphParser::ParamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitParamList(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::ParamListContext* GlyphParser::paramList() {
  ParamListContext *_localctx = _tracker.createInstance<ParamListContext>(_ctx, getState());
  enterRule(_localctx, 24, GlyphParser::RuleParamList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(229);
    param();
    setState(234);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(230);
        match(GlyphParser::COMMA);
        setState(231);
        param(); 
      }
      setState(236);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
    setState(238);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::COMMA) {
      setState(237);
      match(GlyphParser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

GlyphParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::ParamContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

tree::TerminalNode* GlyphParser::ParamContext::COLON() {
  return getToken(GlyphParser::COLON, 0);
}

GlyphParser::TypeContext* GlyphParser::ParamContext::type() {
  return getRuleContext<GlyphParser::TypeContext>(0);
}


size_t GlyphParser::ParamContext::getRuleIndex() const {
  return GlyphParser::RuleParam;
}


std::any GlyphParser::ParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitParam(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::ParamContext* GlyphParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 26, GlyphParser::RuleParam);
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
    setState(241);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::T__9) {
      setState(240);
      match(GlyphParser::T__9);
    }
    setState(243);
    match(GlyphParser::ID);
    setState(244);
    match(GlyphParser::COLON);
    setState(245);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FnDeclContext ------------------------------------------------------------------

GlyphParser::FnDeclContext::FnDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::FnDeclContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

tree::TerminalNode* GlyphParser::FnDeclContext::LPAREN() {
  return getToken(GlyphParser::LPAREN, 0);
}

tree::TerminalNode* GlyphParser::FnDeclContext::RPAREN() {
  return getToken(GlyphParser::RPAREN, 0);
}

GlyphParser::BlockContext* GlyphParser::FnDeclContext::block() {
  return getRuleContext<GlyphParser::BlockContext>(0);
}

GlyphParser::GenericParamsContext* GlyphParser::FnDeclContext::genericParams() {
  return getRuleContext<GlyphParser::GenericParamsContext>(0);
}

GlyphParser::ParamListContext* GlyphParser::FnDeclContext::paramList() {
  return getRuleContext<GlyphParser::ParamListContext>(0);
}

GlyphParser::TypeContext* GlyphParser::FnDeclContext::type() {
  return getRuleContext<GlyphParser::TypeContext>(0);
}


size_t GlyphParser::FnDeclContext::getRuleIndex() const {
  return GlyphParser::RuleFnDecl;
}


std::any GlyphParser::FnDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitFnDecl(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::FnDeclContext* GlyphParser::fnDecl() {
  FnDeclContext *_localctx = _tracker.createInstance<FnDeclContext>(_ctx, getState());
  enterRule(_localctx, 28, GlyphParser::RuleFnDecl);
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
    setState(247);
    match(GlyphParser::T__10);
    setState(248);
    match(GlyphParser::ID);
    setState(250);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::LT) {
      setState(249);
      genericParams();
    }
    setState(252);
    match(GlyphParser::LPAREN);
    setState(254);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::T__9

    || _la == GlyphParser::ID) {
      setState(253);
      paramList();
    }
    setState(256);
    match(GlyphParser::RPAREN);
    setState(259);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::T__11) {
      setState(257);
      match(GlyphParser::T__11);
      setState(258);
      type();
    }
    setState(261);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

GlyphParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GlyphParser::TypeContext::getRuleIndex() const {
  return GlyphParser::RuleType;
}

void GlyphParser::TypeContext::copyFrom(TypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BuiltinTypeContext ------------------------------------------------------------------

GlyphParser::BuiltinTypeContext::BuiltinTypeContext(TypeContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::BuiltinTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitBuiltinType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NamedTypeContext ------------------------------------------------------------------

GlyphParser::TypeNameContext* GlyphParser::NamedTypeContext::typeName() {
  return getRuleContext<GlyphParser::TypeNameContext>(0);
}

GlyphParser::NamedTypeContext::NamedTypeContext(TypeContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::NamedTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitNamedType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ListTypeContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::ListTypeContext::LBRACKET() {
  return getToken(GlyphParser::LBRACKET, 0);
}

GlyphParser::TypeContext* GlyphParser::ListTypeContext::type() {
  return getRuleContext<GlyphParser::TypeContext>(0);
}

tree::TerminalNode* GlyphParser::ListTypeContext::RBRACKET() {
  return getToken(GlyphParser::RBRACKET, 0);
}

GlyphParser::ListTypeContext::ListTypeContext(TypeContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::ListTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitListType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ResultTypeContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::ResultTypeContext::NOT_OP() {
  return getToken(GlyphParser::NOT_OP, 0);
}

GlyphParser::TypeContext* GlyphParser::ResultTypeContext::type() {
  return getRuleContext<GlyphParser::TypeContext>(0);
}

GlyphParser::ResultTypeContext::ResultTypeContext(TypeContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::ResultTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitResultType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FnTypeContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::FnTypeContext::LPAREN() {
  return getToken(GlyphParser::LPAREN, 0);
}

tree::TerminalNode* GlyphParser::FnTypeContext::RPAREN() {
  return getToken(GlyphParser::RPAREN, 0);
}

GlyphParser::TypeListContext* GlyphParser::FnTypeContext::typeList() {
  return getRuleContext<GlyphParser::TypeListContext>(0);
}

GlyphParser::TypeContext* GlyphParser::FnTypeContext::type() {
  return getRuleContext<GlyphParser::TypeContext>(0);
}

GlyphParser::FnTypeContext::FnTypeContext(TypeContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::FnTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitFnType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OptionTypeContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::OptionTypeContext::QUEST() {
  return getToken(GlyphParser::QUEST, 0);
}

GlyphParser::TypeContext* GlyphParser::OptionTypeContext::type() {
  return getRuleContext<GlyphParser::TypeContext>(0);
}

GlyphParser::OptionTypeContext::OptionTypeContext(TypeContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::OptionTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitOptionType(this);
  else
    return visitor->visitChildren(this);
}
GlyphParser::TypeContext* GlyphParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 30, GlyphParser::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(283);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GlyphParser::T__12:
      case GlyphParser::T__13:
      case GlyphParser::T__14:
      case GlyphParser::T__15:
      case GlyphParser::T__16: {
        _localctx = _tracker.createInstance<GlyphParser::BuiltinTypeContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(263);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 253952) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case GlyphParser::LBRACKET: {
        _localctx = _tracker.createInstance<GlyphParser::ListTypeContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(264);
        match(GlyphParser::LBRACKET);
        setState(265);
        type();
        setState(266);
        match(GlyphParser::RBRACKET);
        break;
      }

      case GlyphParser::QUEST: {
        _localctx = _tracker.createInstance<GlyphParser::OptionTypeContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(268);
        match(GlyphParser::QUEST);
        setState(269);
        type();
        break;
      }

      case GlyphParser::NOT_OP: {
        _localctx = _tracker.createInstance<GlyphParser::ResultTypeContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(270);
        match(GlyphParser::NOT_OP);
        setState(271);
        type();
        break;
      }

      case GlyphParser::T__10: {
        _localctx = _tracker.createInstance<GlyphParser::FnTypeContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(272);
        match(GlyphParser::T__10);
        setState(273);
        match(GlyphParser::LPAREN);
        setState(275);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 11) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 11)) & 1155175503578005629) != 0)) {
          setState(274);
          typeList();
        }
        setState(277);
        match(GlyphParser::RPAREN);
        setState(280);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == GlyphParser::T__11) {
          setState(278);
          match(GlyphParser::T__11);
          setState(279);
          type();
        }
        break;
      }

      case GlyphParser::ID: {
        _localctx = _tracker.createInstance<GlyphParser::NamedTypeContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(282);
        typeName();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

GlyphParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GlyphParser::QualifiedNameContext* GlyphParser::TypeNameContext::qualifiedName() {
  return getRuleContext<GlyphParser::QualifiedNameContext>(0);
}

GlyphParser::GenericArgsContext* GlyphParser::TypeNameContext::genericArgs() {
  return getRuleContext<GlyphParser::GenericArgsContext>(0);
}


size_t GlyphParser::TypeNameContext::getRuleIndex() const {
  return GlyphParser::RuleTypeName;
}


std::any GlyphParser::TypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitTypeName(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::TypeNameContext* GlyphParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 32, GlyphParser::RuleTypeName);
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
    setState(285);
    qualifiedName();
    setState(287);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::LT) {
      setState(286);
      genericArgs();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QualifiedNameContext ------------------------------------------------------------------

GlyphParser::QualifiedNameContext::QualifiedNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GlyphParser::QualifiedNameContext::ID() {
  return getTokens(GlyphParser::ID);
}

tree::TerminalNode* GlyphParser::QualifiedNameContext::ID(size_t i) {
  return getToken(GlyphParser::ID, i);
}

std::vector<tree::TerminalNode *> GlyphParser::QualifiedNameContext::DOT() {
  return getTokens(GlyphParser::DOT);
}

tree::TerminalNode* GlyphParser::QualifiedNameContext::DOT(size_t i) {
  return getToken(GlyphParser::DOT, i);
}


size_t GlyphParser::QualifiedNameContext::getRuleIndex() const {
  return GlyphParser::RuleQualifiedName;
}


std::any GlyphParser::QualifiedNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitQualifiedName(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::QualifiedNameContext* GlyphParser::qualifiedName() {
  QualifiedNameContext *_localctx = _tracker.createInstance<QualifiedNameContext>(_ctx, getState());
  enterRule(_localctx, 34, GlyphParser::RuleQualifiedName);
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
    setState(289);
    match(GlyphParser::ID);
    setState(294);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GlyphParser::DOT) {
      setState(290);
      match(GlyphParser::DOT);
      setState(291);
      match(GlyphParser::ID);
      setState(296);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GenericParamsContext ------------------------------------------------------------------

GlyphParser::GenericParamsContext::GenericParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::GenericParamsContext::LT() {
  return getToken(GlyphParser::LT, 0);
}

std::vector<tree::TerminalNode *> GlyphParser::GenericParamsContext::ID() {
  return getTokens(GlyphParser::ID);
}

tree::TerminalNode* GlyphParser::GenericParamsContext::ID(size_t i) {
  return getToken(GlyphParser::ID, i);
}

tree::TerminalNode* GlyphParser::GenericParamsContext::GT() {
  return getToken(GlyphParser::GT, 0);
}

std::vector<tree::TerminalNode *> GlyphParser::GenericParamsContext::COMMA() {
  return getTokens(GlyphParser::COMMA);
}

tree::TerminalNode* GlyphParser::GenericParamsContext::COMMA(size_t i) {
  return getToken(GlyphParser::COMMA, i);
}


size_t GlyphParser::GenericParamsContext::getRuleIndex() const {
  return GlyphParser::RuleGenericParams;
}


std::any GlyphParser::GenericParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitGenericParams(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::GenericParamsContext* GlyphParser::genericParams() {
  GenericParamsContext *_localctx = _tracker.createInstance<GenericParamsContext>(_ctx, getState());
  enterRule(_localctx, 36, GlyphParser::RuleGenericParams);
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
    setState(297);
    match(GlyphParser::LT);
    setState(298);
    match(GlyphParser::ID);
    setState(303);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GlyphParser::COMMA) {
      setState(299);
      match(GlyphParser::COMMA);
      setState(300);
      match(GlyphParser::ID);
      setState(305);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(306);
    match(GlyphParser::GT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GenericArgsContext ------------------------------------------------------------------

GlyphParser::GenericArgsContext::GenericArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::GenericArgsContext::LT() {
  return getToken(GlyphParser::LT, 0);
}

std::vector<GlyphParser::TypeContext *> GlyphParser::GenericArgsContext::type() {
  return getRuleContexts<GlyphParser::TypeContext>();
}

GlyphParser::TypeContext* GlyphParser::GenericArgsContext::type(size_t i) {
  return getRuleContext<GlyphParser::TypeContext>(i);
}

tree::TerminalNode* GlyphParser::GenericArgsContext::GT() {
  return getToken(GlyphParser::GT, 0);
}

std::vector<tree::TerminalNode *> GlyphParser::GenericArgsContext::COMMA() {
  return getTokens(GlyphParser::COMMA);
}

tree::TerminalNode* GlyphParser::GenericArgsContext::COMMA(size_t i) {
  return getToken(GlyphParser::COMMA, i);
}


size_t GlyphParser::GenericArgsContext::getRuleIndex() const {
  return GlyphParser::RuleGenericArgs;
}


std::any GlyphParser::GenericArgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitGenericArgs(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::GenericArgsContext* GlyphParser::genericArgs() {
  GenericArgsContext *_localctx = _tracker.createInstance<GenericArgsContext>(_ctx, getState());
  enterRule(_localctx, 38, GlyphParser::RuleGenericArgs);
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
    setState(308);
    match(GlyphParser::LT);
    setState(309);
    type();
    setState(314);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GlyphParser::COMMA) {
      setState(310);
      match(GlyphParser::COMMA);
      setState(311);
      type();
      setState(316);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(317);
    match(GlyphParser::GT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeListContext ------------------------------------------------------------------

GlyphParser::TypeListContext::TypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GlyphParser::TypeContext *> GlyphParser::TypeListContext::type() {
  return getRuleContexts<GlyphParser::TypeContext>();
}

GlyphParser::TypeContext* GlyphParser::TypeListContext::type(size_t i) {
  return getRuleContext<GlyphParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> GlyphParser::TypeListContext::COMMA() {
  return getTokens(GlyphParser::COMMA);
}

tree::TerminalNode* GlyphParser::TypeListContext::COMMA(size_t i) {
  return getToken(GlyphParser::COMMA, i);
}


size_t GlyphParser::TypeListContext::getRuleIndex() const {
  return GlyphParser::RuleTypeList;
}


std::any GlyphParser::TypeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitTypeList(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::TypeListContext* GlyphParser::typeList() {
  TypeListContext *_localctx = _tracker.createInstance<TypeListContext>(_ctx, getState());
  enterRule(_localctx, 40, GlyphParser::RuleTypeList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(319);
    type();
    setState(324);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(320);
        match(GlyphParser::COMMA);
        setState(321);
        type(); 
      }
      setState(326);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    }
    setState(328);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::COMMA) {
      setState(327);
      match(GlyphParser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

GlyphParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::BlockContext::LBRACE() {
  return getToken(GlyphParser::LBRACE, 0);
}

tree::TerminalNode* GlyphParser::BlockContext::RBRACE() {
  return getToken(GlyphParser::RBRACE, 0);
}

std::vector<GlyphParser::StmtContext *> GlyphParser::BlockContext::stmt() {
  return getRuleContexts<GlyphParser::StmtContext>();
}

GlyphParser::StmtContext* GlyphParser::BlockContext::stmt(size_t i) {
  return getRuleContext<GlyphParser::StmtContext>(i);
}


size_t GlyphParser::BlockContext::getRuleIndex() const {
  return GlyphParser::RuleBlock;
}


std::any GlyphParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::BlockContext* GlyphParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 42, GlyphParser::RuleBlock);
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
    setState(330);
    match(GlyphParser::LBRACE);
    setState(334);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 4) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 4)) & 1517994583757603009) != 0)) {
      setState(331);
      stmt();
      setState(336);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(337);
    match(GlyphParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

GlyphParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GlyphParser::StmtContext::getRuleIndex() const {
  return GlyphParser::RuleStmt;
}

void GlyphParser::StmtContext::copyFrom(StmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StmtReturnContext ------------------------------------------------------------------

GlyphParser::ReturnStmtContext* GlyphParser::StmtReturnContext::returnStmt() {
  return getRuleContext<GlyphParser::ReturnStmtContext>(0);
}

GlyphParser::StmtReturnContext::StmtReturnContext(StmtContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::StmtReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitStmtReturn(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtMatchContext ------------------------------------------------------------------

GlyphParser::MatchStmtContext* GlyphParser::StmtMatchContext::matchStmt() {
  return getRuleContext<GlyphParser::MatchStmtContext>(0);
}

GlyphParser::StmtMatchContext::StmtMatchContext(StmtContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::StmtMatchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitStmtMatch(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtVarContext ------------------------------------------------------------------

GlyphParser::VarStmtContext* GlyphParser::StmtVarContext::varStmt() {
  return getRuleContext<GlyphParser::VarStmtContext>(0);
}

GlyphParser::StmtVarContext::StmtVarContext(StmtContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::StmtVarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitStmtVar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtBlockContext ------------------------------------------------------------------

GlyphParser::BlockContext* GlyphParser::StmtBlockContext::block() {
  return getRuleContext<GlyphParser::BlockContext>(0);
}

GlyphParser::StmtBlockContext::StmtBlockContext(StmtContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::StmtBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitStmtBlock(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtExprContext ------------------------------------------------------------------

GlyphParser::ExprStmtContext* GlyphParser::StmtExprContext::exprStmt() {
  return getRuleContext<GlyphParser::ExprStmtContext>(0);
}

GlyphParser::StmtExprContext::StmtExprContext(StmtContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::StmtExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitStmtExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtWhileContext ------------------------------------------------------------------

GlyphParser::WhileStmtContext* GlyphParser::StmtWhileContext::whileStmt() {
  return getRuleContext<GlyphParser::WhileStmtContext>(0);
}

GlyphParser::StmtWhileContext::StmtWhileContext(StmtContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::StmtWhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitStmtWhile(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtForContext ------------------------------------------------------------------

GlyphParser::ForStmtContext* GlyphParser::StmtForContext::forStmt() {
  return getRuleContext<GlyphParser::ForStmtContext>(0);
}

GlyphParser::StmtForContext::StmtForContext(StmtContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::StmtForContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitStmtFor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtIfContext ------------------------------------------------------------------

GlyphParser::IfStmtContext* GlyphParser::StmtIfContext::ifStmt() {
  return getRuleContext<GlyphParser::IfStmtContext>(0);
}

GlyphParser::StmtIfContext::StmtIfContext(StmtContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::StmtIfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitStmtIf(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtConstContext ------------------------------------------------------------------

GlyphParser::ConstStmtContext* GlyphParser::StmtConstContext::constStmt() {
  return getRuleContext<GlyphParser::ConstStmtContext>(0);
}

GlyphParser::StmtConstContext::StmtConstContext(StmtContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::StmtConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitStmtConst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StmtLetContext ------------------------------------------------------------------

GlyphParser::LetStmtContext* GlyphParser::StmtLetContext::letStmt() {
  return getRuleContext<GlyphParser::LetStmtContext>(0);
}

GlyphParser::StmtLetContext::StmtLetContext(StmtContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::StmtLetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitStmtLet(this);
  else
    return visitor->visitChildren(this);
}
GlyphParser::StmtContext* GlyphParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 44, GlyphParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(349);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GlyphParser::T__3: {
        _localctx = _tracker.createInstance<GlyphParser::StmtConstContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(339);
        constStmt();
        break;
      }

      case GlyphParser::T__17: {
        _localctx = _tracker.createInstance<GlyphParser::StmtLetContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(340);
        letStmt();
        break;
      }

      case GlyphParser::T__9: {
        _localctx = _tracker.createInstance<GlyphParser::StmtVarContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(341);
        varStmt();
        break;
      }

      case GlyphParser::T__10:
      case GlyphParser::T__25:
      case GlyphParser::T__26:
      case GlyphParser::T__27:
      case GlyphParser::T__28:
      case GlyphParser::T__30:
      case GlyphParser::T__31:
      case GlyphParser::T__32:
      case GlyphParser::T__33:
      case GlyphParser::DOUBLE_LITERAL:
      case GlyphParser::INT_LITERAL:
      case GlyphParser::STRING:
      case GlyphParser::ID:
      case GlyphParser::NOT_OP:
      case GlyphParser::MINUS:
      case GlyphParser::LPAREN:
      case GlyphParser::LBRACKET: {
        _localctx = _tracker.createInstance<GlyphParser::StmtExprContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(342);
        exprStmt();
        break;
      }

      case GlyphParser::LBRACE: {
        _localctx = _tracker.createInstance<GlyphParser::StmtBlockContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(343);
        block();
        break;
      }

      case GlyphParser::T__18: {
        _localctx = _tracker.createInstance<GlyphParser::StmtIfContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(344);
        ifStmt();
        break;
      }

      case GlyphParser::T__20: {
        _localctx = _tracker.createInstance<GlyphParser::StmtWhileContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(345);
        whileStmt();
        break;
      }

      case GlyphParser::T__21: {
        _localctx = _tracker.createInstance<GlyphParser::StmtForContext>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(346);
        forStmt();
        break;
      }

      case GlyphParser::T__23: {
        _localctx = _tracker.createInstance<GlyphParser::StmtMatchContext>(_localctx);
        enterOuterAlt(_localctx, 9);
        setState(347);
        matchStmt();
        break;
      }

      case GlyphParser::T__29: {
        _localctx = _tracker.createInstance<GlyphParser::StmtReturnContext>(_localctx);
        enterOuterAlt(_localctx, 10);
        setState(348);
        returnStmt();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstStmtContext ------------------------------------------------------------------

GlyphParser::ConstStmtContext::ConstStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::ConstStmtContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

tree::TerminalNode* GlyphParser::ConstStmtContext::ASSIGN() {
  return getToken(GlyphParser::ASSIGN, 0);
}

GlyphParser::ExprContext* GlyphParser::ConstStmtContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

tree::TerminalNode* GlyphParser::ConstStmtContext::COLON() {
  return getToken(GlyphParser::COLON, 0);
}

GlyphParser::TypeContext* GlyphParser::ConstStmtContext::type() {
  return getRuleContext<GlyphParser::TypeContext>(0);
}


size_t GlyphParser::ConstStmtContext::getRuleIndex() const {
  return GlyphParser::RuleConstStmt;
}


std::any GlyphParser::ConstStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitConstStmt(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::ConstStmtContext* GlyphParser::constStmt() {
  ConstStmtContext *_localctx = _tracker.createInstance<ConstStmtContext>(_ctx, getState());
  enterRule(_localctx, 46, GlyphParser::RuleConstStmt);
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
    setState(351);
    match(GlyphParser::T__3);
    setState(352);
    match(GlyphParser::ID);
    setState(355);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::COLON) {
      setState(353);
      match(GlyphParser::COLON);
      setState(354);
      type();
    }
    setState(357);
    match(GlyphParser::ASSIGN);
    setState(358);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LetStmtContext ------------------------------------------------------------------

GlyphParser::LetStmtContext::LetStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::LetStmtContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

tree::TerminalNode* GlyphParser::LetStmtContext::ASSIGN() {
  return getToken(GlyphParser::ASSIGN, 0);
}

GlyphParser::ExprContext* GlyphParser::LetStmtContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

tree::TerminalNode* GlyphParser::LetStmtContext::COLON() {
  return getToken(GlyphParser::COLON, 0);
}

GlyphParser::TypeContext* GlyphParser::LetStmtContext::type() {
  return getRuleContext<GlyphParser::TypeContext>(0);
}


size_t GlyphParser::LetStmtContext::getRuleIndex() const {
  return GlyphParser::RuleLetStmt;
}


std::any GlyphParser::LetStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitLetStmt(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::LetStmtContext* GlyphParser::letStmt() {
  LetStmtContext *_localctx = _tracker.createInstance<LetStmtContext>(_ctx, getState());
  enterRule(_localctx, 48, GlyphParser::RuleLetStmt);
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
    setState(360);
    match(GlyphParser::T__17);
    setState(361);
    match(GlyphParser::ID);
    setState(364);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::COLON) {
      setState(362);
      match(GlyphParser::COLON);
      setState(363);
      type();
    }
    setState(366);
    match(GlyphParser::ASSIGN);
    setState(367);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarStmtContext ------------------------------------------------------------------

GlyphParser::VarStmtContext::VarStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::VarStmtContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

tree::TerminalNode* GlyphParser::VarStmtContext::COLON() {
  return getToken(GlyphParser::COLON, 0);
}

GlyphParser::TypeContext* GlyphParser::VarStmtContext::type() {
  return getRuleContext<GlyphParser::TypeContext>(0);
}

tree::TerminalNode* GlyphParser::VarStmtContext::ASSIGN() {
  return getToken(GlyphParser::ASSIGN, 0);
}

GlyphParser::ExprContext* GlyphParser::VarStmtContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}


size_t GlyphParser::VarStmtContext::getRuleIndex() const {
  return GlyphParser::RuleVarStmt;
}


std::any GlyphParser::VarStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitVarStmt(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::VarStmtContext* GlyphParser::varStmt() {
  VarStmtContext *_localctx = _tracker.createInstance<VarStmtContext>(_ctx, getState());
  enterRule(_localctx, 50, GlyphParser::RuleVarStmt);
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
    setState(369);
    match(GlyphParser::T__9);
    setState(370);
    match(GlyphParser::ID);
    setState(373);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::COLON) {
      setState(371);
      match(GlyphParser::COLON);
      setState(372);
      type();
    }
    setState(377);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::ASSIGN) {
      setState(375);
      match(GlyphParser::ASSIGN);
      setState(376);
      expr();
    }
   
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

GlyphParser::ExprOrAssignContext* GlyphParser::ExprStmtContext::exprOrAssign() {
  return getRuleContext<GlyphParser::ExprOrAssignContext>(0);
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
  enterRule(_localctx, 52, GlyphParser::RuleExprStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(379);
    exprOrAssign();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

GlyphParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GlyphParser::ExprContext* GlyphParser::IfStmtContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

std::vector<GlyphParser::BlockContext *> GlyphParser::IfStmtContext::block() {
  return getRuleContexts<GlyphParser::BlockContext>();
}

GlyphParser::BlockContext* GlyphParser::IfStmtContext::block(size_t i) {
  return getRuleContext<GlyphParser::BlockContext>(i);
}

GlyphParser::IfStmtContext* GlyphParser::IfStmtContext::ifStmt() {
  return getRuleContext<GlyphParser::IfStmtContext>(0);
}


size_t GlyphParser::IfStmtContext::getRuleIndex() const {
  return GlyphParser::RuleIfStmt;
}


std::any GlyphParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::IfStmtContext* GlyphParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 54, GlyphParser::RuleIfStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(381);
    match(GlyphParser::T__18);
    setState(382);
    expr();
    setState(383);
    block();
    setState(388);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      setState(384);
      match(GlyphParser::T__19);
      setState(385);
      ifStmt();
      break;
    }

    case 2: {
      setState(386);
      match(GlyphParser::T__19);
      setState(387);
      block();
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

//----------------- WhileStmtContext ------------------------------------------------------------------

GlyphParser::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GlyphParser::ExprContext* GlyphParser::WhileStmtContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

GlyphParser::BlockContext* GlyphParser::WhileStmtContext::block() {
  return getRuleContext<GlyphParser::BlockContext>(0);
}


size_t GlyphParser::WhileStmtContext::getRuleIndex() const {
  return GlyphParser::RuleWhileStmt;
}


std::any GlyphParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::WhileStmtContext* GlyphParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 56, GlyphParser::RuleWhileStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(390);
    match(GlyphParser::T__20);
    setState(391);
    expr();
    setState(392);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStmtContext ------------------------------------------------------------------

GlyphParser::ForStmtContext::ForStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GlyphParser::ForStmtContext::getRuleIndex() const {
  return GlyphParser::RuleForStmt;
}

void GlyphParser::ForStmtContext::copyFrom(ForStmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NumericForContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> GlyphParser::NumericForContext::SEMICOLON() {
  return getTokens(GlyphParser::SEMICOLON);
}

tree::TerminalNode* GlyphParser::NumericForContext::SEMICOLON(size_t i) {
  return getToken(GlyphParser::SEMICOLON, i);
}

GlyphParser::BlockContext* GlyphParser::NumericForContext::block() {
  return getRuleContext<GlyphParser::BlockContext>(0);
}

GlyphParser::ForInitContext* GlyphParser::NumericForContext::forInit() {
  return getRuleContext<GlyphParser::ForInitContext>(0);
}

GlyphParser::ExprContext* GlyphParser::NumericForContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

GlyphParser::ForUpdateContext* GlyphParser::NumericForContext::forUpdate() {
  return getRuleContext<GlyphParser::ForUpdateContext>(0);
}

GlyphParser::NumericForContext::NumericForContext(ForStmtContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::NumericForContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitNumericFor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForEachContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::ForEachContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

GlyphParser::ExprContext* GlyphParser::ForEachContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

GlyphParser::BlockContext* GlyphParser::ForEachContext::block() {
  return getRuleContext<GlyphParser::BlockContext>(0);
}

GlyphParser::ForEachContext::ForEachContext(ForStmtContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::ForEachContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitForEach(this);
  else
    return visitor->visitChildren(this);
}
GlyphParser::ForStmtContext* GlyphParser::forStmt() {
  ForStmtContext *_localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
  enterRule(_localctx, 58, GlyphParser::RuleForStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(413);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<GlyphParser::ForEachContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(394);
      match(GlyphParser::T__21);
      setState(395);
      match(GlyphParser::ID);
      setState(396);
      match(GlyphParser::T__22);
      setState(397);
      expr();
      setState(398);
      block();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<GlyphParser::NumericForContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(400);
      match(GlyphParser::T__21);
      setState(402);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 5841169265314761744) != 0)) {
        setState(401);
        forInit();
      }
      setState(404);
      match(GlyphParser::SEMICOLON);
      setState(406);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 5841169265314498560) != 0)) {
        setState(405);
        expr();
      }
      setState(408);
      match(GlyphParser::SEMICOLON);
      setState(410);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 5841169265314498560) != 0)) {
        setState(409);
        forUpdate();
      }
      setState(412);
      block();
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

//----------------- ForInitContext ------------------------------------------------------------------

GlyphParser::ForInitContext::ForInitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GlyphParser::LetStmtContext* GlyphParser::ForInitContext::letStmt() {
  return getRuleContext<GlyphParser::LetStmtContext>(0);
}

GlyphParser::VarStmtContext* GlyphParser::ForInitContext::varStmt() {
  return getRuleContext<GlyphParser::VarStmtContext>(0);
}

GlyphParser::ConstStmtContext* GlyphParser::ForInitContext::constStmt() {
  return getRuleContext<GlyphParser::ConstStmtContext>(0);
}

GlyphParser::ExprOrAssignContext* GlyphParser::ForInitContext::exprOrAssign() {
  return getRuleContext<GlyphParser::ExprOrAssignContext>(0);
}


size_t GlyphParser::ForInitContext::getRuleIndex() const {
  return GlyphParser::RuleForInit;
}


std::any GlyphParser::ForInitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitForInit(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::ForInitContext* GlyphParser::forInit() {
  ForInitContext *_localctx = _tracker.createInstance<ForInitContext>(_ctx, getState());
  enterRule(_localctx, 60, GlyphParser::RuleForInit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(419);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GlyphParser::T__17: {
        enterOuterAlt(_localctx, 1);
        setState(415);
        letStmt();
        break;
      }

      case GlyphParser::T__9: {
        enterOuterAlt(_localctx, 2);
        setState(416);
        varStmt();
        break;
      }

      case GlyphParser::T__3: {
        enterOuterAlt(_localctx, 3);
        setState(417);
        constStmt();
        break;
      }

      case GlyphParser::T__10:
      case GlyphParser::T__25:
      case GlyphParser::T__26:
      case GlyphParser::T__27:
      case GlyphParser::T__28:
      case GlyphParser::T__30:
      case GlyphParser::T__31:
      case GlyphParser::T__32:
      case GlyphParser::T__33:
      case GlyphParser::DOUBLE_LITERAL:
      case GlyphParser::INT_LITERAL:
      case GlyphParser::STRING:
      case GlyphParser::ID:
      case GlyphParser::NOT_OP:
      case GlyphParser::MINUS:
      case GlyphParser::LPAREN:
      case GlyphParser::LBRACKET: {
        enterOuterAlt(_localctx, 4);
        setState(418);
        exprOrAssign();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForUpdateContext ------------------------------------------------------------------

GlyphParser::ForUpdateContext::ForUpdateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GlyphParser::ExprOrAssignContext* GlyphParser::ForUpdateContext::exprOrAssign() {
  return getRuleContext<GlyphParser::ExprOrAssignContext>(0);
}


size_t GlyphParser::ForUpdateContext::getRuleIndex() const {
  return GlyphParser::RuleForUpdate;
}


std::any GlyphParser::ForUpdateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitForUpdate(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::ForUpdateContext* GlyphParser::forUpdate() {
  ForUpdateContext *_localctx = _tracker.createInstance<ForUpdateContext>(_ctx, getState());
  enterRule(_localctx, 62, GlyphParser::RuleForUpdate);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(421);
    exprOrAssign();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MatchStmtContext ------------------------------------------------------------------

GlyphParser::MatchStmtContext::MatchStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GlyphParser::ExprContext* GlyphParser::MatchStmtContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

tree::TerminalNode* GlyphParser::MatchStmtContext::LBRACE() {
  return getToken(GlyphParser::LBRACE, 0);
}

tree::TerminalNode* GlyphParser::MatchStmtContext::RBRACE() {
  return getToken(GlyphParser::RBRACE, 0);
}

std::vector<GlyphParser::MatchArmContext *> GlyphParser::MatchStmtContext::matchArm() {
  return getRuleContexts<GlyphParser::MatchArmContext>();
}

GlyphParser::MatchArmContext* GlyphParser::MatchStmtContext::matchArm(size_t i) {
  return getRuleContext<GlyphParser::MatchArmContext>(i);
}


size_t GlyphParser::MatchStmtContext::getRuleIndex() const {
  return GlyphParser::RuleMatchStmt;
}


std::any GlyphParser::MatchStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitMatchStmt(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::MatchStmtContext* GlyphParser::matchStmt() {
  MatchStmtContext *_localctx = _tracker.createInstance<MatchStmtContext>(_ctx, getState());
  enterRule(_localctx, 64, GlyphParser::RuleMatchStmt);
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
    setState(423);
    match(GlyphParser::T__23);
    setState(424);
    expr();
    setState(425);
    match(GlyphParser::LBRACE);
    setState(429);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 26) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 26)) & 140737488358415) != 0)) {
      setState(426);
      matchArm();
      setState(431);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(432);
    match(GlyphParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MatchArmContext ------------------------------------------------------------------

GlyphParser::MatchArmContext::MatchArmContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GlyphParser::PatternContext* GlyphParser::MatchArmContext::pattern() {
  return getRuleContext<GlyphParser::PatternContext>(0);
}

GlyphParser::BlockContext* GlyphParser::MatchArmContext::block() {
  return getRuleContext<GlyphParser::BlockContext>(0);
}

std::vector<GlyphParser::ExprContext *> GlyphParser::MatchArmContext::expr() {
  return getRuleContexts<GlyphParser::ExprContext>();
}

GlyphParser::ExprContext* GlyphParser::MatchArmContext::expr(size_t i) {
  return getRuleContext<GlyphParser::ExprContext>(i);
}

tree::TerminalNode* GlyphParser::MatchArmContext::COMMA() {
  return getToken(GlyphParser::COMMA, 0);
}


size_t GlyphParser::MatchArmContext::getRuleIndex() const {
  return GlyphParser::RuleMatchArm;
}


std::any GlyphParser::MatchArmContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitMatchArm(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::MatchArmContext* GlyphParser::matchArm() {
  MatchArmContext *_localctx = _tracker.createInstance<MatchArmContext>(_ctx, getState());
  enterRule(_localctx, 66, GlyphParser::RuleMatchArm);
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
    setState(434);
    pattern();
    setState(437);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::T__18) {
      setState(435);
      match(GlyphParser::T__18);
      setState(436);
      expr();
    }
    setState(439);
    match(GlyphParser::T__24);
    setState(442);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GlyphParser::LBRACE: {
        setState(440);
        block();
        break;
      }

      case GlyphParser::T__10:
      case GlyphParser::T__25:
      case GlyphParser::T__26:
      case GlyphParser::T__27:
      case GlyphParser::T__28:
      case GlyphParser::T__30:
      case GlyphParser::T__31:
      case GlyphParser::T__32:
      case GlyphParser::T__33:
      case GlyphParser::DOUBLE_LITERAL:
      case GlyphParser::INT_LITERAL:
      case GlyphParser::STRING:
      case GlyphParser::ID:
      case GlyphParser::NOT_OP:
      case GlyphParser::MINUS:
      case GlyphParser::LPAREN:
      case GlyphParser::LBRACKET: {
        setState(441);
        expr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(445);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::COMMA) {
      setState(444);
      match(GlyphParser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PatternContext ------------------------------------------------------------------

GlyphParser::PatternContext::PatternContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GlyphParser::PatternContext::getRuleIndex() const {
  return GlyphParser::RulePattern;
}

void GlyphParser::PatternContext::copyFrom(PatternContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SomePatContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::SomePatContext::LPAREN() {
  return getToken(GlyphParser::LPAREN, 0);
}

tree::TerminalNode* GlyphParser::SomePatContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

tree::TerminalNode* GlyphParser::SomePatContext::RPAREN() {
  return getToken(GlyphParser::RPAREN, 0);
}

GlyphParser::SomePatContext::SomePatContext(PatternContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::SomePatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitSomePat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntPatContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::IntPatContext::INT_LITERAL() {
  return getToken(GlyphParser::INT_LITERAL, 0);
}

GlyphParser::IntPatContext::IntPatContext(PatternContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::IntPatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitIntPat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NonePatContext ------------------------------------------------------------------

GlyphParser::NonePatContext::NonePatContext(PatternContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::NonePatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitNonePat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ErrPatContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::ErrPatContext::LPAREN() {
  return getToken(GlyphParser::LPAREN, 0);
}

tree::TerminalNode* GlyphParser::ErrPatContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

tree::TerminalNode* GlyphParser::ErrPatContext::RPAREN() {
  return getToken(GlyphParser::RPAREN, 0);
}

GlyphParser::ErrPatContext::ErrPatContext(PatternContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::ErrPatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitErrPat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WildcardPatContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::WildcardPatContext::UNDERSCORE() {
  return getToken(GlyphParser::UNDERSCORE, 0);
}

GlyphParser::WildcardPatContext::WildcardPatContext(PatternContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::WildcardPatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitWildcardPat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StrPatContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::StrPatContext::STRING() {
  return getToken(GlyphParser::STRING, 0);
}

GlyphParser::StrPatContext::StrPatContext(PatternContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::StrPatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitStrPat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OkPatContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::OkPatContext::LPAREN() {
  return getToken(GlyphParser::LPAREN, 0);
}

tree::TerminalNode* GlyphParser::OkPatContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

tree::TerminalNode* GlyphParser::OkPatContext::RPAREN() {
  return getToken(GlyphParser::RPAREN, 0);
}

GlyphParser::OkPatContext::OkPatContext(PatternContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::OkPatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitOkPat(this);
  else
    return visitor->visitChildren(this);
}
GlyphParser::PatternContext* GlyphParser::pattern() {
  PatternContext *_localctx = _tracker.createInstance<PatternContext>(_ctx, getState());
  enterRule(_localctx, 68, GlyphParser::RulePattern);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(463);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GlyphParser::UNDERSCORE: {
        _localctx = _tracker.createInstance<GlyphParser::WildcardPatContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(447);
        match(GlyphParser::UNDERSCORE);
        break;
      }

      case GlyphParser::T__25: {
        _localctx = _tracker.createInstance<GlyphParser::SomePatContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(448);
        match(GlyphParser::T__25);
        setState(449);
        match(GlyphParser::LPAREN);
        setState(450);
        match(GlyphParser::ID);
        setState(451);
        match(GlyphParser::RPAREN);
        break;
      }

      case GlyphParser::T__26: {
        _localctx = _tracker.createInstance<GlyphParser::NonePatContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(452);
        match(GlyphParser::T__26);
        break;
      }

      case GlyphParser::T__27: {
        _localctx = _tracker.createInstance<GlyphParser::OkPatContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(453);
        match(GlyphParser::T__27);
        setState(454);
        match(GlyphParser::LPAREN);
        setState(455);
        match(GlyphParser::ID);
        setState(456);
        match(GlyphParser::RPAREN);
        break;
      }

      case GlyphParser::T__28: {
        _localctx = _tracker.createInstance<GlyphParser::ErrPatContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(457);
        match(GlyphParser::T__28);
        setState(458);
        match(GlyphParser::LPAREN);
        setState(459);
        match(GlyphParser::ID);
        setState(460);
        match(GlyphParser::RPAREN);
        break;
      }

      case GlyphParser::INT_LITERAL: {
        _localctx = _tracker.createInstance<GlyphParser::IntPatContext>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(461);
        match(GlyphParser::INT_LITERAL);
        break;
      }

      case GlyphParser::STRING: {
        _localctx = _tracker.createInstance<GlyphParser::StrPatContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(462);
        match(GlyphParser::STRING);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

GlyphParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GlyphParser::ExprContext* GlyphParser::ReturnStmtContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}


size_t GlyphParser::ReturnStmtContext::getRuleIndex() const {
  return GlyphParser::RuleReturnStmt;
}


std::any GlyphParser::ReturnStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitReturnStmt(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::ReturnStmtContext* GlyphParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 70, GlyphParser::RuleReturnStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(465);
    match(GlyphParser::T__29);
    setState(467);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx)) {
    case 1: {
      setState(466);
      expr();
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

//----------------- ExprContext ------------------------------------------------------------------

GlyphParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GlyphParser::TernaryExprContext* GlyphParser::ExprContext::ternaryExpr() {
  return getRuleContext<GlyphParser::TernaryExprContext>(0);
}


size_t GlyphParser::ExprContext::getRuleIndex() const {
  return GlyphParser::RuleExpr;
}


std::any GlyphParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::ExprContext* GlyphParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 72, GlyphParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(469);
    ternaryExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprOrAssignContext ------------------------------------------------------------------

GlyphParser::ExprOrAssignContext::ExprOrAssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GlyphParser::ExprOrAssignContext::getRuleIndex() const {
  return GlyphParser::RuleExprOrAssign;
}

void GlyphParser::ExprOrAssignContext::copyFrom(ExprOrAssignContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SimpleAssignContext ------------------------------------------------------------------

GlyphParser::UnaryExprContext* GlyphParser::SimpleAssignContext::unaryExpr() {
  return getRuleContext<GlyphParser::UnaryExprContext>(0);
}

tree::TerminalNode* GlyphParser::SimpleAssignContext::ASSIGN() {
  return getToken(GlyphParser::ASSIGN, 0);
}

GlyphParser::ExprContext* GlyphParser::SimpleAssignContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

GlyphParser::SimpleAssignContext::SimpleAssignContext(ExprOrAssignContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::SimpleAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitSimpleAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlainExprContext ------------------------------------------------------------------

GlyphParser::ExprContext* GlyphParser::PlainExprContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

GlyphParser::PlainExprContext::PlainExprContext(ExprOrAssignContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::PlainExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitPlainExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CompoundAssignContext ------------------------------------------------------------------

GlyphParser::UnaryExprContext* GlyphParser::CompoundAssignContext::unaryExpr() {
  return getRuleContext<GlyphParser::UnaryExprContext>(0);
}

GlyphParser::ExprContext* GlyphParser::CompoundAssignContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

tree::TerminalNode* GlyphParser::CompoundAssignContext::PLUS_ASSIGN() {
  return getToken(GlyphParser::PLUS_ASSIGN, 0);
}

tree::TerminalNode* GlyphParser::CompoundAssignContext::MINUS_ASSIGN() {
  return getToken(GlyphParser::MINUS_ASSIGN, 0);
}

tree::TerminalNode* GlyphParser::CompoundAssignContext::STAR_ASSIGN() {
  return getToken(GlyphParser::STAR_ASSIGN, 0);
}

tree::TerminalNode* GlyphParser::CompoundAssignContext::SLASH_ASSIGN() {
  return getToken(GlyphParser::SLASH_ASSIGN, 0);
}

tree::TerminalNode* GlyphParser::CompoundAssignContext::PERCENT_ASSIGN() {
  return getToken(GlyphParser::PERCENT_ASSIGN, 0);
}

GlyphParser::CompoundAssignContext::CompoundAssignContext(ExprOrAssignContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::CompoundAssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitCompoundAssign(this);
  else
    return visitor->visitChildren(this);
}
GlyphParser::ExprOrAssignContext* GlyphParser::exprOrAssign() {
  ExprOrAssignContext *_localctx = _tracker.createInstance<ExprOrAssignContext>(_ctx, getState());
  enterRule(_localctx, 74, GlyphParser::RuleExprOrAssign);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(480);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<GlyphParser::CompoundAssignContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(471);
      unaryExpr();
      setState(472);
      antlrcpp::downCast<CompoundAssignContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 17042430230528) != 0))) {
        antlrcpp::downCast<CompoundAssignContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(473);
      expr();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<GlyphParser::SimpleAssignContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(475);
      unaryExpr();
      setState(476);
      match(GlyphParser::ASSIGN);
      setState(477);
      expr();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<GlyphParser::PlainExprContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(479);
      expr();
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

//----------------- TernaryExprContext ------------------------------------------------------------------

GlyphParser::TernaryExprContext::TernaryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GlyphParser::OrExprContext *> GlyphParser::TernaryExprContext::orExpr() {
  return getRuleContexts<GlyphParser::OrExprContext>();
}

GlyphParser::OrExprContext* GlyphParser::TernaryExprContext::orExpr(size_t i) {
  return getRuleContext<GlyphParser::OrExprContext>(i);
}

tree::TerminalNode* GlyphParser::TernaryExprContext::QUEST() {
  return getToken(GlyphParser::QUEST, 0);
}

tree::TerminalNode* GlyphParser::TernaryExprContext::COLON() {
  return getToken(GlyphParser::COLON, 0);
}

GlyphParser::TernaryExprContext* GlyphParser::TernaryExprContext::ternaryExpr() {
  return getRuleContext<GlyphParser::TernaryExprContext>(0);
}


size_t GlyphParser::TernaryExprContext::getRuleIndex() const {
  return GlyphParser::RuleTernaryExpr;
}


std::any GlyphParser::TernaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitTernaryExpr(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::TernaryExprContext* GlyphParser::ternaryExpr() {
  TernaryExprContext *_localctx = _tracker.createInstance<TernaryExprContext>(_ctx, getState());
  enterRule(_localctx, 76, GlyphParser::RuleTernaryExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(482);
    orExpr();
    setState(488);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      setState(483);
      match(GlyphParser::QUEST);
      setState(484);
      orExpr();
      setState(485);
      match(GlyphParser::COLON);
      setState(486);
      ternaryExpr();
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

//----------------- OrExprContext ------------------------------------------------------------------

GlyphParser::OrExprContext::OrExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GlyphParser::AndExprContext *> GlyphParser::OrExprContext::andExpr() {
  return getRuleContexts<GlyphParser::AndExprContext>();
}

GlyphParser::AndExprContext* GlyphParser::OrExprContext::andExpr(size_t i) {
  return getRuleContext<GlyphParser::AndExprContext>(i);
}

std::vector<tree::TerminalNode *> GlyphParser::OrExprContext::OR_OR() {
  return getTokens(GlyphParser::OR_OR);
}

tree::TerminalNode* GlyphParser::OrExprContext::OR_OR(size_t i) {
  return getToken(GlyphParser::OR_OR, i);
}


size_t GlyphParser::OrExprContext::getRuleIndex() const {
  return GlyphParser::RuleOrExpr;
}


std::any GlyphParser::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::OrExprContext* GlyphParser::orExpr() {
  OrExprContext *_localctx = _tracker.createInstance<OrExprContext>(_ctx, getState());
  enterRule(_localctx, 78, GlyphParser::RuleOrExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(490);
    andExpr();
    setState(495);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(491);
        match(GlyphParser::OR_OR);
        setState(492);
        andExpr(); 
      }
      setState(497);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AndExprContext ------------------------------------------------------------------

GlyphParser::AndExprContext::AndExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GlyphParser::EqualityExprContext *> GlyphParser::AndExprContext::equalityExpr() {
  return getRuleContexts<GlyphParser::EqualityExprContext>();
}

GlyphParser::EqualityExprContext* GlyphParser::AndExprContext::equalityExpr(size_t i) {
  return getRuleContext<GlyphParser::EqualityExprContext>(i);
}

std::vector<tree::TerminalNode *> GlyphParser::AndExprContext::AND_AND() {
  return getTokens(GlyphParser::AND_AND);
}

tree::TerminalNode* GlyphParser::AndExprContext::AND_AND(size_t i) {
  return getToken(GlyphParser::AND_AND, i);
}


size_t GlyphParser::AndExprContext::getRuleIndex() const {
  return GlyphParser::RuleAndExpr;
}


std::any GlyphParser::AndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitAndExpr(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::AndExprContext* GlyphParser::andExpr() {
  AndExprContext *_localctx = _tracker.createInstance<AndExprContext>(_ctx, getState());
  enterRule(_localctx, 80, GlyphParser::RuleAndExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(498);
    equalityExpr();
    setState(503);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(499);
        match(GlyphParser::AND_AND);
        setState(500);
        equalityExpr(); 
      }
      setState(505);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 55, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EqualityExprContext ------------------------------------------------------------------

GlyphParser::EqualityExprContext::EqualityExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GlyphParser::ComparisonExprContext *> GlyphParser::EqualityExprContext::comparisonExpr() {
  return getRuleContexts<GlyphParser::ComparisonExprContext>();
}

GlyphParser::ComparisonExprContext* GlyphParser::EqualityExprContext::comparisonExpr(size_t i) {
  return getRuleContext<GlyphParser::ComparisonExprContext>(i);
}

std::vector<tree::TerminalNode *> GlyphParser::EqualityExprContext::EQ() {
  return getTokens(GlyphParser::EQ);
}

tree::TerminalNode* GlyphParser::EqualityExprContext::EQ(size_t i) {
  return getToken(GlyphParser::EQ, i);
}

std::vector<tree::TerminalNode *> GlyphParser::EqualityExprContext::NE() {
  return getTokens(GlyphParser::NE);
}

tree::TerminalNode* GlyphParser::EqualityExprContext::NE(size_t i) {
  return getToken(GlyphParser::NE, i);
}


size_t GlyphParser::EqualityExprContext::getRuleIndex() const {
  return GlyphParser::RuleEqualityExpr;
}


std::any GlyphParser::EqualityExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitEqualityExpr(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::EqualityExprContext* GlyphParser::equalityExpr() {
  EqualityExprContext *_localctx = _tracker.createInstance<EqualityExprContext>(_ctx, getState());
  enterRule(_localctx, 82, GlyphParser::RuleEqualityExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(506);
    comparisonExpr();
    setState(511);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(507);
        _la = _input->LA(1);
        if (!(_la == GlyphParser::EQ

        || _la == GlyphParser::NE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(508);
        comparisonExpr(); 
      }
      setState(513);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComparisonExprContext ------------------------------------------------------------------

GlyphParser::ComparisonExprContext::ComparisonExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GlyphParser::AdditiveExprContext *> GlyphParser::ComparisonExprContext::additiveExpr() {
  return getRuleContexts<GlyphParser::AdditiveExprContext>();
}

GlyphParser::AdditiveExprContext* GlyphParser::ComparisonExprContext::additiveExpr(size_t i) {
  return getRuleContext<GlyphParser::AdditiveExprContext>(i);
}

std::vector<tree::TerminalNode *> GlyphParser::ComparisonExprContext::LT() {
  return getTokens(GlyphParser::LT);
}

tree::TerminalNode* GlyphParser::ComparisonExprContext::LT(size_t i) {
  return getToken(GlyphParser::LT, i);
}

std::vector<tree::TerminalNode *> GlyphParser::ComparisonExprContext::LE() {
  return getTokens(GlyphParser::LE);
}

tree::TerminalNode* GlyphParser::ComparisonExprContext::LE(size_t i) {
  return getToken(GlyphParser::LE, i);
}

std::vector<tree::TerminalNode *> GlyphParser::ComparisonExprContext::GT() {
  return getTokens(GlyphParser::GT);
}

tree::TerminalNode* GlyphParser::ComparisonExprContext::GT(size_t i) {
  return getToken(GlyphParser::GT, i);
}

std::vector<tree::TerminalNode *> GlyphParser::ComparisonExprContext::GE() {
  return getTokens(GlyphParser::GE);
}

tree::TerminalNode* GlyphParser::ComparisonExprContext::GE(size_t i) {
  return getToken(GlyphParser::GE, i);
}


size_t GlyphParser::ComparisonExprContext::getRuleIndex() const {
  return GlyphParser::RuleComparisonExpr;
}


std::any GlyphParser::ComparisonExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitComparisonExpr(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::ComparisonExprContext* GlyphParser::comparisonExpr() {
  ComparisonExprContext *_localctx = _tracker.createInstance<ComparisonExprContext>(_ctx, getState());
  enterRule(_localctx, 84, GlyphParser::RuleComparisonExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(514);
    additiveExpr();
    setState(519);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(515);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 1055531162664960) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(516);
        additiveExpr(); 
      }
      setState(521);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AdditiveExprContext ------------------------------------------------------------------

GlyphParser::AdditiveExprContext::AdditiveExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GlyphParser::MultiplicativeExprContext *> GlyphParser::AdditiveExprContext::multiplicativeExpr() {
  return getRuleContexts<GlyphParser::MultiplicativeExprContext>();
}

GlyphParser::MultiplicativeExprContext* GlyphParser::AdditiveExprContext::multiplicativeExpr(size_t i) {
  return getRuleContext<GlyphParser::MultiplicativeExprContext>(i);
}

std::vector<tree::TerminalNode *> GlyphParser::AdditiveExprContext::PLUS() {
  return getTokens(GlyphParser::PLUS);
}

tree::TerminalNode* GlyphParser::AdditiveExprContext::PLUS(size_t i) {
  return getToken(GlyphParser::PLUS, i);
}

std::vector<tree::TerminalNode *> GlyphParser::AdditiveExprContext::MINUS() {
  return getTokens(GlyphParser::MINUS);
}

tree::TerminalNode* GlyphParser::AdditiveExprContext::MINUS(size_t i) {
  return getToken(GlyphParser::MINUS, i);
}


size_t GlyphParser::AdditiveExprContext::getRuleIndex() const {
  return GlyphParser::RuleAdditiveExpr;
}


std::any GlyphParser::AdditiveExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpr(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::AdditiveExprContext* GlyphParser::additiveExpr() {
  AdditiveExprContext *_localctx = _tracker.createInstance<AdditiveExprContext>(_ctx, getState());
  enterRule(_localctx, 86, GlyphParser::RuleAdditiveExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(522);
    multiplicativeExpr();
    setState(527);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(523);
        _la = _input->LA(1);
        if (!(_la == GlyphParser::PLUS

        || _la == GlyphParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(524);
        multiplicativeExpr(); 
      }
      setState(529);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiplicativeExprContext ------------------------------------------------------------------

GlyphParser::MultiplicativeExprContext::MultiplicativeExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GlyphParser::CastExprContext *> GlyphParser::MultiplicativeExprContext::castExpr() {
  return getRuleContexts<GlyphParser::CastExprContext>();
}

GlyphParser::CastExprContext* GlyphParser::MultiplicativeExprContext::castExpr(size_t i) {
  return getRuleContext<GlyphParser::CastExprContext>(i);
}

std::vector<tree::TerminalNode *> GlyphParser::MultiplicativeExprContext::STAR() {
  return getTokens(GlyphParser::STAR);
}

tree::TerminalNode* GlyphParser::MultiplicativeExprContext::STAR(size_t i) {
  return getToken(GlyphParser::STAR, i);
}

std::vector<tree::TerminalNode *> GlyphParser::MultiplicativeExprContext::SLASH() {
  return getTokens(GlyphParser::SLASH);
}

tree::TerminalNode* GlyphParser::MultiplicativeExprContext::SLASH(size_t i) {
  return getToken(GlyphParser::SLASH, i);
}

std::vector<tree::TerminalNode *> GlyphParser::MultiplicativeExprContext::PERCENT() {
  return getTokens(GlyphParser::PERCENT);
}

tree::TerminalNode* GlyphParser::MultiplicativeExprContext::PERCENT(size_t i) {
  return getToken(GlyphParser::PERCENT, i);
}


size_t GlyphParser::MultiplicativeExprContext::getRuleIndex() const {
  return GlyphParser::RuleMultiplicativeExpr;
}


std::any GlyphParser::MultiplicativeExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpr(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::MultiplicativeExprContext* GlyphParser::multiplicativeExpr() {
  MultiplicativeExprContext *_localctx = _tracker.createInstance<MultiplicativeExprContext>(_ctx, getState());
  enterRule(_localctx, 88, GlyphParser::RuleMultiplicativeExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(530);
    castExpr();
    setState(535);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(531);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 1008806316530991104) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(532);
        castExpr(); 
      }
      setState(537);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CastExprContext ------------------------------------------------------------------

GlyphParser::CastExprContext::CastExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GlyphParser::CastExprContext::getRuleIndex() const {
  return GlyphParser::RuleCastExpr;
}

void GlyphParser::CastExprContext::copyFrom(CastExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AsCastContext ------------------------------------------------------------------

GlyphParser::UnaryExprContext* GlyphParser::AsCastContext::unaryExpr() {
  return getRuleContext<GlyphParser::UnaryExprContext>(0);
}

GlyphParser::PrimitiveKwContext* GlyphParser::AsCastContext::primitiveKw() {
  return getRuleContext<GlyphParser::PrimitiveKwContext>(0);
}

GlyphParser::AsCastContext::AsCastContext(CastExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::AsCastContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitAsCast(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TryExprContext ------------------------------------------------------------------

GlyphParser::UnaryExprContext* GlyphParser::TryExprContext::unaryExpr() {
  return getRuleContext<GlyphParser::UnaryExprContext>(0);
}

GlyphParser::TryExprContext::TryExprContext(CastExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::TryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitTryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CastOperandContext ------------------------------------------------------------------

GlyphParser::UnaryExprContext* GlyphParser::CastOperandContext::unaryExpr() {
  return getRuleContext<GlyphParser::UnaryExprContext>(0);
}

GlyphParser::CastOperandContext::CastOperandContext(CastExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::CastOperandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitCastOperand(this);
  else
    return visitor->visitChildren(this);
}
GlyphParser::CastExprContext* GlyphParser::castExpr() {
  CastExprContext *_localctx = _tracker.createInstance<CastExprContext>(_ctx, getState());
  enterRule(_localctx, 90, GlyphParser::RuleCastExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(545);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<GlyphParser::AsCastContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(538);
      unaryExpr();
      setState(539);
      match(GlyphParser::T__2);
      setState(540);
      primitiveKw();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<GlyphParser::TryExprContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(542);
      match(GlyphParser::T__30);
      setState(543);
      unaryExpr();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<GlyphParser::CastOperandContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(544);
      unaryExpr();
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

//----------------- PrimitiveKwContext ------------------------------------------------------------------

GlyphParser::PrimitiveKwContext::PrimitiveKwContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GlyphParser::PrimitiveKwContext::getRuleIndex() const {
  return GlyphParser::RulePrimitiveKw;
}


std::any GlyphParser::PrimitiveKwContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitPrimitiveKw(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::PrimitiveKwContext* GlyphParser::primitiveKw() {
  PrimitiveKwContext *_localctx = _tracker.createInstance<PrimitiveKwContext>(_ctx, getState());
  enterRule(_localctx, 92, GlyphParser::RulePrimitiveKw);
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
    setState(547);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 253952) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryExprContext ------------------------------------------------------------------

GlyphParser::UnaryExprContext::UnaryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GlyphParser::UnaryExprContext::getRuleIndex() const {
  return GlyphParser::RuleUnaryExpr;
}

void GlyphParser::UnaryExprContext::copyFrom(UnaryExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- UnaryOperandContext ------------------------------------------------------------------

GlyphParser::PostfixExprContext* GlyphParser::UnaryOperandContext::postfixExpr() {
  return getRuleContext<GlyphParser::PostfixExprContext>(0);
}

GlyphParser::UnaryOperandContext::UnaryOperandContext(UnaryExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::UnaryOperandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitUnaryOperand(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryOpContext ------------------------------------------------------------------

GlyphParser::UnaryExprContext* GlyphParser::UnaryOpContext::unaryExpr() {
  return getRuleContext<GlyphParser::UnaryExprContext>(0);
}

tree::TerminalNode* GlyphParser::UnaryOpContext::MINUS() {
  return getToken(GlyphParser::MINUS, 0);
}

tree::TerminalNode* GlyphParser::UnaryOpContext::NOT_OP() {
  return getToken(GlyphParser::NOT_OP, 0);
}

GlyphParser::UnaryOpContext::UnaryOpContext(UnaryExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::UnaryOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitUnaryOp(this);
  else
    return visitor->visitChildren(this);
}
GlyphParser::UnaryExprContext* GlyphParser::unaryExpr() {
  UnaryExprContext *_localctx = _tracker.createInstance<UnaryExprContext>(_ctx, getState());
  enterRule(_localctx, 94, GlyphParser::RuleUnaryExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(552);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GlyphParser::T__31:
      case GlyphParser::NOT_OP:
      case GlyphParser::MINUS: {
        _localctx = _tracker.createInstance<GlyphParser::UnaryOpContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(549);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 76561197960265728) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(550);
        unaryExpr();
        break;
      }

      case GlyphParser::T__10:
      case GlyphParser::T__25:
      case GlyphParser::T__26:
      case GlyphParser::T__27:
      case GlyphParser::T__28:
      case GlyphParser::T__32:
      case GlyphParser::T__33:
      case GlyphParser::DOUBLE_LITERAL:
      case GlyphParser::INT_LITERAL:
      case GlyphParser::STRING:
      case GlyphParser::ID:
      case GlyphParser::LPAREN:
      case GlyphParser::LBRACKET: {
        _localctx = _tracker.createInstance<GlyphParser::UnaryOperandContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(551);
        postfixExpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PostfixExprContext ------------------------------------------------------------------

GlyphParser::PostfixExprContext::PostfixExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GlyphParser::PrimaryExprContext* GlyphParser::PostfixExprContext::primaryExpr() {
  return getRuleContext<GlyphParser::PrimaryExprContext>(0);
}

std::vector<GlyphParser::PostfixOpContext *> GlyphParser::PostfixExprContext::postfixOp() {
  return getRuleContexts<GlyphParser::PostfixOpContext>();
}

GlyphParser::PostfixOpContext* GlyphParser::PostfixExprContext::postfixOp(size_t i) {
  return getRuleContext<GlyphParser::PostfixOpContext>(i);
}


size_t GlyphParser::PostfixExprContext::getRuleIndex() const {
  return GlyphParser::RulePostfixExpr;
}


std::any GlyphParser::PostfixExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitPostfixExpr(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::PostfixExprContext* GlyphParser::postfixExpr() {
  PostfixExprContext *_localctx = _tracker.createInstance<PostfixExprContext>(_ctx, getState());
  enterRule(_localctx, 96, GlyphParser::RulePostfixExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(554);
    primaryExpr();
    setState(558);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(555);
        postfixOp(); 
      }
      setState(560);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PostfixOpContext ------------------------------------------------------------------

GlyphParser::PostfixOpContext::PostfixOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GlyphParser::PostfixOpContext::getRuleIndex() const {
  return GlyphParser::RulePostfixOp;
}

void GlyphParser::PostfixOpContext::copyFrom(PostfixOpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CallContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::CallContext::LPAREN() {
  return getToken(GlyphParser::LPAREN, 0);
}

tree::TerminalNode* GlyphParser::CallContext::RPAREN() {
  return getToken(GlyphParser::RPAREN, 0);
}

GlyphParser::ArgListContext* GlyphParser::CallContext::argList() {
  return getRuleContext<GlyphParser::ArgListContext>(0);
}

GlyphParser::CallContext::CallContext(PostfixOpContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::CallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StaticAccessContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::StaticAccessContext::COLONCOLON() {
  return getToken(GlyphParser::COLONCOLON, 0);
}

tree::TerminalNode* GlyphParser::StaticAccessContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

GlyphParser::StaticAccessContext::StaticAccessContext(PostfixOpContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::StaticAccessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitStaticAccess(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IndexContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::IndexContext::LBRACKET() {
  return getToken(GlyphParser::LBRACKET, 0);
}

GlyphParser::ExprContext* GlyphParser::IndexContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

tree::TerminalNode* GlyphParser::IndexContext::RBRACKET() {
  return getToken(GlyphParser::RBRACKET, 0);
}

GlyphParser::IndexContext::IndexContext(PostfixOpContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::IndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitIndex(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PropagateContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::PropagateContext::QUEST() {
  return getToken(GlyphParser::QUEST, 0);
}

GlyphParser::PropagateContext::PropagateContext(PostfixOpContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::PropagateContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitPropagate(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FieldAccessContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::FieldAccessContext::DOT() {
  return getToken(GlyphParser::DOT, 0);
}

tree::TerminalNode* GlyphParser::FieldAccessContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

GlyphParser::FieldAccessContext::FieldAccessContext(PostfixOpContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::FieldAccessContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitFieldAccess(this);
  else
    return visitor->visitChildren(this);
}
GlyphParser::PostfixOpContext* GlyphParser::postfixOp() {
  PostfixOpContext *_localctx = _tracker.createInstance<PostfixOpContext>(_ctx, getState());
  enterRule(_localctx, 98, GlyphParser::RulePostfixOp);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(575);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GlyphParser::DOT: {
        _localctx = _tracker.createInstance<GlyphParser::FieldAccessContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(561);
        match(GlyphParser::DOT);
        setState(562);
        match(GlyphParser::ID);
        break;
      }

      case GlyphParser::COLONCOLON: {
        _localctx = _tracker.createInstance<GlyphParser::StaticAccessContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(563);
        match(GlyphParser::COLONCOLON);
        setState(564);
        match(GlyphParser::ID);
        break;
      }

      case GlyphParser::LBRACKET: {
        _localctx = _tracker.createInstance<GlyphParser::IndexContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(565);
        match(GlyphParser::LBRACKET);
        setState(566);
        expr();
        setState(567);
        match(GlyphParser::RBRACKET);
        break;
      }

      case GlyphParser::LPAREN: {
        _localctx = _tracker.createInstance<GlyphParser::CallContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(569);
        match(GlyphParser::LPAREN);
        setState(571);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 5841169265314498560) != 0)) {
          setState(570);
          argList();
        }
        setState(573);
        match(GlyphParser::RPAREN);
        break;
      }

      case GlyphParser::QUEST: {
        _localctx = _tracker.createInstance<GlyphParser::PropagateContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(574);
        match(GlyphParser::QUEST);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryExprContext ------------------------------------------------------------------

GlyphParser::PrimaryExprContext::PrimaryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GlyphParser::PrimaryExprContext::getRuleIndex() const {
  return GlyphParser::RulePrimaryExpr;
}

void GlyphParser::PrimaryExprContext::copyFrom(PrimaryExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StructLitInferredContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::StructLitInferredContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

tree::TerminalNode* GlyphParser::StructLitInferredContext::LBRACE() {
  return getToken(GlyphParser::LBRACE, 0);
}

std::vector<GlyphParser::FieldInitContext *> GlyphParser::StructLitInferredContext::fieldInit() {
  return getRuleContexts<GlyphParser::FieldInitContext>();
}

GlyphParser::FieldInitContext* GlyphParser::StructLitInferredContext::fieldInit(size_t i) {
  return getRuleContext<GlyphParser::FieldInitContext>(i);
}

tree::TerminalNode* GlyphParser::StructLitInferredContext::RBRACE() {
  return getToken(GlyphParser::RBRACE, 0);
}

std::vector<tree::TerminalNode *> GlyphParser::StructLitInferredContext::COMMA() {
  return getTokens(GlyphParser::COMMA);
}

tree::TerminalNode* GlyphParser::StructLitInferredContext::COMMA(size_t i) {
  return getToken(GlyphParser::COMMA, i);
}

GlyphParser::StructLitInferredContext::StructLitInferredContext(PrimaryExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::StructLitInferredContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitStructLitInferred(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DoubleLitContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::DoubleLitContext::DOUBLE_LITERAL() {
  return getToken(GlyphParser::DOUBLE_LITERAL, 0);
}

GlyphParser::DoubleLitContext::DoubleLitContext(PrimaryExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::DoubleLitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitDoubleLit(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OkCtorContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::OkCtorContext::LPAREN() {
  return getToken(GlyphParser::LPAREN, 0);
}

GlyphParser::ExprContext* GlyphParser::OkCtorContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

tree::TerminalNode* GlyphParser::OkCtorContext::RPAREN() {
  return getToken(GlyphParser::RPAREN, 0);
}

GlyphParser::OkCtorContext::OkCtorContext(PrimaryExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::OkCtorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitOkCtor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ErrCtorContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::ErrCtorContext::LPAREN() {
  return getToken(GlyphParser::LPAREN, 0);
}

GlyphParser::ExprContext* GlyphParser::ErrCtorContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

tree::TerminalNode* GlyphParser::ErrCtorContext::RPAREN() {
  return getToken(GlyphParser::RPAREN, 0);
}

GlyphParser::ErrCtorContext::ErrCtorContext(PrimaryExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::ErrCtorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitErrCtor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LambdaExprShortContext ------------------------------------------------------------------

GlyphParser::LambdaParamsContext* GlyphParser::LambdaExprShortContext::lambdaParams() {
  return getRuleContext<GlyphParser::LambdaParamsContext>(0);
}

GlyphParser::ExprContext* GlyphParser::LambdaExprShortContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

GlyphParser::TypeContext* GlyphParser::LambdaExprShortContext::type() {
  return getRuleContext<GlyphParser::TypeContext>(0);
}

GlyphParser::LambdaExprShortContext::LambdaExprShortContext(PrimaryExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::LambdaExprShortContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitLambdaExprShort(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LambdaExprContext ------------------------------------------------------------------

GlyphParser::LambdaParamsContext* GlyphParser::LambdaExprContext::lambdaParams() {
  return getRuleContext<GlyphParser::LambdaParamsContext>(0);
}

GlyphParser::BlockContext* GlyphParser::LambdaExprContext::block() {
  return getRuleContext<GlyphParser::BlockContext>(0);
}

GlyphParser::TypeContext* GlyphParser::LambdaExprContext::type() {
  return getRuleContext<GlyphParser::TypeContext>(0);
}

GlyphParser::LambdaExprContext::LambdaExprContext(PrimaryExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::LambdaExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitLambdaExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FalseLitContext ------------------------------------------------------------------

GlyphParser::FalseLitContext::FalseLitContext(PrimaryExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::FalseLitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitFalseLit(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ListLitContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::ListLitContext::LBRACKET() {
  return getToken(GlyphParser::LBRACKET, 0);
}

tree::TerminalNode* GlyphParser::ListLitContext::RBRACKET() {
  return getToken(GlyphParser::RBRACKET, 0);
}

std::vector<GlyphParser::ExprContext *> GlyphParser::ListLitContext::expr() {
  return getRuleContexts<GlyphParser::ExprContext>();
}

GlyphParser::ExprContext* GlyphParser::ListLitContext::expr(size_t i) {
  return getRuleContext<GlyphParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> GlyphParser::ListLitContext::COMMA() {
  return getTokens(GlyphParser::COMMA);
}

tree::TerminalNode* GlyphParser::ListLitContext::COMMA(size_t i) {
  return getToken(GlyphParser::COMMA, i);
}

GlyphParser::ListLitContext::ListLitContext(PrimaryExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::ListLitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitListLit(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SomeCtorContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::SomeCtorContext::LPAREN() {
  return getToken(GlyphParser::LPAREN, 0);
}

GlyphParser::ExprContext* GlyphParser::SomeCtorContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}

tree::TerminalNode* GlyphParser::SomeCtorContext::RPAREN() {
  return getToken(GlyphParser::RPAREN, 0);
}

GlyphParser::SomeCtorContext::SomeCtorContext(PrimaryExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::SomeCtorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitSomeCtor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringLitContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> GlyphParser::StringLitContext::STRING() {
  return getTokens(GlyphParser::STRING);
}

tree::TerminalNode* GlyphParser::StringLitContext::STRING(size_t i) {
  return getToken(GlyphParser::STRING, i);
}

GlyphParser::StringLitContext::StringLitContext(PrimaryExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::StringLitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitStringLit(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NoneLitContext ------------------------------------------------------------------

GlyphParser::NoneLitContext::NoneLitContext(PrimaryExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::NoneLitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitNoneLit(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StructLitNamedContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::StructLitNamedContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

tree::TerminalNode* GlyphParser::StructLitNamedContext::COLON() {
  return getToken(GlyphParser::COLON, 0);
}

tree::TerminalNode* GlyphParser::StructLitNamedContext::LBRACE() {
  return getToken(GlyphParser::LBRACE, 0);
}

std::vector<GlyphParser::FieldInitContext *> GlyphParser::StructLitNamedContext::fieldInit() {
  return getRuleContexts<GlyphParser::FieldInitContext>();
}

GlyphParser::FieldInitContext* GlyphParser::StructLitNamedContext::fieldInit(size_t i) {
  return getRuleContext<GlyphParser::FieldInitContext>(i);
}

tree::TerminalNode* GlyphParser::StructLitNamedContext::RBRACE() {
  return getToken(GlyphParser::RBRACE, 0);
}

std::vector<tree::TerminalNode *> GlyphParser::StructLitNamedContext::COMMA() {
  return getTokens(GlyphParser::COMMA);
}

tree::TerminalNode* GlyphParser::StructLitNamedContext::COMMA(size_t i) {
  return getToken(GlyphParser::COMMA, i);
}

GlyphParser::StructLitNamedContext::StructLitNamedContext(PrimaryExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::StructLitNamedContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitStructLitNamed(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdentifierContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::IdentifierContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

GlyphParser::IdentifierContext::IdentifierContext(PrimaryExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitIdentifier(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TrueLitContext ------------------------------------------------------------------

GlyphParser::TrueLitContext::TrueLitContext(PrimaryExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::TrueLitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitTrueLit(this);
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

GlyphParser::ParenExprContext::ParenExprContext(PrimaryExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::ParenExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitParenExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntLitContext ------------------------------------------------------------------

tree::TerminalNode* GlyphParser::IntLitContext::INT_LITERAL() {
  return getToken(GlyphParser::INT_LITERAL, 0);
}

GlyphParser::IntLitContext::IntLitContext(PrimaryExprContext *ctx) { copyFrom(ctx); }


std::any GlyphParser::IntLitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitIntLit(this);
  else
    return visitor->visitChildren(this);
}
GlyphParser::PrimaryExprContext* GlyphParser::primaryExpr() {
  PrimaryExprContext *_localctx = _tracker.createInstance<PrimaryExprContext>(_ctx, getState());
  enterRule(_localctx, 100, GlyphParser::RulePrimaryExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(665);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<GlyphParser::IntLitContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(577);
      match(GlyphParser::INT_LITERAL);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<GlyphParser::DoubleLitContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(578);
      match(GlyphParser::DOUBLE_LITERAL);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<GlyphParser::TrueLitContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(579);
      match(GlyphParser::T__32);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<GlyphParser::FalseLitContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(580);
      match(GlyphParser::T__33);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<GlyphParser::NoneLitContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(581);
      match(GlyphParser::T__26);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<GlyphParser::SomeCtorContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(582);
      match(GlyphParser::T__25);
      setState(583);
      match(GlyphParser::LPAREN);
      setState(584);
      expr();
      setState(585);
      match(GlyphParser::RPAREN);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<GlyphParser::OkCtorContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(587);
      match(GlyphParser::T__27);
      setState(588);
      match(GlyphParser::LPAREN);
      setState(589);
      expr();
      setState(590);
      match(GlyphParser::RPAREN);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<GlyphParser::ErrCtorContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(592);
      match(GlyphParser::T__28);
      setState(593);
      match(GlyphParser::LPAREN);
      setState(594);
      expr();
      setState(595);
      match(GlyphParser::RPAREN);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<GlyphParser::StringLitContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(598); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(597);
                match(GlyphParser::STRING);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(600); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<GlyphParser::ListLitContext>(_localctx);
      enterOuterAlt(_localctx, 10);
      setState(602);
      match(GlyphParser::LBRACKET);
      setState(611);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 5841169265314498560) != 0)) {
        setState(603);
        expr();
        setState(608);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == GlyphParser::COMMA) {
          setState(604);
          match(GlyphParser::COMMA);
          setState(605);
          expr();
          setState(610);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(613);
      match(GlyphParser::RBRACKET);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<GlyphParser::StructLitNamedContext>(_localctx);
      enterOuterAlt(_localctx, 11);
      setState(614);
      match(GlyphParser::ID);
      setState(615);
      match(GlyphParser::COLON);
      setState(616);
      match(GlyphParser::LBRACE);
      setState(617);
      fieldInit();
      setState(622);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(618);
          match(GlyphParser::COMMA);
          setState(619);
          fieldInit(); 
        }
        setState(624);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx);
      }
      setState(626);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GlyphParser::COMMA) {
        setState(625);
        match(GlyphParser::COMMA);
      }
      setState(628);
      match(GlyphParser::RBRACE);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<GlyphParser::StructLitInferredContext>(_localctx);
      enterOuterAlt(_localctx, 12);
      setState(630);
      match(GlyphParser::ID);
      setState(631);
      match(GlyphParser::LBRACE);
      setState(632);
      fieldInit();
      setState(635); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(633);
                match(GlyphParser::COMMA);
                setState(634);
                fieldInit();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(637); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(640);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GlyphParser::COMMA) {
        setState(639);
        match(GlyphParser::COMMA);
      }
      setState(642);
      match(GlyphParser::RBRACE);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<GlyphParser::ParenExprContext>(_localctx);
      enterOuterAlt(_localctx, 13);
      setState(644);
      match(GlyphParser::LPAREN);
      setState(645);
      expr();
      setState(646);
      match(GlyphParser::RPAREN);
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<GlyphParser::LambdaExprContext>(_localctx);
      enterOuterAlt(_localctx, 14);
      setState(648);
      match(GlyphParser::T__10);
      setState(649);
      lambdaParams();
      setState(652);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GlyphParser::T__11) {
        setState(650);
        match(GlyphParser::T__11);
        setState(651);
        type();
      }
      setState(654);
      block();
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<GlyphParser::LambdaExprShortContext>(_localctx);
      enterOuterAlt(_localctx, 15);
      setState(656);
      match(GlyphParser::T__10);
      setState(657);
      lambdaParams();
      setState(660);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GlyphParser::T__11) {
        setState(658);
        match(GlyphParser::T__11);
        setState(659);
        type();
      }
      setState(662);
      expr();
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<GlyphParser::IdentifierContext>(_localctx);
      enterOuterAlt(_localctx, 16);
      setState(664);
      match(GlyphParser::ID);
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

//----------------- FieldInitContext ------------------------------------------------------------------

GlyphParser::FieldInitContext::FieldInitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::FieldInitContext::ID() {
  return getToken(GlyphParser::ID, 0);
}

tree::TerminalNode* GlyphParser::FieldInitContext::COLON() {
  return getToken(GlyphParser::COLON, 0);
}

GlyphParser::ExprContext* GlyphParser::FieldInitContext::expr() {
  return getRuleContext<GlyphParser::ExprContext>(0);
}


size_t GlyphParser::FieldInitContext::getRuleIndex() const {
  return GlyphParser::RuleFieldInit;
}


std::any GlyphParser::FieldInitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitFieldInit(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::FieldInitContext* GlyphParser::fieldInit() {
  FieldInitContext *_localctx = _tracker.createInstance<FieldInitContext>(_ctx, getState());
  enterRule(_localctx, 102, GlyphParser::RuleFieldInit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(667);
    match(GlyphParser::ID);
    setState(668);
    match(GlyphParser::COLON);
    setState(669);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LambdaParamsContext ------------------------------------------------------------------

GlyphParser::LambdaParamsContext::LambdaParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GlyphParser::LambdaParamsContext::LPAREN() {
  return getToken(GlyphParser::LPAREN, 0);
}

tree::TerminalNode* GlyphParser::LambdaParamsContext::RPAREN() {
  return getToken(GlyphParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> GlyphParser::LambdaParamsContext::ID() {
  return getTokens(GlyphParser::ID);
}

tree::TerminalNode* GlyphParser::LambdaParamsContext::ID(size_t i) {
  return getToken(GlyphParser::ID, i);
}

std::vector<tree::TerminalNode *> GlyphParser::LambdaParamsContext::COMMA() {
  return getTokens(GlyphParser::COMMA);
}

tree::TerminalNode* GlyphParser::LambdaParamsContext::COMMA(size_t i) {
  return getToken(GlyphParser::COMMA, i);
}

std::vector<tree::TerminalNode *> GlyphParser::LambdaParamsContext::COLON() {
  return getTokens(GlyphParser::COLON);
}

tree::TerminalNode* GlyphParser::LambdaParamsContext::COLON(size_t i) {
  return getToken(GlyphParser::COLON, i);
}

std::vector<GlyphParser::TypeContext *> GlyphParser::LambdaParamsContext::type() {
  return getRuleContexts<GlyphParser::TypeContext>();
}

GlyphParser::TypeContext* GlyphParser::LambdaParamsContext::type(size_t i) {
  return getRuleContext<GlyphParser::TypeContext>(i);
}


size_t GlyphParser::LambdaParamsContext::getRuleIndex() const {
  return GlyphParser::RuleLambdaParams;
}


std::any GlyphParser::LambdaParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitLambdaParams(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::LambdaParamsContext* GlyphParser::lambdaParams() {
  LambdaParamsContext *_localctx = _tracker.createInstance<LambdaParamsContext>(_ctx, getState());
  enterRule(_localctx, 104, GlyphParser::RuleLambdaParams);
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
    setState(671);
    match(GlyphParser::LPAREN);
    setState(688);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::ID) {
      setState(672);
      match(GlyphParser::ID);
      setState(675);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GlyphParser::COLON) {
        setState(673);
        match(GlyphParser::COLON);
        setState(674);
        type();
      }
      setState(685);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GlyphParser::COMMA) {
        setState(677);
        match(GlyphParser::COMMA);
        setState(678);
        match(GlyphParser::ID);
        setState(681);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == GlyphParser::COLON) {
          setState(679);
          match(GlyphParser::COLON);
          setState(680);
          type();
        }
        setState(687);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(690);
    match(GlyphParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgListContext ------------------------------------------------------------------

GlyphParser::ArgListContext::ArgListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GlyphParser::ExprContext *> GlyphParser::ArgListContext::expr() {
  return getRuleContexts<GlyphParser::ExprContext>();
}

GlyphParser::ExprContext* GlyphParser::ArgListContext::expr(size_t i) {
  return getRuleContext<GlyphParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> GlyphParser::ArgListContext::COMMA() {
  return getTokens(GlyphParser::COMMA);
}

tree::TerminalNode* GlyphParser::ArgListContext::COMMA(size_t i) {
  return getToken(GlyphParser::COMMA, i);
}


size_t GlyphParser::ArgListContext::getRuleIndex() const {
  return GlyphParser::RuleArgList;
}


std::any GlyphParser::ArgListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GlyphVisitor*>(visitor))
    return parserVisitor->visitArgList(this);
  else
    return visitor->visitChildren(this);
}

GlyphParser::ArgListContext* GlyphParser::argList() {
  ArgListContext *_localctx = _tracker.createInstance<ArgListContext>(_ctx, getState());
  enterRule(_localctx, 106, GlyphParser::RuleArgList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(692);
    expr();
    setState(697);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(693);
        match(GlyphParser::COMMA);
        setState(694);
        expr(); 
      }
      setState(699);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx);
    }
    setState(701);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GlyphParser::COMMA) {
      setState(700);
      match(GlyphParser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void GlyphParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  glyphParserInitialize();
#else
  ::antlr4::internal::call_once(glyphParserOnceFlag, glyphParserInitialize);
#endif
}
