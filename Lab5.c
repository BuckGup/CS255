//Sam Strecker 10/7/19
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	struct phoneBook {
		//declaring variables for our structure
		char firstName[32];
		char lastName[32];
		char phoneNumber[8];
	};
	

	int  main(){
	
		struct phoneBook *per_ptr;
		int size;
		
		printf("Number of entries in phonebook: ");
		scanf("%d", &size);//the size of entries in the phoneBook
		
		per_ptr = (struct phoneBook*) malloc(size * sizeof(struct phoneBook));
		//size is calculated by the size of the char for firstName and lastName 
		//plus phoneNumber. This equals 32+32+8 which is 72
			

		printf("\nSize of phonebook struct: %d", sizeof(struct phoneBook));


	
		for(int i = 0; i < size; i++){ //for loop which updates the values in the phoneBook entry
		printf("\nProvide first_name last_name telephone_number: ");
		scanf("%s%s%s", (per_ptr + i)->firstName, (per_ptr + i)-> lastName, (per_ptr +i)-> phoneNumber);
		
		}
		

		for(int i = 0; i <size; i++){//prints out the values of all entries in the phoneBook using arra notation
		printf("%s %s can be reached at: %s\n", per_ptr[i].firstName, per_ptr[i].lastName, per_ptr[i].phoneNumber);
	
		}

		free(per_ptr);
 
return 0;
}
