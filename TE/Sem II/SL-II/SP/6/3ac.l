%{
#include<stdio.h>
#include"y.tab.h"
extern char yyval;
%}

%%
if {return IF;}
then {return THEN;}
else {return ELSE;}
[a-z] {yylval.sym=yytext[0];return ID;}
\n {return 0;}
. {return yytext[0];}
%%
