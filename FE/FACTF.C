/*
Name - Samkitkumar H. Jain
Std - F.E. (B.E.)	Div - B
Batch - B1	Date - 10/10/2013
Program : To find factorial using function.
*/
int fact(int n);
#include<stdio.h>
#include<conio.h>
void main()
{
	int f,n;
	clrscr();
	printf("Enter the no to be factorialed: ");
	scanf("%d",&n);
	f=fact(n);
	printf("Factorial of %d is %d",n,f);
	getch();
}
int fact(int n)
{
	int f;
	if(n==1)
	return 1;
	f=n*fact(n-1);
	return f;
}