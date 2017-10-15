#include <stdio.h>

int y = 1; // global variable is stored in the "global" area of memory

int main(void){

	int x = 4; //local variable is stored in the "stack" area of memory
	printf("x is stored in %p\n",&x);
	return 0;
}

