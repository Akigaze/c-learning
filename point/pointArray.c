//
// Created by Akigaze on 10/11/2020.
//

#include <stdio.h>

int main() {
    char ex[] = "how are you";
    printf("ex = %s \n", ex);
    // 使用指针来保存字符串
    char *arr[] = {"good", "nice", "beautiful", "outstanding"};
    // 等价与
    // char arr[4][20] = {"good", "nice", "beautiful", "outstanding"};
    for (int i = 0; i < 4; ++i) {
        printf("%s \n", arr[i]);
    }
}
