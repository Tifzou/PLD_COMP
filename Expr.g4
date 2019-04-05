grammar Expr;
prog:base;



base: 'int main' '(' ')'core; 

core: '{' code* ret '}';

code: typevar vari ';' #decdef
    | VAR '=' expr ';' #aff
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
