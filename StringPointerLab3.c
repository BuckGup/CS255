//Sam Strecker 9/23/19

#include <stdio.h>

	int main(){


//intilizing varibles
	int a;
	char b;
	double c;
//intilizing pointers
	int *ap;
	char *bp;
	double *cp;
//assigning varibles 	
	a = 7;
	b = 'z';
	c = 2.2;
//storing the pointers to the variables 
	ap = &a;
	bp = &b;
	cp = &c;
//prints out the size of the data type
	printf("%ld\n", sizeof(a));
	printf("%ld\n", sizeof(b));
	printf("%ld\n", sizeof(c));
//prints the address of each variables
	printf("%p\n", a);
	printf("%p\n", b);
	printf("%p\n", c);
//prints the value of the pointer
	printf("%p\n", cp);
	printf("%p\n", bp);
	printf("%p\n", ap);
//prints what the pointer points to
	printf("%d\n", *ap);
	printf("%d\n", *bp);
	printf("%d\n", *cp);

return 0;
}
