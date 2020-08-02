/*
 * 编程: xxx.c
 * 编译: xxx.c -> xxx.obj
 * 链接: xxx.obj -> xxx.exe
 * 执行: xxx.exe
 */

/*
 * gcc 命令
 * gcc xxx.c yyy.c     编译链接生成 a.exe
 * gcc xxx.c yyy.c -o 文件名.exe   编译链接生成 文件名.exe
 * ===========================================================
 * 预编译处理，生成 main.i 文件：gcc -E main.c -o main.i
 * 编译处理，生成 main.s 文件：gcc -S main.i -o main.s
 * 汇编处理，生成 main.o 文件：gcc -c main.i -o main.o
 * 链接处理，生成 main.exe 文件：gcc main.o -o main
 * 执行main.exe：main
 */

#include <stdio.h>

int main() {
    printf("Hello World!");
}
