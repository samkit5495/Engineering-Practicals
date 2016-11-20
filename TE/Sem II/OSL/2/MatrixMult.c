/*
				Assigment 2
				Matrix Multiplication using threads
Name - Samkitkumar H. Jain
Date of Performance : 23/01/16
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define MAX 10

void op(long a[][MAX],long m,long n,int o)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(o==0)
				scanf("%ld",&a[i][j]);
			else
				printf("%ld\t",a[i][j]);
		}
		if(o!=0)
			printf("\n");
	}
}

void mult(long temp[])
{
	long x=temp[0]*temp[1];
	pthread_exit((void*)x);
}

int main()
{
	long a[MAX][MAX],b[MAX][MAX],c[MAX][MAX],m,n,p,q,i,j,k;
	printf("Enter Size of A Matrix:\nRow: ");
	scanf("%ld",&m);
	printf("\nColumn: ");
	scanf("%ld",&n);
	printf("\nEnter Matrix A: ");
	op(a,m,n,0);
	printf("Enter Size of B Matrix:\nRow: ");
	scanf("%ld",&p);
	printf("\nColumn: ");
	scanf("%ld",&q);
	printf("\nEnter Matrix B: ");
	op(b,p,q,0);
	printf("\nMatrix A:\n");
	op(a,m,n,1);
	printf("\nMatrix B:\n");
	op(b,p,q,1);
	if(n!=p)
	{
		printf("Invalid Matrix Sizes!!!\n");
		exit(0);
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
		{
			c[i][j]=0;
			for(k=0;k<p;k++)
			{
				pthread_t t[p];
				long temp[]={a[i][k],b[k][j]},x;
				pthread_create(&t[k],NULL,(void*)mult,temp);
				pthread_join(t[k],(void*)&x);
				c[i][j]+=x;
			}
		}
	}
	printf("\nMatrix A x B:\n");
	op(c,m,q,1);
	return 0;
}
