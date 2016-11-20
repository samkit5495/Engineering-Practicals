/*
				Assigment 6
				Threaded Binary Tree
Name: Jain Samkitkumar Hasmukhlal
Class: SEIT	Roll. No.: 20
Date: 24/02/2015

Write a program to Construct an inorder threaded binary tree from inorder/postorder
expression and traverse it in inorder and preorder

lb/rb   = 0 threaded link
        = 1 normal link

*/

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct node
{
	char data;
	int lb,rb;
	struct node *l,*r;
}node;

class tbt
{
	node *head;
public:
	tbt()
	{
		head=new node;
		head->data='H';
		head->lb=0;
		head->rb=1;
		head->l=head->r=head;
	}
	void create1(node*,char[],char[],int);
	void divide(char[],char[],char[],char[],char[],char[]);
	int belong(char,char[]);
	void create()
	{
		char in[20],post[20];
		cout<<"Enter Infix Expression: ";
		cin>>in;
		cout<<"Enter Postfix Expression: ";
		cin>>post;
		create1(head,in,post,0);
	}
	void inorder();
	void preorder();
	void postorder();
};

void tbt::create1(node * head,char in[],char post[],int f)
{
	if(strlen(in)==0)
		return;
	char in1[20],post1[20],in2[20],post2[20];
	node *p=new node;
	p->data=post[strlen(post)-1];
	p->lb=p->rb=0;
	p->l=p->r=head;
	if(f==0)
	{
		p->l=head->l;
		head->l=p;
		head->lb=1;
	}
	else
	{
		p->r=head->r;
		head->r=p;
		head->rb=1;
	}
	divide(in,post,in1,in2,post1,post2);
	create1(p,in1,post1,0);
	create1(p,in2,post2,1);
}

void tbt::divide(char in[],char post[],char in1[],char in2[],char post1[],char post2[])
{
	int i,j,k;
	for(i=0;in[i]!=post[strlen(post)-1];i++)
		in1[i]=in[i];
	in1[i]='\0';
	i++;
	for(j=0;in[i]!='\0';j++)
		in2[j]=in[i++];
	in2[j]='\0';
	for(i=0,j=0,k=0;i<strlen(post)-1;i++)
	{
		if(belong(post[i],in1))
			post1[j++]=post[i];
		else
			post2[k++]=post[i];
	}
	post1[j]=post2[k]='\0';
}

int tbt::belong(char post,char in1[])
{
	for(int i=0;in1[i]!='\0';i++)
		if(post==in1[i])
			return 1;
	return 0;
}

void tbt::inorder()
{
	if(head->l==head)
	{
		cout<<"Tree is Empty!";
		return;
	}
	node *t=head->l;
	while(t!=head)
	{
		while(t->lb==1&&t->l!=head)
			t=t->l;
		cout<<t->data;
		while(t->rb==0&&t->r!=head)
		{
			t=t->r;
			cout<<t->data;
		}
		t=t->r;
	}
}

void tbt::preorder()
{
	if(head->l==head)
	{
		cout<<"Tree is Empty!";
		return;
	}
	node *t=head->l;
	while(t!=head)
	{
		while(t->lb==1&&t->l!=head)
		{
			cout<<t->data;
			t=t->l;
		}
		cout<<t->data;
		while(t->rb==0&&t->r!=head)
			t=t->r;
		t=t->r;
	}
}

void tbt::postorder()
{
	if(head->l==head)
	{
		cout<<"Tree is Empty!";
		return;
	}
	node *t=head->l;
	char a[20];
	int k=0;
	while(t!=head)
	{
		while(t->rb==1)
		{
			a[k++]=t->data;
			t=t->r;
		}
		a[k++]=t->data;
		while(t->lb==0&&t->l!=head)
			t=t->l;
		t=t->l;
	}
	for(int i=k;i>=0;i--)
		cout<<a[i];
}

int main()
{
	tbt obj;
	int ch;
	while(1)
	{
		system("clear");
		cout<<"1. Accept\n2. Inorder\n3. Preorder\n4. Postorder\n5. Exit\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				obj.create();
				getchar();
				break;
			case 2:
				cout<<"Inorder traversal of tree is ";
				obj.inorder();
				getchar();
				break;
			case 3:
				cout<<"Preorder traversal of tree is ";
				obj.preorder();
				getchar();
				break;
			case 4:
				cout<<"Postorder traversal of tree is ";
				obj.postorder();
				getchar();
				break;

			case 5:
				exit(0);
			default:
				cout<<"\nEnter correct choice!\n";
				getchar();
		}
		getchar();
	}
	getchar();
	return 0;
}
