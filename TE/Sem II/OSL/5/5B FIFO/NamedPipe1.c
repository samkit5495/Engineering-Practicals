/*
                Assigment 5 B
                FIFO
Name - Samkitkumar H. Jain
Date of Performance : 12/03/16

FIFOs: Full duplex communication between two independent processes. First process
accepts sentences and writes on one pipe to be read by second process and second
process counts number of characters, number of words and number of lines in accepted
sentences, writes this output in a text file and writes the contents of the file on second
pipe to be read by first process and displays on standard output.

*/

/*
Modes
Read - 4
Write - 2
Execute - 1
Add them to get digit

0 user	group other
0 r+w+e r+w+e r+w+e
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h> //Unix Standard Functions
#include<fcntl.h> //File Control Unix Function

int main()
{
	char str[50]="Hello\nMy name is samkit jain.",buffer[50];
	char *myfifo1="myfifo1";
	char *myfifo2="myfifo2";
	int fd1,fd2,words;
	mkfifo(myfifo1,0666);
	mkfifo(myfifo2,0777);
    fd1=open(myfifo1,O_WRONLY);
    write(fd1,str,sizeof(str));
    close(fd1);
    unlink(myfifo1);
    fd2=open(myfifo2,O_RDONLY);
    read(fd2,buffer,sizeof(buffer));
    printf("Result:\n%s",buffer);
    close(fd2);
}
