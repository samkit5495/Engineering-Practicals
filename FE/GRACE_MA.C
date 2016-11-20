/*
Name - Samkitkumar H. Jain
Std - F.E. (B.E.)	Div - B
Batch - B1	Date - 16/10/2013
Program : To find total grace marks of any student.
*/
#include<stdio.h>
#include<conio.h>
void main()
{
	float fail,grace;
	int grade;
	clrscr();
	printf("Enter Your Grade in no 1,2 or 3 \n");
	scanf("%d",&grade);
	printf("Enter no of subjects in which you are fail\n");
	scanf("%f",&fail);
	switch(grade)
	{
		case 1:
		{
			if(fail<=3 && fail>0)
			{
				grace=fail*5;
				printf("\nYour Grace marks are %f",grace);
			}
			else
			{
				grace=0;
				printf("\nYour Grace marks are %f",grace);
			}
			break;
		}
		case 2:
		{
			if(fail<=2 && fail>0)
			{
				grace=fail*4;
				printf("\nYour Grace marks are %f",grace);
			}
			else
			{
				grace=0;
				printf("\nYour Grace marks are %f",grace);
			}
			break;
		}
		case 3:
		{
			if(fail==1)
			{
				grace=fail*5;
				printf("\nYour Grace marks are %f",grace);
			}
			else
			{
				grace=0;
				printf("\nYour Grace marks are %f",grace);
			}
			break;
		}
	}
	getch();
}