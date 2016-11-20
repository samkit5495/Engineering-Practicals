/*
				Assigment 1 A
				Sorting with Fork function
Name - Samkitkumar H. Jain
Date of Performance : 19/12/15
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
int accept(int a[10])
{
	int i,n;
	printf("Enter no of elements to be sorted: ");
	scanf("%d",&n);
	printf("\nEnter Elements No. \n");
	for(i=0;i<n;i++)
	{
		printf("%d. ",i+1);
		scanf("%d",&a[i]);
	}
	return n;
}

void display(int a[10],int n)
{
	int i;
	printf("\n{");
	for(i=0;i<n-1;i++)
		printf("%d, ",a[i]);
	printf("%d}\n",a[i]);
}

void merge(int a[],int l,int m,int h)
{
	int i=l,j=m+1,k=0,c[20];
	while(i<=m && j<=h)
	{
		if(a[i]<a[j])
			c[k++]=a[i++];
		else
			c[k++]=a[j++];
	}
	while(i<=m)
		c[k++]=a[i++];
	while(j<=h)
		c[k++]=a[j++];
	i=l;
	j=0;
	while(i<=h)//copy c to original a
	{
		a[i++]=c[j++];
	}
}

void msort(int a[],int l,int h)
{
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		msort(a,l,m);
		msort(a,m+1,h);
		merge(a,l,m,h);
	}
}

void quick(int a[10],int n,int low, int high)
{
	int i,j,p;
	p=a[low];
	i=low+1;
	j=high;
	if(low<high)
	{
		while(i<=j)
		{
			while(a[i]<=p&&i<=high)
				i++;
			while(a[j]>p&&j>low)
				j--;
			if(i<j)
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		a[low]=a[j];
		a[j]=p;
		quick(a,n,low,j-1);
		quick(a,n,j+1,high);
	}
}

int main()
{
	int a[10],n,ch;
	pid_t pid;
	system("clear");
	n=accept(a);
	printf("Before Sort:\n");
	display(a,n);
	pid=fork();
	if(pid<0)
		printf("Error creating process!!!\n");
	else if(pid>0)
	{
		msort(a,0,n-1);
		printf("\n(Merge Sort) Sorted Array is:\n");
		display(a,n);
	}
	else
	{
		quick(a,n,0,n-1);
		printf("\n(Quick Sort) Sorted Array is:\n");
		display(a,n);
	}	
	getchar();
	return 0;
}
