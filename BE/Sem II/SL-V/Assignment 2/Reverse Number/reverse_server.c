#include "reverse.h"

int rev=0;

int * reverse_1_svc(int *input, struct svc_req * svc)
{	
	int t=*input;
	while(t)
	{
		rev=(rev*10)+(t%10);
		t=t/10;
	}
	return &rev;
}
