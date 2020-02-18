//Sam Strecker 10/21/19
#include <stdio.h>

	typedef unsigned short bitSet;
	
	bitSet makeBitSet(); // Create a new bitset
	displayBitSet(bitSet* bs); // Displays the 16 bits of the bitset to the screen
	void setBit(bitSet* bs, int index); // Sets bit 'index' of the bitset to 1
	void clearBit(bitSet* bs, int index); // Sets bit 'index' of the bitset to 0
	int bitValue(bitSet* bs, int index); // Returns the value of the bit at 'index'


	int main() {	//main method to run prpgram

		bitSet bs = makeBitSet();
		printf("%d: ", bs);
		displayBitSet(&bs);
		setBit(&bs, 5);
		printf("%d: ", bs);
		displayBitSet(&bs);
		setBit(&bs, 3);
		printf("%d: ", bs);
		displayBitSet(&bs);
		setBit(&bs, 2);
		printf("%d: ", bs);
		displayBitSet(&bs);
		clearBit(&bs, 3);
		printf("%d: ", bs);
		displayBitSet(&bs);
		printf("%d\n", bitValue(&bs, 1));
		printf("%d\n", bitValue(&bs, 2));

	}


	bitSet makeBitSet(){//fills the bitset with 0 wih our "free" function 
		return 0;
	}
		

	displayBitSet(bitSet* bs){
		
		for(int i = 15; i >= 0; --i){ //walks backwards through the bitset printing each character as it goes
			printf("%d", (*bs >> i) & 1);
		}
		printf("\n");	
	}
	
	void setBit(bitSet* bs, int index){

		*bs |= 1 << index;//walks to the element at index and sets it to 1
	}



	void clearBit(bitSet* bs, int index){

		*bs &= ~(1 << index);//walks to element at index and sets it to zero
	}


	int bitValue(bitSet* bs, int index){

		return (*bs >> index) & 1; //returns the 0 or 1 value at index

	}




