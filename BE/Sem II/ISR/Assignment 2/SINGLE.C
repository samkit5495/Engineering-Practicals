#include<stdio.h>
#include<string.h>

int main()
{
	FILE *f1,*f2;
	char word[20],s_word[20],file[4][20];
	int found,cnt,i,j,x,y,clusterd[4],cluster[4][4];
	float s_mat[4][4],d_coef,a,b,thrshld;
	for(i=0;i<4;i++)
	{
		printf("\nEnter name of conflation file%d:",i+1);
		scanf("%s",file[i]);
	}
	for(i=0;i<4;i++)
	{
		clusterd[i]=-1;
		for(j=0;j<4;j++)
		{
			cluster[i][j]=-1;
			if(i==j)
			{
				s_mat[i][j]=1;
				continue;
			}
			f1=fopen(file[i],"r");
			if(f1==NULL)
				printf("\nCannot open conflation file");
			cnt=x=0;
			while(!feof(f1))
			{
				fscanf(f1,"%s",word);
				found=y=0;
				x++;
				f2=fopen(file[j],"r");
				while(!feof(f2))
				{
					y++;
					fscanf(f2,"%s",s_word);
					if(strcmp(word,s_word)==0)
					{
						found=1;
						break;
					}
				}
				fclose(f2);
				if(found==1)
					cnt++;
			}
			a=(2*cnt);
			b=(x+y);
			d_coef=a/b;
			s_mat[i][j]=d_coef;
			fclose(f1);
		}
	}
//	clrscr();
	printf("\nSimilarity matrix:\n");
	for(i=0;i<4;i++)
	{
		printf("\tfile%d\t",(i+1));
	}
	for(i=0;i<4;i++)
	{
		printf("\nfile%d",i+1);
		for(j=0;j<4;j++)
		{
			printf("\t%f",s_mat[i][j]);
		}
	}
	printf("\nEnter the Threshold value(0-1):");
	scanf("%f",&thrshld);
	for(i=0;i<4;i++)
	{
		for(j=i;j<4;j++)
		{
			if(thrshld<=s_mat[i][j]&&clusterd[j]==-1)
			{
				clusterd[j]=1;
				cluster[i][j]=1;
			}
		}
	}
	cnt=1;
	for(i=0;i<4;i++)
	{
		found=0;
		for(j=i;j<4;j++)
		{
			if(cluster[i][j]==1)
			{
			       found=1;
			       printf(" file%d ",j+1);
			}
		}
		if(found==1)
			printf("\tin Cluster%d\n",cnt++);
	}
	return 0;
}

