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
    |   RET	 expr  #ret
    |   VAR	    #var
    |  '{' expr '}' #brac
    |  '(' expr ')' #par
    ;
RET : 'RETURN'|'return' ;    
INT : [0-9]+ ;
VAR : [a-zA-Z]+ ;   
WS : [ |\t|\r|\n]+ -> skip;