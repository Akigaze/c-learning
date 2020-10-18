//
// Created by Akigaze on 10/18/2020.
//
#include <stdio.h>

int main() {
    // 使用数组的形式声明初始化字符串，通过声明数组为变量开辟内存空间
    char hello[10] = "hello!!!!!";
    hello[9] = '#';
    printf("char array: %s \n", hello);

    // 使用指针的方式声明一个字符串，此时该变量并不是一个数组变量，并没有开辟内存空间
    // 它只是一个指向常量区的指针变量
    char *world = "world";
    world = "earth";
    printf("point string: %s \n", world);
    // 不支持修改常量字符串
    // world[1] = 'e';
}
