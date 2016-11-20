//				Assigment 2
//				Matrix Operations
/*
Name - Samkitkumar H. Jain
Date of Performance : 27/7/14
Write a program to perform following  operations on matrix using functions
1. Addition using double pointers
2. Substraction using double pointers
3. Multiplication without using pointers
4. Transpose using double pointers
*/
#include<stdio.h>
#include<stdlib.h>

int **create(int r,int c)
{
	int **a,i;
	a=(int**)malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
		*(a+i)=(int*)malloc(c*sizeof(int));
	return a;
}

void accept(int **a,int p[8][8],int r,int c,int o)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("\nEnter Element At [%d][%d]: ",i,j);
			if(o==1)
				scanf("%d",*(a+i)+j);
			else
				scanf("%d",&p[i][j]);
		}
	}
}

void display(int **a,int p[8][8],int r,int c, int o)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(o==1)
				printf("%d\t",*(*(a+i)+j));
			else
				printf("%d\t",p[i][j]);
		}
		printf("\n");
	}
}

void add(int **a,int **b,int **c,int ra,int ca)
{
	int i,j;
	for(i=0;i<ra;i++)
	{
		for(j=0;j<ca;j++)
			*(*(c+i)+j)=*(*(a+i)+j)+*(*(b+i)+j);
	}
}

void sub(int **a,int **b,int **c,int ra,int ca)
{
	int i,j;
	for(i=0;i<ra;i++)
	{
		for(j=0;j<ca;j++)
			*(*(c+i)+j)=*(*(a+i)+j)-*(*(b+i)+j);
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

int **trans(int **a,int row,int col)
{
	int **c,i,j;
	c=create(col,row);
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			*(*(c+j)+i)=*(*(a+i)+j);
	}
	return c;
}

void main()
{
	int **a,**b,**c,ra,ca,rb,cb,ch;
	int p[8][8],q[8][8],r[8][8];
	system("clear");
	while(1)
	{
		system("clear");
		printf("Matrix Operations\n1. Add\n2. Subtract\n3. Multiply\n4. Transpose\n5. Exit\nPls. select your option: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter Rows in Matrix A: ");
				scanf("%d",&ra);
				printf("\nEnter Columns in Matrix A: ");
				scanf("%d",&ca);
				printf("\nEnter Matrix A:\n");
				a=create(ra,ca);
				accept(a,p,ra,ca,1);
				printf("\nEnter Rows in Matrix B: ");
				scanf("%d",&rb);
				printf("\nEnter Columns in Matrix B: ");
				scanf("%d",&cb);
				printf("\nEnter Matrix A:\n");
				b=create(rb,cb);
				accept(b,q,rb,cb,1);
				printf("Matrix A:\n");
				display(a,p,ra,ca,1);
				printf("Matrix B:\n");
				display(b,q,rb,cb,1);
				if(ra==rb&&ca==cb)
				{
					printf("Addition:\n");
					c=create(ra,ca);
					add(a,b,c,ra,ca);
					display(c,r,ra,ca,1);
				}
				else
					printf("Cannot Add as Bases are different.");
				break;
			case 2:
				printf("\nEnter Rows in Matrix A: ");
				scanf("%d",&ra);
				printf("\nEnter Columns in Matrix A: ");
				scanf("%d",&ca);
				printf("\nEnter Matrix A:\n");
				a=create(ra,ca);
				accept(a,p,ra,ca,1);
				printf("\nEnter Rows in Matrix B: ");
				scanf("%d",&rb);
				printf("\nEnter Columns in Matrix B: ");
				scanf("%d",&cb);
				printf("\nEnter Matrix A:\n");
				b=create(rb,cb);
				accept(b,q,rb,cb,1);
				printf("Matrix A:\n");
				display(a,p,ra,ca,1);
				printf("Matrix B:\n");
				display(b,q,rb,cb,1);
				if(ra==rb&&ca==cb)
				{
					printf("Addition:\n");
					c=create(ra,ca);
					sub(a,b,c,ra,ca);
					display(c,r,ra,ca,1);
				}
				else
					printf("Cannot be subtracted as base is different.");
				getchar();
				break;
			case 3:
				printf("\nEnter Rows in Matrix A: ");
				scanf("%d",&ra);
				printf("\nEnter Columns in Matrix A: ");
				scanf("%d",&ca);
				printf("\nEnter Matrix A:\n");
				accept(a,p,ra,ca,0);
				printf("\nEnter Rows in Matrix B: ");
				scanf("%d",&rb);
				printf("\nEnter Columns in Matrix B: ");
				scanf("%d",&cb);
				printf("\nEnter Matrix A:\n");
				accept(b,q,rb,cb,0);
				printf("Matrix A:\n");
				display(a,p,ra,ca,0);
				printf("Matrix B:\n");
				display(b,q,rb,cb,0);
				if(ca==rb)
				{
					printf("Multiplication:\n");
					mul(p,q,r,ra,ca,cb);
					display(c,r,ra,cb,0);
				}
				else
					printf("Cannot multiply as Bases are different.");
				getchar();
				break;
			case 4:
				printf("\nEnter Rows in Matrix A: ");
				scanf("%d",&ra);
				printf("\nEnter Columns in Matrix A: ");
				scanf("%d",&ca);
				printf("\nEnter Matrix A:\n");
				a=create(ra,ca);
				accept(a,p,ra,ca,1);
				printf("Matrix A:\n");
				display(a,p,ra,ca,1);
				c=trans(a,ra,ca);
				display(c,p,ca,ra,1);
				getchar();
				break;
			case 5:
				exit(0);
			default:
				printf("Pls. enter correct option.");
				getchar();
		}
		getchar();
	}
	getchar();
}
