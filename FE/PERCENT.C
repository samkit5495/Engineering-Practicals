/*
Name - Samkitkumar H. Jain
Std - F.E. (B.E.)	Div - B
Batch - B1	Date - 15/10/2013
Program : To find total grace marks of any student.
*/
#include<stdio.h>
#include<conio.h>
void main()
{
	float sub1,sub2,sub3,sub4,sub5,total,percent,grade,fail;
	clrscr();
	printf("Note - Enter Marks in following subjects out of 100.\n");
	printf("Enter Marks in Sub 1:\n");
	scanf("%f",&sub1);
	printf("Enter Marks in Sub 2:");
	scanf("%f",&sub2);
	printf("Enter Marks in Sub 3: \n");
	scanf("%f",&sub3);
	printf("Enter Marks in Sub 4: \n");
	scanf("%f",&sub4);
	printf("Enter Marks in Sub 5: \n");
	scanf("%f",&sub5);
	total=sub1+sub2+sub3+sub4+sub5;
	percent=(total/500)*100;
	printf("Your Total is %f.\n",total);
	printf("Your Percentage are %f.\n",percent);
	if(percent<=100 && percent >=60)
	{
		printf("You are in First Class.\n");
		grade=1;
	}
	else if(percent<60 && percent >=50)
	{
		printf("You are in Second Class.\n");
		grade=2;
	}
	else if(percent<50 && percent >=35)
	{
		printf("You are in Third Class.\n");
		grade=3;
	}
	else
	{
		printf("You are in Fail !.\n");
		grade=4;
	}
	printf("Your Grade is %f",grade);
	getch();
}