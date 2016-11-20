#include<stdio.h>
#include<stdlib.h>
void main(int argc,char *argv[])
{
	int i,c=0;
	FILE *fp;
	char x;
	if(argc!=2)
	{
		printf("Invalid Arguments.\n");
		exit(0);
	}	
	fp=fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("FILE OPENING ERROR.\n");
		exit(0);
	}
	printf("Data in file: \n");
	while((x=getc(fp))!=EOF)
	{
		printf("%c",x);
	}
	printf("\n");
	fclose(fp);
}
