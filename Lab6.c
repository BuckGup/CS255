//Sam Strecker 10/14/19
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

	int binToDec(char* bin){

		printf("Call to binToDec given 10101 results in : ");
		int i, x = 0, a; //intializing variables 
		int sizeArray = 0;
		sizeArray = strlen(bin); //getting the string length and saving it as a variable
	
		for(int i = sizeArray - 1, j = 0; i >= 0; --i, ++j){//loop that checks if the character 1 is present and if so take it 
								    //to the power of j and add itself to the previous non zero value

			if(bin[i]== '1'){
				x = (pow(2, j))+ x;
			}
		}
			
		printf("%ld \n", x); //standard print statement	
	}

	char* decToBin(int dec){
	
		int n;
		int m = 0; 
		int i = 0;

		printf("Call to decToBin given %d results in: ", dec);
			while(dec >= pow(2, i)){ //determines the size to malloc for by checking if the integer will fit in 
						 //the size given by binary increments
				i++;
			}
			
			char *ptr_dec;
			ptr_dec = (char *)malloc(i *(sizeof(char)));//mallocing the pointer to our string
			int remainder = 0;
			for(int j = 0, m = i - 1; j < i; j++, m--){//checks if there is a remainder and if the character is a 1 or 0 to 
								  //compute the decimal value approriately 
				if (dec % 2 == 1){
					ptr_dec[m] = '1';
					dec = dec / 2;
				
				}
				else{
					ptr_dec[m] = '0';
					dec = dec / 2;
				}
			}		
	
		printf("%s\n", ptr_dec);
		return ptr_dec;
		}

	int main(){

		int dec = 11;
		char bin[6] = {'1', '0', '1', '0', '1'};
		char *myPtr;//running the functions 
		binToDec(bin);
		myPtr = decToBin(dec);
		free(myPtr);
	
		return 0;
	}

