%{
    
    #include<stdio.h>
    int v=0,c=0;
%}
%%
[\t]+ ;
[aeiou]+ {v++;}
[0-9]+ {ECHO;}
. {c++;}


\n printf("%d %d\n",v,c);
%%
int main()
{
    printf("\n Enter Input: ");
    yylex();
    
    return 0;
}

