grammar Expr;
prog:base;



base: 'int main' '(' ')'core; 

core: '{' code* ret '}';

code: typevar vari ';' #decdef
    | VAR '=' expr ';' #aff
    ;


ret: 'return' VAR ';' ;
vari: VAR (','VAR)* #decVar
    | VAR '=' expr #defVar
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
