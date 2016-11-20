/*
                Assigment 5 C
                Signal
Name - Samkitkumar H. Jain
Date of Performance : 16/03/16
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

int nprocess=0;

void child(int n)
{
	printf("Child[%d], child with pid=%d sleeping for %d seconds\n",n,getpid(),n);
	sleep(n);
	printf("Child[%d], I am exiting!!!\n",n);
	exit(100+n);
}

void catch()
{
	int status;
	int pid=waitpid(-1,&status,0);
	printf("Parent:Child Process pid=%d exited with value %d\n",pid,WEXITSTATUS(status));
	nprocess--;
}

int main()
{
	int i,n;
	signal(SIGCHLD,catch);
	printf("Enter no of Child Processes to create: \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		switch(fork())
		{
			case 0:
				child(i);
				break;
			case -1:
				perror("fork");
				break;
			default:
				nprocess++;
				break;
		}
		printf("Parent sleep\n");
		while(nprocess!=0)
		{
			printf("Parent Sleeping!!!\n");
			sleep(120);
		}
	}
	printf("Parent Exiting!!!\n");	
	return 0;
}
