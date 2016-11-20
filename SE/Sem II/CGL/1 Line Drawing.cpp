using namespace std;

#include<graphics.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int xx1,yy1,xx2,yy2;
class graph
{

	int xmax,ymax,xmid,ymid;
	public:
	void create();
	void accept();
	void dda(int,int,int,int,int);
	void thickl(float);
	int sign(int);
	void thickb(float);
	void bresenham(int,int,int,int,int);
};

void graph::create()
{
	//char s1[10];
	int i;
	int gd = DETECT,gm;
    initgraph(&gd,&gm,NULL);
    //initwindow();
    xmax=getmaxx();
    ymax=getmaxy();
    xmid = xmax/2;
    ymid = ymax/2;
	cleardevice();
	line(0,ymid,xmax,ymid);//x axis
	line(xmid,0,xmid,ymax);//y axis
	/*outtextxy(xmid+5,ymid+5,"(0,0)");
	outtextxy(xmax-50,ymid+30,"X-axis");
	outtextxy(xmid+10,ymax-30,"Y-axis");
	for(i=xmid+30;i<=xmax;i=i+30)     //x-axis +ve
	{
		line(i,ymid-5,i,ymid+5);
		itoa(i-xmid,s1,10);
		outtextxy(i,ymid+20,s1);
	}
	for(i=xmid-30;i>=0;i=i-30)      //x-axis -ve
	{
		line(i,ymid-5,i,ymid+5);
		itoa(i-xmid,s1,10);
		outtextxy(i,ymid+20,s1);
	}
	for(i=ymid-30;i>=0;i=i-30)      //y-axis +ve
	{
		line(xmid-5,i,xmid+5,i);
		itoa(ymid-i,s1,10);
		outtextxy(xmid-30,i,s1);
	}
	for(i=ymid+30;i<=ymax;i=i+30)      //y-axis -ve
	{
		line(xmid-5,i,xmid+5,i);
		itoa(ymid-i,s1,10);
		outtextxy(xmid-40,i,s1);
	}*/
}
void graph::accept()
{
	cout<<"Line:\nPoint A:\nX: ";
	cin>>xx1;
	cout<<"Y: ";
	cin>>yy1;
	cout<<"Point B:\nX: ";
	cin>>xx2;
	cout<<"Y: ";
	cin>>yy2;
}

void graph::thickl(float w)
{

	float wx,wy;
	line(xmid+xx1,ymid-yy1,xmid+xx2,ymid-yy2);
	if(((yy2-yy1)/(xx2-xx1))<1)//gentle slope
	{
		wy=((w-1)*sqrt(pow((xx2-xx1),2)+pow((yy2-yy1),2)))/(2*abs(xx2-xx1));
		for(int i=0;i<wy;i++)
		{
			line(xmid+xx1,ymid-(yy1-i),xmid+xx2,ymid-(yy2-i));
			line(xmid+xx1,ymid-(yy1+i),xmid+xx2,ymid-(yy2+i));
		}
	}
	else
	{
		wx=((w-1)*sqrt(pow((xx2-xx1),2)+pow((yy2-yy1),2)))/(2*abs(yy2-yy1));
		for(int i=0;i<wx;i++)
		{
			line(xmid+(xx1-i),ymid-yy1,xmid+(xx2-i),ymid-yy2);
			line(xmid+(xx1+i),ymid-yy1,xmid+(xx2+i),ymid-yy2);
		}
	}
}


void graph::thickb(float w)
{
	line(xmid+xx1,ymid-yy1,xmid+xx2,ymid-yy2);
	for(int i=0;i<w;i++)
		if(((yy2-yy1)/(xx2-xx1))<1)
			line(xmid+xx1,ymid-(yy1+i),xmid+xx2,ymid-(yy2+i));
		else
			line(xmid+(xx1+i),ymid-yy1,xmid+(xx2+i),ymid-yy2);
}


void graph::dda(int x1,int y1,int x2,int y2,int o)
{
	int dx=x2-x1,dy=y2-y1,steps;
	float xi,yi,x,y;
	if(abs(dx)>abs(dy))//gentle slope
		steps=abs(dx);
	else
		steps=abs(dy);//steep slope
	xi=(float)dx/steps;
	yi=(float)dy/steps;
	x=x1;
	y=y1;
	putpixel(xmid+x,ymid-y,15);
	for(int i=1;i<=steps;i++)
	{
		x+=xi;
		y+=yi;
		x1=x+0.5;
		y1=y+0.5;
		if(o==1)//normal line
			putpixel(xmid+x1,ymid-y1,15);
		else if(o==2&&i%2==0)//dotted line
			putpixel(xmid+x1,ymid-y1,15);
		else if(o==3&&i%7!=5&&i%7!=6)//dash line
			putpixel(xmid+x1,ymid-y1,15);
		else if(o==4&&i%7!=4&&i%7!=6)//center line
			putpixel(xmid+x1,ymid-y1,15);
	}
}

int graph::sign(int x)
{
    if(x>0)
        return 1;
    else if(x<0)
        return -1;
    else
        return 0;
}

void graph::bresenham(int x1,int y1,int x2,int y2,int o)
{
    int s1,s2,exec,c,x,y,i,e,dx,dy;
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    s1=sign(x2-x1);
    s2=sign(y2-y1);
    if(dy>dx)//steep slope
    {
        int temp=dx;
        dx=dy;
        dy=temp;
        exec=1;
    }
    else//gentle slope
        exec=0;
    e=2*dy-dx;
    x=x1;
    y=y1;
    putpixel(xmax+x,ymax-y,15);
    for(i=0;i<dx;i++)
    {
        while(e>=0)
        {
            if(exec==1)
                x+=s1;
            else
                y+=s2;
            e-=2*dx;
        }
        if(exec==1)
            y+=s2;
        else
            x+=s1;
        e+=2*dy;
        if(o==1)
                putpixel(xmid+x,ymid-y,6);
            else if(o==2&&i%2==0)
                putpixel(xmid+x,ymid-y,6);
            else if(o==3&&i%7!=5&&i%7!=6)
                putpixel(xmid+x,ymid-y,6);
            else if(o==4&&i%7!=4&&i%7!=6)
                putpixel(xmid+x,ymid-y,6);
    }
}

int main()
{
	graph obj;
	int ch,o;
	float w;
	system("clear");
	cout<<"1. DDA\n2. Bresenham\n3. Shape\n4. Exit\nEnter your choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			obj.accept();
			cout<<"\nDDA Line Style:\n1. Normal\n2. Dotted Line\n3. Dash Line\n4. Center Line\n5. Thick Line\n Enter your choice: ";
			cin>>o;

			if(o==5)
			{
				cout<<"Enter Width of thick Line: ";
				cin>>w;
				obj.create();
				obj.thickl(w);
			}
			else
			{
				obj.create();
				obj.dda(xx1,yy1,xx2,yy2,o);
			}
			getch();
			break;
		case 2:
			obj.accept();
			cout<<"\nBresenham Line Style:\n1. Normal\n2. Dotted Line\n3. Dash Line\n4. Center Line\n5. Thick Line\n Enter your choice: ";
			cin>>o;
			if(o==5)
			{
				cout<<"Enter Width of thick Line: ";
				cin>>w;
				obj.create();
				obj.thickb(w);
			}
			else
			{

				obj.create();
				obj.bresenham(xx1,yy1,xx2,yy2,o);
			}
			getch();
			break;
		case 3:
		    obj.create();
		    obj.bresenham(30,10,20,20,1);
            obj.bresenham(20,20,30,30,1);
            obj.bresenham(30,30,40,20,1);
            obj.bresenham(40,20,30,10,1);
            getchar();
		    break;
        case 4:
			exit(0);
		default:
			cout<<"Enter valid choice!";
			getchar();
	}
	getchar();
	return 0;
}
