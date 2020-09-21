//
// Created by Akigaze on 9/19/2020.
//


#include <stdio.h>

int main() {
    /*
     * 逗号运算符 X=(A, B, C)
     * 依次执行表达式A, B, C, 将最后一个表达式的结果赋值给X
     */
    int a = 10, b = 20;
    int c;
    c = (a += 10, b += 20, a += b);
    printf("a=%d, b=%d, c=%d", a, b, c);
}
