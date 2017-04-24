#include "arithOP.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/rpc.h>

int fact(int);

outputInfo *performoperation_1_svc(inputInfo *inputArg, struct svc_req *rqstp) {
	static outputInfo result;
	switch (inputArg->option) {
		case 1:
			result.resultValue = inputArg->num_1 + inputArg->num_2;
			break;
		case 2:
			result.resultValue = inputArg->num_1 - inputArg->num_2;
			break;
		case 3:
			result.resultValue = inputArg->num_1 * inputArg->num_2;
			break;
		case 4:
			result.floatResultValue = (float)inputArg->num_1 / inputArg->num_2;
			break;
		case 5:
			result.floatResultValue = fact(inputArg->num_4);
			break;
	}
	
	return (&result);
}

int fact(int n)
{
	int res=1,i;
	for(i=n;i>0;i--)
	{
		res=n*fact(n-1);
	}
	return res;
}


