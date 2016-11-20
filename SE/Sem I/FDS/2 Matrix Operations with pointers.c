/*
Name - Samkitkumar H. Jain
Date of Performance : 25/7/14
Write a program to perform following  operations on matrix using functions without pointers
1. Addition
2. Substraction
3. Multiplication
4. Transpose
*/
#include<stdio.h>
#include<stdlib.h>
void accept(int a[8][8],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter element no %d%d: ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void display(int a[8][8],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
}
void add(int a[8][8],int b[8][8],int c[8][8],int ra,int ca)
{
	int i,j;
	for(i=0;i<ra;i++)
	{
		for(j=0;j<ca;j++)
			c[i][j]=a[i][j]+b[i][j];
	}
}
void sub(int a[8][8],int b[8][8],int c[8][8],int ra,int ca)
{
	int i,j;
	for(i=0;i<ra;i++)
	{
		for(j=0;j<ca;j++)
			c[i][j]=a[i][j]-b[i][j];
	}
}
void mul(int a[8][8],int b[8][8],int c[8][8],int ra,int ca,int rb,int cb)
{
	int i,j,k;
	for(i=0;i<ra;i++)
	{
		for(j=0;j<cb;j++)
		{
			c[i][j]=0;
			for(k=0;k<ca;k++)
				c[i][j]+=a[i][k]*b[k][j];
		}
			
	}
}
void trans(int a[8][8],int c[8][8],int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
				c[j][i]=a[i][j];
		}
}
void main()
{
	int a[8][8],b[8][8],c[8][8],ra,ca,rb,cb,ch;
	system("clear");
	while(1)
	{
		system("clear");
		printf("Matrix Operations\n1. Input\n2. Add\n3. Subtract\n4. Multiply\n5. Transpose\n6. Exit\nPls. select your option: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				//Accept Matrix A
				printf("\nMatrix A:\nRows: ");
				scanf("%d",&ra);
				printf("\nColumns: ");
				scanf("%d",&ca);
				accept(a,ra,ca);
				//Accept Matrix B
				printf("\nMatrix B:\nRows: ");
				scanf("%d",&rb);
				printf("\nColumns: ");
				scanf("%d",&cb);
				accept(b,rb,cb);
				//Display Matrix A
				printf("\nMatrix A:\n");
				display(a,ra,ca);
				printf("\n");
				//Display Matrix A
				printf("\nMatrix B:\n");
				display(b,rb,cb);
				getchar();
				break;
			case 2:
				printf("\nMatrix A:\n");
				display(a,ra,ca);
				printf("\nMatrix B:\n");
				display(b,rb,cb);
				printf("\nMatrix A+B:\n");
				if(ra==rb&&ca==cb)
				{
					add(a,b,c,ra,ca);
					display(c,ra,ca);
				}
				else
					printf("Cannot be Added as base is different.");
				getchar();
				break;
			case 3:
				printf("\nMatrix A:\n");
				display(a,ra,ca);
				printf("\nMatrix B:\n");
				display(b,rb,cb);
				printf("\nMatrix A-B:\n");
				if(ra==rb&&ca==cb)
				{
					sub(a,b,c,ra,ca);
					display(c,ra,ca);
				}
				else
					printf("Cannot be subtracted as base is different.");
				getchar();
				break;
			case 4:
				printf("\nMatrix A:\n");
				display(a,ra,ca);
				printf("\nMatrix B:\n");
				display(b,rb,cb);
				printf("\nMatrix A*B:\n");
				if(ca==rb)
				{
					mul(a,b,c,ra,ca,rb,cb);
					display(c,ra,cb);
				}
				else
					printf("Cannot be multiplied as base is different.");
				getchar();
				break;
			case 5:
				printf("\nMatrix A:\n");
				display(a,ra,ca);
				printf("\nMatrix A Transpose:\n");
				trans(a,c,ra,ca);
				display(c,ca,ra);
				printf("\nMatrix B:\n");
				display(b,rb,cb);
				printf("\nMatrix B Transpose:\n");
				trans(b,c,rb,cb);
				display(c,cb,rb);
				getchar();
				break;
			case 6:
				exit(0);
			default:
				printf("Pls. enter correct option.");
				getchar();
		}
		getchar();
	}
	getchar();
}
