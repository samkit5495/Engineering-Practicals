/*
				Assigment 4
				Expression Tree Traversal
Name: Jain Samkitkumar Hasmukhlal
Class: SEIT	Roll. No.: 20
Date:

 Write a program to Construct and expression tree from postfix/prefix expression
and perform recursive and non-recursive Inorder , preorder and postorder traversals.

*/

using namespace std;

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"stack.cpp"

typedef struct nod
{
	char data;
	struct nod *l,*r;
}nod;

class exp
{
	nod *root;
	public:
	exp()
	{
		root=NULL;
	}

	void rev(char *);

	void accept();

	void check();

	void rec_inorder()
	{
		rec_inorder1(root);
	}
	void rec_inorder1(nod*);

	void rec_preorder()
	{
		rec_preorder1(root);
	}
	void rec_preorder1(nod*);

	void rec_postorder()
	{
		rec_postorder1(root);
	}
	void rec_postorder1(nod*);

	void nonrec_inorder();

	void nonrec_preorder();

	void nonrec_postorder();
};

void exp::rev(char str[])
{
	for(int i=0,j=strlen(str)-1;i<j;i++,j--)
	{
		char t=str[i];
		str[i]=str[j];
		str[j]=t;
	}
}

void exp::accept()
{
	stack<nod*> s;
	char str[100];
	nod *x;
	int o;
	cout<<"Expression Type:\n1. Postfix\n2. Prefix\nEnter your choice: ";
	cin>>o;
	cout<<"Enter Expression: ";
	cin>>str;
	if(o!=1)
        rev(str);
	for(int i=0;str[i]!='\0';i++)
	{
		x=new nod;
		x->l=x->r=NULL;
		x->data=str[i];
		if(isalnum(x->data))
			s.push(x);
		else
		{
			if(o==1)
			{
				x->r=s.pop();
				x->l=s.pop();
			}
			else
			{
				x->l=s.pop();
				x->r=s.pop();
			}
			s.push(x);
		}
	}
	root=s.pop();
}

void exp::check()
{
    if(root==NULL)
    {
        cout<<"Pls. Enter Equation first!\n";
        accept();
    }
}

void exp::rec_inorder1(nod* t)
{
	if(t!=NULL)
	{
		rec_inorder1(t->l);
		cout<<t->data;
		rec_inorder1(t->r);
	}
}

void exp::rec_preorder1(nod* t)
{
	if(t!=NULL)
	{
		cout<<t->data;
		rec_preorder1(t->l);
		rec_preorder1(t->r);
	}
}

void exp::rec_postorder1(nod* t)
{
	if(t!=NULL)
	{
		rec_postorder1(t->l);
		rec_postorder1(t->r);
		cout<<t->data;
	}
}

void exp::nonrec_inorder()
{
	nod *t=root;
	stack<nod*> s;
	while(t!=NULL||!s.isempty())
	{
		if(t!=NULL)
		{
			s.push(t);
			t=t->l;
		}
		else
		{
			t=s.pop();
			cout<<t->data;
			t=t->r;
		}
	}
}

void exp::nonrec_preorder()
{
	nod *t=root;
	stack<nod*> s;
	while(t!=NULL||!s.isempty())
	{
		if(t!=NULL)
		{
			cout<<t->data;
			s.push(t);
			t=t->l;
		}
		else
		{
			t=s.pop();
			t=t->r;
		}
	}
}

void exp::nonrec_postorder()
{
	nod *t=root;
	stack<nod*> s;
	stack<int> f;
	while(t!=NULL||!s.isempty())
	{
		if(t!=NULL)
		{
			s.push(t);
			f.push(0);
			t=t->l;
		}
		else
		{
			t=s.pop();
			if(!f.pop())//f=0 traversed & f=1 print
			{
			    s.push(t);
				f.push(1);
				t=t->r;
			}
			else
			{
				cout<<t->data;
				t=NULL;
			}
		}
	}
}

int main()
{
	exp obj;
	int ch;
	while(1)
	{
		system("clear");
		cout<<"1. Accept\n\tRecursive: \n2.Inorder \n3.Preorder \n4. Postorder\n\tNon-Recursive:\n5. Inorder \n6. Preorder \n7. Postorder\n8. Exit\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				obj.accept();
				getchar();
				break;
			case 2:
			    obj.check();
				obj.rec_inorder();
				getchar();
				break;
			case 3:
			    obj.check();
				obj.rec_preorder();
				getchar();
				break;
			case 4:
			    obj.check();
				obj.rec_postorder();
				getchar();
				break;
			case 5:
			    obj.check();
				obj.nonrec_inorder();
				getchar();
				break;
			case 6:
			    obj.check();
				obj.nonrec_preorder();
				getchar();
				break;
			case 7:
			    obj.check();
				obj.nonrec_postorder();
				getchar();
				break;
			case 8:
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
