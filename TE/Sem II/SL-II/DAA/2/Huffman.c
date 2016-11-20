/*
				Assigment 2
				Huffman Tree
Name: Jain Samkitkumar Hasmukhlal
Class: TEIT	Roll. No.: 20   Batch:T1
Date:15/03/2016
*/
#include<stdio.h>
#include<stdlib.h>
#define max 100

typedef struct MinHeapNode// Node structure
{
    int f;
    char s;
    struct MinHeapNode *l,*r;
}MinHeapNode;

typedef struct MinHeap// structure of array
{
	int size,capacity;
	MinHeapNode **array;
}MinHeap;

MinHeapNode* newNode(char s,int f)//Memory alloction of node
{
	MinHeapNode *temp=(MinHeapNode*)malloc(sizeof(MinHeapNode));
	temp->l=temp->r=NULL;
	temp->s=s;
	temp->f=f;
	return temp;
}

void minHeapify(MinHeap * minHeap,int i)
{
	int smallest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l < minHeap->size && minHeap->array[l]->f < minHeap->array[smallest]->f)
		smallest=l;
	if(r < minHeap->size && minHeap->array[r]->f < minHeap->array[smallest]->f)
		smallest=r;
	if(smallest!=i)
	{
		//swap
		MinHeapNode *t=minHeap->array[smallest];
		minHeap->array[smallest]=minHeap->array[i];
		minHeap->array[i]=t;
		minHeapify(minHeap,smallest);
	}
}

void buildMinHeap(MinHeap* minHeap)
{
	int n=minHeap->size-1,i;
	for(i=(n-1)/2;i>=0;i--)
		minHeapify(minHeap,i);
}

MinHeap* createMinHeap(char s[],int f[],int n)
{
	int i;
	MinHeap *minHeap=(MinHeap*)malloc(sizeof(MinHeap));
	minHeap->capacity=n;
	minHeap->array=(MinHeapNode **)malloc(n*sizeof(MinHeapNode*));
	for(i=0;i<n;i++)
		minHeap->array[i]=newNode(s[i],f[i]);
	minHeap->size=n;
	buildMinHeap(minHeap);
	return minHeap;
}

MinHeapNode *extractMin(MinHeap *minHeap)
{
	MinHeapNode *temp=minHeap->array[0];
	minHeap->array[0]=minHeap->array[minHeap->size-1];
	minHeap->size--;
	minHeapify(minHeap,0);
	return temp;
}

void insertMinHeap(MinHeap *minHeap,MinHeapNode *minHeapNode)
{
	int i;
	minHeap->size++;
	i=minHeap->size-1;//i points to last empty position
	while(i && minHeapNode->f < minHeap->array[(i-1)/2]->f)
	{
		minHeap->array[i]=minHeap->array[(i-1)/2];
		i=(i-1)/2;
	}
	minHeap->array[i]=minHeapNode;
}

MinHeapNode* buildHuffmanTree(char s[],int f[],int n)
{
	MinHeapNode *l,*r,*top;
	MinHeap *minHeap=createMinHeap(s,f,n);
	while(minHeap->size!=1)
	{
		l=extractMin(minHeap);
		r=extractMin(minHeap);
		top=newNode('$',l->f+r->f);
		top->l=l;
		top->r=r;
		insertMinHeap(minHeap,top);
	}
	return extractMin(minHeap);
}

void printCodes(MinHeapNode *root,int code[],int top)
{
	if(root->l)
	{
		code[top]=0; 
		printCodes(root->l,code,top+1);
	}
	if(root->r)
	{
		code[top]=1;
		printCodes(root->r,code,top+1);
	}
	if(root->l==NULL&&root->r==NULL)
	{
		int i;
		printf("%c: ",root->s);
		for(i=0;i<top;i++)
			printf("%d",code[i]);
		printf("\n");
	}
}

void decode(MinHeapNode *root,char x[])
{
	int i=0;
	MinHeapNode *t=root;
	while(x[i]!='\0' && t->l!=NULL && t->r!=NULL)
	{
		if(x[i]=='0')
			t=t->l;
		else
			t=t->r;
		i++;
	}
	if(x[i]!='\0')
		printf("Data Not Found!!!\n");
	else
		printf("Decoded data is %c\n",t->s);
}

int main()
{
    int i,f[max],n,code[max],ch;
    char s[max],x[max];
    MinHeapNode *root;
    printf("Enter count of data to be encoded: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       	getchar();//to remove \n
        printf("%d. Enter Symbol: ",i+1);
        scanf("%c",&s[i]);
        printf("%d. its frequency: ",i+1);
        scanf("%d",&f[i]);
    }
	root=buildHuffmanTree(s,f,n);
	printCodes(root,code,0);
	while(1)
	{
		printf("\n1. Decode\n2. Exit\nEnter Your Choice: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("\nEnter binary data to decode: ");
			scanf("%s",x);
			decode(root,x);
		}
		else if(ch==2)
			exit(0);
		else
			printf("\nEnter Correct Choice!!!");
	}
    return 0;
}
