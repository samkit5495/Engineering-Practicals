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

struct LiteralTable
{
    int val,addr;
}lt[100];

int pt[100];

int icptr=0,stptr=1,ltptr=1,lc=1,ptp=1;

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

int getLiteral(char t[])
{
	int i;
    for(i=pt[ptp];i<ltptr;i++)
		if(atoi(t+1)==lt[i].val)
			return i;
	lt[ltptr].addr=-1;
	lt[ltptr].val=atoi(t+1);
	return ltptr++;
}

void LiteralAddress()
{
    int i;
    for(i=pt[ptp];i<ltptr;i++)
    {
        lt[i].addr=ic[icptr].loc=lc++;
        strcpy(ic[icptr].clas,"DL");
        ic[icptr].code=1;
        ic[icptr].reg=0;
        strcpy(ic[icptr].sop,"C");
        ic[icptr++].index=lt[i].val;

    }
    pt[++ptp]=ltptr;//pt-pooltab
}

int main(int argc,char *argv[])
{
    FILE *fp,*fpi;
    int i,j=0,flag=0;
    pt[ptp]=1;
    fp=fopen("Mix.asm","r");
    fgets(line,120,fp);
    while(strcmp(line,"END\n")!=0&&strcmp(line,"END")!=0)
    {
    	j++;
        int n=token();
        if(n>4)
        {
            printf("\nWrong Statement %s",line);
            exit(0);
        }
        if(strcmp(first,"START")==0||strcmp(first,"ORIGIN")==0)
            lc=atoi(second);
        else if(strcmp(second,"EQU")==0)
        	st[getSymbol(first)].addr=st[getSymbol(third)].addr;
        else if(strcmp(first,"LTORG")==0)
            LiteralAddress();
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
                if(third[0]=='=')
                {
                    strcpy(ic[icptr].sop,"L");
                    ic[icptr++].index=getLiteral(third);
                }
                else
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
                    for(i=lc;i<(lc+atoi(second));i++)
                        ic[icptr++].loc=i;
                else
                    ic[icptr++].index=getSymbol(second);
            }
            else if(n==1)
                strcpy(ic[icptr++].sop,"-");
            else
            {
                printf("\nError: Invalid Statement at line no %d!!!\n",j);
                exit(0);
            }
            lc++;
        }
        fgets(line,120,fp);
    }
    //Assign Address to literals after END
    LiteralAddress();
    close(fp);
    fpi=fopen("IC.txt","w");
    fprintf(fpi,"\n\tIntermediate Code\n");
    for(i=0;i<icptr;i++)
    {
        if(ic[i].code==-1)
            fprintf(fpi,"%d)\n",ic[i].loc);
        else
            fprintf(fpi,"%d)\t(%s,%d)\t(%d)\t(%s,%d)\n",ic[i].loc,ic[i].clas,ic[i].code,ic[i].reg,ic[i].sop,ic[i].index);
    }
    printf("\n\tSymbol Table\nSr. No.\tSymbol\tAddress\n");
    for(i=1;i<stptr;i++)
    {
    	if(st[i].addr==-1)
    		flag=1;
        printf("%d\t%s\t%d\n",i,st[i].sym,st[i].addr);
    }
    printf("\n\tLiteral Table\nSr. No.\tLiteral\tAddress\n");
    for(i=1;i<ltptr;i++)
        printf("%d\t=%d\t%d\n",i,lt[i].val,lt[i].addr);
    printf("\n\tPoolTAB\n");
    for(i=1;i<ptp;i++)
        printf("%d\t%d\n",i,pt[i]);
    if(flag==1)
    {
        close(fpi);
    	printf("\nForward reference (Symbol used but not defined)\n");
    	remove("IC.txt");
    	exit(0);
    }
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
        else if(strcmp(ic[i].sop,"L")==0)
            x=lt[ic[i].index].addr;
        else
            x=ic[i].index;
        if(y==-1)
            printf("%d)+\n",ic[i].loc);
        else
            printf("%d)+\t%d\t%d\t%d\n",ic[i].loc,y,ic[i].reg,x);
    }
    return 0;
}
