//				Assigment 3
//				String Manipulation with pointers
/*
Name - Samkitkumar H. Jain
Date of Performance : 18/7/14
Write a program to perform following  operations on string using functions & pointers
1. Length
2. Copy
3. Concate
4. Compare
5. Reverse
6. Palindrome
7. Substring
*/

#include<stdio.h>
#include<stdlib.h>
void accept(char a[20])
{
	printf("Enter String: ");
	scanf("%s",a);
}

void display(char a[20])
{
	printf("%s",a);
}

int mystrlen(char *a)
{
	int i;
	for(i=0;*(a+i)!='\0';i++);
	return i;
}

void mystrcpy(char *a,char *b)
{
	int i;
	for(i=0;*(a+i)!='\0';i++)
		*(b+i)=*(a+i);
	*(b+i)='\0';
}

void mystrcat(char *a,char *b)
{
	int i=mystrlen(a),j;
	for(j=0;*(b+j)!='\0';j++)
	{
		*(a+i)=*(b+j);
		i++;
	}
	*(a+i)='\0';
}

int mystrcmp(char *a,char *b)
{
	int i;
	for(i=0;*(a+i)!='\0'&&*(b+i)!='\0';i++)
	{
		if(*(a+i)!=*(b+i))
			return(*(a+i)-*(b+i));
	}
	return(*(a+i)-*(b+i));
}

void reverse(char *a)
{
	int start,end;
	end=mystrlen(a)-1;
	for(start=0;start<end;start++)
	{
		char temp;
		temp=*(a+start);
		*(a+start)=*(a+end);
		*(a+end)=temp;
		end--;
	}
}

int palin(char *a)
{
	int start,end;
	end=mystrlen(a)-1;
	for(start=0;start<end;)
	{
		if(*(a+start)==*(a+end))
		{
			start++;
			end--;
		}
		else
			break;
	}
	if(start<end)
		return 0;
	else
		return 1;
}

/*
int substring(char *a,char *b)
{
	int count=0,i,j;
	for(i=0;*(a+i)!='\0';i++)
	{
		for(j=0;*(b+j)!='\0';j++)
		{
			if(*(a+i+j)!=*(b+j))
				break;
		}
		if(*(b+j)=='\0')
			count++;
	}
	return count;
}
*/

int substring(char *a,char *b)
{
	int count=0,i,j;
	for(i=0;*(a+i)!='\0';i++)
	{
		if(*(a+i)==*b)
		{
			for(j=0;*(b+j)!='\0';j++,i++)
			{
				if(*(a+i)!=*(b+j))
					break;
			}
			i--;
			if(*(b+j)=='\0')
			{
				count++;	
			}
		}
	}
	return count;
}

void main()
{
	char a[20],b[20];
	int ch,len,cmp,pal,sub;
	system("clear");
	while(1)
	{
		system("clear");
		printf("String Manipulation\n1. Length\n2. Copy\n3. Concate\n4. Compare\n5. Reverse\n6. Palindrome\n7. Substring\n8. Exit\nPls. Choose your option: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				accept(a);
				len=mystrlen(a);
				printf("Length of String is %d.",len);
				getchar();
				break;
			case 2:
				accept(a);
				mystrcpy(a,b);
				printf("String to be copied: ");
				display(a);
				printf("\nCopied String: ");
				display(b);
				getchar();
				break;
			case 3:
				accept(a);
				accept(b);
				mystrcat(a,b);
				printf("Concated String: ");
				display(a);
				getchar();
				break;
			case 4:
				printf("String Comparision\n");
				accept(a);
				accept(b);
				cmp=mystrcmp(a,b);
				if(cmp==0)
					printf("\nBoth Strings are equal.");
				else if(cmp<0)
					printf("\nString %s is less than %s string.",a,b);
				else
					printf("\nString %s is less than %s string.",b,a);
				getchar();
				break;
			case 5:
				accept(a);
				reverse(a);
				printf("Reversed String is: ");
				display(a);
				getchar();
				break;
			case 6:
				accept(a);
				pal=palin(a);
				if(pal==1)
					printf("Given string is Palindrome.");
				else
					printf("Given string is not Palindrome.");
				getchar();
				break;
			case 7:
				accept(a);
				accept(b);
				sub=substring(a,b);
				if(sub==0)
					printf("Second string is not present in first string.");
				else
					printf("Second string is present %d times in first string.",sub);
				getchar();
				break;
			case 8:
				exit(0);
			default:
				printf("Pls. enter correct option");
				getchar();
		}
		getchar();
	}
	getchar();
}
