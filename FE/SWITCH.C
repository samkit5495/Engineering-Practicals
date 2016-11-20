/*
Name - Samkitkumar H. Jain
Std - F.E. (B.E.)	Div - B
Batch - B1	Date - 22/08/2013
Program : To use switch in creating a menu program.
*/
#include<stdio.h>
#include<conio.h>
void main()
{
	float a,b,c;
	int i,s;
	for(i=1;i<=3;i++)
	{
		clrscr();
		printf("\n1. Addition\n\t2. Substration\n\t\t3. Multiplication\n\t\t\t4. Division\n\t\t\t\t5. Comparision");
		printf("\n\nPlease select the option : ");
		scanf("%d",&s);
		if(s>=1 && s<=5)
		{
			clrscr();
			printf("Value of A : ");
			scanf("%f",&a);
			printf("Value of B : ");
			scanf("%f",&b);
			switch(s)
			{
				case 1:
					c=a+b;
					printf("Your Addition is : %f",c);
					break;
				case 2:
					c=a-b;
					printf("Your Subtraction is : %f",c);
					break;
				case 3:
					c=a*b;
					printf("Your Multiplication is : %f",c);
					break;
				case 4:
					c=a/b;
					printf("Your Division is : %f",c);
					break;
				case 5:
					if(a<b)
					{
						printf("%f is smaller than %f",a,b);
					}
					else if(b<a)
					{
						printf("%f is smaller than %f",b,a);
					}
					else
					{
						printf("Both numbers %f & %f are same.",a,b);
					}
					break;
			}
	}
	else
	{
		printf("Please enter a valid value.");
	}
	}
	getch();
}