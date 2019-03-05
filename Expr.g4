grammar Expr;
prog: expr';';
expr: expr '*' expr #mult
    | expr '/' expr #div
    | expr '+' expr #add
    | expr '-' expr #sub
    |   INT 	    #ldconst
    |   RET	    #ret
    |   VAR	    #var
    |  '{' expr '}' #brac
    |  '(' expr ')' #par
    ;
RET : 'RETURN'|'return' ;    
INT : [0-9]+ ;
VAR : [a-zA-Z]+ ;   
 


