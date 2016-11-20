/*
				Assigment 2
				Circular Queue
Name: Jain Samkitkumar Hasmukhlal
Class: SEIT	Roll. No.: 20
Date:

 Implementation of circular queue using array and perform following operations on it.
 i) Add a record
 ii) Delete a record
 iii) Checking Empty
 iv) Checking Underflow
 v) Checking overflow
*/

using namespace std;

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#define MAX 100

typedef struct stud
{
	int rollno;
	char name[10];
}stud;

class queue
{
	stud q[MAX];
	int f,r;
	public:
	queue();
	void create();
	void display();
	void enqueue(stud);
	stud dequeue();
	int isfull();
	int isempty();
	stud dispf();
	stud dispr();
};

queue::queue()
{
	f=r=-1;
}

void queue::create()
{
	int n;
	stud x;
	cout<<"Enter No of Records: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter Roll. No.: ";
		cin>>x.rollno;
		cout<<"Enter Name: ";
		cin>>x.name;
		enqueue(x);
	}
}

void queue::display()
{
	int i;
	if(!isempty())
	{
		cout<<"Roll No."<<"\t"<<"Name"<<"\n";
		for(i=f;i!=r;i=((i+1)%MAX))
			cout<<q[i].rollno<<"\t"<<q[i].name<<"\n";
		cout<<q[i].rollno<<"\t"<<q[i].name<<"\n";
	}
	else
		cout<<"No records found!\n\n";
}

int queue::isfull()
{
	if((r+1)%MAX==f)
		return 1;
	else
		return 0;
}

int queue::isempty()
{
	if(f==-1)
		return 1;
	else
		return 0;
}

void queue::enqueue(stud x)
{
	if(!isfull())
	{
		if(isempty())
			f=r=0;
		else
			r=(r+1)%MAX;
        q[r]=x;
	}
	else
		cout<<"Queue is full!";
}

stud queue::dequeue()
{
	if(!isempty())
	{
	    stud x;
        x=q[f];
		if(f==r)
			r=f=-1;
		else
			f=(f+1)%MAX;
        return x;

	}
}

stud queue::dispf()
{
		return q[f];
}

stud queue::dispr()
{
		return q[r];
}

int main()
{
	int ch;
	stud x;
	queue obj;
	while(1)
	{
		system("clear");
		obj.display();
		cout<<"1. Create\n2. Enqueue\n3. Dequeue\n4. Display Front\n5. Display Rear\n6. Exit\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				obj.create();
				getchar();
				break;
			case 2:
				cout<<"Enter Roll No.: ";
				cin>>x.rollno;
				cout<<"Enter Name: ";
				cin>>x.name;
				obj.enqueue(x);
				getchar();
				break;
			case 3:
				x=obj.dequeue();
				cout<<"Roll No.: "<<x.rollno<<"\nName: "<<x.name;
				getchar();
				break;
			case 4:
				if(!obj.isempty())
				{
					x=obj.dispf();
					cout<<"Roll No. "<<x.rollno<<"\nName: "<<x.name;
				}
				else
					cout<<"Queue Is Empty!\n";
				getchar();
				break;
			case 5:
				if(!obj.isempty())
				{
					x=obj.dispr();
					cout<<"Roll No. "<<x.rollno<<"\nName: "<<x.name;
				}
				else
					cout<<"Queue Is Empty!\n";
				getchar();
				break;
			case 6:
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
