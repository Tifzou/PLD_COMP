grammar Expr;
preg: expr;
expr: expr '*' expr #mult
    | expr '+' expr #add
    | expr '-' expr #sub
    |   INT 	    #ldconst
    |   VAR	    #var
    |  '{' expr '}' #brac
    |  '(' expr ')' #par
    ;
INT : [0-9]+ ;
VAR : [a-zA-Z]+ ;
