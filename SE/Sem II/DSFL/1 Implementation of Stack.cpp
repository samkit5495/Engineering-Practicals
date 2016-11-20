/*
				Assigment 1
				Implementation of Stack
Name: Jain Samkitkumar Hasmukhlal
Class: SEIT	Roll. No.: 20   Batch:S1
Date:
*/

using namespace std;

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include "stack.cpp"
#define MAX 100
class eq
{
	char infix[MAX],postfix[MAX],prefix[MAX];
	public:
	eq();
	void accept(int);
	void display(int);
	int icp(char); //incoming stack priority
	int isp(char); //in stack priority
	void infixtopostfix();
	void rev();
	void infixtoprefix();
	float solve(float,float,char);
	float evaluatepost();
	float evaluatepre();
};

eq::eq()
{
	infix[0]='\0';
	postfix[0]='\0';
	prefix[0]='\0';
}

void eq::accept(int o)
{
	if(o==0)
	{
		cout<<"Enter Infix Equation: ";
		cin>>infix;
		if(!isalnum(infix[0])&&infix[0]!='(')
		{
			cout<<"\nEnter Valid Infix Expression!\n";
			accept(o);
		}

	}
	else if(o==1)
	{
		cout<<"Enter Postfix Equation: ";
		cin>>postfix;
	}
	else if(o==2)
	{
		cout<<"Enter Prefix Equation: ";
		cin>>prefix;
	}
}

void eq::display(int o)
{
	if(o==0&&infix[0]!='\0')
		cout<<"Infix Form: "<<infix<<endl;
	else if(o==1&&postfix[0]!='\0')
		cout<<"Postfix Form: "<<postfix<<endl;
	else if(o==2&&prefix[0]!='\0')
		cout<<"Prefix Form: "<<prefix<<endl;
	else
	{
		accept(o);
		display(o);
	}
}

int eq::icp(char t)
{
	if(t=='(')
		return 4;
	else if(t=='^'||t=='$')
		return 3;
	else if(t=='*'||t=='&'||t=='/'||t=='%')
		return 2;
	else if(t=='+'||t=='-')
		return 1;
	else
		return 0;
}

int eq::isp(char t)
{
	if(t=='(')
		return 0;
	else if(t=='^'||t=='$'||t=='*'||t=='&'||t=='/'||t=='%')
		return 2;
	else if(t=='+'||t=='-')
		return 1;
	else
		return 0;
}

void eq::infixtopostfix()
{
	stack<char> s;
	int i=0,k=0;
	char token,x;
	while(infix[i]!='\0')
	{
		token=infix[i++];
		if(token=='(')
			s.push(token);
		else if(isalnum(token))
			postfix[k++]=token;
		else if(token==')')
			while((x=s.pop())!='(')
				postfix[k++]=x;
		else
		{
			while(!s.isempty()&&icp(token)<=isp(s.disptop()))
				postfix[k++]=s.pop();
			s.push(token);
		}
	}
	while(!s.isempty())
		postfix[k++]=s.pop();
	postfix[k]='\0';
}

void eq::rev()
{
	for(int i=0,j=strlen(prefix)-1;i<j;i++,j--)
	{
		char t=prefix[i];
		prefix[i]=prefix[j];
		prefix[j]=t;
	}
}

void eq::infixtoprefix()
{
	stack<char> s;
	int i=strlen(infix)-1,k=0;
	char token,x;
	while(i!=-1)
	{
		token=infix[i--];
		if(token==')')
			s.push(token);
		else if(isalnum(token))
			prefix[k++]=token;
		else if(token=='(')
			while((x=s.pop())!=')')
				prefix[k++]=x;
		else
		{
			while(!s.isempty()&&icp(token)<isp(s.disptop()))
				prefix[k++]=s.pop();
			s.push(token);
		}
	}
	while(!s.isempty())
		prefix[k++]=s.pop();
	prefix[k]='\0';
	rev();
}

float eq::solve(float x1,float x2,char t)
{
	switch(t)
	{
		case '+':
			return x1+x2;
		case '-':
			return x1-x2;
		case '*':
			return x1*x2;
		case '&':
			return x1*x2;
		case '/':
			return x1/x2;
		case '%':
			return (int)x1%(int)x2;
		case '^':
		case '$':
			return powf(x1,x2);
	}
}

float eq::evaluatepost()
{
	stack<float> s;
	char token;
	float x1,x2,x;
	for(int i=0;postfix[i]!='\0';i++)
	{
		token=postfix[i];
		if(isalpha(token))
		{
			cout<<"Enter Value of "<<token<<" : ";
			cin>>x;
			s.push(x);
		}
		else if(isdigit(token))
			s.push(token-48);
		else
		{
			x2=s.pop();
			x1=s.pop();
			s.push(solve(x1,x2,token));
		}
	}
	return s.pop();
}

float eq::evaluatepre()
{
	stack<float> s;
	char token;
	float x1,x2,x;
	rev();
	for(int i=0;prefix[i]!='\0';i++)
	{
		token=prefix[i];
		if(isalpha(token))
		{
			cout<<"Enter Value of "<<token<<" : ";
			cin>>x;
			s.push(x);
		}
		else if(isdigit(token))
			s.push(token-48);
		else
		{
			x1=s.pop();
			x2=s.pop();
			s.push(solve(x1,x2,token));
		}
	}
	return s.pop();
}

int main()
{
	eq obj;
	int ch;
	float x;
	while(1)
	{
		system("clear");
		cout<<"1. Accept Infix\n2. Infix to Postfix\n3. Infix to Prefix\n4. Evaluate Postfix\n5. Evaluate Prefix\n6. Exit\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				obj.accept(0);
				getchar();
				break;
			case 2:
				obj.display(0);
				obj.infixtopostfix();
				obj.display(1);
				getchar();
				break;
			case 3:
				obj.display(0);
				obj.infixtoprefix();
				obj.display(2);
				getchar();
				break;
			case 4:
				cout<<"Do you want to enter new postfix expression.\n(Enter 1 for 'Yes' & 0 for 'No'): ";
				cin>>x;
				if(x==1)
				obj.accept(1);
				obj.display(1);
				x=obj.evaluatepost();
				cout<<"Postfix Evaluation is "<<x;
				getchar();
				break;
			case 5:
				cout<<"Do you want to enter new postfix expression.\n(Enter 1 for 'Yes' & 0 for 'No'): ";
				cin>>x;
				if(x==1)
				obj.accept(2);
				obj.display(2);
				x=obj.evaluatepre();
				cout<<"Prefix Evaluation is "<<x;
				getchar();
				break;
			case 6:
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
