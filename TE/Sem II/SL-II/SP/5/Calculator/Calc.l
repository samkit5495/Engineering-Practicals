%{
#include<stdio.h>
#include"y.tab.h"
extern int yylval;
void yyerror(char *);
%}

%%
[0-9]+ {yylval=atoi(yytext); return num;}
[\t ]+ ;
[-+*/()^] return yytext[0];
\n return 0;
. {ECHO;yyerror("Unexpected Character!!!");}
%%