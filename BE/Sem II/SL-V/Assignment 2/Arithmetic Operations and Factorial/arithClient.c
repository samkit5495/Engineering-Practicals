#include "arithOP.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/rpc.h>

void displayResult(inputInfo inpInfo, outputInfo *outInfo) {
	if (inpInfo.option == 1) {
		printf("\nResult of Addition = %d\n",outInfo->resultValue);
	} else if (inpInfo.option == 2) {
		printf("\nResult of Subtraction = %d\n",outInfo->resultValue);
	} else if (inpInfo.option == 3) {
		printf("\nResult of Multiplication = %d\n",outInfo->resultValue);
	} else if (inpInfo.option == 4) {
		printf("\nResult of Division = %0.2f\n",outInfo->floatResultValue);
	} else {
		printf("\nResult of Factorial = %0.2f\n",outInfo->floatResultValue);
	}
}

void arithmetic_program(char *host, int num_1, int num_2, int option,int num_4) {
	CLIENT *clnt;
	outputInfo *result;
	inputInfo inputArg;
	
	inputArg.num_1 = num_1;
	inputArg.num_2 = num_2;
	inputArg.num_4=num_4;
	inputArg.option = option;
	
	if((clnt = clnt_create(host, ARITHMETICPROGRAM, ARITHMETICVERSION, "tcp")) == NULL) {
		clnt_pcreateerror(host);
		exit(1);
	}
	
	if((result = performoperation_1(&inputArg, clnt)) == NULL )
		clnt_perror(clnt, "Error: Call failed.");
	else
		displayResult(inputArg, result);
	
	clnt_destroy(clnt);
}

int main(int argc, char *argv[]) {
	char *hostName;
	int firstNum, secondNum, option,fno;
	
	if(argc==4 && atoi(argv[2])==5)
	{
		fno=atoi(argv[3]);
	}
	else if(atoi(argv[2])==5)
	{
		printf("\n Usage: %s <host> <option> <factorial> \n",argv[0]);
		printf("Option: 1-Add, 2-Sub, 3-Mul, 4-Div, 5.Factorial\n");
		exit(1);
	}
	else if (argc < 5) {
		printf("\n Usage: %s <host> <option> <num_1> <num_2> \n",argv[0]);
		printf("Option: 1-Add, 2-Sub, 3-Mul, 4-Div, 5.Factorial\n");
		exit(1);
	}
	else if(argc==5)
	{
		firstNum = atoi(argv[3]);
		secondNum = atoi(argv[4]);
	}
	hostName = argv[1];
	option = atoi(argv[2]);
	
	
	arithmetic_program(hostName, firstNum, secondNum, option,fno);
	
	return 0;
}
