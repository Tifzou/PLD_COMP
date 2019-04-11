grammar Expr;
prog:base;


base: (function)* mainFunction;

function : typevar VAR'(' param* ')'core ;

mainFunction : 'int main' '(' ')'core ;

param : typevar VAR (',')*;

core: '{' code* ret '}';

code: typevar vari ';' #decdef
    | VAR '=' expr ';' #aff
    | VAR '=' VAR'(' param* ')' ';' #afffunc
    | VAR'(' param* ')' ';'#callfunc
    ;

condition: 'if' '('boolExpression')' '{'condIf'}' 'else' '{'condElse'}' #ifElse
    |'if' '('boolExpression')' '{'condIf'}' #simpleIf
    ;

condIf:ifCore;
condElse:ifCore;

ifCore:code* #ifCommande
    | code* ret #ifRet
    ;

boolExpression:predicat;

predicat:expr '==' expr #egal
    |expr '>=' expr # ge
    |expr '>' expr # gt
    |expr '<=' expr # le
    |expr '<' expr # lt
;

ret: 'return' expr ';' ;
vari: VAR (','VAR)* #decVar
    | VAR '=' expr #defVar
    ;

expr: terme ('+' terme)* ;

terme: facteur ('*' facteur)* ;

facteur: INT #factInt
    | VAR #factVar
    | '(' expr ')' #factPar
    ;

typevar: TYPEINT #int
    | TYPECHAR #char
    ;

TYPEINT: 'int';
TYPECHAR:'char';
INT: [0-9]+ ;
VAR: [a-zA-Z]+ ;
WS: [ \t\r\n] -> skip;
