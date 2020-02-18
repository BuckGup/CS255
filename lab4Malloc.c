//Sam Strecker 9/29/19

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

		char input[255];
	void mostFrequent(int *counts, char *most_freq, int *qty_most_freq){ //calling the function 

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
	
		int *ptr_counts;//declaration of pointers and malloc
		ptr_counts  = (int *)malloc(sizeof(int));
		char *ptr_mostfreq;
		ptr_mostfreq = (char *)malloc(sizeof(char)); 
		int *ptr_numcounts;
		ptr_numcounts = (int *)malloc(sizeof(int));
		int *ptr_qtymostfreq;
		ptr_qtymostfreq = (int *)malloc(sizeof(int));

		
		//the memory addresses are so different because one points to the heap while the other points to the stack which are
		//vastly different in location on the computer.
		mostFrequent(ptr_counts, ptr_mostfreq, ptr_qtymostfreq);//calling the function
		printf("Address of counts: %p, address of string: %p \n", ptr_counts, input);
		printf("The most frequent character was %c with %d occurrences.\n %d characters were entered. \n", *ptr_mostfreq, *ptr_qtymostfreq, *ptr_counts);//print stament to console
	
		free(ptr_counts);
		free(ptr_mostfreq);
		free(ptr_numcounts);
		free(ptr_qtymostfreq);
	}
