//
// Created by Akigaze on 9/20/2020.
//
#include <stdio.h>

void staticLocalVariableTest(char name[]) {
    /*
     * 静态局部变量，针对所在函数，只会进行一次创建，当函数调用结束后会保留其已有的内存空间和值，在下一次调用会沿用之前的值
     */
    static int num = 10;
    num++;
    printf("%s: num = %d \n", name, num);
}

int main() {
    staticLocalVariableTest("no-1");
    staticLocalVariableTest("no-2");
    staticLocalVariableTest("no-3");
}
