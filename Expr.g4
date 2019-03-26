grammar Expr;
prog:expr;

expr: 'int main' '(' ')'core; 
core: '{' code ';' '}'; 
code: 'return' INT ; 

INT : [0-9]+ ;  
WS : [ \t\r\n] -> skip;