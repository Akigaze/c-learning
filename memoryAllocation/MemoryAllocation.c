//
// Created by Akigaze on 10/25/2020.
//

#include <stdio.h>
#include <stdlib.h>

char *getHelloByMalloc() {
    /*
     * void *malloc(int)
     * 在堆区开辟一块连续的内存空间，需要指定相应的字节数
     * 返回值是一个 void * ，一般需要强转想要的数组类型
     * 如果内配内失败，则返回NULL
     */
    char *hello = (char *) malloc(100 * sizeof(char));
    if (hello == NULL) {
        return NULL;
    }
    hello[0] = 'h';
    hello[1] = 'e';
    hello[2] = 'l';
    hello[3] = 'l';
    hello[4] = 'o';
    hello[5] = '\0'; // 需要手动指定结束符
    return hello;
}

void freeHello(char **hello) {
    /*
     * void free(void *)
     * 释放掉指定首地址的堆区空间，释放的含义是运行其他变量使用该内存空间(原有的内容应该也被清除掉了)
     * 只能释放堆区的空间，所以只能针对 malloc, calloc 和 realloc 申请的空间
     * 只能释放一次申请的所有空间，不能释放部分空间
     */
    free(*hello);
    printf("after free: %s \n", *hello);
    *hello = NULL;
}

char *getGoodMorningByCalloc() {
    /*
     * void *calloc(int nmember, int size)
     * 与 malloc 相似用于申请内存
     * 第一个参数是内存块的数量，第二个参数是每块内存块的字节数，每块内存里面的空间是连续的
     */
    char *goodMorning = (char *)calloc(3, 5);
    if (goodMorning == NULL) {
        return NULL;
    }
    goodMorning[0] =  'g';
    goodMorning[1] =  'o';
    goodMorning[2] =  'o';
    goodMorning[3] =  'd';
    goodMorning[4] =  ' ';
    goodMorning[5] =  'm';
    goodMorning[6] =  'o';
    goodMorning[7] =  'r';
    goodMorning[8] =  'n';
    goodMorning[9] =  'i';
    goodMorning[10] =  'n';
    goodMorning[11] =  'g';
    goodMorning[12] =  '\0';
    return goodMorning;
}

void testRealloc() {
    char *str = (char *)malloc(3);
    str[0] = '2';
    str[1] = '2';
    str[2] = '2';
    str[3] = '\0';
    printf("%s \n", str);
    /*
     * void *realloc(void *s, int)
     * 为指定首地址的变量重新分配堆空间，新的空间大小为指定的字节数
     * 如果原有空间后有足够的连续空间，则会使用后面的空间
     * 若原有空间后没有足够的连续空间，则会重新开辟一块完整的空间，将原有的内容拷贝到新的地址，释放原有空间
     * 若新的空间比原有的小，则释放原有空间后面的部分空间
     */
    str = (char *)realloc(str, 6);
    str[3] = '3';
    str[4] = '3';
    str[5] = '3';
    str[6] = '\0';
    printf("%s \n", str);

}

int main(int args, char *argv[]) {
    printf("------------------ 1. allocate memory by malloc -------------------------- \n");
    char *hello = getHelloByMalloc();
    printf("%s \n", hello);

    printf("------------------ 2. release memory by free -------------------------- \n");
    freeHello(&hello);
    printf("%s \n", hello);

    printf("------------------ 3. allocate memory by calloc -------------------------- \n");
    char *goodMorning = getGoodMorningByCalloc();
    printf("%s \n", goodMorning);

    printf("------------------ 4. re-allocate memory by realloc -------------------------- \n");
    testRealloc();

}
