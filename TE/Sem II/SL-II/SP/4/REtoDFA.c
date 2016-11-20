/*
				Assigment 4
				RE to DFA
Name: Jain Samkitkumar Hasmukhlal
Class: TEIT	Roll. No.: 20   Batch:T1
Date:10/03/2016
Write a program to convert RE to DFA. (Compiler point of view, RE to DFA direct method from Uho Ulman Sethi)
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //for isalpha function
#define max 20

typedef struct node
{
    char data;
    struct node *left,*right;
    int pos,fpos[max],lpos[max],nullable;
}node;

//followpos table
struct fptab
{
	int posn,followp[max];
	char symbol;
}fp[max];

int posn=0;

typedef struct stack
{
	node *data[max];
	int top;
}stack;

struct dfa1
{
	char state;
	int starray[max];
}dfa[max];

void init(stack *s)
{
	s->top=-1;
}

void push(stack *s,node *p)
{
	s->data[++(s->top)]=p;
}

node *pop(stack *s)
{
	return s->data[(s->top)--];
}

void calfollowp(node *x,node *y)//followpos calculation
{
	int i,j,k,cnt,m;
	for(i=1;i<=x->lpos[0];i++)
	{
		j=x->lpos[i];
		cnt=fp[j].followp[0];
		for(k=1;k<=y->fpos[0];k++)
		{
			m=y->fpos[k];
			if(fp[j].followp[m]!=m)
			{
				cnt++;
				fp[j].followp[m]=m;
			}
		}
		fp[j].followp[0]=cnt;
	}
}

node *create()
{
    char re[max];
    node *p,*q,*root;
    int i,j,x;
    stack s;
    init(&s);
    for(i=1;i<max;i++)//initialize follow position
    	fp[i].followp[0]=0;
    printf("Enter RE in Postfix form: ");
    scanf("%s",re);
    for(x=0;re[x]!='\0';x++)
    {
        if(isalpha(re[x])||re[x]=='#')
        {
        	p=(node*)malloc(sizeof(node));
	        p->data=re[x];
	        p->left=p->right=NULL;
	        push(&s,p);
	        p->fpos[0]=p->lpos[0]=1; //count of elements in the set
	        p->fpos[1]=p->lpos[1]=++posn;
	        p->nullable=0;
	        fp[posn].symbol=re[x];//follow position table entry
	        fp[posn].posn=posn;
        }
        else if(re[x]=='*')
        {
        	q=pop(&s);
        	root=(node*)malloc(sizeof(node));
        	root->data=re[x];
        	root->left=q;
        	root->right=NULL;
        	push(&s,root);
        	root->nullable=1;
        	root->fpos[0]=q->fpos[0];//firstpos calculation
        	for(i=1;i<=q->fpos[0];i++)
        		root->fpos[i]=q->fpos[i];
        	root->lpos[0]=q->lpos[0];//lastpos calculation
        	for(i=1;i<=q->lpos[0];i++)
        		root->lpos[i]=q->lpos[i];
        	calfollowp(root,root); //followpos calculation
        }
        else if(re[x]=='.')
        {
        	p=pop(&s);
        	q=pop(&s);
        	root=(node*)malloc(sizeof(node));
        	root->left=q;
        	root->right=p;
        	root->data=re[x];
        	push(&s,root);
        	root->nullable= p->nullable && q->nullable;
        	root->fpos[0]=q->fpos[0];//firstpos calculation
        	for(i=1;i<=q->fpos[0];i++)
        		root->fpos[i]=q->fpos[i];
        	if(q->nullable==1)
        	{
        		root->fpos[0]=p->fpos[0]+q->fpos[0];
        		j=i;
        		for(i=1;i<=p->fpos[0];i++)
        			root->fpos[j++]=p->fpos[i];
        	}
        	root->lpos[0]=p->lpos[0];//lastpos calculation
        	for(i=1;i<=p->lpos[0];i++)
        		root->lpos[i]=p->lpos[i];
        	if(p->nullable==1)
        	{
        		root->lpos[0]=p->lpos[0]+q->lpos[0];
        		j=i;
        		for(i=1;i<=q->lpos[0];i++)
        			root->lpos[j++]=q->lpos[i];
        	}
        	calfollowp(q,p);//follow position calculation
        }
        else if(re[x]=='|')
        {
			p=pop(&s);
			q=pop(&s);
			root=(node*)malloc(sizeof(node));
        	root->left=q;
        	root->right=p;
        	root->data=re[x];
        	push(&s,root);
        	root->nullable= p->nullable || q->nullable;
        	root->fpos[0]=p->fpos[0]+q->fpos[0];//firstpos calculation
        	for(i=1;i<=q->fpos[0];i++)
        		root->fpos[i]=q->fpos[i];
        	j=i;
        	for(i=1;i<=p->fpos[0];i++)
        		root->fpos[j++]=p->fpos[i];
        	root->lpos[0]=p->lpos[0]+q->lpos[0];//lastpos calculation
        	for(i=1;i<=q->lpos[0];i++)
        		root->lpos[i]=q->lpos[i];
        	j=i;
        	for(i=1;i<=p->lpos[0];i++)
        		root->lpos[j++]=p->lpos[i];
        }
    }
    return pop(&s);
}

void printfollowp()
{
	int i,j,cnt,len;
	printf("\n\tPosition\tSymbol\tFollow Positions\n");
	for(i=1;i<=posn;i++)
	{
		printf("\t%d\t\t%c\t",fp[i].posn,fp[i].symbol);
		len=fp[i].followp[0];
		cnt=0;
		for(j=1;j<max;j++)
		{
			if(fp[i].followp[j]!=0)
			{
				printf("%3d",fp[i].followp[j]);
				cnt++;
			}
			if(cnt==len)
				break;
		}
		printf("\n");
	}
	printf("\n\n");
}

void postorder(node *t)
{
	int i;
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		printf("\n%c\nNullable=%3d\nfpos = ",t->data,t->nullable);
		for(i=1;i<=t->fpos[0];i++)
			printf("%3d",t->fpos[i]);
		printf("\nlpos = ");
		for(i=1;i<=t->lpos[0];i++)
			printf("%3d",t->lpos[i]);
	}
}

void check(int *len,int set[])
{
	int i,l=set[0],z,match=0,b;
	for(i=1;i<=set[0];i++)
		printf("%3d",set[i]);
	printf("\n");
	getchar();
	for(z=1;z<=*len;z++)
	{
		if(l==dfa[z].starray[0])
		{
			match=1;
			for(b=1;b<=l;b++)
			{
				if(dfa[z].starray[b]!=set[b])
				{
					match=0;//new state
					break;
				}
			}
		}
		if(match==1)//old state
			break;
	}
	if(match==0)//new state
	{
		(*len)++;
		for(b=1;b<=l;b++)
			dfa[*len].starray[b]=set[b];
		dfa[*len].starray[0]=l;
	}
}

void printstate(int s)
{
	int i;
	for(i=1;i<=dfa[s].starray[0];i++)
		printf("%3d",dfa[s].starray[i]);
}

void compdfa(node *root)
{
	int set[max],len=1,x,i,j,k,l,y=1,m,m1,cnt;//len is no of states
	char str[max]={' ','a','b'};
	for(i=1;i<=max;i++)
		dfa[i].starray[0]=0;
	dfa[1].starray[0]=root->fpos[0];//copy count of elements of root node
	for(i=1;i<=root->fpos[0];i++)//copy all elements of root node
		dfa[1].starray[i]=root->fpos[i];
	while(y<=len)
	{
		printf("\n\nState is ");
		printstate(y);//print state
		for(x=1;x<=2;x++)//loop for each symbol
		{
			l=0;//pointer to new state array named "set"
			for(j=1;j<=dfa[y].starray[0];j++)//loop for 
			{
				k=dfa[y].starray[j];
				if(fp[k].symbol==str[x])
				{
					m=1;
					m1=fp[k].followp[0];//symbol's follow position count
					cnt=1;
					while(m<=max)//code for union
					{
						if(fp[k].followp[m]==m)
						{
							set[++l]=fp[k].followp[m];//new state
							cnt++;
						}
						m++;
						if(cnt>m1)
							break;
					}
				}
			}
			set[0]=l;
			printf("\n on input symbol %c goes to state \t",str[x]);
			check(&len,set);
		}
		y++;
	}
	printf("\nPrinting All States\n");
	for(i=1;i<=len;i++)
	{
		for(j=1;j<=dfa[i].starray[0];j++)
			printf("%3d",dfa[i].starray[j]);
		printf("\n");
	}
}

int main()
{
	node *root;
    system("clear");
    root=create();
    postorder(root);
    printfollowp();
    printf("\nDFA:\n");
    compdfa(root);
    return 0;
}
