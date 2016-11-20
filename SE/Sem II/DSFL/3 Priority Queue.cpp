/*
				Assigment 3
				Priority Queue
Name: Jain Samkitkumar Hasmukhlal
Class: SEIT	Roll. No.: 20
Date:

Problem Statement: Implement priority queue as ADT using multiple linked lists ,one list for each
priority for servicing patients in an hospital with priorities as
i) Serious (top priority)
ii)medium illness (medium priority)
iii) General (Least priority).

*/

using namespace std;

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"pqueue.cpp"

class hospital
{
	pat x;
	public:
	pqueue obj;
	void admit();
	void discharge();
};

void hospital::admit()
{
	int p;
	cout<<"Enter Patient Id: ";
	cin>>x.id;
	cout<<"Enter Patient Name: ";
	cin>>x.name;
	cout<<"Enter Priority:\n1. Serious (Top Priority)\n2. Medium Illness (Medium Priority)\n3. General (Least Priority)\nEnter your choice: ";
	cin>>p;
	if(p>=1&&p<=3)
		obj.enqueue(x,p);
	else
		cout<<"Enter correct priority";
}

void hospital::discharge()
{
	if(!obj.isempty())
	{
		x=obj.dequeue();
		cout<<"Next patient:\nId : "<<x.id<<"\nName : "<<x.name;
	}
	else
		cout<<"No patient in queue!";
}

int main()
{
	hospital s;
	int ch,p;
	while(1)
	{
		system("clear");
		cout<<"1. Admit New Patient\n2. Discharge A Patient\n3. Display Patient\n4. Exit\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				s.admit();
				getchar();
				break;
			case 2:
				s.discharge();
				getchar();
				break;
			case 3:
				cout<<"Enter Priority:\n1. Serious (Top Priority)\n2. Medium Illness (Medium Priority)\n3. General (Least Priority)\n4. Display All Priority wise\nEnter your choice: ";
				cin>>p;
				if(p>=1&&p<=4)
				{
                    cout<<"ID\tPatient Name\tPriority"<<endl;
					s.obj.display(p);
				}
				getchar();
				break;
			case 4:
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
