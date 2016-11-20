#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
void doprocessing(int sock)
{
	char buffer[256],buffer1[256],buffer2[256],op;
	int no1,no2,result,n,i=0,j=0,k=0;
	bzero(buffer,256);
	n=read(sock,buffer,255);
	if(n<0)
	{
		printf("Error reading from socket!!!\n");
		exit(0);
	}
	while(buffer[i]!='\0')
	{
		if(isalnum(buffer[i]))
			buffer1[j++]=buffer[i];
		else
			break;
		i++;
	}
	op=buffer[i++];
	while(buffer[i]!='\0')
	{
		buffer2[k++]=buffer[i++];
	}
	no1=atoi(buffer1);
	no2=atoi(buffer2);
	switch(op)
	{
		case '+':result=no1+no2;break;
		case '-':result=no1-no2;break;
		case '*':result=no1*no2;break;
		case '/':result=no1/no2;break;
	}
	bzero(buffer,256);
	sprintf(buffer,"%d",result);
	n=write(sock,buffer,strlen(buffer));
	if(n<0)
	{
		printf("Error in writing!!\n");
		exit(0);
	}
	
}

void main(int argc,char * argv[])
{
	int sockfd,clilen,newsockfd;
	
	struct sockaddr_in server_addr,client_addr;

	if(argc!=2)
	{
		printf("Enter valid Arguments!!!\n");
		exit(0);
	}	
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		printf("Error Creating Socket!!!\n");
		exit(0);
	}
	bzero((char *)&server_addr,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(atoi(argv[1]));	
	server_addr.sin_addr.s_addr=INADDR_ANY;
	
	if(bind(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr))<0)
	{
		printf("Error on binding!!!\n");
		exit(0);
	}
	
	listen(sockfd,5);
	clilen=sizeof(client_addr);	
	while(1)
	{
		newsockfd=accept(sockfd,(struct sockaddr*)&client_addr,&clilen);
		if(newsockfd<0)
		{
			printf("Error on accept!!!");
			exit(0);
		}
		doprocessing(newsockfd);
		close(newsockfd);
	}
	
}
