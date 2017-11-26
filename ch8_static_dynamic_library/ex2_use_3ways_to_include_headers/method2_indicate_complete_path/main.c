/*===============================================================
2) 把完整的路徑名稱放進我的include陳列式 :
e.g. : 
我把 encrypt.h 放到 /my_header_files/
#include "/githome/my_header_files/encrypt.h"

compile method : 
1) put hello.h into "/githome/my_header_files/hello.h"
2) gen hello.o : gcc hello.c -c
3) gen execute file : gcc main.c hello.o -o main
===============================================================*/
#include <stdio.h>
#include "../../../../my_header_files/hello.h"

int main(void){

    printf("walter\n");
    hello();

    return 0;
}

