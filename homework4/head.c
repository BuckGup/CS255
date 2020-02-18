//Sam Strecker CS252
//11/25/2019
#include <stdio.h>
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 

#define MAX 257 
#define PORT 9857 
#define SA struct sockaddr

//The struct to be used:
typedef struct results {
int min;
int max;
int numPrime;
} results;

int setupServerSocket(int portno);//setup a server socket	

results result;
int callServer(char *host, int portno);//connect to a server
//accept connections on a server socket, return the id of the new socket

int serverSocketAccept(int serverSocket);

void writeInt(int x, int socket);//write an int over the given socket

int readInt(int socket); //read an int from the given socket

    int len; 
    struct sockaddr_in servaddr, cli;

// Function for calculating prime number between multiple nodes 
int func(int sockfd, int min, int max) 
{
 
	results result;
	result.min = min;
	result.max = max;
	result.numPrime = 0;

        write(sockfd, &result, sizeof(result));//sends the structure back to client 

	read(sockfd, &result, sizeof(result));//reads in the structure from the client

	printf("\nServer got: ");
	printf("%d", result.numPrime);

	return result.numPrime;

}  
// Driver function 
int main() 
{ 
    int connfd[3];//I currently handle 3 clients
    int sockfd;
  
    // socket create and verification
    sockfd = setupServerSocket(PORT); 
    //assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
   // Binding newly created socket to given IP and verification 
  if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
  
    bzero(&servaddr, sizeof(servaddr));
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(cli); 
  
    // Accept the data packet from client and verification 
    //connfd = accept(sockfd[0], (SA*)&cli, &len); 



     int i = 0;

     while(i < 3){ //loop used to iterate the clients

          while((connfd[i] = serverSocketAccept(sockfd)) < 0){} //wait statement to hold until 3 clients connect

        printf("server acccepted the client %d\n", i); 
  
	i++;
     }

    // Function for chatting between client and server 
   int x = func(connfd[0], 1000, 334000); 
   int y = func(connfd[1], 334000, 667000);
   int z = func(connfd[2], 667000, 1000000);
   int finalCount = x+y+z;

   printf("\n");
   printf("Total: ");
   printf("%d\n", finalCount);
    // After chatting close the socket 
    close(sockfd); 
}




int serverSocketAccept(int serverSocket){

	return accept(serverSocket, (SA*)&cli, &len);

}


 int setupServerSocket(int portno){

    int sockID;


    sockID = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockID == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 



	return sockID;
}



 
