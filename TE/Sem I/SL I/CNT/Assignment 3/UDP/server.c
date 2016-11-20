/* UDP Server */
/*
Name - Samkit H Jain
Roll No. 20
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/types.h> 
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<unistd.h>

void doprocessing (int sockfd,struct sockaddr_in cli_addr,int slen)
{
    int n,i,j,k;
    char buffer[256],op;
    char buffer1[256],buffer2[256];
    int no1,no2,result;

    bzero(buffer,256);
    
    n = recvfrom(sockfd,buffer, 255, 0, (struct sockaddr *) &cli_addr, &slen);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        exit(1);
    }
    i=j=k=0;
    while(buffer[i]!='\0')
    {
    	if(isalnum(buffer[i]))
		{
			buffer1[j]=buffer[i];j++;
		}
     	else
      		break;   
     	i++;
    }
    op=buffer[i];i++;
    while(buffer[i]!='\0')
    {
	    buffer2[k]=buffer[i];k++;
	    i++;
    }
    no1=atoi(buffer1);
    no2=atoi(buffer2);
   
    printf("The expression is: %s",buffer);
    
    switch(op)
    {
     case '+':result=no1+no2;
              break;
     case '-':result=no1-no2;
              break;
     case '*':result=no1*no2;
              break;
     case '/':result=no1/no2;
              break;
     default:result=9999;
             break;
    }
   
    sprintf(buffer,"%d",result);
    n=sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*) &cli_addr, slen);
    if (n < 0) 
    {
        perror("ERROR writing to socket");
        exit(1);
    }
}

int main( int argc, char *argv[] )
{
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int  n,pid;

    /* First call to socket() function */
    sockfd=socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) 
    {
        perror("ERROR opening socket");
        exit(1);
    }
    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 5002;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
 
    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
                          sizeof(serv_addr)) < 0)
    {
         perror("ERROR on binding");
         exit(1);
    }
    /*Now start listening for the clients, here 
      process will go in sleep mode and will wait 
      for the incoming connection */
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    while (1) 
    {
        /* This is the client process */
        doprocessing(sockfd,cli_addr,clilen);
    } /* end of while */
    close(sockfd);            
    exit(0);
}
