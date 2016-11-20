using namespace std;
#include<iostream>
#include<graphics.h>
//#include<conio.h>
int main()
{
	int gd=DETECT,gm;
	int xmax,ymax,maxcolor;
	//initgraph(&gd,&gm,"c:\\tc\\bgi");
	initgraph(&gd,&gm,NULL);
	cleardevice();
	xmax=getmaxx();
	ymax=getmaxy();
	maxcolor=getmaxcolor();
	cout<<"\nX MAX= "<<xmax<<"\nY MAX= "<<ymax<<"\nMAX Color= "<<maxcolor;
	outtext("Hello Samy");
	setcolor(RED);
	settextstyle(1,0,1);
	outtextxy(230,230,"Jain Samkitkumar Hasmukhlal");
	setcolor(WHITE);
	setlinestyle(1,1,1);
	line(0,15,640,15);
	line(0,65,640,65);
	putpixel(80,80,RED);
	circle(80,80,5);
	rectangle(100,100,200,200);
	circle(300,150,50);
	bar(500,100,400,200);
	ellipse(300,320,0,360,100,50);
	arc(100,320,0,180,50);
	setfillstyle(2,2);
	pieslice(500,320,0,180,50);
	getch();
	return 0;
}
