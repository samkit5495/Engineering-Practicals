using namespace std;

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

template<class T>

class Add
{
	T a,b;
	public:
	T add()
	{
		cout<<"Enter two values: ";
		cin>>a>>b;
		return a+b;
	}
};

int main()
{
	Add<int> obj;
	system("clear");
	cout<<"A+B="<<obj.add()<<"\n";
	getchar();
	return 0;
}
