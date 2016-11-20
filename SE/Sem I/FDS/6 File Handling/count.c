/*
Name - Samkitkumar H. Jain
Date of Performance : 25/8/14
a) Write C program to implement TYPE and COPY commands of DOS using
command line arguments.
b) Find out number of characters, words, spaces and sentences from a file and
write result in another file.
*/

#include<stdio.h>
#include<stdlib.h>

void main(int argc,char *argv[])
{
	FILE *fp;
	char x;
	int c=0,w=0,sp=0,spf,sen=0;
	if(argc!=3)
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
	while((x=getc(fp))!=EOF)
	{
			c++;
			if(isspace(x))
			{
				sp++;
				spf=1;
			}
			else if(x=='.')
				sen++;
			if(spf==1&&!isspace(x))
			{
				w++;
				spf=0;
			}
	}
	fclose(fp);
	if(c==0)
		printf("File is empty!\n");
	else
	{
		fp=fopen(argv[2],"w");
		if(fp==NULL)
		{
			printf("RESULT FILE OPENING ERROR.\n");
			exit(0);
		}
		fprintf(fp,"----------------------------------\n\t\tResults\n----------------------------------");
		fprintf(fp,"\nNo of Characters: %d",c);
		fprintf(fp,"\nNo of Words: %d",w+1);
		fprintf(fp,"\nNo of Spaces: %d",sp);
		fprintf(fp,"\nNo of Sentences: %d",sen);
		fprintf(fp,"\n----------------------------------");
		fclose(fp);
		printf("\nResult stores in file named %s in same folder.\n",argv[2]);
	}
}
