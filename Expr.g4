grammar Expr;
prog:base;



base: 'int main' '(' ')'core; 

core: '{' code* ret ';' '}'; 

code: typevar vari ';'; 


ret: 'return' VAR;
vari: VAR  #dec
    | VAR '=' INT #aff
    | VAR '=' expr #expression
    ;

expr: expr '*' expr #mult
    | expr '/' expr #div
    | expr '+' expr #add
    | expr '-' expr #sub
    |   VAR	    #var
    |   INT 	#ldconst
    |  '(' expr ')' #par
    ;


typevar : TYPEINT #int
    |TYPECHAR #char
    ;

TYPEINT : 'int';
TYPECHAR :'char';
INT : [0-9]+ ; 


VAR : [a-zA-Z]+ ; 
WS : [ \t\r\n] -> skip;
