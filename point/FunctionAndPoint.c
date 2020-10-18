//
// Created by Akigaze on 10/18/2020.
//
#include <stdio.h>

// 赋值传参：形参和实参的值一样，但是并不是地址不用，函数调用时是将实参等的值赋值了一份给形参
void fakeSwap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("in swap: a(%p) = %d, b(%p) = %d \n", &a, a, &b, b);
}

// 地址传参：参数接收指针类型，同时调用方法时实参也必须指针类型
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("in swap: a(%p) = %d, b(%p) = %d \n", a, *a, b, *b);
}

// *p 接收到一个地址，它就可以根据这个地址获得它存储的内容
// 但是形参和实参始终时两个不同的变量，只是它们都存了同一个地址
void passArrayPoint1(char *p) {
    // 修改指针指向的地址，因为形参和实参不是同一个指针变量，因此实参不会改变
    p = "hello ketty";
    printf("p(%p) = %s \n", p, p);
}

// 一维数组的指针要用二级指针接收
void passArrayPoint2(char **p) {
    *p = "hello ketty";
    printf("p(%p) = %s \n", p, *p);
}

int main() {
    printf("------------------ 1. copy value -------------------- \n");
    int a = 10, b = 100;
    printf("before swap: a(%p) = %d, b(%p) = %d \n", &a, a, &b, b);
    fakeSwap(a, b);
    printf("after swap: a(%p) = %d, b(%p) = %d \n", &a, a, &b, b);
    printf("------------------ 2. copy address -------------------- \n");
    int m = 10, n = 100;
    printf("before swap: m(%p) = %d, n(%p) = %d \n", &m, m, &n, n);
    // 传递地址的值
    swap(&m, &n);
    printf("after swap: m(%p) = %d, n(%p) = %d \n", &m, m, &n, n);
    printf("------------------ 3.1 copy address of array -------------------- \n");
    char *hello = "hello world";
    passArrayPoint1(hello);
    printf("after change: hello(%p) = %s \n", hello, hello);
    printf("------------------ 3.2 copy address of array -------------------- \n");
    char *hello2 = "hello world";
    // 传递字符串变量(指针)的指针，在方法中就可以修改字符串变量所指向的地址
    passArrayPoint2(&hello2);
    printf("after change: hello(%p) = %s \n", &hello2, hello2);

}
