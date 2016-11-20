//				Assigment 7
//				Quick Sort
/*
Name - Samkitkumar H. Jain
Date of Performance : 27/7/14
Write a program to sort the given array using quick sort (recursive functions)
*/

#include<stdio.h>
#include<stdlib.h>

int pass=1;

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
		printf("\nPass: %d\t\tPivot: %d\n",pass,p);
		pass++;
		display(a,n);
		quick(a,n,low,j-1);
		quick(a,n,j+1,high);
	}
}

void main()
{
	int a[10],n,ch;
	system("clear");
	n=accept(a);
	printf("Before Sort:\n");
	display(a,n);
	printf("\nDuring Quick Sort:\n");
	quick(a,n,0,n-1);
	printf("\nSorted Array is:\n");
	display(a,n);
	getchar();
}
