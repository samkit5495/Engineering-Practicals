%{
	//definition section
#include<stdio.h>
#include"y.tab.h"
extern int yylval;
void yyerror(char *);
%} // Delimiter

%%// Delimiter
	//rule section
//re 	action
[0-9]+ {yylval=atoi(yytext); return num;} //returning token using num 
[\t ]+ ;//do nothing using ;
[-+*/()^] return yytext[0];// - sign shows range so should come first
\n return 0;//return calling 
. {ECHO;yyerror("Unexpected Character!!!");}// ECHO displayes the part which is being processed
%%

// user subroutine section
