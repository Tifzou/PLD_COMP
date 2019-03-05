grammar Expr;
prog: expr;
expr: expr '*' expr #mult
    | expr '+' expr #add
    | expr '-' expr #sub
    | expr '/' expr #sub
    |   INT 	    #ldconst
    |   RET	    #ret
    |   VAR	    #var
    |  '{' expr '}' #brac
    |  '(' expr ')' #par
    ;
INT : [0-9]+ ;
VAR : [a-zA-Z]+ ;   
RET : 'RETURN'|'return' ;     
