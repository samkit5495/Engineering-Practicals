//write a c program to compute the roots of qwuadratic eq.:
/*
Name - Samkitkumar H. Jain
Std - F.E. (B.E.)	Div - B
Batch - B1	Date - 15/10/2013
Program : To find roots of quadratic eq.
*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	float a,b,c,d,r1,r2,real,imag;
	clrscr();
	printf("Enter the value of a,b,c in eq.\nax^2+bx+c=0\n");
	scanf("%f %f %f",&a,&b,&c);
	d=(b*b)-(4*a*c);
	if(d>0)
	{
		r1=(-b+sqrt(d))/(2*a);
		r2=(-b-sqrt(d))/(2*a);
		printf("Roots are %f and %f.",r1,r2);
	}
	else if(d==0)
	{
		r1=r2=-b/(2*a);
		printf("Roots are %f and %f.",r1,r2);
	}
	else
	{
		real=-b/(2*a);
		imag=sqrt(-d)/(2*a);
		printf("Roots are :\n %f+%fi\tand\t%f-%fi",real,imag,real,imag);
	}
	getch();
}