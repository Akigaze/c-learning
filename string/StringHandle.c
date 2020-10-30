//
// Created by Akigaze on 10/26/2020.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void testStrlen() {
    /*
     * size_t strlen (const char *)
     * 获取字符串中字符的个数，只计算第一个 \0 之前的字符
     * 对比 sizeof 是获取一个变量所分配的字节数，数组就是其声明时的大小，指针变量就是4个字节(32位)
     */
    char hello[20] = "hello";
    printf("string length of hello: %d \n", strlen(hello));
    printf("size of hello: %d \n", sizeof(hello));

    char pencil[10] = "pen\0cil";
    printf("string pen\\0cil: %s \n", pencil);
    printf("string length of pencil: %d \n", strlen(pencil));
    printf("size of pencil: %d \n", sizeof(pencil));

    char *sunny = "sunny";
    printf("string length of sunny: %d \n", strlen(sunny));
    printf("size of sunny: %d \n", sizeof(sunny));
}

void testStrcpy() {
    char hello[16] = "hello world";
    char pencil[16] = "pencil";
    /*
     * char *strcpy (char *dest, const char *src)
     * 将src的字符串内容拷贝到dest的空间中，包括 \0
     * 拷贝时从头拷贝，并且时直接替换掉原有的字符，若目标字符串原本的字符串长度比新的长，则还是会保留后面的所有字符
     * 拷贝时必须保证目标字符串有足够的空间，不然可能会造成内存污染
     */
    strcpy(hello, pencil);
    printf("copy 'pencil' to 'hello world': %s \n", hello);
    for (int i = 0; i < sizeof(hello); i++) {
        printf("[%c] - %d \n", hello[i], hello[i]);
    }
}

void testStrncpy() {
    char hello[20] = "hello";
    char pencil[10] = "pencil";
    /*
     * strncpy(dest, src, n)
     * 复制 src 的前 n 个字符到 dest
     */
    strncpy(hello, pencil, 3);
    printf("copy first 3 char of 'pencil' to 'hello': %s \n", hello);
}

void testStrcat() {
    char hello[20] = "hello";
    char world[8] = "world";
    /*
     * char *strcat (char *dest, const char *src)
     * 将src的内容拷贝追加到dest之后
     * 追加的位置时从dest的第一个\0 开始，src 拷贝的部分是到第一个 \0 位置(包括 \0)
     */
    strcat(hello, world);

    printf("cat 'world' after 'hello': %s \n", hello);
}

void testStrncat() {
    char hello[20] = "hello";
    char pencil[10] = "pencil";
    /*
     * strncat(dest, src, n)
     * 复制 src 的前 n 个字符并追加到 dest
     */
    strncat(hello, pencil, 3);
    printf("cat first 3 char of 'pencil' to 'hello': %s \n", hello);
}

void testStrcmp() {
    char s1[] = "beijing";
    char s2[] = "beifeng";

    /*
     * int strcmp (const char *s1, const char *s2)
     * 比较 s1 和 s2 是否相等，各自的第一个字符开始，逐个比较Ascii码，直到第一个大小不相等，或者第一个 \0 为止
     * 返回的结果有 0，1，-1
     */
    int res = strcmp(s1, s2);
    if (res == 0) {
        printf("'%s' = '%s': %d \n", s1, s2, res);
    } else if (res > 0) {
        printf("'%s' > '%s': %d \n", s1, s2, res);
    } else {
        printf("'%s' < '%s': %d \n", s1, s2, res);
    }
}

void testStrncmp() {
    char s1[] = "beijing";
    char s2[] = "beifeng";

    /*
     * int strncmp (const char *s1, const char *s2, n)
     * 比较 s1 和 s2 的前 n 个字符是否相等
     */
    int res = strncmp(s1, s2, 3);
    if (res == 0) {
        printf("first 3 char of '%s' = '%s': %d \n", s1, s2, res);
    } else if (res > 0) {
        printf("first 3 char of '%s' > '%s': %d \n", s1, s2, res);
    } else {
        printf("first 3 char of '%s' < '%s': %d \n", s1, s2, res);
    }
}

void testStrchr() {
    char s[] = "hello world";
    /*
     * char *strchr (const char s*, int chr)
     * 在字符串 s 中查找第一个ascii码是chr的字符，返回该字符的地址指针
     */
    char *res = strchr(s, 'o');
    if (res == NULL) {
        printf("could not find 'o' in 'hello world' \n");
    } else {
        // 使用数组变量与其中的元素的指针最差，可以获得这两个地址之间相差的元素个数
        printf("the first 'o' in 'hello world' is at: %d \n", res - s);
    }
}

void testStrrchr() {
    char s[] = "hello world";
    /*
     * char *strrchr (const char s*, int chr)
     * 在字符串 s 中查找最后一个ascii码是chr的字符，返回该字符的地址指针
     */
    char *res = strrchr(s, 'o');
    if (res == NULL) {
        printf("could not find 'o' in 'hello world' \n");
    } else {
        printf("the last 'o' in 'hello world' is at: %d \n", res - s);
    }
}

void testStrstr() {
    char s[] = "123:666:642:666:444:121";
    /*
     * char *strstr (const char haystack*, const char *needle)
     * 在字符串 haystack 中找到第一个 needle 字符串的，返回其首字符的地址指针
     * 对于 needle 是去 \0 前的内容进行匹配
     */
    char *res = strstr(s, "666");
    if (res == NULL) {
        printf("could not find '666' in '%s' \n", s);
    } else {
        printf("find first '666' in '%s' at:%d \n", s, res - s);
    }
}

void testAtoiAtolAtof() {
    char s1[] = "1024";
    // atoi 字符转int整型
    int i1 = atoi(s1);
    printf("'%s' convert to int: %d \n", s1, i1);

    char s2[] = "10241024";
    // atol 字符转long整型
    long l1 = atol(s2);
    printf("'%s' convert to long: %ld  \n", s2, l1);

    char s3[] = "3.1415926";
    // atof 字符转double浮点数
    double f1 = atof(s3);
    printf("'%s' convert to double: %lf  \n", s3, f1);
}

int main(int args, char *argv[]) {
    printf("--------------- 1. strlen --------------- \n");
    testStrlen();
    printf("--------------- 2. strcpy --------------- \n");
    testStrcpy();
    printf("--------------- 3. strncpy --------------- \n");
    testStrncpy();
    printf("--------------- 4. strcpy --------------- \n");
    testStrcat();
    printf("--------------- 5. strncpy --------------- \n");
    testStrncat();
    printf("--------------- 6. strcmp --------------- \n");
    testStrcmp();
    printf("--------------- 7. strcmp --------------- \n");
    testStrncmp();
    printf("--------------- 8. strchr --------------- \n");
    testStrchr();
    printf("--------------- 9. strrchr --------------- \n");
    testStrrchr();
    printf("--------------- 10. strrchr --------------- \n");
    testStrstr();
    printf("--------------- 11. atoi/atol/atof --------------- \n");
    testAtoiAtolAtof();
}
