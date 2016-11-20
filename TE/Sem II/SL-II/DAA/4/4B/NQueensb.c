/*
				Assigment 4 b
				NQueens Non - Recursive
Name: Jain Samkitkumar Hasmukhlal
Class: TEIT	Roll. No.: 20   Batch:T1
*/

#include<stdio.h>
#include<stdlib.h>

int x[100];
static int c=1;

int Place(int k)
{
	int j;
	for(j=1;j<k;j++)
		if(x[j]==x[k]||abs(x[j]-x[k])==abs(j-k))
			return 0;
	return 1;
}

void display(int x[],int n)
{
	int i,j;
	printf("%d.)\n",c++);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i]==j)
				printf(" Q ");
			else
				printf(" - ");
		}
		printf("\n");
	}
}

void NQueens(int n)
{
	int i,k=1;
	x[k]=0;
	while(k!=0)
	{
		x[k]++;
		while(!Place(k)&&x[k]<=n)//value cannot be placed then change value of k
			x[k]++;
		if(x[k]<=n)
		{
			if(k==n)
				display(x,n);
			else
			{
				k++;
				x[k]=0;
			}			
		}
		else
			k--;
	}
}

int main()
{
	int n,k;
	printf("Enter No of queens to place: ");
	scanf("%d",&n);
	printf("All fissible solutions:\n");
	NQueens(n);
	return 0;
}
