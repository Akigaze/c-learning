//
// Created by Akigaze on 9/20/2020.
//

#include <stdio.h>
/*
 * 一般全局变量，定义在方法之外，可以在当前.c文件和其他.c文件中被访问(需要声明)
 */
int globalNum = 10;

/*
 * 静态全局变量，定义在方法之外，使用static修饰，只能被当前.c文件访问到
 */
static int staticGlobalNum = 100;

int main() {

}

