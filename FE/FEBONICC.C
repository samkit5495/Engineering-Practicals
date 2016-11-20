/*
Name - Samkitkumar H. Jain
Std - F.E. (B.E.)	Div - B
Batch - B1	Date - 10/10/2013
Program : To find febonicci.
*/
#include<stdio.h>
#include<conio.h>
void main()
{
	int f1=0,f2=1,f3,n,i;
	clrscr();
	printf("Enter No till febonicci to be calculated: ");
	scanf("%d",&n);
	printf("%d\t%d\t",f1,f2);
	for(i=1;i<n;i++)
	{
		f3=f1+f2;
		printf("%d\t",f3);
		f1=f2;
		f2=f3;
	}
	getch();
}