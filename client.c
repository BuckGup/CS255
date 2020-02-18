//Sam Strecker
//11/18/2019
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
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


 
void func(int sockfd)


{ 
    char buff[MAX] = "TGAAAATCCCTTGTCAACATCTAGGTCTTATCACATCACAAGTCCCACCTCAGACTCTGCAGGGTGATCCAACAACCTTAATAGAAACATTATTGTTAAAGGACAGCATTAGTTCACAGTCAAACAAGCAAGATTGAGAATTAACCTTGGTTTTGAACTTGAATACTTAGAGGATTGGAGATTCAACAACCCTAAAGCTTGGGGTAAAACATTGGAAATAGTTAAAAGACAAATTGCTCGGAATCACAACATTCCG";

	char buff2[MAX] = "AGTATGGATTCTCGTCCTCAGAAAGTCTGGATGACGCCGAGTCTCACTGAATCTGACATGGATTACCACAAGATCTTGACAGCAGGTCTGTCCGTTCAACAGGGGATTGTTCGGCAAAGAGTCATCCCAGTGTATCAAGTAAACAATCTTGAGGAGATTTGCCAACTTATCATACAGGCCTTTGAAGCAGGTGTTGATTTTCAAGAGAGTGCGGACAGTTTCCTTCTCATGCTTTGTCTTCATCATGCGTACCAGG";	
 
	char buff3[MAX] = "ATCTAGTGGAAAAAACATTAAGAGAACACTTGCTGCCATGCCGGAAGAGGAGACAACTGAAGCTAATGCCGGTCAGTTTCTCTCCTTTGCAAGTCTATTCCTTCCGAAATTGGTAGTAGGAGAAAAGGCTTGTCTTGAGAAGGTTCAAAGGCAAATTCAAGTACATGCAGAGCAAGGACTGATACAATATCCAACAGCTTGGCAATCAGTAGGACACATGATGGTGATTTTCCGTTTGATGCGAACAAATTTTT";


	results result;

	result.as = 0;//sets values of the struct to zero
	result.cs = 0;
	result.gs = 0;
	result.ts = 0;

        write(sockfd, buff, sizeof(buff));//sends the arrays to the serve
	write(sockfd, buff2, sizeof(buff2));
	write(sockfd, buff3, sizeof(buff3));


        read(sockfd, &result, sizeof(result));//gets the data back from the server 
	printf("A: %d, C: %d, G: %d, T: %d \n", result.as, result.cs, result.gs, result.ts);
	
	read(sockfd, &result, sizeof(result));
	printf("A: %d, C: %d, G: %d, T: %d \n", result.as, result.cs, result.gs, result.ts);

	read(sockfd, &result, sizeof(result));
	printf("A: %d, C: %d, G: %d, T: %d \n", result.as, result.cs, result.gs, result.ts);


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
