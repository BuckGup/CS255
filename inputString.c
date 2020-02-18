//Sam Strecker 9/23/19
#include <stdio.h>
	
	int main(){
	

	char input[80], output[80]; //intialize array for input and output
	printf("Enter a string: "); //prompt for user
	scanf("%s", input);

	int vowelCheck(char ch)//helper function to check if character inputed is character
		{if (ch == 'a' || ch == 'i' || ch == 'e' || ch == 'o' || ch == 'u')
		 return 1;
		else
		 return 0;
	}



	int c, arrayIndexFill = 0;

	for(c=0; input[c] != '\0'; c++){ //for loop that walks across array until end
		if(vowelCheck(input[c]) == 0){
			output[arrayIndexFill] = input[c]; //if char is not a vowel it is input into output
			arrayIndexFill++;

		}	
	

	}
	
	printf("%s\n", output);//prints the array to screen 

	return 0;
}
	

	
