/*===============================================================
# compile method
1) gen encrypt.o : gcc encrypt.c -c
2) gen checksum.o : gcc checksum.c -c
3) gen execute file "test" : gcc main.c checksum.o encrypt.o -o test

# 此程式編譯和執行步驟 :
gcc ex1_simple_pthread.c -lpthread -o main
./main
===============================
# 此範例可以看到 :
最簡易的POSIX thread程式庫(pthread)
===============================
# 結果顯示 :
cc@ch12_thread$./main
Does too
Does not
Does not
Does too
Does not
Does too
...
===============================================================*/
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

// 執行緒A
void* does_not(void *a) // 執行緒函式必須具有(void*)回傳型別
{
    int i = 0;
    for(i = 0; i < 5; i++)
    {
        sleep(1);
        puts("Does not");
    }
    return NULL;        // 沒有東西要回傳，就使用NULL吧。
}

// 執行緒B
void* does_too(void *a) // 執行緒函式必須具有(void*)回傳型別
{
    int i = 0;
    for(i = 0; i < 5; i++)
    {
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

















