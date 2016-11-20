/*
				Assigment 11
				Sequential File Organization
Name: Jain Samkitkumar Hasmukhlal
Class: SEIT	Roll. No.: 20
Date: 15/03/2015

Implement an index sequential file for any Database and perform following operations on it
 i) Create Database
 ii) Display Database
 iii) Add a record
 iv) Delete a record
 v)Modify a record.

*/

using namespace std;

#include <iostream>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#define BSIZE 3


typedef struct stud
{
	int rn;
	char name[20];
}stud;

typedef struct index
{
	int rn,pos;
}inde;

class file
{
	stud s;
	inde i1;
	fstream mast,ind;
	char mfile[20],ifile[20];
	public:
	file(char nm[])
	{
		strcpy(mfile,nm);
		strcpy(ifile,"index.txt");
	}
	void error(int);
	void create(int);
	void display();
	void sort();
	void reindex();
	void del(int);
	void modify(int);
    int search(int);
    void disp(int);
    void makeempty();
};

void file::error(int o)
{
	if(o==0)
	{
		if(mast.fail())
		{
			cout<<"\nFile opening error!";
			exit(0);
		}
	}
	else
	{
		if(ind.fail())
		{
			cout<<"\nFile opening error!";
			exit(0);
		}
	}

}

void file::create(int n)
{
	mast.open(mfile,ios::app|ios::out);
	error(0);
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter Record ";
		if(n!=1)
			cout<<i+1;
		cout<<":\nRoll. No.: ";
		cin>>s.rn;
		if(search(s.rn)!=-1)
            cout<<"Duplicate Record!";
        else
        {
            cout<<"Name: ";
            cin>>s.name;
            mast.write((char*)&s,sizeof(stud));
        }
	}
	mast.close();
	sort();
	reindex();
}

void file::display()
{
	int i=0;
	cout<<"\n---------------INDEX FILE---------------------";
	ind.open(ifile,ios::in);
	error(1);
	cout<<"\nRoll No.\tIndex";
	while(ind.read((char*)&i1,sizeof(inde)))
		cout<<"\n"<<i1.rn<<"\t"<<i1.pos;
	ind.close();
	mast.open(mfile,ios::in);
	error(0);
	cout<<"\n\n----------------DATA FILE---------------------";
	cout<<"\nIndex\tRoll. No.\tName";
	while(mast.read((char*)&s,sizeof(s)))
	{
		if(i%BSIZE==0)
			cout<<"\n---------------------------------------------\n";
		cout<<i<<"\t"<<s.rn<<"\t\t"<<s.name<<"\n";
		i++;
	}
	mast.close();
}

void file::sort()
{
	stud s1;
	mast.open(mfile,ios::out|ios::in);
	error(0);
	mast.seekg(0,ios::end);//mast points to end of file
	int n=mast.tellg()/sizeof(stud);//no of records
	//bubble sort
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			mast.seekg(j*sizeof(stud),ios::beg);
			mast.read((char*)&s,sizeof(stud));

			mast.seekg((j+1)*sizeof(stud),ios::beg);
			mast.read((char*)&s1,sizeof(stud));

			if(s1.rn<s.rn)
			{
				mast.seekp(j*sizeof(stud),ios::beg);
				mast.write((char*)&s1,sizeof(stud));

				mast.seekp((j+1)*sizeof(stud),ios::beg);
				mast.write((char*)&s,sizeof(stud));
			}
		}
	}
	mast.close();
}

void file::reindex()
{
	int n;
	ind.open(ifile,ios::out);
	error(1);
	mast.open(mfile,ios::ios::in);
	error(0);
	mast.seekg(0,ios::end);
	n=mast.tellg()/sizeof(stud);//no of records
	mast.seekg(0,ios::beg);
	for(int i=0;i<n;i=i+BSIZE)
	{
		mast.seekg(i*sizeof(stud),ios::beg);
		mast.read((char*)&s,sizeof(stud));
		i1.rn=s.rn;
		i1.pos=i;
		ind.write((char*)&i1,sizeof(inde));
	}
	mast.close();
	ind.close();

}

void file::del(int rn)
{

	int pos=search(rn);
	if(pos!=-1)
	{
		mast.open(mfile,ios::in);
		error(0);
		ofstream temp("temp.txt");
		if(temp.fail())
		{
			cout<<"\nFile opening error!";
			exit(0);
		}
		while(mast.read((char*)&s,sizeof(stud)))
			if(s.rn!=rn)
				temp.write((char*)&s,sizeof(stud));
		mast.close();
		temp.close();
		remove(mfile);
		rename("temp.txt",mfile);
		reindex();
	}
	else
		cout<<"\nRecord not found!";
}

void file::modify(int rn)
{
	int pos=search(rn);
	if(pos!=-1)
	{
		cout<<"\nEnter New Record:\nRoll. No.: ";
		cin>>s.rn;
		if(search(s.rn)!=-1)
            cout<<"Duplicate Record!";
        else
        {
            cout<<"Name: ";
            cin>>s.name;
            mast.open(mfile,ios::in|ios::out);
            error(0);
            mast.seekp(pos*sizeof(stud),ios::beg);
            mast.write((char*)&s,sizeof(stud));
            mast.close();
            sort();
            reindex();
        }
	}
	else
		cout<<"\nRecord not found";
}

int file::search(int rn)
{
	stud studs[10];
	ind.open(ifile,ios::in);
	error(1);
	int i=0;
	while(ind.read((char*)&i1,sizeof(inde)))
	{
		if(rn<i1.rn)
			break;
		i++;
	}
	i--;
	if(i==-1)//no records present
	{
		ind.close();
		return -1;
	}
	ind.seekg(i*sizeof(i1),ios::beg);
	ind.read((char*)&i1,sizeof(i1));
	int pos=i1.pos;

	mast.open(mfile,ios::in);
	error(0);
	mast.seekg(pos*sizeof(stud),ios::beg);
	mast.read((char*)studs,BSIZE*sizeof(stud));

	for(i=0;i<BSIZE;i++,pos++)
	{
		if(studs[i].rn==rn)
		{
			ind.close();
			mast.close();
			return pos;
		}
	}
	ind.close();
	mast.close();
	return -1;
}

void file::disp(int pos)
{
	mast.open(mfile,ios::in);
	error(0);
	mast.seekg(pos*sizeof(s),ios::beg);
	mast.read((char*)&s,sizeof(s));
	cout<<"\nIndex\tRoll. No.\tName\n";
	cout<<pos<<"\t"<<s.rn<<"\t"<<s.name;
	mast.close();
}

void file::makeempty()
{
	mast.open(mfile,ios::out);
	error(0);
	ind.open(ifile,ios::out);
	error(1);
	mast.close();
	ind.close();
}

int main()
{
	char nm[20];
	cout<<"Enter File Name: ";
	cin>>nm;
	file obj(nm);
	obj.makeempty();
	int ch,pos,rn,n;
	while(1)
	{
		system("clear");
		obj.display();
		cout<<"\n\n1. Create\n2. Insert\n3. Search\n4. Delete\n5. Modify\n6. Exit\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter No of records: ";
				cin>>n;
				obj.create(n);
				getchar();
				break;
			case 2:
				obj.create(1);
				getchar();
				break;
			case 3:
				cout<<"Enter Roll No.: ";
				cin>>rn;
				pos=obj.search(rn);
				if(pos>=0)
				{
					cout<<"\nSearched data is: ";
					obj.disp(pos);
				}
				else
					cout<<"\nData not found!";
				getchar();
				break;
			case 4:
				cout<<"Enter Roll No.: ";
				cin>>rn;
				obj.del(rn);
				getchar();
				break;
			case 5:
				cout<<"Enter Roll No.: ";
				cin>>rn;
				obj.modify(rn);
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
