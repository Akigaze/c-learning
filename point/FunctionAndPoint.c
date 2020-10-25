//
// Created by Akigaze on 10/18/2020.
//
#include <stdio.h>

// 赋值传参：形参和实参的值一样，但是并不是地址不用，函数调用时是将实参等的值赋值了一份给形参
void fakeSwap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("in swap: a(%p) = %d, b(%p) = %d \n", &a, a, &b, b);
}

// 地址传参：参数接收指针类型，同时调用方法时实参也必须指针类型
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("in swap: a(%p) = %d, b(%p) = %d \n", a, *a, b, *b);
}

// *p 接收到一个地址，它就可以根据这个地址获得它存储的内容
// 但是形参和实参始终时两个不同的变量，只是它们都存了同一个地址
void passArrayPoint1(char *p) {
    // 修改指针指向的地址，因为形参和实参不是同一个指针变量，因此实参不会改变
    p = "hello ketty";
    printf("p(%p) = %s \n", p, p);
}

// 一维数组的指针要用二级指针接收
void passArrayPoint2(char **p) {
    *p = "hello ketty";
    printf("p(%p) = %s \n", p, *p);
}

// 可以通过指针或者数组作为形参接收数组类型的参数
//void testTestOneDimArray(int arr[]) {
void testTestOneDimArray(int *arr) {
    printf("arr[1] = %d \n", arr[1]);
    printf("*(arr + 3) = %d \n", *(arr + 3));
}

void testOneDimArray() {
    int a[5] = {1, 2, 3, 5, 8};
    testTestOneDimArray(a);
}

void testTestTwoDimArray(int (*arr)[4]) {
    // arr[x][y] <==> *(*(arr + x) + y)
    printf("arr[0][2] = %d \n", arr[0][2]);
    printf("*(*(arr + 1) + 3) = %d \n", *(*(arr + 1) + 3));
}

void testTwoDimArray() {
    int a[2][4] = {0, 1, 1, 2, 3, 5, 8, 13};
    testTestTwoDimArray(a);
}

// 使用二级指针接收指针数组作为参数
void testTestPointArray(char **p) {
    for (int i = 0; i < 3; i++) {
        printf("p[%d] = %s \n", i, p[i]);
    }
}

void testPointArray() {
    char *signs[3] = {"good", "every", "moon"};
    testTestPointArray(signs);
}

char *testTestPointFunction() {
//    1. 使用str[n] 的形式定义的数组，会在函数执行结束后释放其内存空间，所以返回的地址空间所存的内容是空的 (null)
//    char str[30] = "hello hahahahahahaha";
//    2. 将数组声明成静态变量，这样就会分配静态代码区的空间，不会在函数结束后被清除
//    static char str[30] = "hello hahahahahahaha";
    // 3. 直接对指针变量赋值一个字符串，此时该字符串是存放在常量区，所以也不会在函数结束后被清除
    char *str = "hello hahahahahahaha";
    return str;
}

void testPointFunction() {
    char *str;
    str = testTestPointFunction();
    printf("point function return: %s \n", str);
}

int add(int a, int b) {
    return a + b;
}

int minus(int a, int b) {
    return a - b;
}


int mul(int a, int b) {
    return a * b;
}


int dive(int a, int b) {
    return a / b;
}

void testPointOfFunction() {
    int (*fun)(int, int);
    fun = add;
    printf("fun(10, 20) = %d \n", fun(10, 20));
}

void testArrayOfPointOfFunction() {
    int (*funs[4])(int, int) = {add, minus, mul, dive};
    for (int i = 0; i < 4; i++) {
        printf("funs[%d](10,20) = %d \n", i, funs[i](10, 20));
    }
}

int testTestCallBackFunction(int (*fun)(int, int), int p1, int p2) {
    return fun(p1, p2);
}

void testCallBackFunction() {
    int result = testTestCallBackFunction(add, 2, 3);
    printf("add(2, 3) = %d \n", result);

    result = testTestCallBackFunction(minus, 2, 3);
    printf("minus(2, 3) = %d \n", result);

    result = testTestCallBackFunction(mul, 2, 3);
    printf("mul(2, 3) = %d \n", result);

    result = testTestCallBackFunction(dive, 2, 3);
    printf("dive(2, 3) = %d \n", result);
}

int main() {
    printf("------------------ 1. copy value -------------------- \n");
    int a = 10, b = 100;
    printf("before swap: a(%p) = %d, b(%p) = %d \n", &a, a, &b, b);
    fakeSwap(a, b);
    printf("after swap: a(%p) = %d, b(%p) = %d \n", &a, a, &b, b);
    printf("------------------ 2. copy address -------------------- \n");
    int m = 10, n = 100;
    printf("before swap: m(%p) = %d, n(%p) = %d \n", &m, m, &n, n);
    // 传递地址的值
    swap(&m, &n);
    printf("after swap: m(%p) = %d, n(%p) = %d \n", &m, m, &n, n);
    printf("------------------ 3.1 copy address of array -------------------- \n");
    char *hello = "hello world";
    passArrayPoint1(hello);
    printf("after change: hello(%p) = %s \n", hello, hello);
    printf("------------------ 3.2 copy address of array -------------------- \n");
    char *hello2 = "hello world";
    // 传递字符串变量(指针)的指针，在方法中就可以修改字符串变量所指向的地址
    passArrayPoint2(&hello2);
    printf("after change: hello(%p) = %s \n", &hello2, hello2);

    printf("------------------ 4.1 one dim array as param -------------------- \n");
    testOneDimArray();

    printf("------------------ 4.2 two dim array as param -------------------- \n");
    testTwoDimArray();

    printf("------------------ 4.3 point array as param -------------------- \n");
    testPointArray();

    printf("------------------ 5 point function -------------------- \n");
    /*
     * 指针函数：返回值是指针类型的函数
     * 定义是只需要在函数名前加 *
     */
    testPointFunction();

    printf("------------------ 6.1 point of function -------------------- \n");
    /*
     * 函数指针：就是一个指向函数的指针，保存函数的地址
     * 程序运行时会将函数加载到内存的代码段中，所以函数也是有地址范围的
     * C 语言中，函数的名称，就是指向函数首地址的一个指针常量
     * 函数指针的定义：返回值 (*指针名)(参数类型列表) int (*p)(int, int)
     * 使用时将定义好的函数名赋值给函数指针，然后该函数指针就可以等同于原函数使用
     */
    testPointOfFunction();
    printf("------------------ 6.1 array of (point of function) -------------------- \n");
    /*
     * 函数指针的数组：就是保存函数指针的数组
     * 定义方式：返回值 (*指针名[n])(参数类型列表) int (*p[4])(int, int)
     */
    testArrayOfPointOfFunction();

    printf("------------------ 6.1 point of function as param -------------------- \n");
    // 将函数作为参数，需要用函数指针作为形参，这种作为参数的函数又称回调函数
    testCallBackFunction();
}
