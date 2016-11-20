/*
                    Assignment 5
                    2D Clipping
Name: Jain Samkitkumar Hasmukhlal
Class: SEIT	Roll. No.: 20	Batch: S1
Date:
*/

using namespace std;

#include<graphics.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

class polygon
{
	float m,xmin,ymin,xmax,ymax,p1[100],a[100];
	int p[100],n,k;
	public:
	void accept();
	void display()
	{
		cleardevice();
		rectangle(xmin,ymin,xmax,ymax);
        fillpoly(n,p);
	}
	void polyclip();
	void clipl(float,float,float,float);
	void clipr(float,float,float,float);
	void clipt(float,float,float,float);
	void clipb(float,float,float,float);
};

void polygon::accept()
{
	cout<<"Enter No of vertices of Polygon: ";
	cin>>n;
	if(n<3)
    {
        cout<<"\nEnter vertices of a valid polygon!";
        accept();
    }
	else
	{
		cout<<"Enter Polygon Co-ordinates of: \n";
		int i;
		for(i=0;i<2*n;i++)
		{
			cout<<"Vertex "<<":\nX: ";
			cin>>p1[i];
			cout<<"Y: ";
			cin>>p1[++i];
		}
		p1[i]=p1[0];
		p1[++i]=p1[1];
		for(i=0;i<2*n+2;i++)
            p[i]=p1[i];
	}
	cout<<"Enter Window Co-ordinates:\nTop Left Pt 1:\nX: ";
	cin>>xmin;
	cout<<"Y: ";
	cin>>ymin;
	cout<<"Bottom Right Pt 2:\nX: ";
	cin>>xmax;
	cout<<"Y: ";
	cin>>ymax;
}

void polygon::polyclip()
{
	int i;

	k=0;
	for(i=0;i<2*n;i+=2)
		clipl(p1[i],p1[i+1],p1[i+2],p1[i+3]);
	for(i=0;i<k;i++)
		p1[i]=a[i];
	n=k/2;
	p1[i]=p1[0];
	p1[++i]=p1[1];

	k=0;
	for(i=0;i<2*n;i+=2)
		clipr(p1[i],p1[i+1],p1[i+2],p1[i+3]);
	for(i=0;i<k;i++)
		p1[i]=a[i];
	n=k/2;
	p1[i]=p1[0];
	p1[++i]=p1[1];

	k=0;
	for(i=0;i<2*n;i+=2)
		clipb(p1[i],p1[i+1],p1[i+2],p1[i+3]);
	for(i=0;i<k;i++)
		p1[i]=a[i];
	n=k/2;
	p1[i]=p1[0];
	p1[++i]=p1[1];

	k=0;
	for(i=0;i<2*n;i+=2)
		clipt(p1[i],p1[i+1],p1[i+2],p1[i+3]);
	for(i=0;i<k;i++)
		p[i]=a[i];
	n=k/2;
	p[i]=p[0];
	p[++i]=p[1];
}

void polygon::clipl(float x1,float y1,float x2,float y2)
{
	if(x2-x1)
		m=(y2-y1)/(x2-x1);
	else
		m=1;
	if(x1>=xmin && x2>=xmin)//line is inside
	{
		a[k]=x2;
		a[k+1]=y2;
		k+=2;
	}
	if(x1<xmin && x2>=xmin)
	{
		a[k]=xmin;
		a[k+1]=y1+m*(xmin-x1);
		a[k+2]=x2;
		a[k+3]=y2;
		k+=4;
	}
	if(x1>=xmin && x2<xmin)
	{
		a[k]=xmin;
		a[k+1]=y1+m*(xmin-x1);
		k+=2;
	}
}

void polygon::clipr(float x1,float y1,float x2,float y2)
{
	if(x2-x1)
		m=(y2-y1)/(x2-x1);
	else
		m=1;
	if(x1<=xmax && x2<=xmax)
	{
		a[k]=x2;
		a[k+1]=y2;
		k+=2;
	}
	if(x1>xmax && x2<=xmax)
	{
		a[k]=xmax;
		a[k+1]=y1+m*(xmax-x1);
		a[k+2]=x2;
		a[k+3]=y2;
		k+=4;
	}
	if(x1<=xmax && x2>xmax)
	{
		a[k]=xmax;
		a[k+1]=y1+m*(xmax-x1);
		k+=2;
	}
}

void polygon::clipt(float x1,float y1,float x2,float y2)
{
	if(y2-y1)
		m=(x2-x1)/(y2-y1);
	else
		m=1;
	if(y1>=ymin && y2>=ymin)
	{
		a[k]=x2;
		a[k+1]=y2;
		k+=2;
	}
	if(y1<ymin && y2>=ymin)
	{
		a[k]=x1+m*(ymin-y1);
        a[k+1]=ymin;
		a[k+2]=x2;
		a[k+3]=y2;
		k+=4;
	}
	if(y1>=ymin && y2<ymin)
	{
		a[k]=x1+m*(ymin-y1);
		a[k+1]=ymin;
		k+=2;
	}
}

void polygon::clipb(float x1,float y1,float x2,float y2)
{
	if(y2-y1)
		m=(x2-x1)/(y2-y1);
	else
		m=1;
	if(y1<=ymax && y2<=ymax)
	{
		a[k]=x2;
		a[k+1]=y2;
		k+=2;
	}
	if(y1>ymax && y2<=ymax)
	{
		a[k]=x1+m*(ymax-y1);
		a[k+1]=ymax;
		a[k+2]=x2;
		a[k+3]=y2;
		k+=4;
	}
	if(y1<=ymax && y2>ymax)
	{
		a[k]=x1+m*(ymax-y1);
		a[k+1]=ymax;
		k+=2;
	}
}

int main()
{
	polygon obj;
	system("clear");
	obj.accept();
	int gd = DETECT,gm;
   	initgraph(&gd,&gm,NULL);
	obj.display();
	getchar();
	getchar();
	initgraph(&gd,&gm,NULL);
	obj.polyclip();
	obj.display();
	getchar();
	getchar();
	return 0;
}
