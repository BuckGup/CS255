//Sam Strecker 9/29/19

#include <stdio.h>
#include <string.h>

	void mostFrequent(int *counts, char *most_freq, int *qty_most_freq){ //calling the function 

		char input[255];//intializing the variables
		char result;
		int count[255] = {0};
			
		int i, max, index;
	
		printf("Enter a string of characters: "); //prompt to get input from users
		scanf("%s", input);
	
		for(i = 0; input[i] !=0; i++){//copying array of non zero elements
			++count[input[i]];//advances both arrays
		}

		max = count[0];
		index = 0;
		for(i = 0; input[i] != 0; i++){//compares values in array to previous max to update max and eventually
					       //set the char that occurs max in the array
			if(count[input[i]] > max)
			{ 
				max = count[input[i]];
				index = i;

			}
		}
		*qty_most_freq = max;//updates pointer values
		*most_freq = input[index];//char used most
		*counts = strlen(input);//num of characters in array

	}

	void main(){

		int counts = 0;//intialzing variables
		char most_freq = '0';
		int num_counts = 0;
		int qty_most_freq;	


		mostFrequent(&counts, &most_freq, &qty_most_freq);//calling the function
		printf("The most frequent character was %c with %d occurrences.\n %d characters were entered. \n", most_freq, qty_most_freq, counts);//print stament to console
	
	}
