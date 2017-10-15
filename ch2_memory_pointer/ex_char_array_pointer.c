/*
This example shows the difference between char array & pointer.
It came from page 69.

This function will shows "Segmentation fault (core dumped)".
The reason is that "JQK" is stored in constants area of memory, and the constants area is a read-only memory.


*/


#include <stdio.h>

int main(void){

	char *cards = "JQK";	//"JQK" is stored in constants area of memory, read-only.
	//char cards[] = "JQK";	
	/*
	If we unmark line 17, and mark line 16, then we can solve the segmentation fault.
	Line 16 will copy "JQK" from constants area to stack area. Therefore, we can modify the charactor now.
	*/
	char a_card = cards[2];
	cards[2] = cards[1];
	cards[1] = cards[0];
	cards[0] = cards[2];
	cards[2] = cards[1];
	cards[1] = a_card;
	puts(cards);

	return 0;
}


