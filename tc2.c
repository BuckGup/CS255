//Sam Strecker 11/4/19
#include <stdio.h>
#include <string.h>
#include <math.h>


	void displayFloat(float f);//declaration of functions
	float makeFloat(char* f);
	int binToDec(char* bin);
	typedef union floatU {//creation of union
		unsigned int bits;
		float theFloat;
	}floatU;




	int main() { //main running test scenrios 
		displayFloat(-5.8125);
		displayFloat(+0.75);
		displayFloat(-1.5);
		float result = makeFloat("-101.1101");
		printf("%f\n", result);
		displayFloat(result);
	}



	void displayFloat(float f){
		
		floatU newFloatU;//creating the space with the union
		newFloatU.theFloat = f;

		
		for(int i = 31; i >= 0; --i){ //walks backwards through the bitset printing each character as it goes

			if(i == 30 || i == 22){
				printf(" ");
			}
				
			printf("%d", (newFloatU.bits >> i) & 1);
			
                 }
                 printf("\n");
		
          }


	float makeFloat(char* f){
		
		char tempArray[90];//declaration of variables	
		strcpy(tempArray, f);
		char* wholeNum;
		char* fraction;
		char* tempPtr;
		int decNum;
		float fracNum;
		if((strchr(tempArray, '.')) != NULL) {//spits the string at the decimal point and saves it in two new strings
			wholeNum = strtok(tempArray, ".");
			fraction = strtok(NULL, ".");
		}

	
		if((strchr(wholeNum, '-')) != NULL){//determines if it was negative or positive 

			wholeNum[0] = '0';
			decNum = binToDec(wholeNum);//uses my helper function to convert the string to decimal
			printf("-");
		}


		

		if((strchr(wholeNum, '+')) != NULL){//determines if it was negative or positive

			wholeNum[0] = '0';
			decNum = binToDec(wholeNum);
			printf("+");	
		}

			for(int i = 0; i < strlen(fraction); i++){//calculates the fractional portion of the numher
				
				if(fraction[i] == '1'){
					fracNum = (1/(pow(2, i+1))) + fracNum;//divdes by 1 to get the negative exponent 
				}

			}	


			
			float finalNum = fracNum + decNum;	
	
		return finalNum;

		}	

	


		
	int binToDec(char* bin){

		int i, a; //intializing variables 
		int x = 0;
		int sizeArray = 0;
		sizeArray = strlen(bin); //getting the string length and saving it as a variable
	
		for(int i = sizeArray - 1, j = 0; i >= 0; --i, ++j){//loop that checks if the character 1 is present and if so take it 
								    //to the power of j and add itself to the previous non zero value

			if(bin[i]== '1'){
				x = (pow(2, j))+ x;
			}
		}
	
		return x;		
	}

	

		
