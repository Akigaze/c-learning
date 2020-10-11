//
// Created by Akigaze on 9/26/2020.
//

#include <stdio.h>

int main() {
    int *p, *q, temp, a, b;
    p = &a;
    q = &b;
    printf("please input a and b: \n");
    // 将输入的值保持到指定地址
    scanf("%d %d", p, q);
    printf("p = %p, q = %p \n", p, q);

    // 此处的赋值，实际上是值拷贝，不是引用拷贝
    temp = *p;
    printf("&a = %p, &temp = %p \n", &a, &temp);
    *p = *q;
    *q = temp;

    printf("a = %d, b = %d \n", a, b);
    printf("*p = %d, *q = %d \n", *p, *q);
    printf("p = %p, q = %p \n", p, q);

}
