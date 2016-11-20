//				Assigment 1
//				Set Operations
/*
Name - Samkitkumar H. Jain
Date of Performance : 11/7/14
Write a program to perform following  operations on set using functions
1. Union
2. Intersection
3. Difference	A-B & B-A
4. Symmetric difference
*/
#include<stdio.h>
#include<stdlib.h>

int accept(int a[100])
{
	int i,n;
	printf("Enter no of Elements in Set: ");
	scanf("%d",&n);
	printf("\nEnter Elements in Set of: ");
	for(i=0;i<n;i++)
	{
		printf("\nIndex %d: ",i+1);
		scanf("%d",&a[i]);
	}
	return n;
}

void display(int a[100],int n)
{
	int i;
	printf("{");
	for(i=0;i<n-1;i++)
	{
		printf(" %d,",a[i]);
	}
	printf(" %d }",a[i]);
}

int member(int a[100],int n,int x)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
			return 1;
	}
	if(i==n)
		return 0;
}

int Union(int a[100],int b[100],int c[200],int n1,int n2)
{	
	int i,j,n3=0;
	for(i=0;i<n1;i++)
	{
		c[n3]=a[i];
		n3++;
	}
	for(j=0;j<n2;j++)
	{
		for(i=0;i<n1;i++)
		{
			if(b[j]==a[i])
				break;
		}
		if(i==n1)
		{
			c[n3]=b[j];
			n3++;
		}
	}
	return n3;
}

int inter(int a[100],int b[100],int c[200],int n1,int n2)
{	
	int i,j,n3=0;
	for(j=0;j<n2;j++)
	{
		for(i=0;i<n1;i++)
		{
			if(b[j]==a[i])
			{
				c[n3]=b[j];
				n3++;
			}
		}
	}
	return n3;
}

int diff(int a[100],int b[100],int c[200],int n1,int n2)
{	
	int i,j,n3=0;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(b[j]==a[i])
				break;
		}
		if(j==n2)
		{
			c[n3]=a[i];
			n3++;
		}
	}
	return n3;
}

int symmetric(int a[100],int b[100],int c[200],int n1,int n2)
{
	int p[200],q[200],n3,n4,n5;
	n4=Union(a,b,p,n1,n2);
	n5=inter(a,b,q,n1,n2);
	n3=diff(p,q,c,n4,n5);
	return n3;
}

void main()
{
	//declaration
	int a[100],b[100],c[200],n1,n2,n3,n4,ch,x;
	system("clear");
	while(1)
	{
		system("clear");
		//Operation selection
		printf("\nOperations on Set:\n1. Input\n2. Membership\n3. Equality\n4. Union\n5. Intersection\n" 
			"6. Difference (A-B)\n7. Difference (B-A)\n8. Symmetric Difference\n9. Exit\nEnter your choice ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				//Input 2 sets
				n1=accept(a);
				n2=accept(b);	
				//Display 2 sets
				printf("Set A: ");
				display(a,n1);
				printf("\nSet B: ");
				display(b,n2);
				getchar();
				break;
			case 2:
				printf("Set A: ");
				display(a,n1);
				printf("\nSet B: ");
				display(b,n2);
				printf("\nEnter element to find: ");
				scanf("%d",&x);
				printf("\nMembership: ");
				n3=member(a,n1,x);
				n4=member(b,n2,x);
				if(n3==1&&n4==1)
					printf("%d is an element of set A & B.",x);
				else if(n3==1)
					printf("%d is an element of set A.",x);
				else if(n4==1)
					printf("%d is an element of set B.",x);
				else
					printf("%d is not an element of set A nor set B.",x);
				getchar();
				break;
			case 3:
				printf("Set A: ");
				display(a,n1);
				printf("\nSet B: ");
				display(b,n2);
				printf("\nEquality: ");
				n3=inter(a,b,c,n1,n2);
				if(n3==n1&&n3==n2)
					printf("Both Sets are equal.");
				else
					printf("Both Sets not are equal.");
				getchar();
				break;
			case 4:
				printf("Set A: ");
				display(a,n1);
				printf("\nSet B: ");
				display(b,n2);
				printf("\nUnion: ");
				n3=Union(a,b,c,n1,n2);
				if(n3==0)
					printf("NULL");
				else
					display(c,n3);
				getchar();
				break;
			case 5:
				printf("Set A: ");
				display(a,n1);
				printf("\nSet B: ");
				display(b,n2);
				printf("\nIntersection: ");
				n3=inter(a,b,c,n1,n2);
				if(n3==0)
					printf("NULL");
				else
					display(c,n3);
				getchar();
				break;
			case 6:
				printf("Set A: ");
				display(a,n1);
				printf("\nSet B: ");
				display(b,n2);
				printf("\nDifference (A-B): ");
				n3=diff(a,b,c,n1,n2);
				if(n3==0)
					printf("NULL");
				else
					display(c,n3);
				getchar();
				break;
			case 7:
				printf("Set A: ");
				display(a,n1);
				printf("\nSet B: ");
				display(b,n2);
				printf("\nDifference (B-A): ");
				n3=diff(b,a,c,n2,n1);
				if(n3==0)
					printf("NULL");
				else
					display(c,n3);
				getchar();
				break;
			case 8:
				printf("Set A: ");
				display(a,n1);
				printf("\nSet B: ");
				display(b,n2);
				printf("\nSymmetric Difference: ");
				n3=symmetric(a,b,c,n1,n2);
				if(n3==0)
					printf("NULL");
				else
					display(c,n3);
				getchar();
				break;
			case 9:
				exit(0);
				break;
			default:
				printf("Pls. Enter correct choice\n");
				getchar();
		}
		getchar();
	}
	getchar();
}
