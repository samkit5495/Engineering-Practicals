%{
    
    #include<stdio.h>
%}
%%
[\t]+ ;
is |
was |
go {printf("\n %s is a verb",yytext);}
[a-z]+ {printf("\n %s is not a verb",yytext);}
.|\n {ECHO;}
%%
int main()
{
    printf("\n Enter Input: ");
    yylex();
    return 0;
}

