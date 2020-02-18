//Sam Strecker CS252
//11/18/2019
#include <stdio.h>
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 

#define MAX 257 
#define PORT 9457 
#define SA struct sockaddr

//The struct to be used:
typedef struct results {
unsigned short as;
unsigned short cs;
unsigned short gs;
unsigned short ts;
} results;


 
  
// Function designed for chat between client and server. 
void func(int sockfd) 
{ 
    char buff[MAX];
    char buff2[MAX];
    char buff3[MAX];
 
        read(sockfd, buff, sizeof(buff)); //reads in the arrays from the client
	read(sockfd, buff2, sizeof(buff2));
	read(sockfd, buff3, sizeof(buff3));

	//printf("%s\n", buff2);

	//printf("%s\n", buff3);

	results result;

	result.as = 0;//sets all the variables in the struct to zero
	result.cs = 0;
	result.gs = 0;
	result.ts = 0;	

	for(int i = 0; i <= MAX; i++){//loop to count how many times the letters appear

		if(buff[i] == 'A'){
			result.as = result.as + 1;
		}
		if(buff[i] == 'C'){
			result.cs = result.cs + 1;
		}
		if(buff[i] == 'G'){
			result.gs = result.gs + 1;
		}
		if(buff[i] == 'T'){
			result.ts = result.ts + 1;
		}

	}


        write(sockfd, &result, sizeof(result));//sends the structure back to client 

        result.as = 0;
        result.cs = 0;
        result.gs = 0;
        result.ts = 0;

         for(int i = 0; i <= MAX; i++){

                 if(buff2[i] == 'A'){
                         result.as = result.as + 1;
                 }
                 if(buff2[i] == 'C'){
                          result.cs = result.cs + 1;                 }
                  if(buff2[i] == 'G'){
                          result.gs = result.gs + 1;
                  }
                  if(buff2[i] == 'T'){
                          result.ts = result.ts + 1;
                  }
 
         }

	write(sockfd, &result, sizeof(result));

        	result.as = 0;
        	result.cs = 0;
       		result.gs = 0;
       	 	result.ts = 0;


         for(int i = 0; i <= MAX; i++){

                 if(buff3[i] == 'A'){
                         result.as = result.as + 1;
                 }
                 if(buff3[i] == 'C'){
                          result.cs = result.cs + 1;                 }
                  if(buff3[i] == 'G'){
                          result.gs = result.gs + 1;
                  }
                  if(buff3[i] == 'T'){
                          result.ts = result.ts + 1;
                  }
 
         }
	write(sockfd, &result, sizeof(result));

} 
  
// Driver function 
int main() 
{ 
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and verification 
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
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(cli); 
  
    // Accept the data packet from client and verification 
    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server acccept the client...\n"); 
  
    // Function for chatting between client and server 
    func(connfd); 
  
    // After chatting close the socket 
    close(sockfd); 
} 
