/*===============================================================
3) 告訴編譯器要去哪裡找到那些標頭檔
e.g. :
gcc -I/my_header_files main.c checksum.o encrypt.o -o test
-I : 告訴gcc編譯器要去哪裡找標頭檔

compile method :
1) put hello.h into "/githome/my_header_files/hello.h"
2) gen hello.o : gcc -I/home/cc/githome/my_header_files/ hello.c -c
3) gen execute file : gcc -I/home/cc/githome/my_header_files/ main.c hello.o -o test
===============================================================*/
#include <stdio.h>
#include "hello.h"

int main(void){

    printf("walter\n");
    hello();

    return 0;
}

