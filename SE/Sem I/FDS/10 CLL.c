/*
//				Assigment 10
//				Circular Linked List
/*
Name - Samkitkumar H. Jain
Date of Performance : 15/9/14
Implement polynomial using CLL and perform
i) Addition of Polynomials
ii) Multiplication of polynomials and
iii) Evaluation of polynomial.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct poly
{
	float c;
	int e;
	struct poly *next;
}poly;

poly *getnode()
{
	poly *New;
	New=(poly*)malloc(sizeof(poly));
	New->next=New;
	return New;
}

poly *insert(poly *head,float c,int e)
{
	poly *p,*temp;
	p=getnode();
	p->c=c;
	p->e=e;
	if(head==NULL)
	{
		head=p;
		return head;
	}
	if(p->e<head->e)
	{
		p->next=head->next;
		head->next=p;
		head=p;
	}
	else if(p->e==head->e)
		head->c+=p->c;
	else
	{
		temp=head;
		while(temp->next!=head&&p->e<=temp->next->e)
			temp=temp->next;
		if(temp->e==p->e)
			temp->c+=p->c;
		else
		{
			p->next=temp->next;
			temp->next=p;
		}
	}
	return head;
}


poly *create()
{
	int n,i,e;
	float c;
	poly *head,*New,*temp;
	printf("Enter no. of terms to enter: ");
	scanf("%d",&n);
	head=NULL;
	for(i=1;i<=n;i++)
	{
		printf("Enter Coefficient in term %d : ",i);
		scanf("%f",&c);
		printf("Enter Exponent in term %d : ",i);
		scanf("%d",&e);
		head=insert(head,c,e);
	}
	return head;
}

void display(poly *head)
{
	poly *temp;
	if(head==NULL)
		printf("0\n");
	else
	{
		temp=head->next;
		do
		{
			if(temp->e==0)
				printf("(%.2f)",temp->c);
			else if(temp->e==1)
				printf("(%.2f)x + ",temp->c);
			else
				printf("(%.2f)x^%d + ",temp->c,temp->e);
			temp=temp->next;
		}
		while(temp!=head);
		if(head->next!=head)
		{
			if(temp->e==0)
				printf("(%.2f)",temp->c);
			else if(temp->e==1)
				printf("(%.2f)x",temp->c);
			else
				printf("(%.2f)x^%d",temp->c,temp->e);
		}
		printf("\n");
	}
}

poly *add(poly *p1,poly *p2)
{
	poly *p3,*temp;
	p3=NULL;
	temp=p1->next;
	do
	{
		p3=insert(p3,temp->c,temp->e);
		temp=temp->next;
	}
	while(temp!=p1->next);
	temp=p2->next;
	do
	{
		p3=insert(p3,temp->c,temp->e);
		temp=temp->next;
	}
	while(temp!=p2->next);
	return p3;
	
}

poly *multiply(poly *p1,poly *p2)
{
	poly *p3,*temp1,*temp2;
	p3=NULL;
	temp1=p1->next;
	do
	{
		temp2=p2->next;
		do
		{
			p3=insert(p3,temp1->c*temp2->c,temp1->e+temp2->e);
			temp2=temp2->next;
		}
		while(temp2!=p2->next);
		temp1=temp1->next;
	}
	while(temp1!=p1->next);
	return p3;
}

float power(float a,float b)
{
	int i;
	for(i=1;i<=b;i++)
		a*=a;
	return a;
}

float evaluate(poly *p)
{
	float sum=0,x;
	poly *temp;
	printf("Enter value of x to evaluate the equation");
	scanf("%f",&x);
	temp=p->next;
	do
	{
		sum+=temp->c*power(x,temp->c);
		temp=temp->next;
	}
	while(temp!=p->next);
	return sum;
}

void main()
{
	//declaration
	poly *p1,*p2,*p3;
	int ch;
	float evalution;
	system("clear");
	while(1)
	{
		system("clear");
		//Operation selection
		printf("\nOperations on Polynomial using Circular Linked List:\n1. Add\n2. Multiply\n3. Evaluate\n4. Exit\nEnter your choice ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Addition\nEnter Polynomial 1\n");
				p1=create();
				printf("Enter Polynomial 2 \n");
				p2=create();
				printf("Polynomial 1 : ");
				display(p1);
				printf("Polynomial 2 : ");
				display(p2);
				printf("Addition : ");
				if(p1!=NULL&&p2!=NULL)
				{
					p3=add(p1,p2);
					display(p3);
				}
				else if(p1==NULL)
					display(p2);
				else
					display(p1);
				getchar();
				break;
			case 2:
				printf("Multiplication\nEnter Polynomial 1\n");
				p1=create();
				printf("Enter Polynomial 2\n");
				p2=create();
				printf("Polynomial 1 : ");
				display(p1);
				printf("Polynomial 2 : ");
				display(p2);
				printf("Multiplication : ");
				if(p1!=NULL&&p2!=NULL)
				{
					p3=multiply(p1,p2);
					display(p3);
				}
				else
					printf("0");
				getchar();
				break;
			case 3:
				printf("Evaluation\nEnter Polynomial\n");
				p1=create();
				printf("Polynomial : ");
				display(p1);
				evalution=evaluate(p1);
				printf("Evaluation is %.2f.",evalution);
				getchar();
				break;
			case 4:
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
