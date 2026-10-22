// Glyph language grammar (Milestone 1: print, numbers, strings, variables).
// ANTLR 4.13.1 — alternatives are ordered from lowest to highest precedence.
grammar Glyph;

// ---------------------------------------------------------------------------
// Parser rules
// ---------------------------------------------------------------------------

// The program rule must end in EOF so that unterminated constructs are
// reported as errors instead of being silently accepted.
program
    : statement* EOF
    ;

statement
    : printStmt     # PrintStatement
    | assignStmt    # AssignStatement
    | exprStmt      # ExpressionStatement
    ;

printStmt
    : PRINT '(' expr ')'
    ;

assignStmt
    : LOCAL? ID '=' expr
    ;

exprStmt
    : expr
    ;

// Precedence (lowest first): or < and < equality < comparison < additive
// < multiplicative < power (right-assoc) < unary < primary.
expr
    : expr OR expr                                              # OrExpr
    | expr AND expr                                             # AndExpr
    | expr ('==' | '~=') expr                                   # EqualityExpr
    | expr ('<' | '<=' | '>' | '>=') expr                       # ComparisonExpr
    | expr ('+' | '-') expr                                     # AdditiveExpr
    | expr ('*' | '/' | '%') expr                               # MultiplicativeExpr
    | expr '^' expr                                             # PowerExpr
    | ('-' | NOT) expr                                          # UnaryExpr
    | NUMBER                                                    # NumberExpr
    | STRING                                                    # StringExpr
    | ID                                                        # IdentifierExpr
    | '(' expr ')'                                              # ParenExpr
    ;

// ---------------------------------------------------------------------------
// Lexer rules
// ---------------------------------------------------------------------------

PRINT   : 'print' ;
LOCAL   : 'local' ;
AND     : 'and' ;
OR      : 'or' ;
NOT     : 'not' ;

NUMBER  : DIGIT+ '.' DIGIT+ | DIGIT+ ;

STRING  : '"' CHAR*? '"'
        | '\'' CHAR*? '\''
        ;

fragment CHAR
    : ~["'\\\r\n]
    | '\\' .
    ;

ID      : [a-zA-Z_][a-zA-Z0-9_]* ;

// Operators and punctuation. Multi-character operators come first.
EQ      : '==' ;
NE      : '~=' ;
LE      : '<=' ;
GE      : '>=' ;
LT      : '<' ;
GT      : '>' ;
ASSIGN  : '=' ;
PLUS    : '+' ;
MINUS   : '-' ;
STAR    : '*' ;
SLASH   : '/' ;
PERCENT : '%' ;
CARET   : '^' ;
LPAREN  : '(' ;
RPAREN  : ')' ;

LINE_COMMENT     : '--' ~[\r\n]* -> skip ;
BLOCK_COMMENT    : '--[[' .*? ']]' -> skip ;
WS               : [ \t\r\n]+ -> skip ;

fragment DIGIT : [0-9] ;
