using namespace std;

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

class basics1
{
					//by default access specifier is private
	char name[10];			//data member
	public:				//access specifier is public
	void accept()			//member function
	{
		cout<<"Enter Your name: ";
		cin>>name;
	}
	void display();
};

void basics1::display()
{
	cout<<"Welcome "<<name<<" !";
}


int main()
{
	basics1 obj;
	obj.accept();
	obj.display();
	getchar();
	return 0;
}
