struct inputString {
	string inWord<>;
	int length;
};

struct outString {
	string outWord<>;
};

program LOWERTOUPPERCASEPROG {
	version LOWERTOUPPERCASEPROGVERSION {
		struct outString lowertoupper(struct inputString)=1;
	}=1;
}=463874;
