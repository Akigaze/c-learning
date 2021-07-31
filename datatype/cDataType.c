#include <stdio.h>
#include <limits.h>



int main() {
    printf("------ 整数类型 ------\n");
    printf("整型默认都是带正负号的，使用unsigned关键字可以定义不带正负号的整型，此时的数字均为正数\n");
    short shortInteger = 512;
    int intInteger = 1024;
    long longInteger = LONG_MAX;
    long long longLongInteger = 9223372036854775000L;
    printf("short: 2个字节: %d, size is: %llu byte\n", shortInteger, sizeof(shortInteger));
    printf("int: 2个或4个字节，不同操作系统可能不同: %d, size is %llu byte\n", intInteger, sizeof(intInteger));
    printf("long: 4个字节: %ld, size is %llu byte\n", longInteger, sizeof(longInteger));
    printf("long long: 8个字节: %lld, size is %llu byte\n", longLongInteger, sizeof(longLongInteger));

    printf("------ 字符类型 ------\n");
    char aChar = 'X';
    int integerOfChar = aChar;
    printf("char: 1个字节: %c, size is %llu byte, 对应的整型为: %d\n", aChar, sizeof(integerOfChar), integerOfChar);

    printf("------ 进制 -------\n");
    int hundred = 100;
    printf("%d octal: %#o\n", hundred, hundred);
    printf("%d hexadecimal: %#x\n", hundred, hundred);
    printf("&hundred memory address: %p\n", &hundred);
}
