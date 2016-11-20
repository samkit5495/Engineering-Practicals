
using namespace std;

#include<graphics.h>
#include<iostream>
#include<stdio.h>

class lnclip
{
        const int a=8,b=4,r=2,l=1;
	int x1,y1,x2,y2,xmin,ymin,xmax,ymax;
	public:
	void accept();
	int calcode(int,int);
	void lineclipping();
};

void lnclip::accept()
{
	cout<<"Enter Line Co-ordinates:\nPt 1:\nX: ";
	cin>>x1;
	cout<<"Y: ";
	cin>>y1;
	cout<<"Pt 2:\nX: ";
	cin>>x2;
	cout<<"Y: ";
	cin>>y2;
	cout<<"Enter Window Co-ordinates:\nTop Left Pt 1:\nX: ";
	cin>>xmin;
	cout<<"Y: ";
	cin>>ymin;
	cout<<"Bottom Right Pt 2:\nX: ";
	cin>>xmax;
	cout<<"Y: ";
	cin>>ymax;
}

int lnclip::calcode(int x,int y)
{
	int code=0;
	if(y>ymax)
		code=a;
	else if(y<ymin)
		code=b;
	else if(x>xmax)
		code=r;
	else if(x<xmin)
		code=l;
	return code;
}

void lnclip::lineclipping()
{
	unsigned int code1,code2,codeout;
	int accept=0,done=0;
	line(x1,y1,x2,y2);
	rectangle(xmin,ymin,xmax,ymax);
	getchar();
	getchar();
	cleardevice();
	code1=calcode(x1,y1);
	code2=calcode(x2,y2);
	do
	{
		if(!(code1 | code2))
		{
			accept=1;
			done=1;
		}
		else if(code1 & code2)
			done=1;
		else
		{
			float x,y;
			codeout=code1?code1:code2;
			if(codeout & a)
			{
				x=x1+(x2-x1)*(ymax-y1)/(y2-y1);
				y=ymax;
			}
			else if(codeout & b)
			{
				x=x1+(x2-x1)*(ymin-y1)/(y2-y1);
				y=ymin;
			}
			else if(codeout & r)
			{
				y=y1+(y2-y1)*(xmax-x1)/(x2-x1);
				x=xmax;
			}
			else
			{
				y=y1+(y2-y1)*(xmin-x1)/(x2-x1);
				x=xmin;
			}
			if(codeout==code1)
			{
				x1=x;
				y1=y;
				code1=calcode(x1,y1);
			}
			else
			{
				x2=x;
				y2=y;
				code2=calcode(x2,y2);
			}
		}
	}
	while(done==0);
	if(accept)
		line(x1,y1,x2,y2);
	rectangle(xmin,ymin,xmax,ymax);
}

int main()
{
	lnclip obj;
	system("clear");
	obj.accept();
	int gd = DETECT,gm;
    initgraph(&gd,&gm,NULL);
	obj.lineclipping();
	getchar();
	return 0;
}
