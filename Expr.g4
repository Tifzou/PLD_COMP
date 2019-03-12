grammar Expr;
prog: expr';';


code: expr #line;

expr: expr '*' expr #mult
    | expr '/' expr #div
    | expr '+' expr #add
    | expr '-' expr #sub
    |   INT 	    #ldconst
    |   RET	expr  #ret
    |   VAR	    #var
    |  '{' expr '}' #brac
    |  '(' expr ')' #par
    ;

RETOUR : 'void'|'int'|'double'|'char';
RET : 'RETURN'|'return' ;    
INT : [0-9]+ ;
VAR : [a-zA-Z]+ ;   
WS : [ |\t|\r|\n]+ -> skip;

