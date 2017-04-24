#include "reverse.h"
#include <stdio.h>
#include <rpc/rpc.h>

int main(int argc,char **argv)
{
	int n,*r;
	CLIENT *client;
	if(argc!=3)
	{
		printf("invalid args");
		return 0;
	}
	client=clnt_create(argv[1],REVERSEPROGRAM,REVERSEVERSION,"tcp");
	if(client==NULL)
	{
		printf("connection error");
		return 0;
	}
	n=atoi(argv[2]);
	r=reverse_1(&n,client);
	printf("Reversed Integer: %d",*r);
	return 0;
}
