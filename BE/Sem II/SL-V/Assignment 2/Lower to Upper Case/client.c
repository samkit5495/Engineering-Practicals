#include "uppercase.h"
#include <string.h>

void toUpperProgram(char *host, char *input, int len) {
	CLIENT *clnt;
	inputString iString;
	outString *oString;
	
	iString.length = len;
	iString.inWord = (char *)malloc(len * sizeof(char));
	strcpy(iString.inWord, input);
	
	if((clnt = clnt_create(host, LOWERTOUPPERCASEPROG, LOWERTOUPPERCASEPROGVERSION, "tcp")) == NULL) {
		clnt_pcreateerror(host);
		exit(1);
	}
	
	if((oString = lowertoupper_1(&iString,clnt)) == NULL)
		clnt_perror(clnt, "Error: Call failed.");
	else
		printf("Result: %s.\n",oString->outWord);
	
	clnt_destroy(clnt);
}

int main(int argc, char *argv[]) {
	if (argc < 3) {
		exit(1);
	}
	
	toUpperProgram(argv[1], argv[2], strlen(argv[2]));
	return 0;
}
