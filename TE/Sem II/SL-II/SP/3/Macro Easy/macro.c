/*
Name:Jagtap Aishwarya S.
Roll NO:19 TEIT

				macro
				Assignment No:3
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 FILE *fp,*fp1;
char line[100];
char ft[30],st[30],tt[30],lt[30];
struct pnt
{
	int no;
	char pname[50];
}pn[100];
int pnptr=1;

struct kpn 
{
	char kpname[50],value[50];
}kpn[100];
int kpptr=1;

struct mnt
{
	int pp,kp,ev,mdtp,kpdtp,sstp;
	char mname[50];
}mnt[100];
int mntptr=0;
struct mdt 
{
	char op[50],operand1[50],operand2[50];
}mdt[100];
int mdtptr=1;

struct aptab
{
	char aname[50];
}aptab[100];
int MEC=1;
int token()
{
	int i=0,j=0;
	while(line[i]!=' ' && line[i]!='\n')
	{
		ft[j]=line[i];
		i++;j++;
	}
	ft[j]='\0';
	if(line[i]=='\n')
		return(1);

	j=0;i++;

	//SEC

	while(line[i]!=' ' && line[i]!='\n')
	{
		st[j]=line[i];
		i++;j++;
	}
	st[j]='\0';
	if(line[i]=='\n')
		return(2);

	j=0;i++;

	//THIRD

	while(line[i]!=' ' && line[i]!='\n')
	{
		tt[j]=line[i];
		i++;j++;
	}
	tt[j]='\0';
	if(line[i]=='\n')
		return(3);

	j=0;i++;

	//LAST

	while(line[i]!=' ' && line[i]!='\n')
	{
		lt[j]=line[i];
		i++;j++;
	}
	lt[j]='\0';
	if(line[i]=='\n')
		return(4);

	j=0;i++;


}

int checkequ(char t[])
{
	int i;
	for(i=1;t[i]!='\0';i++)
	{
		if(t[i]=='=')
		{
			return 1;
		}		
	}
	return 0;
}


void para(char st[30])
{
	int i,j,n1;
	n1=checkequ(st);
	if(n1==0)
	{
		/*for(i=0;st[i]!='\0';i++)
			{
				pn[pnptr].pname[i]=st[i];
			}
			pn[pnptr++].pname[i]='\0';*/
		strcpy(pn[pnptr++].pname,st);
		mnt[mntptr].pp++;
	}
	else
	{
			for(i=0;st[i]!='=';i++)
			{
				pn[pnptr].pname[i]=st[i];
				kpn[kpptr].kpname[i]=st[i];
			}
			pn[pnptr++].pname[i]='\0';
			kpn[kpptr].kpname[i]='\0';
			i++;
			j=0;
			while(st[i]!='\0')
			{
			
				kpn[kpptr].value[j]=st[i];
				i++;j++;

			}
				kpn[kpptr].value[j]='\0';
				kpptr++;
				mnt[mntptr].kp++;
	}
	
}

int searchpn(char t[])
{
	int i;
	for(i=1;i<pnptr;i++)
	{	
		if(strcmp(t,pn[i].pname)==0)
		{	
			//printf("%d",i);
			return i;
		}		
	}
	return 0;
	//strcpy(mdt[mdtptr].op,t);
}

void expand(int o)
{
	int a,b,c;
	a=searchpn(ft);b=searchpn(st);c=searchpn(tt);
	if(o==1)
	{
		if(a!=0)
		{
			sprintf(mdt[mdtptr].op,"(p,%d)",a);
		}
		else
		{
			strcpy(mdt[mdtptr].op,ft);
		}
	}
	else if(o==2)
	{
		if(b!=0)
		{
			sprintf(mdt[mdtptr].operand1,"(p,%d)",b);
		}
		else
		{
			strcpy(mdt[mdtptr].operand1,st);
		}	
	}
	else if(o==3)
	{
		if(c!=0)
		{
			sprintf(mdt[mdtptr].operand2,"(p,%d)",c);
		}
		else
		{
			strcpy(mdt[mdtptr].operand2,tt);
		}	
        }
}

int cal(char f[])
{
	int i;
	for(i=1;i<=mntptr;i++)
	{
		if(strcmp(mnt[i].mname,f)==0)
		{
			return i;
		}
	}
	return 0;
}

void print(char t[])
{
	if(t[0]=='(')
	{
		int p,i,j=0;
		char x[5];
		for(i=3;t[i]!=')';i++)
			x[j++]=t[i];
		x[j]='\0';
		p=atoi(x);
		fprintf(fp1,"%s ",aptab[p].aname);
	}	
	else
	{
		fprintf(fp1,"%s ",t);
	}	
}
int main()
 {
	int i,n=0,n4,d;
	fp=fopen("Macro1","r");
	fp1=fopen("op.txt","w");
	fgets(line,80,fp);
	while(strcmp(line,"END\n")!=0)
	{		
		if(strcmp(line,"MACRO\n")==0)
		{
			//mnt processing
			fgets(line,80,fp);
			n=token();
			strcpy(mnt[++mntptr].mname,ft);
			mnt[mntptr].pp=0;
			mnt[mntptr].kp=0;
			mnt[mntptr].ev=0;
			mnt[mntptr].mdtp=mdtptr;
			mnt[mntptr].kpdtp=kpptr;
			n--;
			if(n==1)
			{
				para(st);
			}
			else if(n==2)
			{
				para(st);
				para(tt);
			}
			else if(n==3)
			{
				para(st);
				para(tt);
				para(lt);
			}
			if(mnt[mntptr].kp==0)
				mnt[mntptr].kpdtp=0;
			fgets(line,80,fp);
			while(strcmp(line,"MEND\n")!=0)
			{
				
				n=token();
				
				
				if(n==1)
				{
					expand(1);	
				}
				else if(n==2)
				{
					expand(1);
					expand(2);
				}
				else if(n==3)
				{
					expand(1);
					expand(2);
					expand(3);
				}
				else
				{
					printf("\nerror:More than two opernds in operation\n");
				}
				
				
				fgets(line,80,fp);	
				mdtptr++;
			}
			strcpy(mdt[mdtptr].op,"MEND");
			mdtptr++;
		}
		fgets(line,80,fp);
			n=token(); 
		d=cal(ft);
		//macro expansion
		if(d!=0)
		{
			int j,pos;
			char *p=strtok(line," \n");
			//for printing positional parameters in  aptab
			for(i=1;i<=mnt[d].pp;i++)
			{
				strcpy(aptab[i].aname,strtok(NULL," \n"));
			}
			
			//keyword parameter
			for(j=1;j<=mnt[d].kp;j++)
			{
				int k=mnt[d].kpdtp;
				strcpy(aptab[i++].aname,kpn[k+j-1].kpname);
			}
			//keyword default parameter
			while((p=strtok(NULL," =\n"))!=NULL)
			{
				//for index of aptab : pp+kptab index - kpdtp +1
				for(i=mnt[d].kpdtp;i<kpptr;i++)
				{
					if(strcmp(p,kpn[i].kpname)==0)
					{
						j=i;
						break;
					}
				}
				pos=mnt[d].pp+j-mnt[d].kpdtp+1;
				strcpy(aptab[pos].aname,strtok(NULL, " \n"));
			}
			MEC=mnt[d].mdtp;
			while(strcmp(mdt[MEC].op,"MEND"))
			{
				fprintf(fp1,"+");
				print(mdt[MEC].op);
				print(mdt[MEC].operand1);
				print(mdt[MEC++].operand2);
				fprintf(fp1,"\n");
			}
		}
		else
		{
			fprintf(fp1,"%s",line);
		}
		//fgets(line,80,fp);
	}
	printf("\n--------------------------------");
	printf("\nParameter table\n");
	printf("\nno\tparameter name\n");
	for(i=1;i<=pnptr;i++)
	{
		printf("%d\t%s\n",i,pn[i].pname);
	}  
	printf("--------------------------------");
	printf("\n--------------------------------");
	printf("\nKeyword parameter table\n");
	printf("\nno\tkeyword parameter name\n");
	for(i=1;i<=kpptr;i++)
	{
		printf("%d\t%s\t%s\n",i,kpn[i].kpname,kpn[i].value);
	}  
	printf("--------------------------------");
	printf("\n--------------------------------");
	printf("\nMNT table\n");
	printf("\nName\t#pp\t#kp\t#EV\tMDTP\tKPDTP\tSSTP\n");
	for(i=1;i<=mntptr;i++)
	{
		printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n",mnt[i].mname,mnt[i].pp,mnt[i].kp,mnt[i].ev,mnt[i].mdtp,mnt[i].kpdtp,mnt[i].sstp);
	}  
	printf("--------------------------------");
	printf("\n--------------------------------");
	
	printf("\nMDT table\n");
	for(i=1;i<=mdtptr;i++)
	{
		printf("%d %s\t%s\t%s\n",i,mdt[i].op,mdt[i].operand1,mdt[i].operand2);
	}
	printf("\n--------------------------------");
	
	printf("\n--------------------------------");
	
	printf("\nAptab table\n");
	for(i=1;i<=mnt[mntptr].pp+mnt[mntptr].kp;i++)
	{
		printf("%d %s\n",i,aptab[i].aname);
	}
	printf("\n--------------------------------");
 return 0;
 }
