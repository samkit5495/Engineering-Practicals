/*
				Assigment 1 A
				Strassen with Pointers
Name: Jain Samkitkumar Hasmukhlal
Class: TEIT	Roll. No.: 20   Batch:T1
Date:29/12/2015
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int padding(int num)
{
    while(ceil(log(num)/log(2))!=floor(log(num)/log(2)))
        num++;
    return num;
}

void mat(int A[][4],int n,int o)
{
	int i,j;
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n;j++)
	    {
			if(o==0)
				scanf("%d",&A[i][j]);
			else if(o==1)
				printf("%d\t",A[i][j]);
			else
				A[i][j]=0;
	    }
	    if(o==1)
			printf("\n");
	}
}

void matmul(int *A, int *B, int *R, int n)
{
  if (n == 1)
	(*R) += (*A) * (*B);
  else
  {
	matmul(A, B, R, n/4);
	matmul(A, B+(n/4), R+(n/4), n/4);
	matmul(A+2*(n/4), B, R+2*(n/4), n/4);
	matmul(A+2*(n/4), B+(n/4), R+3*(n/4), n/4);
	matmul(A+(n/4), B+2*(n/4), R, n/4);
	matmul(A+(n/4), B+3*(n/4), R+(n/4), n/4);
	matmul(A+3*(n/4), B+2*(n/4), R+2*(n/4), n/4);
	matmul(A+3*(n/4), B+3*(n/4), R+3*(n/4), n/4);
  }
}

void main()
{
	int A[4][4],B[4][4],C[4][4],n,n1,i,j;
	system("clear");
	printf("Enter Size of matrix:");
	scanf("%d",&n);
	n1=padding(n);
	mat(A,n1,2);
	mat(B,n1,2);
	printf("Enter Matrix A:\n");
	mat(A,n,0);
	printf("Matrix A:\n");
	mat(A,n1,1);
	printf("Enter Matrix B:\n");
	mat(B,n,0);
	printf("Matrix B:\n");
	mat(B,n1,1);
	mat(C,n1,2);
	matmul(A,B,C,n1*n1);
	printf("Matrix C:\n");
	mat(C,n1,1);
	getchar();
}
