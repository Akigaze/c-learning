//
// Created by Akigaze on 10/26/2020.
//

#include <stdio.h>
#include <string.h>

void testStrlen() {
    /*
     * size_t strlen (const char *)
     * 获取字符串中字符的个数，只计算第一个 \0 之前的字符
     * 对比 sizeof 是获取一个变量所分配的字节数，数组就是其声明时的大小，指针变量就是4个字节(32位)
     */
    char hello[20] = "hello";
    printf("string length of hello: %d \n", strlen(hello));
    printf("size of hello: %d \n", sizeof(hello));

    char pencil[10] = "pen\0cil";
    printf("string pen\\0cil: %s \n", pencil);
    printf("string length of pencil: %d \n", strlen(pencil));
    printf("size of pencil: %d \n", sizeof(pencil));

    char *sunny = "sunny";
    printf("string length of sunny: %d \n", strlen(sunny));
    printf("size of sunny: %d \n", sizeof(sunny));
}

void testStrcpy() {
    char hello[16] = "hello world";
    char pencil[16] = "pencil";
    /*
     * char *strcpy (char *dest, const char *src)
     * 将src的字符串内容拷贝到dest的空间中，包括 \0
     * 拷贝时从头拷贝，并且时直接替换掉原有的字符，若目标字符串原本的字符串长度比新的长，则还是会保留后面的所有字符
     * 拷贝时必须保证目标字符串有足够的空间，不然可能会造成内存污染
     */
    strcpy(hello, pencil);
    printf("copy 'pencil' to 'hello world': %s \n", hello);
    for (int i=0; i < sizeof(hello); i++) {
        printf("[%c] - %d \n", hello[i], hello[i]);
    }
}

void testStrncpy() {
}

int main(int args, char *argv[]) {
    printf("--------------- 1. strlen --------------- \n");
    testStrlen();
    printf("--------------- 2. strcpy --------------- \n");
    testStrcpy();
    printf("--------------- 3. strncpy --------------- \n");
    testStrncpy();
}
