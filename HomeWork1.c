//Sam Strecker 10/6/19
#include <stdio.h>

	int arr[] = {1,3,3,4,5,2,2,3,5,7,0};
	int *arrPtr = arr;
	int length = *(&arr + 1) - arr;//calculates the lengh of the array


	
	
	void print_array(int *array, int length){//function to print of the array contents

		int i;
		
		for(i = 0; i < length; i++){
		printf("%d ", *(arr + i));
		}
	};

	void removeDups(int *array, int *length){
	
	int *current, *end = array + *length - 1;//declaration of local pointers to be used in loops
	
	for(current = array + 1; array < end; array++, current = array +1){
	//walks across array from start and end towards each other comparing the element it's on with the rest
	//in the array. When no duplicate is found moves to the next element in array and compares against all
	//again
		
		while(current <= end){

		    if(*current == *array){

			*current = *end--;
			*length = *length - 1;			
		      }
		    else{
			current++;
			}
	       	}
	}
	
	};


	void main(){
	//runs the methods and prints out the modified array with formatting
	removeDups(arrPtr, &length);
	printf("\n");	
	printf("Number of elements: 11, Original elements: 1 3 3 4 5 2 2 3 5 7 0 \n");
	printf("Number of unique elements: 7\n");
	printf("Elements: ");
	print_array(arrPtr, length);
	printf("\n");
	}

