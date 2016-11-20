#include<stdio.h>
#include<stdlib.h>
void main(int argc,char *argv[])
{
	int i,c=0;
	FILE *fp1,*fp2;
	char x;
	if(argc!=3)
	{
		printf("Invalid Arguments.\n");
		exit(0);
	}	
	fp1=fopen(argv[1],"r");
	fp2=fopen(argv[2],"w");
	if(fp1==NULL||fp2==NULL)
	{
		printf("FILE OPENING ERROR.\n");
		exit(0);
	}
	while((x=getc(fp1))!=EOF)
	{
		fputc(x,fp2);
	}
	printf("%s file is Copied to %s Successfully.\n",argv[1],argv[2]);
	fclose(fp1);
	fclose(fp2);
}
