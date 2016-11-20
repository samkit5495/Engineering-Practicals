
using namespace std;

#include<graphics.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

class polygon
{
	int n,xx[20],yy[20],ymax,ymin,s;
	float m[20];
	public:
	polygon()
	{
		ymax=0;
		ymin=480;
	}
	void accept();
	void display();
	void slope();
	void scanline();
};

void polygon::accept()
{
	cout<<"Enter No of vertices of Polygon: ";
	cin>>n;
	if(n<3)
		cout<<"\nEnter vertices of a valid polygon!";
	else
	{
		cout<<"Enter Polygon Co-ordinates of: \n";
		int i;
		for(i=0;i<n;i++)
		{
			cout<<"Vertex "<<i+1<<":\nX: ";
			cin>>xx[i];
			cout<<"Y: ";
			cin>>yy[i];
		}
		xx[i]=xx[0];
		yy[i]=yy[0];
		cout<<"Select Line Style for Pattern:\n1. Solid Line\n2. Dotted Line\n3. Center Line\n4. Dashed Line\n Enter your Choice: ";
		cin>>s;
		s--;
	}
}

void polygon::display()
{
	for(int i=0;i<n;i++)
	{
		setcolor(i+1);
		line(xx[i],yy[i],xx[i+1],yy[i+1]);
	}
}

void polygon::slope()
{
	int dx,dy;
	for(int i=0;i<n;i++)
	{
		if(yy[i]>=ymax)
			ymax=yy[i];
		if(yy[i]<=ymin)
			ymin=yy[i];
		dx=xx[i+1]-xx[i];
		dy=yy[i+1]-yy[i];
		if(dx==0)
            m[i]=0;
		else if(dy==0)
			m[i]=1;
		else if(dx!=0&&dy!=0)
			m[i]=(float)dx/dy;
	}
}

void polygon::scanline()
{
	int a=0;
	slope();
	for(int y=ymax;y>=ymin;y--)
	{
		int c=0,inter_x[20];
		//find intersections
		for(int i=0;i<n;i++)
			if((yy[i]>y&&yy[i+1]<=y)||(yy[i]<=y&&yy[i+1]>y))
				inter_x[c++]=xx[i]+(m[i]*(y-yy[i]));
		//arrange intersections in order
        c--;
		for(int k=1;k<c;k++)
        {
			for(int i=0;i<c-k;i++)
            {
				if(inter_x[i]>inter_x[i+1])
				{
					int temp=inter_x[i];
					inter_x[i]=inter_x[i+1];
					inter_x[i+1]=temp;
				}
            }
        }
		//draw scanline
		delay(100);
		for(int i=0;i<c;i+=2)
		{
			if(a>15)
				a=0;
			setcolor(a++);
			setlinestyle(s,1,1);
			line(inter_x[i],y,inter_x[i+1],y);
		}
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
   	obj.scanline();
   	getchar();
	return 0;
}
