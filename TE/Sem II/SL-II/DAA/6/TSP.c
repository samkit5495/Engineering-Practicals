/*
				Assigment 6
				Travelling Salesman Problem
Name: Jain Samkitkumar Hasmukhlal
Class: TEIT	Roll. No.: 20   Batch:T1
Date:19/01/2016
*/
#include <stdio.h>
#define max 10

int visited[max],n,cost[max],l=0,a[max][max];
static int node_no=1;

void get_matrix()
{
	int i,j;
	printf("Enter No of Cities: ");
	scanf("%d",&n);
	printf("Enter Cost Matrix: \n");
	for(i=0;i<n;i++)
	{
		printf("Enter elements of row:%d ",i+1);
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
		visited[i]=-1;
	}
	printf("Cost Matrix: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%5d",a[i][j]);
		printf("\n");
	}
}

int min1(int temp[][2],int q)
{
	int i,j,small=999;
	for(i=0;i<q;i++)
	{
		if(temp[i][1]<small)
		{
			small=temp[i][1];
			j=i;
		}
	}
	return j;
}

int check_visited(int k)
{
	int i;
	for(i=0;i<l;i++)
		if(visited[i]==k)
			return 1;
	return 0;
}

int find_row_min(int b[][max],int r)
{
	int j,min=999;
	for(j=0;j<n;j++)
		if(b[r][j]<min)
			min=b[r][j];
	if(min==999)
		min=0;
	return min;
}

int find_col_min(int b[][max],int c)
{
	int i,min=999;
	for(i=0;i<n;i++)
		if(b[i][c]<min)
			min=b[i][c];
	if(min==999)
		min=0;
	return min;
}

int reduced_matrix(int b[][max])
{
	int i,j,reduced_sum=0,min;
	for(i=0;i<n;i++)//Row Reduction
	{
		min=find_row_min(b,i);
		reduced_sum+=min;
		for(j=0;j<n;j++)
			if(b[i][j]!=999)
				b[i][j]-=min;
	}
	for(i=0;i<n;i++)//Column Reduction
	{
		min=find_col_min(b,i);
		reduced_sum+=min;
		for(j=0;j<n;j++)
			if(b[j][i]!=999)
				b[j][i]-=min;
	}
	printf("\nReduced Matrix for Node no: %d is:\n",node_no++);
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("%5d",b[i][j]);
	}
	return reduced_sum;
}

void dynamic_reduction()
{
	int temp[max][2],q,p,m[max][max][max],sum=0,i,j,k;
	while(l<n)
	{
		q=0;//no of not visited nodes
		for(i=0;i<n;i++)
			if(check_visited(i)==0)
				temp[q++][0]=i;
		for(i=0;i<q;i++)//loop for each not visited vertex
		{
			for(k=0;k<n;k++)//copy into a new matrix m
				for(j=0;j<n;j++)
					m[i][k][j]=a[k][j];
			//we don't have to visit visited node so make their path to infinity
			for(k=0;k<l;k++)
				for(j=0;j<n;j++)
					m[i][visited[k]][j]=999;// make row infinity for visited city
			for(k=1;k<l;k++)
				for(j=0;j<n;j++)
					m[i][j][visited[k]]=999;// make col infinity  for next visited city
			for(j=0;j<n;j++)   // make col infinity for the city to be visited
				m[i][j][temp[i][0]]=999;//temp[i][0] is present visiting node
			for(j=1;j<l;j++)//make m[j][i] infinity  for i to j path
				m[i][visited[j]][0]=999;
			m[i][temp[i][0]][0]=999;
			sum=reduced_matrix(m[i]);
			temp[i][1]=cost[l-1]+sum+a[visited[l-1]][temp[i][0]];
			printf("\nCost of Node%d=%d\n",node_no-1,temp[i][1]);
		}
		p=min1(temp,q);
		visited[l]=temp[p][0];
		cost[l++]=temp[p][1];
		for(k=0;k<n;k++)//copy into a new matrix m
			for(j=0;j<n;j++)
				a[k][j]=m[p][k][j];
		printf("Minimum cost city is= %d and its cost is %d\n",temp[p][0]+1,temp[p][1]);
	}
}

void display_path()
{
	int i;
	printf("\nThe path of tour is: ");
	for(i=0;i<=n;i++)
		printf("%5d",visited[i]+1);
	printf("\nMinimum cost of tour is: %d\n",cost[l-1]);
}

int main()
{
	system("clear");
	get_matrix();
	visited[l]=0;
	cost[l++]=reduced_matrix(a);
	dynamic_reduction();
	display_path();
	return 0;
}
