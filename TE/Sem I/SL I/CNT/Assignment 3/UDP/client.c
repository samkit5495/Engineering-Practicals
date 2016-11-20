/* UDP Client */
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

int main(int argc, char *argv[])
{
    
    struct sockaddr_in serv_addr;
    int sockfd, portno, n,slen=sizeof(serv_addr);
    char buffer[256];
    char buffer1[256],buffer2[256];
    int no1,no2,result;

    /* Create a socket point */
    sockfd=socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) 
    {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
  
    inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr);
    serv_addr.sin_port = htons(5002);

    /* Now ask for a message from the user, this message
     will be read by server */
    printf("Please enter expression: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
        
    /* Send message to the server */
    n = sendto(sockfd, buffer, strlen(buffer) , 0 , (struct sockaddr *) &serv_addr, slen);
    if (n < 0) 
    {
         perror("ERROR writing to socket");
         exit(1);
    }
    /* Now read server response */
    bzero(buffer,256);
    n = recvfrom(sockfd, buffer, 255, 0, (struct sockaddr *) &serv_addr, &slen);
    if (n < 0) 
    {
         perror("ERROR reading from socket");
         exit(1);
    }
	result=atoi(buffer);
    printf("Result is: %d\n",result);
    return 0;
}

