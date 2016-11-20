/*
				Assigment 5
				BST (Binary Search Tree)
Name: Jain Samkitkumar Hasmukhlal
Class: SEIT	Roll. No.: 20
Date:

Implement binary search tree as an ADT. Perform following operations:
a) Insert
b) delete
c) depth of the tree
d) search  a nod
e) Find its mirror image
f) Print original
g) mirror image level wise.

*/

using namespace std;

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include"stack.cpp"
#include"queue.cpp"

typedef struct nod
{
	int data;
	struct nod *l,*r;
}nod;

class bst
{
	nod *root;
	int c;//no of leaf nodes
	public:
	bst()
	{
		root=NULL;
	}

	void create();
	void display()
	{
	    c=0;
		if(root!=NULL)
        {
            cout<<"Data in tree: ";
            display1(root);
        }
		else
			cout<<"Tree is empty!";
	}
	void display1(nod *);
	void ins(nod *);
	void del(int);
	int search(int);
	int minimum();
	int maximum();
	int height()
	{
		return heightoftree(root);
	}
	int heightoftree(nod*);
    void levelwiseprint();
	int countleafnodes();
	int countleafnodes1();
	void mirrorimage();
};

void bst::create()
{
	nod *x;
	int n;
	cout<<"Enter No of Nodes: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		x=new nod;
		x->l=x->r=NULL;
		cout<<"Enter Value at Node: ";
		cin>>x->data;
		ins(x);
	}
}

void bst::display1(nod* t)
{
	if(t!=NULL)
	{
		display1(t->l);
		if(t->l==NULL&&t->r==NULL)
             c++;
		cout<<t->data<<"\t";
		display1(t->r);
	}
}

void bst::ins(nod *x)
{
	if(root==NULL)
		root=x;
	else
	{
		nod *temp=root,*p;
		while(temp!=NULL)
		{
			p=temp;
			if(x->data<temp->data)
				temp=temp->l;
			else
				temp=temp->r;
		}
		if(x->data<p->data)
			p->l=x;
		else
			p->r=x;
	}
}

void bst::del(int x)
{
    nod *t=root,*p=NULL;
    while(t!=NULL&&t->data!=x)
    {
        p=t;
        if(x<t->data)
            t=t->l;
        else
            t=t->r;
    }
    if(t==NULL)//data not found or tree is empty
    {
        cout<<"\nData not Found!";
        return;
    }
    if(t->l==NULL&&t->r==NULL)//leaf node (child checking)
    {
        //parent checking
        if(p==NULL)//root node
            root=NULL;
        else if(p->l==t)//left leaf node
            p->l=NULL;
        else
            p->r=NULL;//right leaf node
        delete t;
    }
    else if(t->l!=NULL&&t->r==NULL)//1 left child (child checking)
    {
        //parent checking
        if(p==NULL)//root node with 1 left child
            root=root->l;
        else if(p->l==t)//left node with 1 left child
            p->l=t->l;
        else
            p->r=t->l;//right node with 1 left child
        delete t;
    }
    else if(t->l==NULL&&t->r!=NULL)//1 right child (child checking)
    {
        //parent checking
        if(p==NULL)//root node with 1 right child
            root=root->r;
        else if(p->l==t)//left node with 1 right child
            p->l=t->r;
        else
            p->r=t->r;//right node with 1 right child
        delete t;
    }
    else if(t->l!=NULL&&t->r!=NULL)//2 child (child checking)
    {
        nod *ts;
        p=t;
        ts=t->r;
        while(ts->l!=NULL)
        {
            p=ts;
            ts=ts->l;
        }
        t->data=ts->data;
        if(p->l==ts)
            p->l=ts->r;
        else
            p->r=ts->r;
        delete ts;
    }
}

int bst::search(int x)
{
    nod *t=root;
    while(t!=NULL)
    {
        if(t->data==x)
            return 1;
        if(x<t->data)
            t=t->l;
        else
            t=t->r;
    }
    return 0;
}

void bst::levelwiseprint()
{
    nod *t=root;
    int level=0;
    queue<nod*> q1;
    q1.enqueue(t);
    while(!q1.isempty())
    {
    	queue<nod*> q2;
    	cout<<"\nLevel "<<level++<<": ";
    	while(!q1.isempty())
    	{
    		t=q1.dequeue();
    		cout<<"\t"<<t->data;
    		if(t->l!=NULL)
    			q2.enqueue(t->l);
    		if(t->r!=NULL)
    			q2.enqueue(t->r);
    	}
    	q1=q2;
    }
}

int bst::countleafnodes1()
{
    return c;
}

int bst::countleafnodes()
{
	int c=0;
	nod *t=root;
	stack<nod*> s;
	while(t!=NULL||!s.isempty())
	{
		if(t!=NULL)
		{
			s.push(t);
			t=t->l;
		}
		else
		{
			t=s.pop();
			if(t->l==NULL&&t->r==NULL)
				c++;
			t=t->r;
		}
	}
	return c;
}

int bst::minimum()
{
	nod *t=root;
	while(t->l!=NULL)
		t=t->l;
	return t->data;
}

int bst::maximum()
{
	nod *t=root;
	while(t->r!=NULL)
		t=t->r;
	return t->data;
}

int bst::heightoftree(nod* t)
{
	int count=0;
	if(t==NULL)
		return -1;
	return count=1+max(heightoftree(t->l),heightoftree(t->r));
}

void bst::mirrorimage()
{
    nod *temp=root,*temp1;
    queue<nod*> q;
    q.enqueue(temp);
    while(!q.isempty())
    {
        temp=q.dequeue();
        temp1=temp->l;
        temp->l=temp->r;
        temp->r=temp1;
        if(temp->l!=NULL)
           q.enqueue(temp->l);
        if(temp->r!=NULL)
            q.enqueue(temp->r);
    }
}

/*
void bst::mirrorimage(node *T)
{
        node *temp;
        if(T!=NULL)
        {

            mirrorimage(T-l);
            mirrorimage(T-r);
            temp=T->l;
            T->l=T->r;
            T->r=temp;
        }
}
*/

int main()
{
	bst obj;
	nod *x;
	int ch,x1;
	while(1)
	{
	    system("clear");
	    obj.display();
		cout<<"\n1. Create\n2. Insert\n3. Delete\n4. Height of the tree\n"
				"5. Search  a Node\n6. Mirror image\n"
				"7. No of Leaf Nodes\n8. Minimum Value\n9. Maximum Value\n"
				"10. Level Wise Print\n11. Exit\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				obj.create();
				getchar();
				break;
			case 2:
				x=new nod;
				x->l=x->r=NULL;
				cout<<"Enter Value: ";
				cin>>x->data;
				obj.ins(x);
				getchar();
				break;
			case 3:
				cout<<"Enter Data to Delete: ";
				cin>>x1;
				obj.del(x1);
				getchar();
				break;
			case 4:
				cout<<"Height of tree is "<<obj.height()<<".";
				getchar();
				break;
			case 5:
				cout<<"Enter Data to find: ";
				cin>>x1;
				x1=obj.search(x1);
				if(x1==0)
					cout<<"Data not found!";
				else
					cout<<"Data Found!";
				getchar();
				break;
			case 6:
                obj.mirrorimage();
                cout<<"Mirror Image: ";
                obj.display();
                obj.mirrorimage();
				getchar();
				break;
			case 7:
				cout<<"No of leaf nodes are "<<obj.countleafnodes1();
				getchar();
				break;
			case 8:
				cout<<"Minimum Value is "<<obj.minimum();
				getchar();
				break;
			case 9:
				cout<<"Maximum Value is "<<obj.maximum();
				getchar();
				break;
			case 10:
				obj.levelwiseprint();
				getchar();
				break;
			case 11:
				exit(0);
			default:
				cout<<"\nEnter correct choice!\n";
				getchar();
		}
		getchar();
	}
	getchar();
	return 0;
}
