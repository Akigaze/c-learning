//
// Created by Akigaze on 10/11/2020.
//

#include <stdio.h>

void exampleOfArrayPoint() {
    /*
     * 在C语言中，数组的名称就是数组的首地址，即0元素的地址，是一个常量
     * 数组名称可以理解成数组中0元素的指针常量
     */
    int a[4] = {1, 2, 3, 4};
    /*
     * 数组名称可以直接赋值给指针变量
     * 数组是引用类型，因此变量名代表的其实是地址，所以可以直接赋值给指针变量
     */
    int *p = a;
    printf("*a = %d, *p = %d \n ", *a, *p);
    printf("a[1] = %d, p[1] = %d \n ", a[1], p[1]);
    /*
     * 对数组变量进行加减运算的结果，就是回去对应下表的元素的地址
     * 这里与普通变量的指针运算有些不同，不是移动到下一个字节的地址，而是移动到下一个元素的地址
     */
    printf("*(a + 2) = %d, *(p + 2) = %d \n ", *(a + 2), *(p + 2));
}

void plusAndMinusBetweenPointAndNumber() {
    // 指针变量加减一个整数, 就是移动到与类型大小相同的字节数
    int a = 100;
    int *p = &a;
    // int 类型为 4 个字节
    printf("p = %p, p+1 = %p, p+2 = %p, p+3 = %p \n", p, p + 1, p + 2, p + 3);
    printf("*(p) = %d, *(p+1) = %d, *(p+2) = %d, *(p+3) = %d \n", *(p), *(p + 1), *(p + 2), *(p + 3));

    char c[5] = "hello";
    char *o = c;
    // char 类型 1 个字节
    printf("o = %p, o+1 = %p, o+2 = %p, o+3 = %p \n", o, o + 1, o + 2, o + 3);
    printf("*(p) = %c, *(p+1) = %c, *(p+2) = %c, *(p+3) = %c \n", *(o), *(o + 1), *(o + 2), *(o + 3));

    int b[4] = {0, 1, 2, 3};
    int *q = b;
    // int数组, int 元素每个 4 个字节
    printf("q = %p, q+1 = %p, q+2 = %p, q+3 = %p \n", q, q + 1, q + 2, q + 3);
}

void pointCompare() {
    char h[5] = "hello";

    char *p = &h[2];
    char *q = &h[3];

    printf("p = %p, q = %p \n", p, q);
    if (p > q) {
        printf("p > q \n");
    } else if (p < q) {
        printf("p < q \n");
    } else {
        printf("p = q \n");
    }
}

void pointMinus() {
    int a[5] = {0, 1, 2, 3, 4};
    int *p = &a[0];
    int *q = &a[3];

    printf("q(&a[0]) - p(&a[3]) = %d", q - p);
}

int main() {
    exampleOfArrayPoint();

    printf("--------------------------------------- \n");
    /*
     * 指针的运算：
     * 1. 指针变量加减一个整数：就是移动到与类型大小相同的字节数
     * 2. 指针的比较：两个同类型且指向用一个数组的元素才能进行大小比较，地址大的就大
     * 3. 指针变量间的减法：两个同类型且指向用一个数组的元素才能进行减法运算，结果是两个指针变量之间相差的元素个数，即从其中一个到另一个需要移动的元素个数
     * 4. 指针相互赋值：必须是相同类型的指针
     */
    plusAndMinusBetweenPointAndNumber();
    printf("--------------------------------------- \n");
    pointCompare();
    printf("--------------------------------------- \n");
    pointMinus();
}
