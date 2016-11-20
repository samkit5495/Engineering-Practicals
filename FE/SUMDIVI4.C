/*
Name - Samkitkumar H. Jain
Std - F.E. (B.E.)	Div - B
Batch - B1	Date - 10/10/2013
Program : To find addition of no divisible by 4 till 100.
*/
#include<stdio.h>
#include<conio.h>
void main()
{
	int i,sum=0;
	clrscr();
	for(i=1;i<=100;i++)
	{
		if(i%4==0)
		{
			printf("%d\t",i);
			sum=sum+i;
		}
	}
	printf("\n\nTheir sum is: %d",sum);
	getch();
}
