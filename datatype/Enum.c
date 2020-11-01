//
// Created by Akigaze on 11/1/2020.
//

#include <stdio.h>

enum Week {
    // 默认编号从 0 开始
    mon, tue, wen, thu, fri, sat, sun
};

enum Color {
    // 手动指定枚举的数值，运行有重复
    red = 3, blue, yellow, green = 1, pink, orange
};

int main(int args, char *argv[]) {
    enum Week workday = mon;
    printf("workday: %d \n", workday);
    workday = fri;
    printf("workday: %d  \n", workday);

    enum Color color = red;
    printf("Color: %d  \n", color);
    color = orange;
    printf("Color: %d  \n", color);
}
