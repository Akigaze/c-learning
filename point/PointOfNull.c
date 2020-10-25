//
// Created by Akigaze on 10/25/2020.
//
#include <stdio.h>

void testNULLPoint() {
    int *p = NULL;
    printf("point of NULL: %p \n", p);
    int *q;
    // 指针变量没有初始化的情况下，编译器会为它随机赋值
    printf("point of random: %p \n", q);
}

int main() {
    // 使用 常量指针 NULL 为指针初始化，指向 0x00000000 的内存地址，表示该指针变量并没有指向任何一个地址
    testNULLPoint();
}
