%{
    
    #include<stdio.h>
    int w=0,l=0,c=0;
%}
%%
[a-zA-Z][\t ]+ {w++;c++;}
[a-zA-Z] {c++;}
\. {l++;w++;}
\n {printf("Word: %d\nLine: %d\nCharacters: %d\n",w,l,c);exit(0);}
. ;
%%
int main()
{
	printf("\n Enter Input: ");
	yylex();
	
    	return 0;
}

