//				Assigment 11
//				Doubly Linked List
/*
Name - Samkitkumar H. Jain
Date of Performance : 5/9/14
Implement any Database using doubly linked list with following options
i) Insert a record
ii) delete a record
iii) modify a record
iV) Display list forward
v) Display list backward
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct DLL
{
	int rollno;
	char name[10];
	float per;
	struct DLL *next,*prev;
}DLL;

DLL *Newnode()
{
	DLL *New;
	New=(DLL*)malloc(sizeof(DLL));
	New->next=New->prev=NULL;
	return New;
}

DLL *create()
{
	int n,i;
	DLL *head,*New,*temp;
	printf("Enter no. of Nodes/Record to enter: ");
	scanf("%d",&n);
	head=NULL;
	for(i=1;i<=n;i++)
	{
		New=Newnode();
		printf("Enter Roll. No. at Node %d : ",i);
		scanf("%d",&New->rollno);
		printf("Enter Name at Node %d : ",i);
		scanf("%s",New->name);
		printf("Enter Percentage at Node %d : ",i);
		scanf("%f",&New->per);
		if(head==NULL)
		{
			head=New;
			temp=New;
		}
		else
		{
			temp->next=New;
			New->prev=temp;
			temp=New;
		}
	}
	return head;
}

void display(DLL *head)
{
	DLL *temp;
	if(head==NULL)
		printf("---------------------------------------------------------\n\t\t\tNO RECORDS FOUND\n---------------------------------------------------------\n");
	else
	{
		int i=1;
		temp=head;
		printf("Sr. No.\tRoll. No.\tName\tPercentage\n---------------------------------------------------------\n");
		while(temp!=NULL)
		{
			printf("%d\t%d\t%s\t\t%.2f\n",i,temp->rollno,temp->name,temp->per);
			temp=temp->next;
			i++;
		}
	}
}

DLL *insert(DLL *head)
{
	DLL *New,*temp;
	int p,i;
	printf("Enter position of New Record to be inserted : ");
	scanf("%d",&p);
	New=Newnode();
	printf("Enter Roll. No. at New Node : ");
	scanf("%d",&New->rollno);
	printf("Enter Name at New Node : ");
	scanf("%s",New->name);
	printf("Enter Percentage at New Node : ");
	scanf("%f",&New->per);
	if(p==1)
	{
		New->next=head;
		head->prev=New;
		head=New;
		printf("\nNode inserted successfully!\n");
		return head;
	}
	temp=head;
	for(i=1;i<p-1;i++)
	{
		if(temp->next!=NULL)
			temp=temp->next;
		else
		{
			printf("Position Not Found!\n");
			return head;
		}
	}
	if(temp->next==NULL)
	{
		temp->next=New;
		New->prev=temp;
		printf("\nNode inserted successfully!\n");
		return head;
	}
	New->next=temp->next;
	temp->next->prev=New;
	temp->next=New;
	New->prev=temp;
	printf("\nNode inserted successfully!\n");
	return head;
}

void modify(DLL *head)
{
	DLL *temp;
	int x;
	temp=head;
	printf("Enter Roll No. to modify its record : ");
	scanf("%d",&x);
	while(temp!=NULL&&temp->rollno!=x)
		temp=temp->next;
	if(temp==NULL)
	{
		printf("Record not found!\n");
	}
	else
	{
		printf("Enter New Roll. No. : ");
		scanf("%d",&temp->rollno);
		printf("Enter New Name : ");
		scanf("%s",temp->name);
		printf("Enter New Percentage : ");
		scanf("%f",&temp->per);
		printf("\nLinked List modified successfully!\n");
	}
}

DLL *delete(DLL *head)
{
	DLL * temp;
	int x;
	printf("Enter Roll No. to delete its record : ");
	scanf("%d",&x);
	if(head->next==NULL&&head->rollno==x)
	{
		free(head);
		printf("\nNode deleted successfully!\n");
		return NULL;
	}
	temp=head;
	if(head->rollno==x)
	{
		head=head->next;
		head->prev=NULL;
		free(temp);
		printf("\nNode deleted successfully!\n");
		return head;
	}
	while(temp!=NULL&&temp->rollno!=x)
		temp=temp->next;
	if(temp==NULL)
	{
		printf("Record not found!\n");
		return head;
	}
	if(temp->next==NULL)
	{
		temp->prev->next=NULL;
		free(temp);
		printf("\nNode deleted successfully!\n");
		return head;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	free(temp);
	printf("\nNode deleted successfully!\n");
	return head;
}

void reverse(DLL *head)
{
	DLL *temp;
	int i=1;
	temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	printf("Sr. No.\tRoll. No.\tName\tPercentage\n---------------------------------------------------------\n");
	while(temp->prev!=NULL)
	{
		printf("%d\t%d\t%s\t\t%.2f\n",i,temp->rollno,temp->name,temp->per);
		temp=temp->prev;
		i++;
	}
	printf("%d\t%d\t%s\t\t%.2f\n",i,temp->rollno,temp->name,temp->per);
}

void main()
{
	//declaration
	DLL *head;
	int ch;
	head=NULL;
	system("clear");
	while(1)
	{
		system("clear");
		display(head);
		//Operation selection
		printf("\nOperations on Doubly Linked List:\n1. Create\n2. Insert\n3. Modify\n4. Delete\n5. Reverse\n6. Exit\nEnter your choice ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				head=create();
				printf("\nDoubly Linked List created successfully!\n");
				getchar();
				break;
			case 2:
				if(head==NULL)
					printf("\nNo Records found so unable to insert Record.");
				else
					head=insert(head);
				getchar();
				break;
			case 3:
				if(head==NULL)
					printf("\nNo Records found so unable to modify Record.");
				else
					modify(head);
				getchar();
				break;
			case 4:
				if(head==NULL)
					printf("\nNo Records found so unable to delete Record.");
				else
					head=delete(head);
				getchar();
				break;
			case 5:
				if(head==NULL)
					printf("\nNo Records found so unable to reverse Record.");
				else
				{
					reverse(head);
					printf("\nLinked List is displayed in reverse successfully!\n");
				}
				getchar();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("\nPls. Enter correct choice\n");
				getchar();
		}
		getchar();
	}
	getchar();
}
