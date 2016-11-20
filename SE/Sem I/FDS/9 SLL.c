//				Assigment 9
//				Singly Linked List
/*
Name - Samkitkumar H. Jain
Date of Performance : 5/9/14
Implement a singly linked list with following options
i) Insertion of a node at any location
ii) Deletion of a node from any location
iii) display a list
iv) Display in reverse
v) Reverse the list without using additional data structure.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct SLL
{
	int data;
	struct SLL *next;
}SLL;

SLL *newnode()
{
	SLL *New;
	New=(SLL*)malloc(sizeof(SLL));
	New->next=NULL;
	return New;
}

SLL *create()
{
	int n,i;
	SLL *head,*New,*prev;
	printf("Enter no. of Nodes/Data to enter: ");
	scanf("%d",&n);
	head=NULL;
	for(i=1;i<=n;i++)
	{
		New=newnode();
		printf("Enter Data at Node %d : ",i);
		scanf("%d",&New->data);
		if(head==NULL)
		{
			head=New;
			prev=New;
		}
		else
		{
			prev->next=New;
			prev=New;
		}
	}
	return head;
}

void display(SLL *head)
{
	SLL *temp;
	if(head==NULL)
		printf("List is empty!\n");
	else
	{
		temp=head;
		printf("List:\n");
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

SLL *insert(SLL *head)
{
	SLL *New,*temp;
	int p,i;
	printf("Enter position of new data to be inserted : ");
	scanf("%d",&p);
	New=newnode();
	printf("Enter New Data to be inserted: ");
	scanf("%d",&New->data);
	if(p==1)
	{
		New->next=head;
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
	New->next=temp->next;
	temp->next=New;
	printf("\nNode inserted successfully!\n");
	return head;
}

SLL *delete(SLL *head)
{
	SLL * temp,*prev;
	int x;
	printf("Enter node data to delete: ");
	scanf("%d",&x);
	if(head->next==NULL&&head->data==x)
	{
		free(head);
		printf("\nNode deleted successfully!\n");
		return NULL;
	}
	prev=temp=head;
	if(head->data==x)
	{
		head=head->next;
		free(temp);
		printf("\nNode deleted successfully!\n");
		return head;
	}
	while(temp!=NULL&&temp->data!=x)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("Data not found!\n");
		return head;
	}
	prev->next=temp->next;
	free(temp);
	printf("\nNode deleted successfully!\n");
	return head;
}

void reverse(SLL *head)
{
	if(head!=NULL)
	{
		reverse(head->next);
		printf("%d\t",head->data);
	}
}

SLL *revert(SLL *head)
{
	SLL *p,*q,*r;
	p=NULL;
	q=head;
	r=q->next;
	while(q!=NULL)
	{
		q->next=p;
		p=q;
		q=r;
		if(r!=NULL)
			r=r->next;
	}
	return p;
}

void main()
{
	//declaration
	SLL *head;
	int ch;
	head=NULL;
	system("clear");
	while(1)
	{
		system("clear");
		display(head);
		//Operation selection
		printf("\nOperations on Singly Linked List:\n1. Create\n2. Insert\n3. Delete\n4. Reverse\n5. Revert\n6. Exit\nEnter your choice ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				head=create();
				printf("\nSingly Linked List created successfully!\n");
				getchar();
				break;
			case 2:
				if(head==NULL)
					printf("\nThe list is empty so unable to insert data.");
				else
					head=insert(head);
				getchar();
				break;
			case 3:
				if(head==NULL)
					printf("\nThe list is empty so unable to delete data.");
				else
					head=delete(head);
				getchar();
				break;
			case 4:
				if(head==NULL)
					printf("\nThe list is empty so unable to reverse data.");
				else
				{
					reverse(head);
					printf("\nLinked List is displayed in reverse successfully!\n");
				}
				getchar();
				break;
			case 5:
				if(head==NULL)
					printf("\nThe list is empty so unable to revert data.");
				else
				{
					head=revert(head);
					printf("\nLinked List reverted successfully!\n");
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
