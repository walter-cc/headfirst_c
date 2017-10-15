#include <stdio.h>

int y = 1; // global variable is stored in the "global" area of memory

int main(void){

	int x = 4; //local variable is stored in the "stack" area of memory
	int *p;

	printf("x is stored in %p\n",&x);
	printf("the size of x is %ld\n",sizeof(x));
	//in 64-bit os, the size of pointer is 8, the size is 6 in 32-bit os
	printf("the size of pointer for int is %ld\n",sizeof(p));	

	return 0;
}

