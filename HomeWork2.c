//Sam Strecker 10/28/19
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

	int baseToDec(int base, char* value){

		int i, x = 0, a = 0; //intializing variables 
		int sizeArray = 0;
		int val = 0;
		sizeArray = strlen(value); //getting the string length and saving it as a variable
	
		for(int i = sizeArray - 1, j = 0; i >= 0; --i, ++j){//loop that checks if the character 1 is present and if so take it 
								    //to the power of j and add itself to the previous non zero value

			 if(value[i] >= '0' && value[i]<='9'){//if else statements used to convert to chars
            			val = value[i] - 48;
       			 }

        		else if(value[i] >= 'a' && value[i]<='f'){
           			 val = value[i] - 97 + 10;
			 }

        		else if(value[i]>='A' && value[i]<='F') {
        		    val = value[i] - 65 + 10;
	       		 }

			else{
				printf("Invalid Number");
				return -1;
			}

					
			x += (pow(base, j) * val);
		}
			
	}

	char* decToBase(int base, int dec){
	
		int n;
		int m = 0; 
		int i = 0;
			while(dec >= pow(base, i)){ //determines the size to malloc for by checking if the integer will fit in 
						 //the size given by binary increments
				i++;
			}
			
			char *ptr_dec;
			ptr_dec = (char *)malloc(i *(sizeof(char)));//mallocing the pointer to our string
			int remainder = 0;
			for(int j = 0, m = i - 1; j < i; j++, m--){//checks if there is a remainder and if the character is a 1 or 0 to 
								  //compute the decimal value approriately 
				if (dec % base != 0){//remainder calculation
					
					int tempVar = dec % base;
					if(tempVar >= 0 && tempVar <= 9){

					ptr_dec[m] = tempVar  + '0';
					}	
			
					else if(tempVar >= 10 && tempVar <= 16){
					
					ptr_dec[m] = tempVar - 10 + 'A';//converts with ascii table value

					}
					
					dec = dec / base;
				
				}

				else{
					ptr_dec[m] = '0';
					dec = dec / base;
				}
			}		
			return ptr_dec;
		}
                                


	int main(){

		int base = 0;
		int dec = 0;
		char value[80];
		char *myPtr;//running the functions 
		char *token1;
		char *token2;
		int num1;
		int num2;
		int num3;

		printf("This is a program that performs mathematical calculations on a variety of bases.\n");
		printf("To use enter a base (from 2 to 16). Next, enter 7 digit binary or 4 digit other base values\n");
		printf("followed by a mathematical symbol: +-*/%, followed by a second 7 digit binary or 4 digit\n"); 
		printf("other base value.\n");
		printf("\n");
		printf("Example:\n");
		printf("Base: 2\n");
		printf("Input: 0000101+0001100\n");
		printf("\n");	
		printf("To quit, type 'quit' at the 'Input: ' prompt.\n");
		printf("\n");
		

		while(strcmp(value, "quit") != 0 && strcmp(value, "end") != 0 && strcmp(value, "exit") != 0){


			printf("Base: ");	
			scanf("%d", &base);


			if(base < 2 || base > 16){
				printf("Enter a base between 2 and 16\n");
				continue;
			}

	
			printf("\n");


			
			
			printf("Input: ");


			scanf("%s%", value);

			if(strcmp(value, "quit") == 0 || strcmp(value, "end") == 0 || strcmp(value, "exit") == 0){
				continue;
			}
			

			if((strchr(value, '+')) != NULL){

				token1 = strtok(value, "+");
				token2 = strtok(NULL, "+");

				if(base == 2){
					if(strlen(token1) > 7 || strlen(token2) > 7){
						printf("Enter a number 7 digits or less\n");
						continue;
					} 

				}
				 else {
                                        if(strlen(token1) > 4 || strlen(token2) > 4){
                                                printf("Enter a number 4 digits or less\n");
						continue;
                                        }
                                }

				num1 = baseToDec(base, token1);
				num2 = baseToDec(base, token2);
				num3 = num1 + num2;
				myPtr = decToBase(base, num3);
				printf("%s + %s = ", token1, token2);		
			}
	
			else if((strchr(value, '-')) != NULL){

                		token1 = strtok(value, "-");
                		token2 = strtok(NULL, "-");
				if(base == 2){
                                        if(strlen(token1) > 7 || strlen(token2) > 7){
                                                printf("Enter a number 7 digits or less\n");
                                                continue;
                                        }

                                }
				 else {
                                        if(strlen(token1) > 4 || strlen(token2) > 4){
                                                printf("Enter a number 4 digits or less\n");
						continue;
                                        }
                                }

                		num1 = baseToDec(base, token1);
                		num2 = baseToDec(base, token2);
               	 		num3 = num1 - num2;
                		myPtr = decToBase(base, num3);
				printf("%s - %s = ", token1, token2);		
        	       	}
			

			else if((strchr(value, '*')) != NULL){

        		        token1 = strtok(value, "*");
               			token2 = strtok(NULL, "*");
				 if(base == 2){
                                        if(strlen(token1) > 7 || strlen(token2) > 7){
                                                printf("Enter a number 7 digits or less\n");
                                                continue;
                                        }
				
                                }
				 else {
                                        if(strlen(token1) > 4 || strlen(token2) > 4){
                                                printf("Enter a number 4 digits or less\n");
						continue;
                                        }
                                }

               			num1 = baseToDec(base, token1);
                		num2 = baseToDec(base, token2);
                		num3 = num1 * num2;
                		myPtr = decToBase(base, num3);
				printf("%s * %s = ", token1, token2);		
        	        }

			else if((strchr(value, '/')) != NULL){

                		token1 = strtok(value, "/");
                		token2 = strtok(NULL, "/");
				 if(base == 2){
                                        if(strlen(token1) > 7 || strlen(token2) > 7){
                                                printf("Enter a number 7 digits or less\n");
                                                continue;
                                        }

                                }
				 else {
                                        if(strlen(token1) > 4 || strlen(token2) > 4){
                                                printf("Enter a number 4 digits or less\n");
						continue; 
                                        }
                                }


				if(token2 == 0){
					printf("Divide by zero error");
				}
				else{
                			num1 = baseToDec(base, token1);
                			num2 = baseToDec(base, token2);
                			num3 = num1 / num2;
               	 			myPtr = decToBase(base, num3);
					printf("%s / %s = ", token1, token2);
				}		
			}

			else if((strchr(value, '%')) != NULL){

                		token1 = strtok(value, "%");
                		token2 = strtok(NULL, "%");
				 if(base == 2){
                                        if(strlen(token1) > 7 || strlen(token2) > 7){
                                                printf("Enter a number 7 digits or less\n");
                                                continue;
                                        }
			
                                }
				else {
					if(strlen(token1) > 4 || strlen(token2) > 4){
						printf("Enter a number 4 diigts or less\n");
					}
				}
                		num1 = baseToDec(base, token1);
               	 		num2 = baseToDec(base, token2);
                		num3 = num1 % num2;
                		myPtr = decToBase(base, num3);
				printf("%s % %s = ", token1, token2);		
			}

			else{
				printf("Enter a valid mathematical operator\n");
				continue;
			}
		
			printf("%s\n", myPtr);

		}
		free(myPtr);
		return 0;
	}


