using namespace std;

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

class node
{
	public:
	int data;
	node *next;
};

class stack
{
	node *top;
	public:
	stack()
	{
	      top=NULL;
	}
	void create();
	void display();
	void push();
	int pop();
	void displaytop();
	int isempty();
};

void stack::create()
{
	int n;
	cout<<"Enter No of elements to enter in stack: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		push();
	}
}

void stack::display()
{
	node *temp=new node;
	if(top!=NULL)
	{
		temp=top;
		while(temp!=NULL)
		{
			cout<<temp->data<<"\n";
			temp=temp->next;
		}
	}
	else
		cout<<"\nStack is empty!\n";
}

void stack::push()
{
	node *New=new node;
	New->next=NULL;
	cout<<"Enter Data: ";
	cin>>New->data;
	New->next=top;
	top=New;
}

int stack::pop()
{
	int x;
	node *temp=new node;
	if(!isempty())
	{
		x=top->data;
		temp=top;
		top=top->next;
		delete temp;
		return x;
	}
	else
		return -1;
}

void stack::displaytop()
{
	cout<<"Data at top "<<top->data;
}

int stack::isempty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}

int main()
{
	stack obj;
	int ch,x;
	while(1)
	{
		system("clear");
		obj.display();
		cout<<"Stack Operations:-";
		cout<<"\n1. Create\n2. Push\n3. Pop\n4. Display Top\n5. Is Empty\n6. Exit\nEnter Your Choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				obj.create();
				getchar();
				break;
			case 2:
				obj.push();
				getchar();
				break;
			case 3:
				x=obj.pop();
				if(x==-1)
					cout<<"Cannot pop list is empty!";
				else
					cout<<"Data poped "<<x;
				getchar();
				break;
			case 4:
				obj.displaytop();
				getchar();
				break;
			case 5:
				if(obj.isempty())
					cout<<"Stack is empty.";
				else
					cout<<"Stack in not full.";
				getchar();
				break;
			case 6:
				exit(0);
			default:
				cout<<"\nEnter correct choice!";
				getchar();
				break;
		}
		getchar();
	}
	getchar();
	return 0;
}
