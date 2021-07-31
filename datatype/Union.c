//
// Created by Akigaze on 11/1/2020.
//

#include <stdio.h>

union Bucket {
    int wood1;
    int wood2;
    int wood3;
};

union Flower {
    int num;
    char color;
};

int main(int args, char *argv[]) {
    union Bucket bucket1;
    bucket1.wood1 = 100;
    bucket1.wood2 = 200;
    bucket1.wood3 = 300;

    printf("sizeof Bucket: %llu \n", sizeof(bucket1));
    printf("bucket1 > wood1: %d, wood2: %d, wood3: %d \n", bucket1.wood1, bucket1.wood2, bucket1.wood3);

    union Bucket bucket2 = {50};
    printf("bucket2 > wood1: %d, wood2: %d, wood3: %d \n", bucket2.wood1, bucket2.wood2, bucket2.wood3);

    union Flower sunflower = {112};
    printf("sizeof Flower: %llu \n", sizeof(sunflower));
    printf("sunflower > num: %d, color: %c \n", sunflower.num, sunflower.color);

    sunflower.color = 'X';
    printf("sunflower > num: %d, color: %c \n", sunflower.num, sunflower.color);
}

