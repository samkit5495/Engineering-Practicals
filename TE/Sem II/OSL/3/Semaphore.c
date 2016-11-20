/*
				Assigment 3
				Semaphore
Name - Samkitkumar H. Jain
Date of Performance : 02/02/16
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#define BF 10

pthread_mutex_t mutex;
sem_t full,empty;
int buffer[BF],counter;
pthread_t tid;

void initialize()
{
    pthread_mutex_init(&mutex,NULL);
    sem_init(&full,0,0);
    sem_init(&empty,0,BF);
    counter=0;
}

void insert_item(int item)
{
    buffer[counter++]=item;
}

int remove_item()
{
    return buffer[--counter];
}

void producer()
{
    int item;
    sleep(rand()%5);//wait time
    item=rand()%10;
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    printf("Producer produced %d\n",item);
    insert_item(item);
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
}

void consumer()
{
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    printf("Consumed item %d\n",remove_item());
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
}

int main()
{
    int p=0,c=0,i;
    initialize();
    do
    {
        if(p<c)
            printf("Consumers cannot be more than producers!!!\n");
        printf("Enter No of Producers: ");
        scanf("%d",&p);
        printf("Enter No of Consumers: ");
        scanf("%d",&c);
    }
    while(p<c);
    for(i=0;i<p;i++)
        pthread_create(&tid,NULL,(void*)producer,NULL);
    for(i=0;i<c;i++)
        pthread_create(&tid,NULL,(void*)consumer,NULL);
    sleep(9999);
    return 0;
}
