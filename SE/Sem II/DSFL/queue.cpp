/*
				Assigment 5
				ADT for Queue
Name: Jain Samkitkumar Hasmukhlal
Class: SEIT	Roll. No.: 20
Date:
*/

using namespace std;
#include<iostream>
#define MAX 100

template<class T1>

class queue
{
	T1 q[MAX];
	int f,r;
	public:
	queue()
	{
		f=r=-1;
	}
	void enqueue(T1);
	T1 dequeue();
	int isfull();
	int isempty();
	T1 dispf();
	T1 dispr();
};

template<class T1>

int queue<T1>::isfull()
{
	if((r+1)%MAX==f)
		return 1;
	else
		return 0;
}

template<class T1>

int queue<T1>::isempty()
{
	if(f==-1)
		return 1;
	else
		return 0;
}

template<class T1>

void queue<T1>::enqueue(T1 x)
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

template<class T1>

T1 queue<T1>::dequeue()
{
	if(!isempty())
	{
		if(f==r)
		{
			T1 x;
			x=q[f];
			r=f=-1;
			return x;
		}
		else
			return q[f++];
	}
	return 0;
}

template<class T1>

T1 queue<T1>::dispf()
{
		return q[f];
}

template<class T1>

T1 queue<T1>::dispr()
{
		return q[r];
}
