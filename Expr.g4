grammar Expr;
prog:base;


base: (function)* mainFunction;

function : typevar VAR '(' param? ')' core ;

mainFunction : 'int main' '(' ')'core ;

param : typevar VAR (',' typevar VAR)*;

core: '{' code* ret '}';

code: typevar vari ';' #decdef
    | VAR '=' expr ';' #aff
    | condition #condif
    | typevar VAR '=' VAR'(' VAR? (',' VAR)* ')' ';' #decfunc
    | VAR '=' VAR '(' VAR? (',' VAR)* ')' ';' #afffunc
    | VAR '(' VAR? (',' VAR)* ')' ';'#callfunc
    | exprl'=' expr ';' #lvalue
    ;

exprl: (expr operatorAll)* VAR (operatorAll expr)*;

operatorAll: OPERATORADD #add_l
            | OPERATORSUB #sub_l
;

condition: 'if' '('boolExpression')' '{'coreIf'}' 'else' '{'coreElse'}' #ifElse
    |'if' '('boolExpression')' '{'coreIf'}' #simpleIf
    |'while' '('boolExpressionWhile')' '{'coreIf'}' #whileLoop
;

coreIf:ifCore;
coreElse:ifCore;

ifCore:code* #ifCommande
    | code* ret #ifRet
    ;

boolExpressionWhile:predicat;
boolExpression:predicat;

predicat:expr '==' expr #egal
    |expr '>=' expr # ge
    |expr '>' expr # gt
    |expr '<=' expr # le
    |expr '<' expr # lt
    |expr '!=' expr # negal
    ;

ret: 'return' expr ';' ;

vari: VAR (','VAR)* #decVar
    | VAR '=' expr #defVar
    ;

expr: terme (operatorAddSub  terme)* ;

terme: facteur ('*' facteur)* ;

facteur: INT #factInt
    | VAR #factVar
    | '(' expr ')' #factPar
    ;




typevar: TYPEINT #int
    | TYPECHAR #char
    ;

operatorAddSub: OPERATORADD #add
    | OPERATORSUB #sub
    ;

TYPEINT: 'int';
TYPECHAR:'char';
OPERATORADD: '+';
OPERATORSUB: '-';
INT: [0-9]+ ;
VAR: [a-zA-Z]+ ;
WS: [ \t\r\n] -> skip;
