%{
    
    #include<stdio.h>
    int f=0;
%}
%%
[\t]+ ;
and |
or |
because {f=1;};
\n {if(f==1)
		printf("Sentence is compound!\n");
	else    	
		printf("Sentence is simple!\n");}
. ;
%%
int main()
{
	printf("\n Enter Input: ");
	yylex();
	
    	return 0;
}

