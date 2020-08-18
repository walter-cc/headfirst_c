/*===============================
# 編譯和執行步驟 :
1. gcc -c hello.c                                   // 產生目標檔(object file) hello.o
2. gcc hello.o -o hello / gcc -o hello hello.o      // 產生執行檔(execute file) hello
3. ./hello                                          // 執行 execute file "hello"
or
1. gcc hello.c -o hello
2. ./hello

# 此範例執行步驟
$ gcc ex2_simple_pthread_return_value.c -lpthread -o main    // 使用 gcc 編譯時，要加上 -lpthread 參數
$ ./main

===============================
# 此範例可以看到 :

當我們想要傳遞及回傳整數值給執行緒，技巧之一是使用「long」值，「long」可以被儲存在void指標裡，因為他們具有相同的尺寸。

===============================
# 執行結果 :

cc@ch12_thread$gcc ex2_simple_pthread_return_value.c -lpthread -o main
cc@ch12_thread$./main
Thread number 2
Thread number 1
Thread number 0
Thread 0 returned 1
Thread 1 returned 2
Thread 2 returned 3

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

// 執行緒
void* do_stuff(void* param) // (void* param) : 執行緒函式能夠接受單一的void指標參數
{
    long thread_no = (long)param;       //將param轉換回long

    printf("Thread number %ld\n", thread_no);

    return (void*)(thread_no +1);       // 當它被回傳時，把它強制轉型回void指標。
}

int main(void){

    pthread_t threads[20];   // pthread_t資料結構可儲存 pthead的資訊
    long t;

    for(t = 0; t < 3; t++)
        pthread_create(&threads[t], NULL, do_stuff, (void*)t); // (void*)t : 先將long變數t的值換成void指標，再傳到do_stuff裡的參數(void* param)。

    void* result;   // 從每個函式回傳的void指標將被存放在此。

    for(t = 0; t < 3; t++) {

        pthread_join(threads[t], &result);   // pthread_join()函式等待執行緒結束，reulst 存放 return (void*)(thread_no +1)

        printf("Thread %ld returned %ld\n", t, (long)result); // 使用之前，先將回傳值轉換成long。
    }

    return 0;
}

















