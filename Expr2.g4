/*
grammar Expr;
prog:func;
func:type  name '('')' '{' expr1+ '}'; 
name: VAR+;
param:type INT+;
type:'int';
expr1: expr';';
expr: expr '*' expr #mult
    | expr '/' expr #div
    | expr '+' expr #add
    | expr '-' expr #sub
    |   INT 	    #ldconst
    |   VAR	    #var
    |  '{' expr '}' #brac
    |  '(' expr ')' #par
    ;
RET : 'RETURN'|'return' ;    
INT : [0-9]+ ;
VAR : [a-zA-Z]+ ;   
WS : [ |\t|\r|\n]+ -> skip;

*/

/*grammar Expr;
prog:expr;

expr: 'int main' '(' ')'core; 
core: '{' code ';' '}'; 
code:'return' INT ; 

INT : [0-9]+ ;  
WS : [ \t\r\n] -> skip;

*/



/*dernière grammaire
expr: '(' expr ')' #par
    | expr '*' expr #mult
    | expr '/' expr #div
    | expr '+' expr #add
    | expr '-' expr #sub
    |   VAR	    #var
    |   INT 	#ldconst
    ;
*/
