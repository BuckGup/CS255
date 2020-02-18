//Sam Strecker
//11/25/2019
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#define MAX 257 
#define PORT 9857 
#define SA struct sockaddr

//The struct to be used:
typedef struct results {
int min;
int max;
int numPrime;
} results;


results result;//declaration of all functions to be used
int findPrime(int);	
 
int numPrime(int firstInt, int secondInt);
int findPrime(int numInput);

void writeInt(int x, int socket);//write an int over the given socket

void func(int sockfd){ 

	read(sockfd, &result, sizeof(result));//reads the structure in from the socket

	printf("Start: %d, End: %d", result.min, result.max);
	printf("\n");
	int primeNum = numPrime(result.min, result.max);//uses the structure to pass in parameters for the numPrime function I had written for a previous homework assingment

	writeInt(primeNum, sockfd);//uses the writeInt function to send over the prime number found

} 
  
int main() 
{ 
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and varification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("10.35.195.47"); // thing1 
    servaddr.sin_port = htons(PORT); 
  
    // connect the client socket to server socket 
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
        printf("connected to the server..\n"); 
  
    // function for chat 
    func(sockfd); 
  
    // close the socket 
    close(sockfd); 
}


void writeInt(int x, int socket){

	result.numPrime = x;
	write(socket, &result, sizeof(result));

}

int findPrime(int numInput){

	int i = 2; //declaration of variables 
	int j = 1;
	int isPrime = 1;
	int isNotPrime = 0;

	while(i < numInput && j != 0){
		
		j = (numInput % i);
	
		i++;
	}


	if(j == 1){
		
		return isPrime;
	}

	else{
		return isNotPrime;
	}
}


int numPrime(int firstInt, int secondInt){
	
	int count = 0;
	
	for(int i = firstInt; i < secondInt; i++){

		if(findPrime(i)){
			count++;
		}	
	}
	
	return count;
} 



