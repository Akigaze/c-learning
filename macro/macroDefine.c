//
// Created by Akigaze on 9/20/2020.
//

#include <stdio.h>
/*
 * 定义不带参的宏，可以相对与常量，只读，只能被当前文件使用
 */
#define PI 3.1415926
/*
 * 带参宏，相对与有个短小简单的函数
 * 但其接收的参数并不是实参的值，而是直接传递实参的表达式
 */
#define M(a, b) a * b

int main() {
    printf("PI = %.4lf \n", PI);
    printf("M(1, 3) = %d \n", M(1, 3)); // 实际运行：1 * 3
    printf("M(1+2, 3) = %d \n", M(1 + 2, 3)); // 实际运行：1 + 2 * 3
}
