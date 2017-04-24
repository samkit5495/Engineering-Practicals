/*
				Assigment 1
				Assembler with Symbols
Name: Jain Samkitkumar Hasmukhlal
Class: TEIT	Roll. No.: 20   Batch:T1
Date:01/01/2016
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char line[120];
char first[30],second[30],third[30],fourth[30];

struct ICode
{
	int loc,code,reg,index;
	char clas[10],sop[10];
}ic[100];

struct SymbolTable
{
	int addr;
	char sym[50];
}st[100];

int icptr=0,stptr=1,lc=1;

int token()
{
    int i,c=0;
    for(i=0;i<strlen(line);i++)
        if(line[i]==' '||line[i]=='\n')
            c++;
    sscanf(line,"%s\t%s\t%s\t%s",first,second,third,fourth);
    return c;
}

int getCode(char t[])
{
	if(strcmp(t,"STOP")==0)
		return 0;
	else if(strcmp(t,"ADD")==0)
		return 1;
	else if(strcmp(t,"SUB")==0)
		return 2;
	else if(strcmp(t,"MULT")==0)
		return 3;
	else if(strcmp(t,"MOVER")==0)
		return 4;
	else if(strcmp(t,"MOVEM")==0)
		return 5;
	else if(strcmp(t,"COMP")==0)
		return 6;
	else if(strcmp(t,"BC")==0)
		return 7;
	else if(strcmp(t,"DIV")==0)
		return 8;
	else if(strcmp(t,"READ")==0)
		return 9;
	else if(strcmp(t,"PRINT")==0)
		return 10;
	else
		return -1;
}

int getReg(char t[])
{
	if(strcmp(t,"AREG")==0||strcmp(t,"LT")==0)
		return 1;
	else if(strcmp(t,"BREG")==0||strcmp(t,"LE")==0)
		return 2;
	else if(strcmp(t,"CREG")==0||strcmp(t,"EQ")==0)
		return 3;
	else if(strcmp(t,"DREG")==0||strcmp(t,"GT")==0)
		return 4;
	else if(strcmp(t,"GE")==0)
		return 5;
    else if(strcmp(t,"ANY")==0)
		return 6;
    else
        return 0;
}

int getSymbol(char t[])
{
	int i;
	for(i=1;i<stptr;i++)
		if(strcmp(t,st[i].sym)==0)
			return i;
	st[stptr].addr=-1;
	strcpy(st[stptr].sym,t);
	return stptr++;
}

int main(int argc,char *argv[])
{
    FILE *fp,*fpi;
    int i,flag=0;
    fp=fopen("Symbol.asm","r");
    fgets(line,120,fp);
    while(strcmp(line,"END\n")!=0&&strcmp(line,"END")!=0)
    {
        int n=token();
        if(n>4)
        {
            printf("\nWrong Statement %s",line);
            exit(0);
        }
        if(strcmp(first,"START")==0||strcmp(first,"ORIGIN")==0)
        {
            lc=atoi(second);
        }
        else if(strcmp(second,"EQU")==0)
        {
        	i=getSymbol(first);
        	st[i].addr=st[getSymbol(third)].addr;
        }
        else
        {
            if(getCode(first)==-1)
            {
                i=getSymbol(first);
                st[i].addr=lc;
                n--;
                strcpy(first,second);
                strcpy(second,third);
                strcpy(third,fourth);
            }
            ic[icptr].loc=lc;
	        ic[icptr].code=getCode(first);
            strcpy(ic[icptr].clas,"IS");
            strcpy(ic[icptr].sop,"S");
            if(n==3)
            {
                ic[icptr].reg=getReg(second);
                ic[icptr++].index=getSymbol(third);
            }
            else if(n==2)
            {
                if(strcmp(first,"DC")==0)
                {
                    strcpy(ic[icptr].clas,"DL");
                    ic[icptr].code=1;
                    strcpy(ic[icptr].sop,"C");
                    ic[icptr++].index=atoi(second);
                }
                else if(strcmp(first,"DS")==0)
                	lc+=atoi(second)-1;
                else
                    ic[icptr++].index=getSymbol(second);
            }
            else if(n==1)
                strcpy(ic[icptr++].sop,"-");
            else
            {
                printf("\nError: Invalid Statement!!!\n");
                exit(0);
            }
            lc++;
        }
        fgets(line,120,fp);
    }
		fpi=fopen("IC_S.txt","w");
		fprintf(fpi,"\n\tIntermediate Code\n");
		for(i=0;i<icptr;i++)
        fprintf(fpi,"%d)\t(%s,%d)\t(%d)\t(%s,%d)\n",ic[i].loc,ic[i].clas,ic[i].code,ic[i].reg,ic[i].sop,ic[i].index);
    printf("\n\tSymbol Table\nSr. No.\tSymbol\tAddress\n");
    for(i=1;i<stptr;i++)
    {
    	if(st[i].addr==-1)
    		flag=1;
        printf("%d\t%s\t%d\n",i,st[i].sym,st[i].addr);
    }
    if(flag==1)
    {
    	printf("\nForward reference (Symbol used but not defined)\n");
    	exit(0);
    }
    //generate machine code
    printf("\n\tMachine Code\n");
    for(i=0;i<icptr;i++)
    {
        int x,y;
        if(strcmp(ic[i].clas,"IS")==0)
            y=ic[i].code;
        else
            y=0;
        if(strcmp(ic[i].sop,"S")==0)
            x=st[ic[i].index].addr;
        else
            x=ic[i].index;
        if(x==-1)
        {
            printf("Error Address Not Assigned!!!\n");
            exit(0);
        }
        printf("%d)+\t%d\t%d\t%d\n",ic[i].loc,y,ic[i].reg,x);
    }
    return 0;
}