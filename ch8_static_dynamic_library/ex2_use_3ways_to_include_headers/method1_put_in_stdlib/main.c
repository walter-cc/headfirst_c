/*===============================================================
1) 把標頭檔存放在標準目錄裡 : /usr/local/include 
#include <encrypt.h> --> 這樣就可以把它當成是一個"標準"，可以用尖括號。

compile method : 
1) put bye.h into "/usr/local/include" : "sudo mv bye.h /usr/local/include/"
2) gen bye.o : gcc bye.c -c
3) gen execute file : gcc main.c bye.o -o main
===============================================================*/
#include <stdio.h>
#include <bye.h>	// due to bye.h is in "/usr/local/include"

int main(void){

    printf("walter\n");
    bye();
	
    return 0;
}

