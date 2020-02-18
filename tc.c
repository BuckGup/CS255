//Sam Strecker 10/28/19
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

	void displayInt(int j);
	int makeInt(char* j);
	int binToDec(double n);
	typedef union intU{

		unsigned int bits;
		int theInt;

	}intU;


	void main(){

		displayIntI(5);
		displayIntI(-9);
		makeInt("+101");
		displayIntI(5);
		makeInt("-1001");
		displayIntI(-9);
	}




	void displayIntI(int j){
	
	for(int i = 31; i >= 0; --i){ //walks backwards through the bitset printing each character as it goes
                        printf("%d", (j >> i) & 1);
                }
                printf("\n");				
	}

	int binToDec(double n){

		int decimalNumber = 0, p = 0, remainder;
		while(n != 0){

			remainder = n%10;
			n /= 10;
			decimalNumber +- remainder*pow(2, p);
			++p;

		}

	}




	int makeInt(char* j){

		intU newU;
		newU.bits = 0; //assign to 0 to make sure value isn't full 


		int p;
		for(p = 1; p < strlen(j); p++){ //
			newU.bits = ((newU.bits << 1) + ( j[p] - '0'));
			
		}


		if(p[0] == '-'){

			newU.bits = ~(newU.bits);
			newU.bits = newU.bits + 1;
		}


		
			//all garbage code below
		/*if(j[0] = "+"){ //logic to test if it is positive or negative
			j[0] = "0";						
	//for(int i = 1; i != '\0'; i++){
				binaryNumber = atoi(*j);//sets variable 
			//}	
		
			}	
		else{
			//j[0] = "0";
			for(int k = 1; i != '\0'; i++){

				if(j[k] == "0"){
					tempString[k] = "1";
				}

				else{
					tempString[k] = "0";
				}		
				binaryNumber = atoi(tempString);		
			}
		

		}

				
			
		//int finalNumber = binToDec(binaryNumber);		

		//printf("%d", finalNumber);
	*/
			
		return newU.theInt;
	}
