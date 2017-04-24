#include "uppercase.h"
#include <ctype.h>

void convert(char *s){
	while(*s != '\0'){
		*s = toupper(*s);
		s++;
	}
}

outString *lowertoupper_1_svc(inputString *inArg, struct svc_req *rqstp) {
	static outString result;
	// char *temp = (char *)malloc(inArg->length * sizeof(char));
	result.outWord = (char *)malloc(inArg->length * sizeof(char));
	strcpy(result.outWord,inArg->inWord);
	// result.outWord = temp;
	convert(result.outWord);
	return &result;
}
