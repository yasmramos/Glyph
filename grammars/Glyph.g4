// =============================================================================
// Glyph language grammar — Draft 0.2 (static-typing redesign)
// ANTLR 4 — alternatives are ordered from lowest to highest precedence.
//
// This revision aligns the grammar with the reference program
// `examples/inventario.glyph`: static types, structs, classes with single
// inheritance, interfaces, generics, Option/Result types, pattern matching
// and block-delimited control flow (C-like braces, Rust-flavoured keywords).
//
// The former Lua-inspired dynamic design (print/local/end/~=/^) is retired;
// see docs/LANGUAGE.md §13 for the migration notes.
// =============================================================================
grammar Glyph;

// ---------------------------------------------------------------------------
// Parser rules
// ---------------------------------------------------------------------------

program
    : moduleDecl? importDecl* topLevelDecl* EOF
    ;

moduleDecl
    : 'module' qualifiedName
    ;

importDecl
    : 'import' qualifiedName ('as' ID)?
    ;

topLevelDecl
    : constDecl               # TopConst
    | structDecl              # TopStruct
    | interfaceDecl           # TopInterface
    | classDecl               # TopClass
    | fnDecl                  # TopFn
    ;

// ---------- Declarations ------------------------------------------------------

constDecl
    : 'const' ID '=' expr
    ;

structDecl
    : 'struct' ID genericParams? '{' fieldDecl* '}'
    ;

interfaceDecl
    : 'interface' ID '{' (sigDecl ',')* sigDecl? '}'
    ;

classDecl
    : 'class' ID genericParams? ('extends' typeName)? ('implements' typeList)?
      '{' memberDecl* '}'
    ;

fieldDecl
    : ('const' | 'var')? ID ':' type
    ;

sigDecl
    : 'fn' ID '(' paramList? ')' ('->' type)?
    ;

memberDecl
    : fieldDecl                       # MemberField
    | ID? attrDecl? fnDecl                 # MemberFn
    ;

attrDecl
    : '@' ID
    ;

paramList
    : param (',' param)* ','?
    ;

param
    : 'var'? ID ':' type
    ;

fnDecl
    : 'fn' ID genericParams? '(' paramList? ')' ('->' type)? block
    ;

// ---------- Types -------------------------------------------------------------

type
    : ('int' | 'long' | 'double' | 'bool' | 'str') # BuiltinType
    | '[' type ']'                                 # ListType
    | '?' type                                     # OptionType
    | '!' type                                     # ResultType
    | 'fn' '(' typeList? ')' ('->' type)?          # FnType
    | typeName                                     # NamedType
    ;

typeName
    : qualifiedName genericArgs?
    ;

qualifiedName
    : ID ('.' ID)*
    ;

genericParams
    : '<' ID (',' ID)* '>'
    ;

genericArgs
    : '<' type (',' type)* '>'
    ;

typeList
    : type (',' type)* ','?
    ;

// ---------- Statements --------------------------------------------------------

block
    : '{' stmt* '}'
    ;

stmt
    : constStmt           # StmtConst
    | letStmt             # StmtLet
    | varStmt             # StmtVar
    | exprStmt            # StmtExpr
    | block               # StmtBlock
    | ifStmt              # StmtIf
    | whileStmt           # StmtWhile
    | forStmt             # StmtFor
    | matchStmt           # StmtMatch
    | returnStmt          # StmtReturn
    ;

constStmt
    : 'const' ID (':' type)? '=' expr
    ;

letStmt
    : 'let' ID (':' type)? '=' expr
    ;

varStmt
    : 'var' ID (':' type)? ('=' expr)?
    ;

exprStmt
    : exprOrAssign
    ;

ifStmt
    : 'if' expr block ('else' ifStmt | 'else' block)?
    ;

whileStmt
    : 'while' expr block
    ;

forStmt
    : 'for' ID 'in' expr block                # ForEach
    | 'for' forInit? ';' expr? ';' forUpdate? block   # NumericFor
    ;

forInit
    : letStmt | varStmt | constStmt | exprOrAssign
    ;

forUpdate
    : exprOrAssign
    ;

matchStmt
    : 'match' expr '{' matchArm* '}'
    ;

matchArm
    : pattern ('if' expr)? '=>' (block | expr) ','?
    ;

pattern
    : '_'                                        # WildcardPat
    | 'some' '(' ID ')'                          # SomePat
    | 'none'                                     # NonePat
    | 'ok' '(' ID ')'                            # OkPat
    | 'err' '(' ID ')'                           # ErrPat
    | INT_LITERAL                                # IntPat
    | STRING                                     # StrPat
    ;

returnStmt
    : 'return' expr?
    ;

// ---------- Expressions -------------------------------------------------------
// Precedence (lowest first):
//   assignment < ternary < logical-or < logical-and < equality < comparison
//   < additive < multiplicative < cast/unary < postfix < primary

expr
    : ternaryExpr
    ;

exprOrAssign
    : unaryExpr op=('+=' | '-=' | '*=' | '/=' | '%=') expr   # CompoundAssign
    | unaryExpr '=' expr                                     # SimpleAssign
    | expr                                                   # PlainExpr
    ;

ternaryExpr
    : orExpr ('?' orExpr ':' ternaryExpr)?
    ;

orExpr
    : andExpr ('||' andExpr)*
    ;

andExpr
    : equalityExpr ('&&' equalityExpr)*
    ;

equalityExpr
    : comparisonExpr (('==' | '!=') comparisonExpr)*
    ;

comparisonExpr
    : additiveExpr (('<' | '<=' | '>' | '>=') additiveExpr)*
    ;

additiveExpr
    : multiplicativeExpr (('+' | '-') multiplicativeExpr)*
    ;

multiplicativeExpr
    : castExpr (('*' | '/' | '%') castExpr)*
    ;

castExpr
    : unaryExpr 'as' primitiveKw        # AsCast
    | 'try' unaryExpr                   # TryExpr
    | unaryExpr                         # CastOperand
    ;

primitiveKw
    : 'int' | 'long' | 'double' | 'str' | 'bool'
    ;

unaryExpr
    : ('-' | '!' | 'not') unaryExpr    # UnaryOp
    | postfixExpr                    # UnaryOperand
    ;

postfixExpr
    : primaryExpr postfixOp*
    ;

postfixOp
    : '.' ID                       # FieldAccess
    | '::' ID                              # StaticAccess
    | '[' expr ']'                         # Index
    | '(' argList? ')'                     # Call
    | '?'                                  # Propagate
    ;

primaryExpr
    : INT_LITERAL                                   # IntLit
    | DOUBLE_LITERAL                                # DoubleLit
    | 'true'                                                # TrueLit
    | 'false'                                             # FalseLit
    | 'none'                                        # NoneLit
    | 'some' '(' expr ')'                           # SomeCtor
    | 'ok' '(' expr ')'                             # OkCtor
    | 'err' '(' expr ')'                            # ErrCtor
    | STRING+                                       # StringLit
    | '[' (expr (',' expr)*)? ']'                   # ListLit
    | ID ':' '{' fieldInit (',' fieldInit)* ','? '}' # StructLitNamed
    | ID '{' fieldInit (',' fieldInit)+ ','? '}'     # StructLitInferred
    | '(' expr ')'                                  # ParenExpr
    | 'fn' lambdaParams ('->' type)? block          # LambdaExpr
    | 'fn' lambdaParams ('->' type)? expr           # LambdaExprShort
    | ID                                            # Identifier
    ;

fieldInit
    : ID ':' expr
    ;

lambdaParams
    : '(' ((ID (':' type)? ) (',' ID (':' type)?)*)? ')'
    ;

argList
    : expr (',' expr)* ','?
    ;

// ---------------------------------------------------------------------------
// Lexer rules
// ---------------------------------------------------------------------------

// Keywords are matched before ID thanks to the longest-match rule; they are
// listed explicitly here for documentation purposes.

// Literals. DOUBLE_LITERAL must be tried before INT_LITERAL (order matters).
DOUBLE_LITERAL : DIGIT+ '.' DIGIT+ EXPONENT?
               | DIGIT+ EXPONENT
               ;
INT_LITERAL    : DIGIT+ ;

STRING : '"' DCHAR*? '"' ;

fragment DCHAR
    : ~["\\\r\n]
    | '\\' .
    ;

ID : [a-zA-Z_][a-zA-Z0-9_]* ;

// Multi-character operators must precede their single-character counterparts.
PLUS_ASSIGN    : '+=' ;
MINUS_ASSIGN   : '-=' ;
STAR_ASSIGN    : '*=' ;
SLASH_ASSIGN   : '/=' ;
PERCENT_ASSIGN : '%=' ;
EQ             : '==' ;
NE             : '!=' ;
LE             : '<=' ;
GE             : '>=' ;
LT             : '<' ;
GT             : '>' ;
AND_AND        : '&&' ;
OR_OR          : '||' ;
NOT_OP         : '!' ;
ASSIGN         : '=' ;
DOT_DOT        : '..' ;
PLUS           : '+' ;
MINUS          : '-' ;
STAR           : '*' ;
SLASH          : '/' ;
PERCENT        : '%' ;
LPAREN         : '(' ;
RPAREN         : ')' ;
LBRACKET       : '[' ;
RBRACKET       : ']' ;
LBRACE         : '{' ;
RBRACE         : '}' ;
COLONCOLON     : '::' ;
SEMICOLON      : ';' ;
COMMA          : ',' ;
DOT            : '.' ;
COLON          : ':' ;
QUEST          : '?' ;
AT             : '@' ;
UNDERSCORE     : '_' ;

// Comments follow the C family: `//` for line comments and `/* ... */` for
// block comments. The legacy Lua-style `--`/`--[[ ]]` forms are retired.
LINE_COMMENT  : '//' ~[\r\n]* -> skip ;
BLOCK_COMMENT : '/*' .*? '*/' -> skip ;
WS            : [ \t\r\n]+ -> skip ;

fragment DIGIT   : [0-9] ;
fragment EXPONENT : [eE] [+-]? DIGIT+ ;
