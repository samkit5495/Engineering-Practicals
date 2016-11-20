
using namespace std;

#include<graphics.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

class polygon
{
	float n,a[100][3],t[3][3],r[100][3];
	int xmax,ymax,xmid,ymid;
	public:
	polygon()
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				t[i][j]=0;
		t[0][0]=t[1][1]=t[2][2]=1;
	}
	void accept();
	void graph();
	void display(float[][3]);
	void multiply(float[][3],float[][3]);
	void reflection(int);
};

void polygon::accept()
{
	cout<<"Enter No of vertices: ";
	cin>>n;
	if(n<3)
		cout<<"\nEnter vertices of a valid polygon!";
	else
	{
		cout<<"Enter Co-ordinates of: \n";
		for(int i=0;i<n;i++)
		{
			cout<<"Vertex "<<i+1<<":\nX: ";
			cin>>a[i][0];
			cout<<"Y: ";
			cin>>a[i][1];
			a[i][2]=1;
		}
	}
}

void polygon::graph()
{
	//char s1[10];
	//int i;
	int gd = DETECT,gm;
	initgraph(&gd, &gm,NULL);
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

void polygon::display(float a[][3])
{
	int i;
	for(i=0;i<n-1;i++)
		line(xmid+a[i][0],ymid-a[i][1],xmid+a[i+1][0],ymid-a[i+1][1]);
	line(xmid+a[i][0],ymid-a[i][1],xmid+a[0][0],ymid-a[0][1]);
}

void polygon::multiply(float a[][3],float t[][3])
{
    int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			r[i][j]=0;
			for(k=0;k<3;k++)
				r[i][j]+=a[i][k]*t[k][j];
		}
	}
}

void polygon::reflection(int o)
{
    graph();
    if(o==1)
        t[1][1]=-1;
    else if(o==2)
        t[0][0]=-1;
    else if(o==3)
    {
        t[0][0]=-1;
        t[1][1]=-1;
    }
    else if(o==4)
    {
        t[0][0]=0;
        t[0][1]=1;
        t[1][0]=1;
        t[1][1]=0;
        line(0,479,639,0);
    }
    else if(o==5)
    {
        t[0][0]=0;
        t[0][1]=-1;
        t[1][0]=-1;
        t[1][1]=0;
        line(0,0,639,479);
    }
	multiply(a,t);
	display(a);
	setcolor(RED);
	display(r);
}

int main()
{
	polygon obj;
	int ch;
	while(1)
	{
		system("clear");
		cout<<"1. Accept\n2. Reflection about X-axis\n3. Reflection about Y-axis\n4. Reflection about Origin\n5. Reflection about Arbitrary Axis (y=x)\n6. Reflection about Arbitrary Axis (y=-x)\n7. Exit\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				obj.accept();
				getchar();
				break;
			case 2:
                obj.reflection(1);
				getchar();
				break;
			case 3:
                obj.reflection(2);
				getchar();
				break;
			case 4:
                obj.reflection(3);
				getchar();
				break;
			case 5:
                obj.reflection(4);
				getchar();
				break;
            case 6:
                obj.reflection(5);
				getchar();
				break;
			case 7:
				exit(0);
			default:
				cout<<"Enter valid choice!";
				getchar();
		}
	}
	getchar();
	return 0;
}
