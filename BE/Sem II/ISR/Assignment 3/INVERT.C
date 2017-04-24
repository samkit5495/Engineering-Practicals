#include<stdio.h>
#include<string.h>
struct words
{
	char str[50];
	int index[5];
	int count;
}w[20];

int main()
{
	FILE *fp;
	char read[50];
	char avoid[][10]={"This","is","a","that","of","my","you","I","an","were","and","but"};
	int i,j,flag=0,flag1=0;
	int point=1,k=0;
	fp=fopen("read.txt","r+");
	while(!feof(fp))
	{
		flag=flag1=0;
		fscanf(fp,"%s",read);
		printf("%s ",read);
		for(i=0;i<12;i++)
		{
			if(strcmp(read,avoid[i])==0)
			{
				  flag=1;
				  break;
			}
		}
		if(flag==0)
		{
			for(i=0;i<k;i++)
			{
				if(strcmp(read,w[i].str)==0)
				{
					flag1=1;
					break;
				}
			}
			if(flag1==1)
			{
				w[i].index[w[i].count]=point;
				w[i].count++;
			}
			else
			{
				strcpy(w[k].str,read);
				w[k].index[0]=point;
				w[k].count=1;
				k++;
			}
		}
		point+=strlen(read);point++;
	}
	for(j=0;j<k;j++)
	{
		printf("\n\n\n%s\t\t",w[j].str);
		printf("%d\t\t",w[j].count);
		if(w[j].count>=1)
			for(i=0;i<w[j].count;i++)
				printf("%d ",w[j].index[i]);
		printf("\n");
	}
	return 0;
}




