using namespace std;

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

class arithmetic
{
					
	int a,b,c;
	public:
	void accept()
	{
		cout<<"Enter Operand A: ";
		cin>>a;
		cout<<"Enter Operand B: ";
		cin>>b;
	}
	void add()
	{
		c=a+b;
	}
	void sub()
	{
		c=a-b;
	}
	void mul()
	{
		c=a*b;
	}
	void div()
	{
		c=a/b;
	}
	void display()
	{
		cout<<c<<"\n";
	}
};


int main()
{
	arithmetic a;
	a.accept();
	a.add();
	cout<<"A+B=";
	a.display();
	a.sub();
	cout<<"A-B=";
	a.display();
	a.mul();
	cout<<"A*B=";
	a.display();
	a.div();
	cout<<"A/B=";
	a.display();
	getchar();
	return 0;
}
