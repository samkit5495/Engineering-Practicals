/*
				Assigment 9
				Hash Table (Chaining without replacement)
Name: Jain Samkitkumar Hasmukhlal
Class: SEIT	Roll. No.: 20
Date: 17/3/15

Implementation of Hash table using array and handle collisions using
Linear probing, chaining without replacement and Chaining with replacement.

*/

using namespace std;

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#define MAX 10

class hash
{
	int data[MAX],chain[MAX];
	public:
	hash();
	void display();
	int hf(int);
	int full();
	void insert(int);
	int search(int);
};

hash::hash()
{
	for(int i=0;i<MAX;i++)
		data[i]=chain[i]=-1;
}

void hash::display()
{
	cout<<"| Address|\tData|\tChain|\n";
	for(int i=0;i<MAX;i++)
		cout<<"| "<<i<<"\t|\t"<<data[i]<<"\t|\t"<<chain[i]<<"|\n";
}

int hash::hf(int x)
{
	return x%MAX;
}

int hash::full()
{
	for(int i=0;i<MAX;i++)
		if(data[i]==-1)
			return 0;
	return 1;
}

void hash::insert(int x)
{
	if(full())
	{
		cout<<"\nHash Table is Full!";
		return;
	}
	int start=hf(x);
	if(data[start]==-1)//location is empty
		data[start]=x;
	else if(start==hf(data[start]))//same hash function
	{
		while(chain[start]!=-1)//to point chain pointer
			start=chain[start];
		int loc=start;
		while(data[loc]!=-1)//to point to data
			loc=(loc+1)%MAX;
		data[loc]=x;
		chain[start]=loc;
	}
	else//different hash function
	{
		while(data[start]!=-1)
			start=(start+1)%MAX;
		data[start]=x;
	}
}

int hash::search(int x)
{
	int start=hf(x),i=0;
	if(x==data[start])
		return start;
	while(i<MAX && hf(x)!=hf(data[start]))//linearly check hash function
	{
		start=(start+1)%MAX;
		i++;
	}
	if(i==MAX)//all records checked
		return -1;
	while(start!=-1)
	{
		if(data[start]==x)//chain wise check data
			return start;
		start=chain[start];
	}
	return -1;
}

int main()
{
	int ch,x;
	hash obj;
	while(1)
	{
		system("clear");
		obj.display();
		cout<<"\n\n1. Insert\n2. Search\n3. Exit\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter Data to Insert: ";
				cin>>x;
				obj.insert(x);
				getchar();
				break;
			case 2:
				cout<<"Enter Data to Search: ";
				cin>>x;
				x=obj.search(x);
				if(x!=-1)
					cout<<"Data found at location "<<x;
				else
					cout<<"Data not found";
				getchar();
				break;
			case 3:
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
