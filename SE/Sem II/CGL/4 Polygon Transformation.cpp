using namespace std;

#include<graphics.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
	void translation();
	void scaling();
	void rotation(int);
};

void polygon::accept()
{
	cout<<"Enter No of vertices: ";
	cin>>n;
	if(n<3)
    {
		cout<<"\nEnter vertices of a valid polygon!";
		accept();
    }
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

void polygon::scaling()
{
	cout<<"Enter Sx: ";
	cin>>t[0][0];
	cout<<"Enter Sy: ";
	cin>>t[1][1];
	multiply(a,t);
	graph();
	display(a);
	setcolor(RED);
	display(r);
}

void polygon::translation()
{
	cout<<"Enter Tx: ";
	cin>>t[2][0];
	cout<<"Enter Ty: ";
	cin>>t[2][1];
	multiply(a,t);
	graph();
	display(a);
	setcolor(RED);
	display(r);
}

void polygon::rotation(int o)
{
    float ang;
    int dir,x,y;
	cout<<"Enter Angle in degree: ";
	cin>>ang;
	ang=ang*3.14/180;//radian conversion
	if(o==1)//arbitrary point for rotation
	{
		cout<<"Enter co-ordinates of Arbitrary Point:\nX: ";
		cin>>x;
		cout<<"Y: ";
		cin>>y;
	}
	cout<<"1. Clockwise\n2. Anticlockwise\nEnter your choice: ";
	cin>>dir;
	t[0][0]=t[1][1]=cos(ang);
	if(dir==1)//clockwise
	{
		t[0][1]=-sin(ang);
		t[1][0]=sin(ang);
	}
	else//anticlockwise
	{
		t[0][1]=sin(ang);
		t[1][0]=-sin(ang);
	}
	if(o==1)//for rotation through arbitrary point
	{
	    if(dir==1)
        {
            t[2][0]=-x*cos(ang)+y*sin(ang)+x;
            t[2][1]=-x*sin(ang)-y*cos(ang)+y;
        }
        else
        {
            t[2][0]=-x*cos(ang)-y*sin(ang)+x;
            t[2][1]=x*sin(ang)-y*cos(ang)+y;
        }
	}
	multiply(a,t);
	graph();
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
		cout<<"1. Accept\n2. Scale\n3. Translate\n4. Rotate\n5. Rotate w.r.t. Arbitrary Point\n6. Exit\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				obj.accept();
				getchar();
				break;
			case 2:
				obj.scaling();
				getchar();
				break;
			case 3:
				obj.translation();
				getchar();
				break;
			case 4:
				obj.rotation(0);
				getchar();
				break;
			case 5:
				obj.rotation(1);
				getchar();
				break;
			case 6:
				exit(0);
			default:
				cout<<"Enter valid choice!";
				getchar();
		}
	}
	getchar();
	return 0;
}
