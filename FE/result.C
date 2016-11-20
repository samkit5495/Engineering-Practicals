/*
Name - Samkitkumar H. Jain
Std - F.E. (B.E.)	Div - B
Batch - B1	Date - 22/08/2013
Program : To find class of any student.
*/
#include<stdio.h>
#include<conio.h>
void main()
{
	float p;
	clrscr();
	printf("Enter your percentage : ");
	scanf("%f",&p);
	if(p>=70 && p<=100)
	{
		printf("You scored First Class.");
	}
	else if(p>=50 && p<70)
	{
		printf("You scored Second Class.");
	}
	else if(p>=35 && p<50)
	{
		printf("You scored Third Class.");
	}
	else if(p>=0 && p<35)
	{
		printf("You are Fail !.");
	}
	getch();
}