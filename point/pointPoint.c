//
// Created by Akigaze on 10/11/2020.
//

#include <stdio.h>

int main() {
    // 指针变量本质上也是变量，所以也需要内存空间来保持指针的值

    int a = 100;
    // 一级指针，普通变量的指针
    int *p = &a;
    // 二级指针，指针的指针
    int **q = &p;

    printf("a = %d %d %d \n", a, *p, **q);
    printf("&a = %p %p %p \n", &a, p, *q);
    printf("&p = %p %p \n", &p, q);
}
