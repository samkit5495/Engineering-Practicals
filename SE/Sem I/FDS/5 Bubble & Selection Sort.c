//				Assigment 5
//				Searching & Sorting
/*
Name - Samkitkumar H. Jain
Date of Performance : 27/7/14
Sort the set of strings in ascending order using bubble sort and desending order by using selection sort.
Search for paticular string using binary search.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int accept(char a[10][10])
{
	int i,n;
	printf("Enter no of strings: ");
	scanf("%d",&n);
	printf("\nEnter String No \n");
	for(i=0;i<n;i++)
	{
		printf("%d. ",i+1);
		scanf("%s",a[i]);
	}
	return n;
}

void display(char a[10][10],int n)
{
	int i;
	printf("Strings :\n");
	for(i=0;i<n;i++)
		printf("%d. %s\n",i+1,a[i]);
}

void bubble(char a[10][10],int n)
{
	int i,j,flag=1;
	for(i=1;i<=n-1&&flag==1;i++)
	{
		flag=0;
		for(j=0;j<n-i;j++)
		{
			if(strcmp(a[j],a[j+1])>0)
			{
				char t[10];
				strcpy(t,a[j]);
				strcpy(a[j],a[j+1]);
				strcpy(a[j+1],t);
				flag=1;
			}
		}
		printf("Pass No. %d\n",i);
		display(a,n);
	}
}

void selection(char a[10][10],int n)
{
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(strcmp(a[k],a[j])<0)
				k=j;
		}
		if(i!=k)
		{
			char t[10];
			strcpy(t,a[i]);
			strcpy(a[i],a[k]);
			strcpy(a[k],t);
		}
		printf("Pass No. %d\n",i+1);
		display(a,n);
	}
}

int binsrch(char a[10][10], int n,char x[10])
{
	int low=0,high=n-1,mid;
	for(;low<=high;)
	{
		mid=(low+high)/2;
		if(strcmp(x,a[mid])==0)
			return mid;
		else if(strcmp(x,a[mid])<0)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}

void main()
{
	char a[10][10],x[10];
	int n,ret,ch;
	system("clear");
	while(1)
	{
		system("clear");
		printf("Searching & Sorting\n1. Input\n2. Selection Sort (Descending)\n3. Bubble Sort(Ascending)\n" 
			"4. Binary Search\n5. Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				n=accept(a);
				display(a,n);
				getchar();
				break;
			case 2:
				printf("Before Sort:\n");
				display(a,n);
				printf("After Selection Sort in descending order:\n");
				selection(a,n);
				getchar();
				break;
			case 3:
				printf("Before Sort:\n");
				display(a,n);
				printf("After Bubble Sort in ascending order:\n");
				bubble(a,n);
				getchar();
				break;
			
			case 4:
				printf("Enter string to be find: ");
				scanf("%s",x);
				ret=binsrch(a,n,x);
				display(a,n);
				if(ret==-1)
					printf("String Not Found.");
				else
					printf("Position of String is %d",ret+1);
				getchar();
				break;
			case 5:
				exit(0);
			default:
				printf("Pls. enter correct option.");
				getchar();
		}
		getchar();
	}
	getchar();
}
