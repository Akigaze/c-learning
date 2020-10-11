//
// Created by Akigaze on 9/26/2020.
//

#include <stdio.h>
/*
 * 关于指针和地址
 * 在32位的系统中，指针地址的范围是2^32(0x00,00,00,00 - 0xff,ff,ff,ff)，所以每个指针变量的大小是4个字节
 * 对于一个整型变量，要占用4个字节的空间
 * 则每个自己都有自己的指针地址，这些地址是连续的
 * ”该整型变量的指针“ 指的是所有地址中最小的一个
 *
 * 指针指向已经开辟内存空间的变量地址
 */
int main() {
    // 定义普通变量
    int a = 100;
    int b = 100;
    int c = 100;
    // 声明一个int变量的指针变量，变量名前加 * 标识该变量是一个指针变量
    int *p;
    // & 获取一个变量的地址，及获取变量的指针
    p = &a;
    // 对于一个指针变量，使用 *指针变量名 可以获取指针所指向的地址空间，也相当于指向该地址空间的变量
    printf("a = %d / %d \n", a, *p);
    // 输出地址要使用 %p 格式符
    printf("&a = %p / %p \n", &a, p);
    printf("&b = %p \n", &b);
    printf("&c = %p \n", &c);

    printf("----------------- size of point --------------------- \n");

    char *m;
    short *n;
    int *w;
    long *x;
    float *y;
    double *z;
    // 指针的大小为4个字节
    printf("sizeof(m) = %d \n", sizeof(m));
    printf("sizeof(n) = %d \n", sizeof(n));
    printf("sizeof(w) = %d \n", sizeof(w));
    printf("sizeof(x) = %d \n", sizeof(x));
    printf("sizeof(y) = %d \n", sizeof(y));
    printf("sizeof(z) = %d \n", sizeof(z));
}