%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void yyerror(char *s);	
%}

%token num// token declared
//associativity operators
%left '+''-'
%left '*''/'
%left '^'
%left '('')'
%right '='
%nonassoc UMINUS// nonassoc means no associativity

%%
//grammer


op:e {printf("Result=%d\n",$1);}
;
e:e'+'e {$$=$1+$3;}
|e'-'e {$$=$1-$3;}
|e'*'e {$$=$1*$3;}
|e'/'e {if($3==0){ printf("\nDivide by zero error!\n");exit(0);}else $$=$1/$3;}
|e'^'e {$$=pow($1,$3);}
|'('e')' {$$=$2;}
|'-'e %prec UMINUS {$$=-$2;}//%prec assigns '-'e precendence of UMINUS
|num {$$=$1;}
;

%%

int main()
{
	printf("\nEnter the Expression: ");
	yyparse();
	return 0;
}

void yyerror(char *str)
{
	printf("\n%s",str);
}


