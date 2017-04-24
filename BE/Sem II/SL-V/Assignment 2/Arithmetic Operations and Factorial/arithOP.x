struct inputInfo {
	int num_1;
	int num_2;
	int num_4;
	int option;
};

struct outputInfo {
	int resultValue;
	float floatResultValue;
};

program ARITHMETICPROGRAM {
	version ARITHMETICVERSION {
		struct outputInfo performoperation(inputInfo inpInfo)=1;
	}=1;
}=55555555;

