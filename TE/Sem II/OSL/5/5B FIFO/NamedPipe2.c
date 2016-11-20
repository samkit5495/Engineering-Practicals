/*
                Assigment 5 B
                FIFO
Name - Samkitkumar H. Jain
Date of Performance : 12/03/16
*/
#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h> //Unix Standard Functions
#include<fcntl.h> //File Control Unix Function

int main()
{
	char buffer[50],buffer1[50];
	char *myfifo1="myfifo1";
	char *myfifo2="myfifo2";
	FILE *fp;
	int fd1,fd2,i=0,words=1,sp=0,line=1;
    fd1=open(myfifo1,O_RDONLY);
    read(fd1,buffer,sizeof(buffer));
    unlink(myfifo1);
    printf("Contents received:\n%s\n",buffer);
    while(buffer[i]!='\0')
    {
        if(buffer[i]==' ')
        {
            words++;
            sp++;
        }
        if(buffer[i]=='\n')
        {
            line++;
            words++;
        }
        i++;
    }
    printf("Total Count of:\nWords:%d\nCharacters:%d\nLine:%d\n",words,i,line);
    fp=fopen("Op.txt","w");
    fprintf(fp,"Total Count of:\nWords:%d\nCharacters:%d\nLine:%d\n",words,i,line);
    sprintf(buffer1,"Total Count of:\nWords:%d\nCharacters:%d\nLine:%d\n",words,i,line);
    fclose(fp);
    close(fd1);
    fd2=open(myfifo2,O_WRONLY);
    write(fd2,buffer1,sizeof(buffer1));
    close(fd2);
}

