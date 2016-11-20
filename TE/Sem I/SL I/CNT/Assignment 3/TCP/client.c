#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
void main(int argc,char *argv[])
{
	char buffer[256];
	int result,n,sockfd;
	struct sockaddr_in server_addr;
	
	if(argc!=3)
	{
		printf("Enter valid arguments!!!\n");
		exit(0);
	}
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		printf("error creating socket!!!\n");
		exit(0);
	}
	bzero((char *)&server_addr,sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_port=htons(atoi(argv[2]));
	inet_pton(AF_INET,argv[1],&server_addr.sin_addr);
	
	if(connect(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr))<0)
	{
		printf("Error in connecting!!!\n");
		exit(0);
	}
	bzero(buffer,256);
	printf("Enter Expression: ");
	scanf("%s",buffer);
	n=write(sockfd,buffer,strlen(buffer));
	if(n<0)
	{
		printf("Error writing to server!!!");
		exit(0);
	}
	bzero(buffer,256);
	n=read(sockfd,buffer,256);
	if(n<0)
	{
		printf("Error on reading from socket!!!");
		exit(0);
	}
	printf("Result is %s",buffer);
}
