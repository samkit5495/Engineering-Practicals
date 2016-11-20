/*
				Assigment 1 C
				Bubble Sort using fork and execve functions
Name - Samkitkumar H. Jain
Date of Performance : 02/01/16
*/
#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
void op(int a[],int n,int o)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(o==0)
			scanf("%d",&a[i]);
		else
			printf("%d ",a[i]);
	}
}

void bubblesort(int a[],int n)
{
	int i,j;
	for(i=1;i<=n-1;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}

int main(int argc,char *argv[])
{
	int n,arr[20],pid,i;
	char *cval[20];
	printf("Enter no of elements: ");
	scanf("%d",&n);
	printf("Enter Elements: ");
	op(arr,n,0);
	printf("\nEntered Elements: ");
	op(arr,n,1);
	bubblesort(arr,n);
	printf("\nSorted Elements: ");
	op(arr,n,1);
	printf("\nEnter element to search: ");
	scanf("%d",&arr[n]);
	for(i=0;i<n+1;i++)
	{
		char x[5];
		snprintf(x,5,"%d",arr[i]);
		cval[i]=malloc(sizeof(x));
		strcpy(cval[i],x);
	}
	cval[i]=NULL;
	pid=fork();
	if(pid==0)
		execve(argv[1],cval,NULL);
	return 0;
}
