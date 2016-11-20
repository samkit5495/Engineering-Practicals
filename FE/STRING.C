#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	char s[100];
	int i,length,a=0;
	clrscr();
	printf("Enter the string: ");
	gets(s);
	length=strlen(s);
	for(i=0;i<=length;i++)
	{
	       if(s[i]=='a')
	       {
			a++;
	       }
	}
	printf("Length of the string is %d",length);
	printf("\nNo of a in string : %d",a);
	getch();
}