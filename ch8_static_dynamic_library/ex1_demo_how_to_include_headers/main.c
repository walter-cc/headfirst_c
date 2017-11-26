/*===============================================================
show how to include header files
# compile method
1) gen encrypt.o : gcc encrypt.c -c
2) gen checksum.o : gcc checksum.c -c
3) gen execute file "test" : gcc main.c checksum.o encrypt.o -o test
===============================================================*/

#include <stdio.h>
#include "encrypt.h"
#include "checksum.h"

int main(void){

    char s[] = "i am walter";
	
	//Encrypted
	encrypt(s);
	printf("Encrypted to '%s'\n",s);
	printf("checksum is %i\n",checksum(s));
	
	//Dencrypted
	encrypt(s);
	printf("Dencrypted to '%s'\n",s);
	printf("checksum is %i\n",checksum(s));
	
    return 0;
}

