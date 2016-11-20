/*
				Assigment 1 C
				Binary Search using execve
Name - Samkitkumar H. Jain
Date of Performance : 02/01/16
*/
#include<stdio.h>

int main(int argc,char *argv[],char *en[])
{
    int arr[20],i,n=argc-1,s=atoi(argv[n]);
    int f,l,m;
    for(i=0;i<n;i++)
        arr[i]=atoi(argv[i]);
    f=0;
    l=n-1;
    while(f<=l)
    {
        m=(f+l)/2;
        if(arr[m]==s)
        {
            printf("%d found at location %d.\n",s,m+1);
            break;
        }
        else if(arr[m]>s)
            l=m-1;
        else
            f=m+1;
    }
    if(f>l)
        printf("\n%d is not found!\n",s);
    return 0;
}
