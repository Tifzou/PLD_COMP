grammar Expr;
prog:base;



base: 'int main' '(' ')'core;

core: '{' code* ret '}';

code: typevar vari ';' #decdef
    | VAR '=' expr ';' #aff
    | condition; #condif
    ;

condition: 'if('preficat'){'code*'}else{'code*'}' #ifElse
    |'if('preficat'){'code*'}' #simpleIf

predicat:expr '==' expr #egal
    |expr '>=' expr # ge
    |expr '>' expr # g
    |expr '<=' expr # le
    |expr '<' expr # l
  

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
