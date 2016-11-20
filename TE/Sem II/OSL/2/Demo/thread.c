/*
				Assigment 2
				Threads
Name - Samkitkumar H. Jain
Date of Performance : 23/01/16
*/
#include<stdio.h>
#include<pthread.h>

#define num 5

void print(long t)
{
	printf("Thread No: %ld\n",t);
	pthread_exit((void*)t);
}

int main()
{
	pthread_t t[num];
	long i,status;
	for(i=0;i<num;i++)
	{
		printf("In main thread:%ld\n",i);
		pthread_create(&t[i],NULL,(void*)print,(void *)i);
		pthread_join(t[i],(void*)&status);
		printf("Status: %ld\n",status);
	}
	return 0;
}
