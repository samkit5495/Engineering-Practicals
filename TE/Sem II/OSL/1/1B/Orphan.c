/*
				Assigment 1 A
				Orphan
Name: Jain Samkitkumar Hasmukhlal
Class: TEIT	Roll. No.: 20   Batch:T1
Date of Performance : 19/12/15
*/

#include<stdio.h>
#include<sys/types.h>

void childprocess()
{
	printf("\n\t----CHILD PROCESS----\n");
	printf("\nChild process id is : %d\n",getpid());
	sleep(10);
	printf("\nNew Parent process id is : %d\n",getppid());
}

void parentprocess()
{
	printf("\n\t----PARENT PROCESS----\n");
	printf("\nParent process id is : %d\n",getpid());
}

int main()
{
	pid_t pid;
	pid=fork();

	if(pid>0)
		parentprocess();
	else
		childprocess();
	return 0;
}
