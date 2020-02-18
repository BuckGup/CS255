//Sam Strecker 11/9/19

#include <stdio.h>
#include <math.h>
	
int findPrime(int);



int main(){

	int finalCount = numPrime(1000, 1000000);
	printf("Start: 1000 End: 1000000\n");
	printf("Total number of primes:");
	printf("%d\n", finalCount);
}	


int findPrime(int numInput){

	int i = 2; //declaration of variables 
	int j = 1;
	int isPrime = 1;
	int isNotPrime = 0;

	while(i < numInput && j != 0){
		
		j = (numInput % i);
	
		i++;
	}


	if(j == 1){
		
		return isPrime;
	}

	else{
		return isNotPrime;
	}
}




int numPrime(int firstInt, int secondInt){
	
	int count = 0;
	
	for(int i = firstInt; i < secondInt; i++){

		if(findPrime(i)){
			count++;
		}	
	}
	
	return count;
} 



