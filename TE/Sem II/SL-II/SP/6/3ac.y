%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void ThreeAddressCode();
char AddToTable(char,char,char);
void codeforif();
void codeforthen();
void codeforelse();
void yyerror(char *);
int count,ind=1,label=1;
char temp='A',temp1='A';

struct incod
{
	char opd1,opd2,opr;
}code[20];
%}

%union
{
	char sym;
}

%token IF THEN ELSE
%token <sym> ID
%type <sym> expr
%right '='
%left '-''+'
%left '*''/'
%left '>''<'

%%
st:IF'('expr')'{codeforif();}THEN expr';'{codeforthen();}ELSE expr';'{codeforelse();}
;
expr:expr'+'expr {$$=AddToTable($1,$3,'+');}
|expr'-'expr {$$=AddToTable($1,$3,'-');}
|expr'*'expr {$$=AddToTable($1,$3,'*');}
|expr'/'expr {$$=AddToTable($1,$3,'/');}
|expr'>'expr {$$=AddToTable($1,$3,'>');}
|expr'<'expr {$$=AddToTable($1,$3,'<');}
|ID'='expr {$$=AddToTable($1,$3,'=');}
|ID {$$==$1;}
;
%%

char AddToTable(char opd1,char opd2,char opr)
{
	code[ind].opd1=opd1;
	code[ind].opd2=opd2;
	code[ind].opr=opr;
	ind++;
	temp++;
	return temp-2;
}
void codeforif()
{
	printf("if(%c %c %c) goto L%d",code[ind-1].opd1,code[ind-1].opr,code[ind-1].opd2,label++);
	printf("\ngoto L%d",label++);
	count=ind;
}

void ThreeAddressCode()
{
	while(count<ind)
	{
		printf("%c:=\t%c\t%c\t%c\n",temp1,code[count].opd1,code[count].opr,code[count].opd2);
		temp1++;
		count++;
	}	
}

void codeforthen()
{
	printf("\nL%d:",label-2);
	ThreeAddressCode();
	printf("goto label L%d",label++);
	printf("\nL%d:",label-2);
	count=ind;
}

void codeforelse()
{
	ThreeAddressCode();
	printf("\nL%d\n\n",label-1);
}

int main()
{
	printf("Enter Statement: ");
	yyparse();
}

void yyerror(char *s)
{
	printf("%s\n",s);
}
