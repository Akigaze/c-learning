//
// Created by Akigaze on 9/19/2020.
//

#include <stdio.h>

int main() {
    /*
     * >> 右移运算
     * 逻辑右移：高位补零，低位溢出
     * 算数右移：高位补符号位，低位溢出
     */
    printf("-5 >> 1 = %d\n", (-5 >> 1));
    printf("5 >> 1 = %d\n", (5 >> 1));
}