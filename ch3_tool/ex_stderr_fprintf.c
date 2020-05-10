/*===============================

# 我們可以利用**gcc -E**來觀看程式碼被展開之後的樣子
gcc -E test2.c

===============================
# 新增編譯和執行步驟 :

$gcc ex_stderr_fprintf.c -o geo2json
$./geo2json < gpsdata_stderr.csv > output.json

===============================
# 此範例可以看到 : 「習」



======= 別的範例，在這裡沒用 =======

1. cc@simple_File_IO$vi fileA
   ------ 內容 --------
   it is a file 
   --------------------
2. gcc fileIO.c -o test
3. ./test fileA

cc@simple_File_IO$./test fileA

arguments numbers : 2
[0] ./test
[1] fileA

it is a file

----------
cc@simple_File_IO$./test

arguments numbers : 1
[0] ./test

usage : ./test <file>
open: Bad address

===============================
# 參考文件 :
深入淺出 C，O'Reilly
Head First C: A Brain-Friendly Guide
David Griffiths、Dawn Griffiths

*/

#include <stdio.h>      // printf()


/*
# argc : 所帶參數的數目
# argv : 一個陣列，它會分拆所帶的參數放到陣列內
*/
int main(int argc, char *argv[]) {

	int i;
    float latitude;
    float longitude;
    char info[80];
    int started = 0;
	
    printf("arguments numbers : %d\n", argc);   // argc : 所帶參數的數目

    for (i = 0; i < argc; i++) {
        printf("[%d] %s\n", i, argv[i]);    // argv : 一個陣列，它會分拆所帶的參數放到陣列內
    }
    printf("\n");

    puts("data = [");
    while(scanf("%f, %f, %79[^\n]", &latitude, &longitude, info) == 3){
        if(started)
           printf(",\n"); 
       else
           started = 1;
       
        if((longitude < -180.0) || (longitude > 180.0)){
            fprintf(stderr, "Invalid latitude : %f\n", latitude);
            return 2;
        }

        if((longitude < -180.0) || (longitude > 180.0)){
            fprintf(stderr, "Invalid latitude : %f\n", latitude);
            return 2;
        }
        printf("{latitude : %f, longitude : %f, info : '%s'}", latitude, longitude, info);    
    }
    puts("\n]");

    return 0;
}





