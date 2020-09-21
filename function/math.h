//
// Created by Akigaze on 9/20/2020.
//

#ifndef GET_START_MATH_H
#define GET_START_MATH_H

int poww(int m, int n);

/*
 * 静态函数，又称内部函数，与java的静态函数又很大不同
 * 只能在定义的.c文件中被使用，无法被其他文件调用
 */
static int innerPow(int m, int n);

#endif //GET_START_MATH_H
