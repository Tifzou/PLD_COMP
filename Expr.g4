grammar Expr;
prog:expr;

expr: 'int main' '(' ')'core;
core: '{' code ret ';' '}';
code: typevar vari ';';
ret: 'return' VAR;
vari: VAR  #dec
    | VAR '=' INT #aff
    ;
typevar : TYPEINT #int
    |TYPECHAR #char
    ;
TYPEINT : 'int';
TYPECHAR :'char';
INT : [0-9]+ ;
VAR : [a-zA-Z]+ ;
WS : [ \t\r\n] -> skip;