/*
				Assigment 3
				Warshal & Floyd's Algorithm
Name: Jain Samkitkumar Hasmukhlal
Class: TEIT	Roll. No.: 20   Batch:T1
Date:02/02/2016
*/

#include<stdio.h>
#define max 50

void op(int k,int a[][max][max],int v,int o)
{
	int i,j;
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			if(o==1)
				printf("%d\t",a[k][i][j]);
			else
			{
				if(i==j)
					a[k][i][j]=0;
				else
					a[k][i][j]=999;
			}
		}
		if(o==1)
			printf("\n");
	}
}

void accept(int a[][max][max],int v,int e)
{
    int i,t;
    op(0,a,v,2);
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
            a[0][f][to]=d;
            if(t==2)
                a[0][to][f]=d;
        }
    }
}

int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}

void floyd(int a[][max][max],int v)
{
	int i,j,k;
	for(k=1;k<=v;k++)
		for(i=1;i<=v;i++)
			for(j=1;j<=v;j++)
				a[k][i][j]=min(a[k-1][i][j],a[k-1][i][k]+a[k-1][k][j]);
}


void convert(int a[][max][max],int b[][max][max],int v)
{
	int i,j;
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
		    if(a[0][i][j]>0&&a[0][i][j]<999)
				b[0][i][j]=1;
            else
                b[0][i][j]=0;
		}
	}
}

void warshal(int a[][max][max],int v)
{
	int i,j,k;
	for(k=1;k<=v;k++)
		for(i=1;i<=v;i++)
			for(j=1;j<=v;j++)
				a[k][i][j]=(a[k-1][i][j]) | ((a[k-1][i][k]) & (a[k-1][k][j]));
}

int main()
{
    int a[max][max][max],b[max][max][max],v,e,i;
    system("clear");
    printf("Enter total no of Vertex:");
    scanf("%d",&v);
    printf("Enter total no of Edges:");
    scanf("%d",&e);
    accept(a,v,e);
    printf("I/P Matrix:\n");
    op(0,a,v,1);
    floyd(a,v);
    printf("Floyd Cost Matrix:\n");
    for(i=0;i<=v;i++)
    {
    	printf("\nD%d:\n",i);
        op(i,a,v,1);
    }
    printf("Warshal Closure Matrix:\n");
    convert(a,b,v);
    warshal(b,v);
    for(i=0;i<=v;i++)
    {
    	printf("\nW%d:\n",i);
        op(i,b,v,1);
    }
    return 0;
}
