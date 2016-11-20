//				Assigment 4
//				Structure Manipulation
/*
Name - Samkitkumar H. Jain
Date of Performance : 4/8/14
Write a program to perform following operations on array of structure using pointers
1. Create Database
2. Display Database
3. Add Record
4. Search Record
5. Modify Record
6. Delete Record
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct stud
{
	int rollno;
	char name[10];
	float per;
}stud;

int accept(stud *a)
{
	int n,i;
	printf("\nEnter no of Records: ");
	scanf("%d",&n);
	for(i=0;i<n;i++,a++)
	{
		printf("\nElement Record No %d:\n",i+1);
		printf("Enter Roll. No.: ");
		scanf("%d",&a->rollno);
		printf("Enter Name: ");
		scanf("%s",a->name);
		printf("Enter Percent: ");
		scanf("%f",&a->per);				
	}
	return n;
}

void display(stud *a,int n,int o)
{
	int i;
	if(n!=0&&o==0)
	{
		printf("Sr. No.\tRoll. No.\tName\t\tPercentage\n---------------------------------------------------------\n");
		for(i=0;i<n;i++,a++)
			printf("   %d\t %d\t\t%s\t\t%.2f\n",i+1,a->rollno,a->name,a->per);
		printf("\n---------------------------------------------------------\n");
	}
	else if(o==1)
	{
		printf("Sr. No.\tRoll. No.\tName\t\tPercentage\n---------------------------------------------------------\n");
		for(i=0;i<n;i++,a++);
		printf("   %d\t %d\t\t%s\t\t%.2f\n",n+1,a->rollno,a->name,a->per);
	}
	else
		printf("---------------------------------------------------------\n\t\t\tNO RECORDS FOUND\n---------------------------------------------------------\n");
}

int search(stud *a,int n,int x)
{
	int i;
	for(i=0;i<n;i++,a++)
	{
		if(a->rollno==x)
		{
			return i;
		}
	}
	return -1;
}

int insert(stud *a,int n)
{
	int p,x,i;
	printf("\nEnter Position: ");
	scanf("%d",&p);
	if(p<=n&&p>0)
	{
		for(i=n;i>=p;i--)
			a[i]=a[i-1];
		printf("Enter Roll No.");
		scanf("%d",&a[p-1].rollno);
		printf("Enter Name: ");
		scanf("%s",a[p-1].name);
		printf("Enter Percent: ");
		scanf("%f",&a[p-1].per);
		n++;
	}
	else
		printf("Invalid Position.");
	return n;
}

void modify(stud *a,int n)
{
	int p,x,i;
	printf("\nEnter element old Roll. No.: ");
	scanf("%d",&x);
	p=search(a,n,x);
	if(p<=n&&p>=0)
	{
		printf("Enter New Roll No.");
		scanf("%d",&a[p].rollno);
		printf("Enter New Name: ");
		scanf("%s",a[p].name);
		printf("Enter New Percent: ");
		scanf("%f",&a[p].per);
	}
	else
		printf("Invalid Roll No.");
}

int delete(stud *a,int n)
{
	int p,x,i;
	printf("\nEnter Roll No.: ");
	scanf("%d",&x);
	p=search(a,n,x);
	if(p<=n&&p>=0)
	{
		for(i=p;i<n;i++,a++)
			a[i]=a[i+1];
		n--;
	}
	else
		printf("Invalid Roll No.");
	return n;
}

void main()
{
	stud *a;
	a=(stud*)malloc(10*sizeof(stud));
	int n=0,loc,ch,x;
	system("clear");
	while(1)
	{
		system("clear");
		display(a,n,0);
		printf("Structure Manipulation\n1. Input\n2. Modify\n3. Insert\n4. Delete\n5. Search\n6. Exit\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				n=accept(a);
				printf("Records Added Successfully!");
				getchar();
				break;
			case 2:
				modify(a,n);
				printf("Record Modified Successfully!");
				getchar();
				break;
			case 3:
				n=insert(a,n);
				printf("Record Inserted Successfully!");
				getchar();
				break;
			case 4:
				n=delete(a,n);
				printf("Record Deleted Successfully!");
				getchar();
				break;
			case 5:
				printf("Enter Roll no.");
				scanf("%d",&x);
				loc=search(a,n,x);
				if(loc==-1)
					printf("Not Found!");
				else
				{
					printf("Found at Position %d.\n",loc+1);
					display(a,loc,1);
				}
				getchar();
				break;
			case 6:
				exit(0);
			default:
				printf("Pls. Enter correct option.");
				getchar();
		}
		getchar();
	}	
	getchar();
}
