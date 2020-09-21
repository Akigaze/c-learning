//
// Created by Akigaze on 9/20/2020.
//

#include <stdio.h>
#include "math.h"
/*
 * 函数的声明：
 * 1。 在同一个.c文件中
 *  - 被调用函数在调用位置的上方定义，则可以不用进行函数声明
 *  - 被调用函数在调用位置的下方定义，要进行函数声明(现代编译器一般还是可以编译成功的，只是会抛出警告⚠)
 * 函数声明的方式：
 * 1. 与声明变量相似，只需要在调用之前声明函数的返回值类型，函数名和参数列表即可
 * 2. 使用头文件声明函数并添加实现的.c文件，在调用的文件中引用相应的头文件即可
 */

int max(int m, int n) {
    return m > n ? m : n;
}
int min(int m, int n);

int main() {
    int a = 10, b = 20;
    printf("max of (%d, %d) is %d \n", a, b, max(a, b));
    printf("min of (%d, %d) is %d \n", a, b, min(a, b));
    printf("pow of (%d, %d) is %d \n", a, b, poww(a, b));
    // 无法调用其他文件的内部函数
//    printf("pow of (%d, %d) is %d \n", a, b, innerPow(a, b));

}

int min(int m, int n) {
    return m > n ? n : m;
}



