/*
				Assigment 7
				Prim's & Kruskal's Algorithm
Name: Jain Samkitkumar Hasmukhlal
Class: SEIT	Roll. No.: 20
Date: 10/03/2015

Represent any real world graph using adjacency list/adjacency matrix find
minimum spanning tree using Prim's or Kruskal's algorithm.
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
	void prim(int);
	void kruskal();
};

void graph::accept()
{
	cout<<"Enter Total No of Vertex: ";
	cin>>n;
	cout<<"Enter Total no of edges: ";
	cin>>e;
	init();
	for(int i=0;i<e;i++)
	{
	    int f,t,wt;
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

void graph::prim(int u)
{
	int v[n],d[n],f[n],mst=0;
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
		//print the path
		cout<<f[u]<<" -> "<<u<<" = "<<d[u]<<endl;
		mst+=min;
		//update arrays
		//update distance & from array to find min distance from next visited vertex
		for(int i=0;i<n;i++)
		{
			if(!v[i] && G[u][i]<d[i])
			{
				d[i]=G[u][i];
				f[i]=u;
			}
		}
		//display arrays
		/*
		cout<<"Visited\t";
		for(int i=0;i<n;i++)
            cout<<v[i]<<"\t";
        cout<<"\nDistance\t";
        for(int i=0;i<n;i++)
            cout<<d[i]<<"\t";
        cout<<"\nFrom\t";
        for(int i=0;i<n;i++)
            cout<<f[i]<<"\t";
        cout<<endl;*/

	}
	cout<<"MST = "<<mst;
}

void graph::kruskal()
{
    int v[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            v[i][j]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {

        }
    }
}

int main()
{
	graph obj;
	int ch,u;
	while(1)
	{
		system("clear");
		cout<<"1. Accept\n2. Display\n3. Prim's Algorithm\n4. Kruskal's Algorithm\n5. Exit\nEnter your choice: ";
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
				obj.prim(u);
				getchar();
				break;
			case 4:

				getchar();
				break;
			case 5:
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
