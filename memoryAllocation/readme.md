## 动态分配内存
在程序运行时按实际需要来分配内存空间，C语言提供了一系列分配内存，回收内存的方法

### 1 静态分配
- 事先决定要使用的内存大小，如 `int a[10]`
- 一般是分配 **栈区** 或 **全局变量区** 的内存，主要以数组的形式
- 按计划分配

### 2 动态分配
- 程序运行时按实际需求来分配内存空间
- 一般是分配堆区的内存空间，通过特定函数进行分配
- 按需分配

### 动态分配内存的函数
内存分配相关的函数存放在 `stdlib.h` 这个头文件中，使用时需要手动引入
```c
#include<stdlib.h>
```

#### malloc 申请内存
> void *malloc(int) 

- 在**堆区**开辟一块**连续**的内存空间，需要指定相应的字节数
- 返回值是一个 `void *` ，一般需要强转想要的数组类型
- 如果内配内失败，则返回 `NULL`

#### free 释放内存
> void free(void *)

- 释放掉指定首地址的**堆区**空间，释放的含义是运行其他变量使用该内存空间(原有的内容应该也被清除掉了)
- 只能释放**堆区**的空间，所以只能针对 `malloc`, `calloc` 和 `realloc` 申请的空间
- 只能释放一次申请的所有空间，不能释放部分空间

#### calloc 申请内存
> void *calloc(int nmember, int size)

- 与 `malloc` 相似用于申请内存
- 第一个参数是**内存块的数量**，第二个参数是**每块内存块的字节数**，每块内存里面的空间是连续的

#### realloc 重新申请内存
> void *realloc(void *s, int)

- 为指定首地址的变量重新分配堆空间，新的空间大小为指定的字节数
- 如果原有空间后有足够的连续空间，则会使用后面的空间
- 若原有空间后没有足够的连续空间，则会重新开辟一块完整的空间，将原有的内容拷贝到新的地址，释放原有空间
- 若新的空间比原有的小，则释放原有空间后面的部分空间

### 内存泄漏
`malloc`, `calloc` 和 `realloc` 申请的堆空间只有在程序运行结束或者使用 `free` 的情况下才会被释放

所有如果丢失了首地址引用，或者在方法中申请的空间没有返回或者释放，就可能造成内存泄漏

#### 1 丢失首地址
```c
int func() {
    char *str = (char *)malloc(100);
    str = "hello world";
}
``` 

#### 没有释放
```c
void func() {
    char *str = (char *)malloc(100);
    // 对str进行操作
    return;
}
```