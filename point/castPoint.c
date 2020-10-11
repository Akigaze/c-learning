//
// Created by Akigaze on 9/26/2020.
//

#include <stdio.h>

int main() {
    int a = 0x1234, b = 0x5678;
    char *p, *q;
    // %#x 格式输出十六进制数
    printf("%#x %#x \n", a, b);
    p = (char *)&a; // 指针变量的类型强转
    q = (char *)&b;
    printf("%#x(%c) %#x(%c) \n", *p, *p, *q, *q);
    // 指针变量++ 表示指向下一个相同类型的数据的地址
    p++;
    q++;
    printf("%#x %#x \n", *p, *q);
}