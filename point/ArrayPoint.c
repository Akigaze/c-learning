//
// Created by Akigaze on 10/18/2020.
//

#include <stdio.h>

void initTest2();

void arrayPoint() {
    // 声明一个二维数组
    int a[3][4];
    // 声明一个数组指针，使用 (*变量名) 的方式声明，使用指针的方式来存放数组，后面的[4] 表示每个数组的元素个数
    // 数组指针声明的变量是一个指针变量
    int (*p)[4];

    printf("a = %p \n", a);
    printf("a + 1 = %p \n", a + 1);

    p = a;
    // 数组指针实际是指向第一个元素的首地址
    printf("p = %p \n", p);
    printf("p + 1 = %p \n", p + 1);
}

// 使用数组指针的方式接收二维数组作为参数
//void update(int p[3][4]) {
void update(int (*p)[4]) {
    p[0][0] = 3;
}

void arrayPointAsParam() {
    int a[3][4] = {0};
    update(a);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("a[%d][%d] = %d\t", i, j, a[i][j]);
        }
        printf(" \n");
    }
}

//对数组取地址，实际是数组升级
void addressOfArray() {
    int a[5];
    // a 指向数组0元素首地址，所以 +1 是移动到下一个元素(int 4个字节)
    printf("a = %p \n", a);
    printf("a + 1 = %p \n", a + 1);
    // 对数组变量取地址，就是得到数组的指针，所以 +1 时是移动到下一个数组(int[5] 4*5个字节)
    printf("&a = %p \n", &a);
    printf("&a + 1 = %p \n", &a + 1);
}

void valueOfArray() {
    int a[2][5];
    // a 指向二维数组中第一个数组的首地址，所以 +1 是移动到下一个数组(int[5] 4*5个字节)
    printf("a = %p \n", a);
    printf("a + 1 = %p \n", a + 1);
    // 对数组变量取 *，实际是对数组进行降级，得到的是一个一维数组的指针，所以 +1 是移动到下一个元素(int 4个字节)
    printf("*a = %p \n", *a);
    printf("*a + 1 = %p \n", *a + 1);
}


int main() {
    printf("------------- array point ------------ \n");
    arrayPoint();
    printf("------------- array point as param ------------ \n");
    arrayPointAsParam();
    printf("------------- address of array ------------ \n");
    addressOfArray();
    printf("------------- value of array ------------ \n");
    valueOfArray();
}
