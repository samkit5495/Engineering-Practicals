#include<graphics.h>
#include<conio.h>
void main()
{
	int gd=DETECT,gm;
	int xmax,ymax,x,y;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	cleardevice();
	xmax=getmaxx();
	ymax=getmaxy();
	line(0,ymax-50,xmax,ymax-50);
	rectangle((xmax/2)-100,(ymax/2)-50,(xmax/2),(ymax/2)+100);
	line((xmax/2)-100,(ymax/2)-50,(xmax/2)-50,(ymax/2)-100);
	line((xmax/2)-50,(ymax/2)-100,(xmax/2),(ymax/2)-50);
	bar((xmax/2)-75,(ymax/2)+25,(xmax/2)-25,(ymax/2)+100);
	pieslice((xmax/2)+10,(ymax/2)-150,0,360,20);
	rectangle((xmax/2)+50,(ymax/2)+30,(xmax/2)+200,(ymax/2)+60);
	rectangle((xmax/2)+80,(ymax/2)+30,(xmax/2)+120,(ymax/2)-15);
	rectangle((xmax/2)+120,(ymax/2)-15,(xmax/2)+170,(ymax/2)+30);
	circle((xmax/2)+50,(ymax/2)+90,30);
	getch();
}