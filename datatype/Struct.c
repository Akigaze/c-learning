//
// Created by Akigaze on 11/1/2020.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book {
    int id;
    char name[100];
    char author[50];
    int page;
};

// 先定义结构体，在声明其变量
struct Book b1, b2;

// 定义结构体的同时声明变量
struct Student {
    int id; //4
    char name[50]; // 50
    char gender; //1
    int age; //4
} xiaoMing, xiaoHong;

// 定义无名结构体，必须在定义的同时声明变量，否在无法在其他地方声明它的变量
struct {
    int wheel;
    char band[20];
} bmw, bench = {4, "Bench"};

/*
 * 使用 typedef 关键字给结构体起别名
 * 要在结构体定义时使用，此时这个别名就相当于 struct name，所以在定义该结构体类型的变量时，可以使用 alias variable，不需要再加上 struct 关键字
 * 此外，typedef 也可以对无名结构体使用
 */
typedef struct card {
    char name[10];
    int type;
} Card;

Card c1, c2;

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    int id;
    char name[21];
    Date birthday;
} STUDENT;

void printStudent(struct Student stu) {
    printf("Student name: %s, id: %d, gender: %c, age: %d \n", stu.name, stu.id, stu.gender, stu.age);
};


int main(int args, char *argv[]) {

    printf("sizeof Student: %d \n", sizeof(struct Student));
    printf("sizeof Date: %d \n", sizeof(Date));
    printf("sizeof STUDENT: %d \n", sizeof(STUDENT));
    printf("sizeof Card: %d \n", sizeof(Card));


    struct Student lily = {1, "Lily", 'f', 19}, bob;

    printf("Student name: %s, id: %d, gender: %c, age: %d \n", lily.name, lily.id, lily.gender, lily.age);

    bob.id = 2;
    bob.age = 20;
    bob.gender = 'm';
    strcpy(bob.name, "Bob");
    printf("Student name: %s, id: %d, gender: %c, age: %d \n", bob.name, bob.id, bob.gender, bob.age);

    printf("Car name: %s, wheel: %d \n", bench.band, bench.wheel);

    STUDENT make = {3, "Make", {2000, 2, 4}};
    char birthday[20];
    sprintf(birthday, "%d-%d-%d", make.birthday.year, make.birthday.month, make.birthday.day);
    printf("Student name: %s, id: %d, birthday: %s \n", make.name, make.id, birthday);

    // 相同类型的结构体可以相互赋值
    struct Student lucy = bob;
    printStudent(lucy);
    printf("*lucy = %p, *bob = %p \n", &lucy, &bob);
    printf("*lucy.name = %p, *bob.name = %p \n", &(lucy.name), &(bob.name));

    printf("----------- struct array ------------- \n");
    STUDENT class1[3] = {
            {1, "Tom", {2000, 1,  2}},
            {2, "Jim", {2001, 10, 5}},
            {3, "Roy", {2002, 5,  23}},
    };
    for (int i = 0; i < 3; i++) {
        STUDENT stu = class1[i];
        printf("Student name: %s, id: %d, birthday: %d-%d-%d \n", stu.name, stu.id, stu.birthday.year,
               stu.birthday.month, stu.birthday.day);
    }

    printf("----------- point of struct ------------- \n");
    struct Student *p_lucy = &lucy;
    printf("Student name: %s, id: %d, gender: %c, age: %d \n", (*p_lucy).name, p_lucy->id, p_lucy->gender, p_lucy->age);

    // 通过指针创建一个结构体变量
    struct Student *p_any;
    p_any = (struct Student *) malloc(sizeof(struct Student));
    strcpy(p_any->name, "Any");
    p_any->id = 10;
    p_any->gender = 'm';
    p_any->age = 13;
    printf("Student name: %s, id: %d, gender: %c, age: %d \n", p_any->name, p_any->id, p_any->gender, p_any->age);

    printf("----------- memory of struct ------------- \n");
    struct{
        int num;
        int age;
    } s1;
    printf("sizeof S1: %d \n", sizeof(s1));
    printf("num: %p, age: %p \n", &(s1.num), &(s1.age));

    struct{
        char gender;
        int age;
    } s2;
    printf("sizeof S2: %d \n", sizeof(s2));
    printf("gender: %p, age: %p \n", &(s2.gender), &(s2.age));

    struct{
        char gender;
        short age;
        int high;
    } s3;
    printf("sizeof S3: %d \n", sizeof(s3));
    printf("gender: %p, age: %p, high: %p \n", &(s3.gender), &(s3.age), &(s3.high));

    struct{
        char gender;
        int high;
        short age;
    } s4;
    printf("sizeof S4: %d \n", sizeof(s4));
    printf("gender: %p, high: %p, age: %p \n", &(s4.gender), &(s4.high), &(s4.age));

    struct{
        char name[10];
        int age;
    } s5;
    printf("sizeof S5: %d \n", sizeof(s5));
    printf("name: %p, age: %p \n", &(s5.name), &(s5.age));

    printf("----------- weiduan ------------- \n");
    struct {
        unsigned int a:3;
        char c:4;
    } d1;
    d1.a = 5;
    d1.c = '8';
    printf("a= %d, c = %c", d1.a, d1.c);


}