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
    printf("string length of hello: %llu \n", strlen(hello));
    printf("size of hello: %llu \n", sizeof(hello));

    char pencil[10] = "pen\0cil";
    printf("string pen\\0cil: %s \n", pencil);
    printf("string length of pencil: %llu \n", strlen(pencil));
    printf("size of pencil: %llu \n", sizeof(pencil));

    char *sunny = "sunny";
    printf("string length of sunny: %llu \n", strlen(sunny));
    printf("size of sunny: %llu \n", sizeof(sunny));
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
        printf("the first 'o' in 'hello world' is at: %lld \n", res - s);
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
        printf("the last 'o' in 'hello world' is at: %lld \n", res - s);
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
        printf("find first '666' in '%s' at:%lld \n", s, res - s);
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

void testStrtok() {
    /*
     * char *strtok (char *str, const char *pattern)
     * 类似与split，对字符串 str 使用 pattern 字符串进行切割，但是一次调用只进行一次切割，返回切割后得到的字符串
     * 当要继续切割同一字符串时，要指定 str 参数为 NULL ，似乎 strtok 函数会记住上一个切割的字符串和切割后剩下的部分，在次此基础上继续切割
     * 切割的原理是把遇到的第一个与 pattern 相符的子串的首字符替换成 \0 ，返回前的字串的首地址，并将切割光标移动到下一个与 pattern 不符的子串首地址
     */
    char str1[] = "111,222.333,444,5555";
    printf("split %s \n", str1);
    char *res1 = strtok(str1, ",");
    printf("split %s by ',': %s \n", str1, res1);
    char *res2 = strtok(NULL, ".");
    printf("split %s by '.': %s \n", str1, res2);
    char *res3 = strtok(NULL, ",");
    printf("split %s by '.': %s \n", str1, res3);

    char str2[] = "aaa,,bbb,ccc";
    char *r1 = strtok(str2, ",");
    char *r2 = strtok(NULL, ",");
    char *r3 = strtok(NULL, ",");
    printf("split %s by ',': %s \n", str2, r1);
    printf("split %s by ',': %s \n", str2, r2);
    printf("split %s by ',': %s \n", str2, r3);
    for (int i = 0; i < sizeof(str2); ++i) {
        printf("%c \n", str2[i]);
    }

    char str3[] = "123,456,222,333";
    char *res = strtok(str3, ",");
    while (res != NULL) {
        printf("split %s by ',': '%s' \n", str3, res);
        res = strtok(NULL, ",");
    }

}

void testSprintf() {
    char buff[20];

    /*
     * int sprintf (char *buff, const char *format, args...)
     * 类似于printf，把格式化的结果复制到数组 buff 中
     */
    sprintf(buff, "%d:%d:%c", 100, 333, 'f');

    printf("buff = %s \n", buff);
}

void testSscanf() {
    int a, b;
    char c;

    /*
     * int sscanf (const char *str, const char *format, args...)
     * 类似于scanf , 将 str 根据 format 指定的格式，将分离得到的内容存放的指定的地址
     */
    sscanf("123:666.f", "%d:%d.%c", &a, &b, &c);
    printf("a = %d, b = %d, c = %c \n", a, b, c);

    char buff[10];
    // 使用 %* 可以跳过指定的字符，不对指定格式的内容进行保存
    sscanf("4444 5555", "%*d %s", buff);
    printf("buff = %s \n", buff);
    // 使用 %n 指定格式化的字符个数
    sscanf("hello world", "%6s", buff);
    printf("buff = %s \n", buff);
    // 使用 %[] 类似正则表达式的方式对字符进行匹配
    sscanf("aWfd45hJK", "%[a-zA-Z]", buff);
    printf("buff = %s \n", buff);
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
    printf("--------------- 12. strtok --------------- \n");
    testStrtok();

    printf("--------------- 13. sprintf --------------- \n");
    testSprintf();
    printf("--------------- 14. sscanf --------------- \n");
    testSscanf();
}
