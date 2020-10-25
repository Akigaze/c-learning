//
// Created by Akigaze on 10/25/2020.
//

#include <stdio.h>

int main(int args, char *argv[]) {
    // args: 记录参数的个数
    printf("number of parameter: args = %d \n", args);
    for (int i = 0; i < args; ++i) {
        // argv: 记录保存参数值的地址
        printf("value of parameter: argv[%d] = %s \n", i, argv[i]);
    }
}
