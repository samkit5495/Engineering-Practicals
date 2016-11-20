//				Assigment 8
//				Sparse Matrix
/*
Name - Samkitkumar H. Jain
Date of Performance : 19/9/14
Represent sparse matrix using two dimensional array or structure and perform simple and fast transpose
*/

#include<stdio.h>
#include<stdlib.h>

void accept(int s[100][3])
{
	int i,j,a[8][8],r,c,k=1;
	printf("Enter No. of rows in matrix : ");
	scanf("%d",&r);
	printf("Enter No. of columns in matrix : ");
	scanf("%d",&c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter Element at Position[%d][%d] : ",i,j);
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0)
			{
				s[k][0]=i;
				s[k][1]=j;
				s[k][2]=a[i][j];
				k++;
			}
		}
	}
	s[0][0]=r;
	s[0][1]=c;
	s[0][2]=k-1;
}

void display(int s[100][3])
{
	int i;
	printf("\nRow\tColumn\tNon-Zero Value\n");
	printf("----------------------------------\n");
	printf("%d\t%d\t%d\n",s[0][0],s[0][1],s[0][2]);
	printf("----------------------------------\n");
	for(i=1;i<=s[0][2];i++)
		printf("%d\t%d\t%d\n",s[i][0],s[i][1],s[i][2]);
}

void simpletrans(int s1[100][3],int s2[100][3])
{
	int k=1,c,i;
	s2[0][0]=s1[0][1];
	s2[0][1]=s1[0][0];
	s2[0][2]=s1[0][2];
	for(c=0;c<s1[0][1];c++)
	{
		for(i=1;i<=s1[0][2];i++)
		{
			if(c==s1[i][1])
			{
				s2[k][0]=s1[i][1];
				s2[k][1]=s1[i][0];
				s2[k][2]=s1[i][2];
				k++;
			}
		}
	}
}

void fasttrans(int s1[100][3],int s2[100][3])
{
	int t[10],index[10],col,row,i;
	s2[0][0]=s1[0][1];
	s2[0][1]=s1[0][0];
	s2[0][2]=s1[0][2];
	for(i=0;i<s1[0][1];i++)
		t[i]=0;
	for(i=1;i<=s1[0][2];i++)
		t[s1[i][1]]++;
	index[0]=1;
	for(i=1;i<s1[0][1];i++)
		index[i]=index[i-1]+t[i-1];
	for(i=1;i<=s1[0][2];i++)
	{
		col=s1[i][1];
		row=index[col];
		index[col]++;
		s2[row][0]=s1[i][1];
		s2[row][1]=s1[i][0];
		s2[row][2]=s1[i][2];
	}	
}

void add(int s1[100][3],int s2[100][3],int s3[200][3])
{
	int k1,k2,i,j,k;
	k1=s1[0][2];
	k2=s2[0][2];
	i=j=k=0;
	while(i<=k1&&j<=k2)
	{
		if(s1[0][i]<s2[0][j])
		{
			s3[k][0]=s1[i][0];
			s3[k][1]=s1[i][1];
			s3[k][2]=s1[i][2];
			k++;
			i++;
		}
		else if(s2[0][j]<s1[0][i])
		{
			s3[k][0]=s2[j][0];
			s3[k][1]=s2[j][1];
			s3[k][2]=s2[j][2];
			k++;
			j++;
		}
		else if(s1[1][i]<s2[1][j])
		{
			s3[k][0]=s1[i][0];
			s3[k][1]=s1[i][1];
			s3[k][2]=s1[i][2];
			k++;
			i++;
		}
		else if(s2[1][j]<s1[1][i])
		{
			s3[k][0]=s2[j][0];
			s3[k][1]=s2[j][1];
			s3[k][2]=s2[j][2];
			k++;
			j++;
		}
		else
		{
			s3[k][0]=s1[i][0];
			s3[k][1]=s1[i][1];
			s3[k][2]=s1[i][2]+s2[j][2];
			k++;
			i++;
			j++;
		}
	}
	while(i<=k1)
	{
		s3[k][0]=s1[i][0];
		s3[k][1]=s1[i][1];
		s3[k][2]=s1[i][2];
		k++;
		i++;
	}
	while(j<=k2)
	{
		s3[k][0]=s2[j][0];
		s3[k][1]=s2[j][1];
		s3[k][2]=s2[j][2];
		k++;
		j++;
	}
	s3[0][0]=s1[0][0];
	s3[0][1]=s1[0][1];
	s3[0][2]=k-1;
}

void main()
{
	int s1[100][3],s2[100][3],s3[200][3];
	int ch;
	system("clear");
	while(1)
	{
		system("clear");
		//Operation selection
		printf("\nSparse Matrix:\n1. Accept\n2. Simple Transpose\n3. Fast Transpose\n4. Add\n5. Exit\nEnter your choice ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				accept(s1);
				display(s1);
				getchar();
				break;
			case 2:
				printf("Before Simple Transpose");
				display(s1);
				printf("After Simple Transpose");
				simpletrans(s1,s2);
				display(s2);
				getchar();
				break;
			case 3:
				printf("Before Fast Transpose");
				display(s1);
				printf("After Fast Transpose");
				fasttrans(s1,s2);
				display(s2);
				getchar();
				break;
			case 4:
				printf("Enter Matrix A: ");
				accept(s1);
				printf("Enter Matrix B: ");
				accept(s2);
				add(s1,s2,s3);
				printf("Addition A+B:\n");
				display(s3);
				getchar();
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("\nPls. Enter correct choice\n");
				getchar();
		}
		getchar();
	}
	getchar();
}
