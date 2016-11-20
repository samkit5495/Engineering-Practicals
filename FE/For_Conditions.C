#include<stdio.h>
#include<conio.h>
void main()
{
	int i,j,k;
	clrscr();
	for(i=1;i<=20;i++)
	{
		for(j=i;j<=20;j++)
		{
			printf("* ");
		}
		printf("\n");
		for(k=1;k<=i;k++)
		{
			printf(" ");
		}
	}
	getch();
}
