/*
				Assigment 3
				Macro
Name: Jain Samkitkumar Hasmukhlal
Class: TEIT	Roll. No.: 20   Batch:T1
Date:01/03/2016

Write a program to implement Macro Processor. (AIF and AGO not expected, nested macro calls not expected) with Error Handling: Macro Duplicate definition, Parameter Mismatching etc.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 50

char line[120];
char first[30],second[30],third[30];

struct PNTAB//Parameter Name Table
{
    char name[20];
}PNTAB[max];

struct MNT//Macro Name Table
{
    char name[20];
    int PP;//Positional Parameter
    int KP;//Keyword Parameter
    int EV;//Expansion Time Variable
    int MDTP;//MDT Pointer
    int KPDTP;//KPDT Pointer
    int SSTP;//SSTAB Pointer
}MNT[max];

struct KPDTAB//Keyword Parameter Table
{
    char name[20],value[20];
}KPDTAB[max];

struct MDT//Macro Definition Table
{
    char opcode[20],operand1[20],operand2[20];
}MDT[max];

struct APTAB//Actual Parameter Table
{
    char value[20];
}APTAB[max];

int KPDTAB_ptr=1,MDT_ptr=1,MNT_ptr=0,PNTAB_ptr=1,MEC=0;

char* getParameter(char t[])
{
	int i;
	for(i=1;i<=MNT[MNT_ptr].PP+MNT[MNT_ptr].KP;i++)
	{
		if(strcmp(PNTAB[i].name,t)==0)
		{
			sprintf(t,"(P,#%d)",i);
			return t;
		}
	}
	return t-1;
}

int inMNT(char name[])
{
    int i;
    for(i=1;i<=MNT_ptr;i++)
        if(strcmp(MNT[i].name,name)==0)
            return i;
    return 0;
}

int getParameterIndex(char t[])
{
	int i,j=0;
	char c[5];
	for(i=4;t[i]!=')';i++)
		c[j++]=t[i];
	c[j]='\0';
	return atoi(c);
}

int getKPIndex(char t[],int n)
{
	int i;
	for(i=MNT[n].KPDTP;i<=MNT[n].KPDTP+MNT[n].KP;i++)
		if(strcmp(KPDTAB[i].name,t)==0)
			return i;
	return -1;
}

int main()
{
    FILE *fp,*fpw;
    int i,j,n;
    char *t,line1[120];
    fp=fopen("Macro1","r");
    fpw=fopen("Assembly.asm","w");
	fgets(line,120,fp);
    while(strcmp(line,"END\n")!=0)
    {
        if(strcmp(line,"MACRO\n")==0)//Processing of Macro Definition
        {
            PNTAB_ptr=1;
            fgets(line,120,fp);
            t=strtok(line," \t\n");//get macro name
            strcpy(MNT[++MNT_ptr].name,t);//copy macro name
            t=strtok(NULL," &\n");//get next Parameter
            while(t!=NULL&&strchr(t,'=')==NULL)//positional Parameter (t!=NULL for checking 0 parameters)
            {
                strcpy(PNTAB[PNTAB_ptr++].name,t);
                t=strtok(NULL," &\n");
            }
            MNT[MNT_ptr].PP=PNTAB_ptr-1;
            MNT[MNT_ptr].KPDTP=KPDTAB_ptr;
            while(t!=NULL)//keyword parameter
            {
            	strncpy(KPDTAB[KPDTAB_ptr].name,t,(long)(strchr(t,'=')-t));//keyword parameter name
            	strncpy(PNTAB[PNTAB_ptr++].name,t,(long)(strchr(t,'=')-t));
				strcpy(KPDTAB[KPDTAB_ptr++].value,strchr(t,'=')+1);
				t=strtok(NULL," &\n");//for next parameter
            }
            MNT[MNT_ptr].KP=KPDTAB_ptr-1;
            MNT[MNT_ptr].MDTP=MDT_ptr;
            fgets(line,120,fp);
           	while(strcmp(line,"MEND\n")!=0)
           	{
           		sscanf(line,"%s\t%s\t%s",first,second,third);
                strcpy(MDT[MDT_ptr].opcode,getParameter(first+1));
                strcpy(MDT[MDT_ptr].operand1,getParameter(second+1));
                strcpy(MDT[MDT_ptr++].operand2,getParameter(third+1));
        		fgets(line,120,fp);
           	}
           	strcpy(MDT[MDT_ptr++].opcode,"MEND");
            if(MNT[MNT_ptr].KP==0)
                MNT[MNT_ptr].KPDTP=0;
        }
        fgets(line,120,fp);
        strcpy(line1,line);
        n=inMNT(strtok(line1," \n"));//Macro calling name
        if(n)//Macro Expansion
        {
            MEC=MNT[n].MDTP;
            for(i=1;i<=MNT[n].PP;i++)//Positional Parameters
                strcpy(APTAB[i].value,t=strtok(NULL," \n"));
            for(j=1;j<=MNT[n].KP;j++)//Default Keyword Parameters
                strcpy(APTAB[MNT[n].PP+j].value,KPDTAB[MNT[n].KPDTP+j-1].value);//KPDTP+j-1
            while((t=strtok(NULL," &=\n"))!=NULL)//Keyword Parameters
                strcpy(APTAB[MNT[n].PP+getKPIndex(t,n)-MNT[n].KPDTP+1].value,strtok(NULL," \n"));//PP+KPTAB Index-KPDTP+1
            while(strcmp(MDT[MEC].opcode,"MEND")!=0)
            {
            	if(MDT[MEC].opcode[0]=='(')
            		fprintf(fpw,"+%s ",APTAB[getParameterIndex(MDT[MEC].opcode)].value);
            	else
            		fprintf(fpw,"+%s ",MDT[MEC].opcode);
            	if(MDT[MEC].operand1[0]=='(')
            		fprintf(fpw,"%s ",APTAB[getParameterIndex(MDT[MEC].operand1)].value);
            	else
            		fprintf(fpw,"%s ",MDT[MEC].operand1);
            	if(MDT[MEC].operand2[0]=='(')
            		fprintf(fpw,"%s\n",APTAB[getParameterIndex(MDT[MEC].operand2)].value);
            	else
            		fprintf(fpw,"%s\n",MDT[MEC].operand2);
            	MEC++;
            }
        }
        else if(strcmp(line,"MACRO\n")!=0)
            fprintf(fpw,"%s",line);
    }
	printf("\n\tPNTAB\nSr. No.\tName\n");
	for(i=1;i<=MNT[MNT_ptr].PP+MNT[MNT_ptr].KP;i++)
		printf("%d\t%s\n",i,PNTAB[i].name);
	printf("\n\tKPDTAB\nSr. No.\tName\tValue\n");
	for(i=1;i<KPDTAB_ptr;i++)
		printf("%d\t%s\t%s\n",i,KPDTAB[i].name,KPDTAB[i].value);
	printf("\n\tMNT\nSr. No.\tName\t\tPP\tKP\tEV\tMDTP\tKPDTP\tSSTP\n");
    for(i=1;i<=MNT_ptr;i++)
    	printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n",i,MNT[i].name,MNT[i].PP,MNT[i].KP,MNT[i].EV,MNT[i].MDTP,MNT[i].KPDTP,MNT[i].SSTP);
    printf("\n\tMDT\nSr. No.\tOpcode\tOperand 1\tOperand 2\n");
    for(i=1;i<=MDT_ptr;i++)
        printf("%d\t%s\t%s\t\t%s\n",i,MDT[i].opcode,MDT[i].operand1,MDT[i].operand2);
     printf("\n\tAPTAB\nSr. No.\tName\n");
    for(i=1;i<=MNT[MNT_ptr].PP+MNT[MNT_ptr].KP;i++)
    	printf("%d\t%s\n",i,APTAB[i].value);
    return 0;
}
