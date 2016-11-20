/****************************************************************************
		  ASSIGNMENT NAME : 2-D ANIMATION USING SEGMENTATION.
*****************************************************************************
							HEADER FILES                                   */

using namespace std;

#include<conio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>

/****************************************************************************
						STRUCTURE FOR DISPLAY FILE.						   */
typedef struct Display
{
	int Opcode;
	int x,y;
	int no;
	int r;
}disp;
/****************************************************************************
						STRUCTURE FOR SEGMENT TABLE.					   */
typedef struct Segment
{
	int start,end;
	int visible;
	int transx,transy,scalex,scaley;
}seg;

int penx,peny;

/****************************************************************************
							FUNCTION PROTOTYPES.						   */
void Display();
disp Rotate(disp,double);
void Interpreter(seg,disp [],int);

/****************************************************************************
							MAIN FUNCTION.					   		   	   */
int main()
{
	int gd = DETECT,gm,i;

	system("clear");
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	Display();

	closegraph();
	return 0;
}
/**************************************************************************
	TO STORE THE OBJECT IN THE DISPLAY FILE.			   */
void Display()
{
	char a[]="Welcome to indian airlines......";

	seg s[4];
	disp d[80];
	int i,j,k;
	double o;

	d[0].no = 1;
	d[0].Opcode = 1;
	d[0].x = 330;
	d[0].y = 330;

	d[1].no = 2;
	d[1].Opcode = 2;
	d[1].x = 430;
	d[1].y = 410;

	d[2].no = 3;
	d[2].Opcode = 2;
	d[2].x = 490;
	d[2].y = 390;

	d[3].no = 4;
	d[3].Opcode = 2;
	d[3].x = 440;
	d[3].y = 390;

	d[4].no = 5;
	d[4].Opcode = 2;
	d[4].x = 365;
	d[4].y = 330;

	d[5].no = 6;
	d[5].Opcode = 2;
	d[5].x = 330;
	d[5].y = 330;

	s[0].start = 0;
	s[0].end = 5;
	s[0].visible = 1;
	s[0].transx = 2;
	s[0].transy = 2;
	Interpreter(s[0],d,1);

	for(i=0;a[i]!='\0';i++)
	{
		delay(300);
		cout<<a[i];
	}

	Interpreter(s[0],d,1);

	Interpreter(s[0],d,2);

	for(o=1;o<=8;o++)
	{
		for(i=s[0].start;i<=s[0].end;i++)
		{
			d[i] =  Rotate(d[i],-o);
		}
		Interpreter(s[0],d,1);
		delay(200);
		Interpreter(s[0],d,2);
	}
	for(j=0;j<40;j++)
	{
		s[0].transx = j+2;
		s[0].transy = j+2;

		for(i=s[0].start;i<s[0].end+1;i++)
		{
			d[i].x = d[i].x - s[0].transx;
		}
		Interpreter(s[0],d,1);
		delay(40);
		Interpreter(s[0],d,2);
	}
}
/****************************************************************************
			TO INTERPRET THE CODES IN THE SEGMENT FILE.					   */
void Interpreter(seg s,disp d[],int k)
{
	int i;
	if(k!=1)
	{
		setcolor(0);
	}
	else
	{
		setcolor(15);
	}
	for(i=s.start;i<s.end+1;i++)
	{
		if(d[i].Opcode == 1)
		{
			penx = d[i].x;
			peny = d[i].y;
		}
		if(d[i].Opcode == 2)
		{
			line(penx,peny,d[i].x,d[i].y);
			penx = d[i].x;
			peny = d[i].y;
		}
		if(d[i].Opcode == 3)
		{
			circle(penx,peny,d[i].r);
		}
	}
}
/****************************************************************************
			TO ROTATE THE OBJECT TO MOVE TO NEW LOCATION.				   */
disp Rotate(disp d,double o)
{
	int x1 = 275,y1 = 460;
	int i,j,k,val=0;
	double a[5][5],b[5][5],xy[1][3];

	o = o*3.1415/180;
	xy[0][0] = d.x;
	xy[0][1] = d.y;
	xy[0][2] = 1;
	a[0][0] = cos(o);
	a[0][1] = sin(o);
	a[1][0] = -sin(o);
	a[1][1] = cos(o);
	a[0][2] = 0;
	a[1][2] = 0;
	a[2][2] = 1;
	a[2][0] = x1 + (-x1*cos(o) + y1*sin(o));
	a[2][1] = y1 + (-x1*sin(o) - y1*cos(o));

	for(i=0;i<1;i++)
	{
		for(j=0;j<3;j++)
		{
			val = 0;
			for(k=0;k<3;k++)
			{
				val = val + xy[i][k]*a[k][j];
			}
			b[i][j] = val;
		}
	}
	d.x = b[0][0];
	d.y = b[0][1];
	return(d);
}
/*				   END OF THE	PROGRAM.
****************************************************************************/
