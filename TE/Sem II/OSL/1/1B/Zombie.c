/*
				Assigment 1 B
				Zombie
Name: Jain Samkitkumar Hasmukhlal
Class: TEIT	Roll. No.: 20   Batch:T1
Date of Performance : 19/12/15

ps aux

ps = process state

a = show processes for all users
u = display the process's user/owner
x = also show processes not attached to a terminal

*/

#include<stdio.h>
#include<sys/types.h>

void childprocess()
{
	printf("\n\t----CHILD PROCESS----\n");
	printf("\nChild process id is : %d\n",getpid());
}

void parentprocess()
{
	sleep(10);
	printf("\n\t----PARENT PROCESS----\n");
	printf("\nParent process id is : %d\n",getpid());
	system("ps u");
}

void main(void)
{
	pid_t pid;
	pid=fork();

	if(pid==0)
		childprocess();
	else
		parentprocess();
}
