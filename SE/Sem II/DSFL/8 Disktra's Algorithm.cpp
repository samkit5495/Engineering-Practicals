/*
				Assigment 8
				Disktra's Algorithm
Name: Jain Samkitkumar Hasmukhlal
Class: SEIT	Roll. No.: 20
Date: 10/03/2015

Represent a given graph using adjacency matrix/adjacency list and find the shortest
path using Dijkstra's algorithm.
*/

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define inf 999
#define max 100
using namespace std;

class graph
{
	int n,e,G[max][max];
    public:
	void init()
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				G[i][j]=inf;
	}
	void accept();
	void display();
	void disktra(int);
};

void graph::accept()
{
	int f,t,wt;
	cout<<"Enter Total No of Vertices: ";
	cin>>n;
	cout<<"Enter Total no of edges: ";
	cin>>e;
	init();
	for(int i=0;i<e;i++)
	{
		cout<<"Enter Edge from: ";
		cin>>f;
		cout<<"Enter Edge till: ";
		cin>>t;
		cout<<"Enter Weight of Edge: ";
		cin>>wt;
		G[f][t]=G[t][f]=wt;
	}
}

void graph::display()
{
	cout<<"Adjacency Matrix:"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<G[i][j]<<"\t";
		cout<<endl;
	}
}

void graph::disktra(int u)
{
	int v[n],d[n],f[n],sv=u;
	//initialization
	for(int i=0;i<n;i++)
	{
		v[i]=0;
		d[i]=G[u][i];
		f[i]=u;
	}
	//values calculation
	v[u]=1;
	for(int k=1;k<n;k++)
	{
	    //minimum distance finding
		int min=inf;
		for(int i=0;i<n;i++)
		{
			if(!v[i] && d[i]<min)
			{
				min=d[i];
				u=i;
			}
		}
		//visited the next close vertex
		v[u]=1;
		//update arrays
		//update distance & from array to find min distance from next visited vertex
		for(int i=0;i<n;i++)
		{
			if(!v[i] && (min+G[u][i])<d[i])
			{
				d[i]=min+G[u][i];
				f[i]=u;
			}
		}
	}
	//display
	for(int i=0;i<n;i++)
	{
		if(i!=sv)
		{
			cout<<i<<" <- ";
			int j=f[i];
			while(j!=sv)
			{
				cout<<j<<" <- ";;
				j=f[j];
			}
			cout<<sv;
			cout<<" = "<<d[i];
		}
		cout<<endl;
	}
}

int main()
{
	graph obj;
	int ch,u;
	while(1)
	{
		system("clear");
		cout<<"1. Accept\n2. Display\n3. Diskta's Algorithm\n4. Exit\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				obj.accept();
				getchar();
				break;
			case 2:
				obj.display();
				getchar();
				break;
			case 3:
				cout<<"Enter Starting Node: ";
				cin>>u;
				obj.disktra(u);
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
