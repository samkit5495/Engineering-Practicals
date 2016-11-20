
using namespace std;

#include<graphics.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int x,y;
	struct node *next;
}node;

class polygon
{
	int n,p[100],sx,sy;
	public:
	void accept();
	void display();
	node* insert(node*,int,int);
	void non_recfill(int,int,int,int);
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
			cout<<"Vertex "<<i+1<<":\nX: ";
			cin>>p[i];
			cout<<"Y: ";
			cin>>p[++i];
		}
		p[i]=p[0];
		p[++i]=p[1];
	}
	cout<<"Enter Seed Pixel:\nX: ";
	cin>>sx;
	cout<<"Y : ";
	cin>>sy;
	sx+=320;
	sy=240-sy;
}

void polygon::display()
{
	int c=0;
	for(int i=0;i<n;i++)
	{
		setcolor(i+1);
		line(320+p[2*i],240-p[(2*i)+1],320+p[(2*i)+2],240-p[(2*i)+3]);
	}
	for(int i=sx;i<640;i++)//pixel inside test
		if(getpixel(i,sy)!=0)//finding intersection pt
			c++;//no of intersection
	if(c%2==0)//intersection is even then outside
	{
		closegraph();
		cout<<"\nPixel is outside polygon!\n";
	}
	else
		non_recfill(sx,sy,0,3);
}

node* polygon::insert(node *r,int x,int y)
{
	node *n=new node;
	n->x=x;
	n->y=y;
	n->next=NULL;
	if(r==NULL)
		r=n;
	else
	{
		r->next=n;
		r=n;
	}
	return r;
}

void polygon::non_recfill(int x,int y,int old,int New)
{
	node *f=NULL,*r=NULL,*q;
	r=insert(r,x,y);
	f=r;
	while(f)
	{
		x=f->x;
		y=f->y;
		putpixel(x,y,New);
		if(getpixel(x+1,y)==old)
		{
			putpixel(x+1,y,New);
			r=insert(r,x+1,y);
		}
		if(getpixel(x-1,y)==old)
		{
			putpixel(x-1,y,New);
			r=insert(r,x-1,y);
		}
		if(getpixel(x,y+1)==old)
		{
			putpixel(x,y+1,New);
			r=insert(r,x,y+1);
		}
		if(getpixel(x,y-1)==old)
		{
			putpixel(x,y-1,New);
			r=insert(r,x,y-1);
		}
		q=f;
		f=f->next;
		delete q;
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
   	getchar();
	return 0;
}
