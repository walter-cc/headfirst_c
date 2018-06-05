/*===============================================================
show how to include header files
# compile method
gcc message_hider.c encrypt.c -o message_hider
===============================================================*/

#include <stdio.h>
#include "encrypt.h"

int main(void){

	char msg[80];
	
	//Encrypted
	while(fgets(msg,80,stdin))
	{
		encrypt(msg);
		printf("Encrypted to '%s'\n",msg);
	}

    return 0;
}

