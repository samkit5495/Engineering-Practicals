//Bubble Sorting
#include<stdio.h>
#include<conio.h>
void main()
{
	int a[10];
	int i,j,t;
	clrscr();
	printf("Enter 10 numbers : ");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<9;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
	printf("The numbers in assending order are : \n");
	for(i=0;i<10;i++)
	{
		printf("%d \t",a[i]);
	}
	getch();
}