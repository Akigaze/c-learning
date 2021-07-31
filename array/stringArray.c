//
// Created by Akigaze on 9/20/2020.
//
#include <stdio.h>

int main() {
    char a[32] = "";
    printf("sizeof(a) = %llu \n", sizeof(a));

    char b[5] = "12345";
    printf("b = %s \n", b);
    printf("sizeof(b) = %llu \n", sizeof(b));
    for (int i = 0; i < sizeof(b); i++) {
        printf("b[%d] = %c \n", i, b[i]);
    }
    printf("b[5] = %c \n", b[5]);
    printf("b[6] = %c \n", b[6]);
    printf("----------------------------------- \n");

    char input[10] = "100";
    // scanf() 接收输入的内容，转换为指定的格式(%s)，并保存到指定变量中
    scanf("%s", input);
    printf(input);

}
