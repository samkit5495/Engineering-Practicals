/*
				Assigment 5
				Pipe Implementation
Name - Samkitkumar H. Jain
Date of Performance : 09/02/16
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>

void pipe_t(char filename[])
{
	pid_t pid;
	FILE *fp;
	int A[2],B[2],nbytes,i=0;
	char buffer[100]="",context[200],ch;
	pipe(A);//0 - read	1 - write
	pipe(B);
	pid=fork();
	if(pid!=0)
	{
		close(A[0]);
		write(A[1],filename,strlen(filename));
		close(B[1]);
		nbytes=read(B[0],buffer,sizeof(buffer));
		printf("Context of file:\n%s",buffer);
		printf("No of bytes in file %d\n",nbytes);
		close(B[0]);
		exit(0);
	}
	else
	{
		close(A[1]);
		nbytes=read(A[0],buffer,sizeof(buffer));
		printf("Received File Name %s\n",buffer);
		printf("No of bytes Received: %d\n",nbytes);
		fp=fopen(buffer,"r");
		//while((context[i++]=fgetc(fp))!=EOF);
		while((ch=fgetc(fp))!=EOF)
			context[i++]=ch;
		context[i]='\0';
		close(B[0]);
		write(B[1],context,strlen(context));
	}
}

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("Invalid Arguments!!!\n");
		exit(0);
	}
	pipe_t(argv[1]);
	return 0;
}
