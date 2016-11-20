/*
				Assigment 1
				Implementation of Stack
Name: Jain Samkitkumar Hasmukhlal
Class: SEIT	Roll. No.: 20
Date:
*/


using namespace std;

#include<iostream>

template<class T>

class node
{
	public:
	T data;
	node *next;
};

template<class T>

class stack
{
	public:
	node<T> *top;
	stack()
	{
	      top=NULL;
	}
	void push(T);
	T pop();
	T disptop();
	int isempty();
};

template<class T>

void stack<T>::push(T x)
{
	node<T> *New=new node<T>;   //create space
	New->next=NULL;             //initialize
	New->data=x;
	New->next=top;
	top=New;
}

template<class T>

T stack<T>::pop()
{
	T x;
	node<T> *temp;
	if(!isempty())
	{
		x=top->data;
		temp=top;
		top=top->next;
		delete temp;
		return x;
	}
}

template<class T>

T stack<T>::disptop()
{
	return top->data;
}

template<class T>

int stack<T>::isempty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}
