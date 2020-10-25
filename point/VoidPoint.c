//
// Created by Akigaze on 10/25/2020.
//

#include <stdio.h>

void testVoidPoint() {
    int *pi;
    void *pv;
    int a = 1;
    pv = &a, pi = &a;
    printf("point of void: %p, point of int: %p \n", pv, pi);
}

int main() {
    /*
     * void * :void 类型的指针，可以接收任何类型的指针
     * 主要用在函数的参数和返回值
     */
    testVoidPoint();
}
