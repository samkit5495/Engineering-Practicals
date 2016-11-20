
using namespace std;

#include<graphics.h>
#include<iostream>
#include<stdio.h>

float xa,ya;

class curve
{
	public:
	void line1(float,float);
	void bezier(float,float,float,float,float,float,int);
};

void curve::line1(float x2,float y2)
{
	line(xa,ya,x2,y2);
	xa=x2;
	ya=y2;
}

void curve::bezier(float xb,float yb,float xc,float yc,float xd,float yd,int n)
{
	float xp,yp,xq,yq,xr,yr,xs,ys,xt,yt,xu,yu;
	if(n==0)
	{
		line1(xb,yb);
		line1(xc,yc);
		line1(xd,yd);
	}
	else
	{
		// cleardevice();
		xp=(xa+xb)/2;yp=(ya+yb)/2;putpixel(xp,yp,YELLOW);
		xq=(xb+xc)/2;yq=(yb+yc)/2;putpixel(xq,yq,YELLOW);
		xr=(xc+xd)/2;yr=(yc+yd)/2;putpixel(xr,yr,YELLOW);
		xs=(xp+xq)/2;ys=(yp+yq)/2;putpixel(xs,ys,YELLOW);
		xu=(xq+xr)/2;yu=(yq+yr)/2;putpixel(xu,yu,YELLOW);
		xt=(xs+xu)/2;yt=(ys+yu)/2;putpixel(xt,yt,YELLOW);
		n--;
		bezier(xp,yp,xs,ys,xt,yt,n);
		bezier(xu,yu,xr,yr,xd,yd,n);
	}
}

int main()
{
	curve obj;
	int ch,t,n,gd = DETECT,gm;
	system("clear");
	cout<<"Enter Value of iterations (n): ";
    cin>>n;
	while(1)
	{
		system("clear");
		cout<<"1. Normal Curve\n2. Flower\n3. Sine Wave\n4. Half Sine Wave\n5. Exit\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				initgraph(&gd, &gm,NULL);
				xa=ya=0;
				obj.bezier(100,0,100,100,0,100,n);
				getchar();
				break;
			case 2:
			    cout<<"\nEnter Center: ";
                cin>>t;
				xa=ya=t;
				initgraph(&gd, &gm,NULL);
                obj.bezier(t,0,2*t,0,t,t,n);
                obj.bezier(2*t,t,2*t,2*t,t,t,n);
                obj.bezier(t,2*t,0,2*t,t,t,n);
                obj.bezier(0,t,0,0,t,t,n);
				getchar();
				break;
			case 3:
			    initgraph(&gd, &gm,NULL);
                line(0,100,200,100);
                xa=0;
                ya=100;
                obj.bezier(0,0,100,0,100,100,n);
                xa=100;
                ya=100;
                obj.bezier(100,200,200,200,200,100,n);
				getchar();
				break;
            case 4:
			    initgraph(&gd, &gm,NULL);
                line(0,100,200,100);
                xa=0;
                ya=100;
                obj.bezier(0,0,100,0,100,100,n);
                xa=100;
                ya=100;
                obj.bezier(100,0,200,0,200,100,n);
				getchar();
				break;
			case 5:
				exit(0);
			default:
				cout<<"Enter valid choice!";
				getchar();
		}
		getchar();
	}
	getchar();
	return 0;
}
