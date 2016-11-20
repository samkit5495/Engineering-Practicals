/*
				Assigment 3
				ADT for Priority Queue
Name: Jain Samkitkumar Hasmukhlal
Class: SEIT	Roll. No.: 20
Date:

*/

#include<iostream>

typedef struct pat
{
	int id;
	char name[10];
	struct pat *next;
}pat;

class pqueue
{
	pat *f[4],*r[4];
	public:
	pqueue()
	{
		for(int i=1;i<4;i++)
			f[i]=r[i]=NULL;
	}
	void enqueue(pat,int);
	pat dequeue();
	int isempty();
	void display(int);
};

void pqueue::enqueue(pat x,int p)
{
	pat *temp=new pat;
	temp->id=x.id;
	strcpy(temp->name,x.name);
	temp->next=NULL;
	if(r[p]==NULL)
		f[p]=r[p]=temp;
	else
	{
		r[p]->next=temp;
		r[p]=temp;
	}
}

pat pqueue::dequeue()
{
   	pat *temp,x;
   	for(int i=1;i<4;i++)
   	{
   		if(f[i]!=NULL)
		{
			temp=f[i];
			if(f[i]==r[i])
				f[i]=r[i]=NULL;
			else
				f[i]=f[i]->next;
			break;
		}
   	}
	x.id=temp->id;
	strcpy(x.name,temp->name);
	delete temp;
	return x;
}

int pqueue::isempty()
{
	for(int i=1;i<4;i++)
		if(f[i]!=NULL)
			return 0;
	return 1;
}

void pqueue::display(int o)
{
    if(!isempty())
	{
		pat *temp=f[o];
		if(o>=1&&o<=3)
		{
			while(temp!=NULL)
			{
			    cout<<temp->id<<"\t"<<temp->name<<"\t"<<o<<endl;
			    temp=temp->next;
			}
		}
		else
		{
			display(1);
			display(2);
			display(3);
		}
	}
	else
		cout<<"No patient in queue!";
}
