/*
				Assigment 9
				Heap Sort
Name: Jain Samkitkumar Hasmukhlal
Class: SEIT	Roll. No.: 20
Date: 15/03/2015

Implement Heap sort by constructing max or min heap.
*/

#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class heap
{
	int a[10],n;
	public:
	void accept();
	void display();
	void downadjust(int);
	void maxheap();
	void sort();
};

void heap::accept()
{
	cout<<"Enter No of Elements : ";
	cin>>n;
	a[0]=n;
	for(int i=1;i<=n;i++)
	{
		cout<<"Enter element No."<<i<<": ";
		cin>>a[i];
	}
}

void heap::display()
{
	for(int i=1;i<=n;i++)
		cout<<a[i]<<"\t";
}

void heap::maxheap()
{
	for(int i=n/2;i>=1;i--)
		downadjust(i);
}

void heap::downadjust(int i)
{
	int j=2*i;
	while(j<=a[0])
	{
	    //to find greater between siblings
		if(j<a[0]&&a[j+1]>a[j])
			j++;
        //to swap if parent is less than selected child
		if(a[i]<a[j])
		{
			int t=a[i];
			a[i]=a[j];
			a[j]=t;
			i=j;//to shift to down position to down adjust till leaf nodes
		}
		else
			break;
		j=2*i;//to shift to down position to down adjust till leaf nodes
	}
}

void heap::sort()
{
	int p=1;
	for(int i=n;i>=2;i--)
	{
		int t=a[1];
		a[1]=a[i];
		a[i]=t;
		a[0]--;
		downadjust(1);
		cout<<"\nPass No.: "<<p++<<endl;
		display();
	}
}

int main()
{
	heap obj;
	system("clear");
	cout<<"\t\tHeap Sort\n";
	obj.accept();
	cout<<"Before Sorting:\n";
	obj.display();
	cout<<"During Sort:\n";
	obj.maxheap();
	obj.sort();
	getchar();
	return 0;
}
