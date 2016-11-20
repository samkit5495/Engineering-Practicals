/*
Name - Samkitkumar H. Jain
Std - F.E. (B.E.)	Div - B
Batch - B1	Date - 10/10/2013
Program : To find prime.
*/
#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i,no,total=0,a;
	clrscr();
	printf("Enter Range End: ");
	scanf("%d",&n);
	for(no=1;no<=n;no++)
	{
		for(i=2;i<no/2+1;i++)
		{
			if(no%i==0)
			break;
		}
		if(i==no/2+1)
		{
			printf("%d \t",no);
			total++;
		}

	}
	printf("\n\nTotal prime no in range till %d are %d",n,total);
	getch();
}