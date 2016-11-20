%{
    
    #include<stdio.h>
    int p=0,n=0;
%}
%%
[\t]+ ;

[0-9]+ {p++;}
-[0-9]+ {n++;}
\n {printf("Positive: %d\nNegative: %d",p,n);exit(0);}
. ;
%%
int main()
{
	printf("\n Enter Input: ");
	yylex();
	
    	return 0;
}

