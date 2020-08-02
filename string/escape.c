#include <stdio.h>

int main() {
    printf("\\r是回车符号，在没有换行符的情况下，光标会回到当前行的开头，覆盖已有的内容\n");
    printf("example: \'I have an \\rapple\'\n");
    printf("I have an \rapple");
    printf("\n---------------------------------\n");

    printf("name\tage\tnative\taddress\nMark\t18\tChina\tBeijing");
}
