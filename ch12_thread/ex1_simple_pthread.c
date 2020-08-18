/*===============================
# 編譯和執行步驟 :
1. gcc -c hello.c                                   // 產生目標檔(object file) hello.o
2. gcc hello.o -o hello / gcc -o hello hello.o      // 產生執行檔(execute file) hello
3. ./hello                                          // 執行 execute file "hello"
or
1. gcc hello.c -o hello
2. ./hello

# 此範例執行步驟
$ gcc ex1_simple_pthread.c -lpthread -o main    // 使用 gcc 編譯時，要加上 -lpthread 參數
$ ./main

===============================
# 此範例可以看到 :

最簡易的POSIX thread程式庫(pthread)

===============================
# 執行結果 :

cc@ch12_thread$gcc ex1_simple_pthread.c -lpthread -o main
cc@ch12_thread$./main 
Does too
Does not
Does too
Does not
Does too
Does not
Does too
Does not
Does too
Does not


===============================
# 參考文件 :

深入淺出 C，David Griffiths、Dawn Griffiths，O'Reilly
Head First C: A Brain-Friendly Guide
David Griffiths、Dawn Griffiths

===============================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>    // 這是ptrhead程式庫的標頭檔

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

// 執行緒A，執行緒函式必須具有(void*)回傳型別
void* does_not(void *a) {

    int i = 0;

    for(i = 0; i < 5; i++) {
        sleep(1);
        puts("Does not");
    }

    return NULL;        // 沒有東西要回傳，就使用NULL吧。
}

// 執行緒B，執行緒函式必須具有(void*)回傳型別
void* does_too(void *a) {

    int i = 0;

    for(i = 0; i < 5; i++) {
        sleep(1);
        puts("Does too");
    }

    return NULL;        // 沒有東西要回傳，就使用NULL吧。
}

int main(void){

    pthread_t t0;   // pthread_t資料結構可儲存 pthead的資訊
    pthread_t t1;

    if( pthread_create(&t0, NULL, does_not, NULL) == -1 )   // does_not 為執行緒要執行的函式名稱
        error("Can't create thead t0");

    if( pthread_create(&t1, NULL, does_too, NULL) == -1 )   // does_too 為執行緒要執行的函式名稱
        error("Can't create thead t1");


    void* result;   // 從每個函式回傳的void指標將被存放在此。


    if( pthread_join(t0, &result) == -1 )   // pthread_join()函式等待執行緒結束
        error("Can't join thead t0");

    if( pthread_join(t1, &result) == -1 )   // pthread_join()函式等待執行緒結束
        error("Can't join thead t1");

    return 0;
}

















