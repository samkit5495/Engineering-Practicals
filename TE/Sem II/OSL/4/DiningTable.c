/*
				Assigment 4
				Dining Table Problem
Name - Samkitkumar H. Jain
Date of Performance : 09/02/16
*/
#include<stdio.h>
#include<pthread.h>
pthread_mutex_t Fork[10];

void philosopher(int i)
{
	pthread_mutex_lock(&Fork[i%5]);
	pthread_mutex_lock(&Fork[(i-1)%5]);
	printf("%d philosopher is eating!!!\n",i);
	sleep(4);
	pthread_mutex_unlock(&Fork[(i-1)%5]);
	pthread_mutex_unlock(&Fork[i%5]);
	printf("%d philosopher is relaxing and thinking!!!\n",i);
	sleep(4);
	pthread_exit(NULL);
}

int main()
{
	long i;
	pthread_t pid[10];
	for(i=0;i<5;i++)
		if(pthread_mutex_init(&Fork[i],NULL)!=0)
			printf("Mutex not initialized!!!\n");
	for(i=1;i<=5;i++)
		pthread_create(&pid[i],NULL,(void*)philosopher,(void*)i);
	for(i=1;i<=5;i++)
		pthread_join(pid[i],NULL);
	return 0;
}
