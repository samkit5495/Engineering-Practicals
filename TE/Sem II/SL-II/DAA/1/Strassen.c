/*
				Assigment 1 B
				Strassen without Pointers
Name: Jain Samkitkumar Hasmukhlal
Class: TEIT	Roll. No.: 20   Batch:T1
Date:19/01/2016
*/
/*
Formulae:
P1 = (A11+ A22)(B11+B22)
P2 = (A21 + A22) * B11
P3 = A11 * (B12 - B22)
P4 = A22 * (B21 - B11)
P5 = (A11 + A12) * B22
P6 = (A21 - A11) * (B11 + B12)
P7 = (A12 - A22) * (B21 + B22)

C11 = P1 + P4 - P5 + P7
C12 = P3 + P5
C21 = P2 + P4
C22 = P1 + P3 - P2 + P6

*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 10
void mat(int A[][MAX],int n1,int n2,int o)
{
	int i,j;
	for(i=0;i<n1;i++)
	{
	    for(j=0;j<n2;j++)
	    {
    		if(o==0)
    			scanf("%d",&A[i][j]);
    		else if(o==1)
    			printf("%d\t",A[i][j]);
	    }
	    if(o==1)
		  printf("\n");
	}
}

int padding(int n1,int n2,int n3,int n4)
{
    int n;
    if(n1>=n2&&n1>=n3&&n1>=n4)
        n=n1;
    else if(n2>=n1&&n2>=n3&&n2>=n4)
        n=n2;
    else if(n3>=n1&&n3>=n2&&n3>=n4)
        n=n3;
    else
        n=n4;
    while(ceil(log(n)/log(2))!=floor(log(n)/log(2)))
        n++;
    return n;
}

void strassen(int a[][MAX],int b[][MAX],int c[][MAX],int n)
{
    int p1[MAX][MAX],p2[MAX][MAX],p3[MAX][MAX],p4[MAX][MAX],p5[MAX][MAX],p6[MAX][MAX],p7[MAX][MAX];
    int temp1[MAX][MAX],temp2[MAX][MAX],i,j;
    if(n>=2)
    {
        //p1
        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
            temp1[i][j]=a[i][j]+a[i+n/2][j+n/2];
            temp2[i][j]=b[i][j]+b[i+n/2][j+n/2];
            }
        }
        strassen(temp1,temp2,p1,n/2);
        //p2
        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
            temp1[i][j]=a[i+n/2][j]+a[i+n/2][j+n/2];
            temp2[i][j]=b[i][j];
            }
        }
        strassen(temp1,temp2,p2,n/2);

        //p3
        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
            temp1[i][j]=a[i][j];
            temp2[i][j]=b[i][j+n/2]-b[i+n/2][j+n/2];
            }
        }
        strassen(temp1,temp2,p3,n/2);

        //p4
        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
            temp1[i][j]=a[i+n/2][j+n/2];
            temp2[i][j]=b[i+n/2][j]-b[i][j];
            }
        }
        strassen(temp1,temp2,p4,n/2);

        //p5
        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
            temp1[i][j]=a[i][j]+a[i][j+n/2];
            temp2[i][j]=b[i+n/2][j+n/2];
            }
        }
        strassen(temp1,temp2,p5,n/2);

        //p6
        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
            temp1[i][j]=a[i+n/2][j]-a[i][j];
            temp2[i][j]=b[i][j]+b[i][j+n/2];
            }
        }
        strassen(temp1,temp2,p6,n/2);

        //p7
        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
            temp1[i][j]=a[i][j+n/2]-a[i+n/2][j+n/2];
            temp2[i][j]=b[i+n/2][j]+b[i+n/2][j+n/2];
            }
        }
        strassen(temp1,temp2,p7,n/2);

        for(i=0;i<n/2;i++)
        {
            for(j=0;j<n/2;j++)
            {
                c[i][j]=p1[i][j]+p4[i][j]-p5[i][j]+p7[i][j];
                c[i][j+n/2]=p3[i][j]+p5[i][j];
                c[i+n/2][j]=p2[i][j]+p4[i][j];
                c[i+n/2][j+n/2]=p1[i][j]+p3[i][j]-p2[i][j]+p6[i][j];
            }
        }
    }
    else if(n==1)
	   c[0][0]=a[0][0]*b[0][0];
}

int main()
{
	int A[MAX][MAX]={0},B[MAX][MAX]={0},C[MAX][MAX]={0},n,n1,n2,n3,n4,i,j;
	system("clear");
    printf("Enter Size of matrix A:\nRow:");
    scanf("%d",&n1);
    printf("Column: ");
    scanf("%d",&n2);
    printf("Enter Matrix A:\n");
	mat(A,n1,n2,0);
    printf("Enter Size of matrix B:\nRow:");
    scanf("%d",&n3);
    printf("Column: ");
    scanf("%d",&n4);
	printf("Enter Matrix B:\n");
    mat(B,n3,n4,0);
    n=padding(n1,n2,n3,n4);
    printf("Matrix A:\n");
	mat(A,n,n,1);
	printf("Matrix B:\n");
	mat(B,n,n,1);
	strassen(A,B,C,n);
	printf("Matrix C:\n");
	mat(C,n,n,1);
	getchar();
	return 0;
}
