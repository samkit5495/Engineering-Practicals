//				Assigment 9
//				Singly Linked List
/*
Name - Samkitkumar H. Jain
Date of Performance : 5/9/14
Implement a singly linked list with following options
1. Create
	Normal
	*Alternate Nodes
	Priority wise
2. Display
	Non-Recursive
	Recursive
3. Insert
	Given Location
	*After Particular element
	Priority wise
4. Delete
	Particular node
	Particular location
5. Modify
6.Search
7. Sort
8. Reverse
9. Revert
10. count
	Non-Recursive
	Recursive
11. Concat
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct SLL
{
	int data;
	struct SLL *next;
}SLL;

SLL *Newnode()
{
	SLL *New;
	New=(SLL*)malloc(sizeof(SLL));
	New->next=NULL;
	return New;
}

SLL *create_normal()
{
	int n,i;
	SLL *head,*New,*prev;
	printf("Enter no. of Nodes/Data to enter: ");
	scanf("%d",&n);
	head=NULL;
	for(i=1;i<=n;i++)
	{
		New=Newnode();
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

SLL *create_priority()
{
	int n,i;
	SLL *head,*New,*prev;
	printf("Enter no. of Nodes/Data to enter: ");
	scanf("%d",&n);
	head=NULL;
	for(i=1;i<=n;i++)
	{
		New=Newnode();
		printf("Enter Data at Node %d : ",i);
		scanf("%d",&New->data);
		if(head==NULL)
		{
			head=New;
			prev=New;
		}
		else if(prev->data<New->data)
		{
			prev->next=New;
			prev=New;
		}
		else
		{
			New->next=head;
			head=New;
		}
	}
	return head;
}

void display_non_recursive(SLL *head)
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

void display_recursive(SLL *head)
{
        if(head!=NULL)
	{
	        printf("%d\t",head->data);
		display_recursive(head->next);
	}
}

SLL *insert_at_location(SLL *head)
{
	SLL *New,*temp;
	int p,i;
	printf("Enter position of New data to be inserted : ");
	scanf("%d",&p);
	New=Newnode();
	printf("Enter New Data to be inserted: ");
	scanf("%d",&New->data);
	if(p==1)
	{
		New->next=head;
		head=New;
		return head;
	}
	temp=head;
	for(i=1;i<p-1;i++)
	{
		if(temp!=NULL)
			temp=temp->next;
		else
		{
			printf("Position Not Found!\n");
			return head;
		}
	}
	New->next=temp->next;
	temp->next=New;
	return head;
}

SLL *insert_after_node(SLL *head)
{
        SLL *New,*temp;
        int x;
	printf("Note:- To insert at head enter 'h' symbol\nEnter data after which New data to be inserted : ");
	New=Newnode();
	printf("Enter New Data to be inserted: ");
	scanf("%d",&New->data);
	temp=head;
	while(temp!=NULL&&x!=temp->data)
		temp=temp->next;
	if(temp==NULL)
	{
		printf("Node Not Found!\n");
		return head;
	}
	New->next=temp->next;
	temp->next=New;
	return head;
}

SLL *insert_priority(SLL *head)
{
	SLL *New,*temp,*prev;
	New=Newnode();
	printf("Enter New Data to be inserted: ");
	scanf("%d",&New->data);
	if(head->data>New->data)
	{
	        New->next=head;
	        head=New;
	        return head;
	}
	prev=temp=head;
	while(temp!=NULL&&temp->data<New->data)
	{
	        prev=temp;
		temp=temp->next;
	}
	New->next=prev->next;
	prev->next=New;
	return head;
}

SLL *delete_particular(SLL *head)
{
	SLL * temp,*prev;
	int x;
	printf("Enter node data to delete: ");
	scanf("%d",&x);
	if(head->next==NULL&&head->data==x)
	{
		free(head);
		return NULL;
	}
	temp=head;
	if(head->data==x)
	{
		head=head->next;
		free(temp);
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
	return head;
}

SLL *delete_position(SLL *head)
{
	SLL * temp,*prev;
	int p,i;
	printf("Enter position of node to delete: ");
	scanf("%d",&p);
	if(head->next==NULL&&p==1)
	{
		free(head);
		return NULL;
	}
	prev=temp=head;
	if(p==1)
	{
		head=head->next;
		free(temp);
		return head;
	}
	for(i=1;i<p-1;i++)
	{
		if(prev->next!=NULL)
		        prev=prev->next;
		else
		{
			printf("Position not found!\n");
			return head;
		}
	}
	temp=prev->next;
	prev->next=temp->next;
	free(temp);
	return head;
}

void modify(SLL *head)
{
	SLL * temp;
	int x;
	printf("Enter node data to modify: ");
	scanf("%d",&x);
	temp=head;
	while(temp!=NULL&&temp->data!=x)
		temp=temp->next;
	if(temp==NULL)
		printf("Data not found!\n");
	else
	{
		printf("Enter New Data : ");
		scanf("%d",&temp->data);
	}
}

int search(SLL *head,int x)
{
	SLL *temp;
	int p=1;
	temp=head;
	while(temp!=NULL&&x!=temp->data)
	{
		temp=temp->next;
		p++;
	}
	if(temp==NULL)
		printf("Data not found.");
	else
		printf("Data found at %d position.",p);
}

int count_nonrecursive(SLL *head)
{
	SLL *temp;
	int c=0;
	temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		c++;
	}
	return c;
}

int count_recursive(SLL *head)
{
	SLL *temp;
	static int c=0;
	temp=head;
	if(temp!=NULL)
	{
		count_recursive(temp->next);
		c++;
	}
	return c;
}

void sort(SLL *head)
{
	SLL *temp,*prev;;
	int i,j,c;
	c=count_nonrecursive(head);
	for(i=1;i<c;i++)
	{
		temp=head;
		for(j=0;j<c-i;j++)
		{
			prev=temp;
			temp=temp->next;
			if(temp->data<prev->data)
			{
				int t;
				t=temp->data;
				temp->data=prev->data;
				prev->data=t;
			}
		}
	}
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

void concat(SLL *head)
{
	SLL *head2,*temp;
	printf("Enter List 2:\n");
	head2=create_normal();
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=head2;
}

void main()
{
	//declaration
	SLL *head;
	int ch,c,p,x;
	head=NULL;
	system("clear");
	while(1)
	{
		system("clear");
		display_non_recursive(head);
		//Operation selection
		printf("\nOperations on Singly Linked List:\n1. Create Normal\n2. Create Alternate Nodes\n3. Create Priority wise\n4. Display Non-Recursive\n5. Display Recursive\n6. Insert Given Location\n7. Insert After Particular element\n8. Insert Priority wise\n9. Delete Particular node\n10. Delete Particular location\n11. Modify\n12. Search\n13. Count Non-Recursive\n14. Count Recursive\n15. Sort\n16. Reverse\n17. Revert\n18. Concat\n19. Exit\nEnter your choice ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				head=create_normal();
				printf("\nSingly Linked List created successfully!\n");
				getchar();
				break;
			case 2:
				
				getchar();
				break;
			case 3:
				head=create_priority();
				printf("\nSingly Linked List created successfully!\n");
				getchar();
				break;
			case 4:
				display_non_recursive(head);
				getchar();
				break;
			case 5:
				display_recursive(head);
				getchar();
				break;
			case 6:
				if(head==NULL)
					printf("\nThe list is empty so unable to insert data.");
				else
				{
					head=insert_at_location(head);
					printf("\nNode inserted successfully!\n");
				}
				getchar();
				break;
			case 7:
				if(head==NULL)
					printf("\nThe list is empty so unable to insert data.");
				else
				{
					head=insert_after_node(head);
					printf("\nNode inserted successfully!\n");
				}
				getchar();
				break;
			case 8:
				if(head==NULL)
					printf("\nThe list is empty so unable to insert data.");
				else
				{
					head=insert_priority(head);
					printf("\nNode inserted successfully!\n");
				}
				
				getchar();
				break;
			case 9:
				if(head==NULL)
					printf("\nThe list is empty so unable to delete data.");
				else
				{
					head=delete_particular(head);
					printf("\nNode deleted successfully!\n");
				}
				getchar();
				break;
			case 10:
				if(head==NULL)
					printf("\nThe list is empty so unable to delete data.");
				else
				{
					head=delete_position(head);
					printf("\nNode deleted successfully!\n");
				}
				getchar();
				break;
			case 11:
				if(head==NULL)
					printf("\nThe list is empty so unable to modify data.");
				else
				{
					modify(head);
					printf("\nNode modified successfully!\n");
				}
				getchar();
				break;
			case 12:
				if(head==NULL)
					printf("\nThe list is empty so unable to search data.");
				else
				{
					printf("Enter data to find : ");
					scanf("%d",&x);
					p=search(head,x);
					if(p==-1)
						printf("Data not found.");
					else
						printf("Data found at %d position.",p);
				}
				getchar();
				break;
			case 13:
				if(head==NULL)
					printf("\nThe list is empty so count is 0.");
				else
				{
					c=count_nonrecursive(head);
					printf("\nThe count of nodes is %d.",c);
				}
				getchar();
				break;
			case 14:
				if(head==NULL)
					printf("\nThe list is empty so count is 0.");
				else
				{
					c=count_recursive(head);
					printf("\nThe count of nodes is %d.",c);
				}
				getchar();
				break;
			case 15:
				if(head==NULL)
					printf("\nThe list is empty so cannot sort.");
				else
				{
					sort(head);
					printf("\nThe list is sorted");
				}
				getchar();
				break;
			case 16:
				if(head==NULL)
					printf("\nThe list is empty so unable to reverse data.");
				else
				{
					reverse(head);
					printf("\nLinked List is displayed in reverse successfully!\n");
				}
				getchar();
				break;
			case 17:
				if(head==NULL)
					printf("\nThe list is empty so unable to revert data.");
				else
				{
					head=revert(head);
					printf("\nLinked List reverted successfully!\n");
				}
				getchar();
				break;
			case 18:
				concat(head);
				printf("\nLinked List concated successfully!\n");
				getchar();
				break;
			case 19:
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
