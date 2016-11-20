using namespace std;

#include<graphics.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

class cir
{
	public:
	void midpoint(float,float,float);
	void bresenham(int,int,int);
	void dda(float,float,float);
	void display(float,float,int,int);
	void olympic(float,float,float);
	void diagram1(float,float,float);
	void diagram2(float,float,float);
	void diagram3(float,float,float);
};

void cir::midpoint(float x1,float y1,float r)
{
	int x=0,y=r;
	float dp=1.25-r;
	do
	{
		if(dp<=0)
			dp+=(2*x++)+3;
		else
			dp+=2*(x++-y--)+5;
		display(x1,y1,x,y);
	}
	while(x<y);
}

void cir::display(float x1,float y1,int x,int y)
{
	putpixel(320+x1,240-y1,15);
	putpixel(320+(x1+x),240-(y1+y),15);
	putpixel(320+(x1+y),240-(y1+x),15);
	putpixel(320+(x1-x),240-(y1+y),15);
	putpixel(320+(x1-y),240-(y1+x),15);
	putpixel(320+(x1-x),240-(y1-y),15);
	putpixel(320+(x1-y),240-(y1-x),15);
	putpixel(320+(x1+x),240-(y1-y),15);
    putpixel(320+(x1+y),240-(y1-x),15);
}

void cir::bresenham(int x1,int y1,int r)
{
	int x,y;
	float dp;
	dp=3-2*r;
	x=0;
	y=r;
	do
	{
		if(dp<=0)
			dp+=(4*x++)+6;
		else
			dp+=4*(x++-y--)+10;
		display(x1,y1,x,y);
	}
	while(x<y);
}

void cir::dda(float xc,float yc,float r)
{
    float i=0,x1=r,y1=0,x2,y2,startx=x1,starty=y1,epsilon,val;
    do
    {
        val=pow(2,i);
        i++;
    }while(val<r);
    epsilon=1/pow(2,i-1);
    do
    {
        x2=x1+y1*epsilon;
        y2=y1-x2*epsilon;
        putpixel(320+x2+xc,240-y2+yc,WHITE);
        delay(50);
        x1=x2;
        y1=y2;
    }
    while((y1-starty)<epsilon||(startx-x1)>epsilon);
}
void cir::olympic(float x1,float y1,float r)
{
	for(int i=0;i<3;i++)
	{
		midpoint(x1,y1,r);
		x1+=2*r;
	}
	y1-=r;
	x1-=5*r;
    for(int i=0;i<2;i++)
	{
		midpoint(x1,y1,r);
		x1+=2*r;
	}
}

void cir::diagram1(float x1,float y1,float r)
{
    int temp=r;
    for(int i=0;i<2;i++)
	{
		midpoint(x1,y1,r);
		r+=2*temp;
	}
	r=temp;
	midpoint(x1-2*r,y1,r);
	midpoint(x1+2*r,y1,r);
	midpoint(x1+r,y1+1.732*r,r);
	midpoint(x1+r,y1-1.732*r,r);
    midpoint(x1-r,y1+1.732*r,r);
    midpoint(x1-r,y1-1.732*r,r);
}

void cir::diagram2(float x1,float y1,float r)
{
    int temp=r;
    for(int i=0;i<3;i++)
	{
		midpoint(x1,y1,r);
		r+=temp;
	}
	r=temp;
	midpoint(x1-2*r,y1,r);
	midpoint(x1+2*r,y1,r);
	midpoint(x1+r,y1+1.732*r,r);
	midpoint(x1+r,y1-1.732*r,r);
    midpoint(x1-r,y1+1.732*r,r);
    midpoint(x1-r,y1-1.732*r,r);
}

void cir::diagram3(float x1,float y1,float r)
{
    midpoint(x1,y1,r);
    r/=2;
    midpoint(x1-r,y1,r);
    midpoint(x1+r,y1,r);
    midpoint(x1,y1-r,r);
    midpoint(x1,y1+r,r);
    midpoint(x1+r/1.4,y1+r/1.4,r);
    midpoint(x1+r/1.4,y1-r/1.4,r);
    midpoint(x1-r/1.4,y1-r/1.4,r);
    midpoint(x1-r/1.4,y1+r/1.4,r);
}

int main()
{
	cir obj;
	int ch;
	float x1,y1,r;
	system("clear");
	cout<<"1. Mid-Point\n2. Bresenham\n3. DDA\n4. Olympic\n5. Diagram 1\n6. Diagram 2\n7. Diagram 3 (flower)\n8. Exit\nEnter your choice: ";
	cin>>ch;
	cout<<"Enter Center Co-ordinates: \n X: ";
	cin>>x1;
	cout<<"Y: ";
	cin>>y1;
	cout<<"Radius: ";
	cin>>r;
	int gd = DETECT,gm;
   	initgraph(&gd, &gm,NULL);
	switch(ch)
	{
		case 1:
			obj.midpoint(x1,y1,r);
			getchar();
			break;
		case 2:
			obj.bresenham(x1,y1,r);
			getchar();
			break;
        case 3:
            obj.dda(x1,y1,r);
            getchar();
            break;
		case 4:
			obj.olympic(x1,y1,r);
			getchar();
			break;
		case 5:
            obj.diagram1(x1,y1,r);
			getchar();
			break;
		case 6:
            obj.diagram2(x1,y1,r);
			getchar();
			break;
		case 7:
            obj.diagram3(x1,y1,r);
			getchar();
			break;
		case 8:
			exit(0);
		default:
			cout<<"Enter valid choice!";
			getchar();
	}
	getchar();
	return 0;
}
