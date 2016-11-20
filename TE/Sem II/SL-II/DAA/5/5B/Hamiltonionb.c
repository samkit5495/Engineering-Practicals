/*
				Assigment 5 B
				Hamiltanion Cycle Non Recursive
Name: Jain Samkitkumar Hasmukhlal
Class: TEIT	Roll. No.: 20   Batch:T1
Date:08/03/2016
*/

#include<stdio.h>
#define max 50
static int c;
void op(int a[][max],int v,int o)
{
	int i,j;
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			if(o==1)
				printf("%d\t",a[i][j]);
			else
				a[i][j]=0;
		}
		if(o==1)
			printf("\n");
	}
}

void accept(int a[][max],int v,int e)
{
    int i,t;
    op(a,v,2);
    printf("Graph Type: 1. Directed Graph 2. Undirected Graph\nEnter Your Choice: ");
    scanf("%d",&t);
    if(t<1||t>2)
    {
        printf("Select correct option!!!\n");
        accept(a,v,e);
    }
    else
    {
        for(i=1;i<=e;i++)
        {
            int f,to,d;
            printf("Enter Edge No. %d:\nFrom: ",i);
            scanf("%d",&f);
            printf("To: ");
            scanf("%d",&to);
            printf("Distance: ");
            scanf("%d",&d);
            a[f][to]=d;
            if(t==2)
                a[to][f]=d;
        }
    }
}

void NextValue(int a[][max],int x[],int n,int k)
{
	int j;
	while(1)
	{
		x[k]=(x[k]+1)%(n+1);
		if(x[k]==0)
			return;
		if(a[x[k-1]][x[k]]!=0)
		{
			for(j=1;j<k;j++)
				if(x[j]==x[k])
					break;
			if(j==k)
				if(k<n||(k==n&&a[x[n]][x[1]]!=0))
					return;
		}
	}
}

void hamiltonion(int a[][max],int x[],int n,int k)
{
	int i;
	while(k!=0)
	{
		NextValue(a,x,n,k);
		if(x[k]!=0)
		{
			if(k==n)
			{
				printf("%d.\t",c++);
				for(i=1;i<=n;i++)
					printf("%d->",x[i]);
				printf("%d\n",x[1]);
			}
			else
				k++;
		}
		else
			k--;
	}
}

int main()
{
    int a[max][max],x[max]={0},v,e,i;
    system("clear");
    printf("Enter total no of Vertex:");
    scanf("%d",&v);
    printf("Enter total no of Edges:");
    scanf("%d",&e);
    accept(a,v,e);
    printf("I/P Adjacency Matrix:\n");
    op(a,v,1);


    for(i=1;i<=v;i++)
	{
		x[1]=i;
		c=1;
	    printf("Hamiltonion Path for k=%d\n",i);
	    hamiltonion(a,x,v,2);
    }
    return 0;
}
