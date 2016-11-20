/*
				Assigment 4
				N Queens Problem
Name: Jain Samkitkumar Hasmukhlal
Class: TEIT	Roll. No.: 20   Batch:T1
Date: 09/02/2016
1 reines => 0 solutions
2 reines => 0 solutions
3 reines => 0 solutions
4 reines => 2 solutions
5 reines => 10 solutions
6 reines => 4 solutions
7 reines => 40 solutions
8 reines => 92 solutions
9 reines => 352 solutions
10 reines => 724 solutions
11 reines => 2680 solutions
12 reines => 14200 solutions
13 reines => 73712 solutions
14 reines => 365596 solutions
15 reines => 2279184 solutions
16 reines => 14772512 solutions
17 reines => 95815104 solutions
18 reines => 666090624 solutions
19 reines => 4968057848 solutions (673090552 + 2^32)
20 reines => 39029188884 solutions

*/
#include<stdio.h>

int x[100];
static int c=1;

int Place(int k,int i)
{
	int j;
	for(j=1;j<k;j++)
		if(x[j]==i||abs(x[j]-i)==abs(j-k))
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

void NQueens(int k, int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(Place(k,i))
		{
			x[k]=i;
			if(k==n)
				display(x,n);
			else
				NQueens((k+1),n);
		}
	}
}

int main()
{
	int n,k;
	printf("Enter No of queens to place: ");
	scanf("%d",&n);
	printf("All feasible solutions:\n");
	NQueens(1,n);
	return 0;
}
