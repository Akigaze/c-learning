字符串操作相关的函数定义在 `string.h` 头文件中

## 获取字符串长度
`size_t strlen (const char *)` 
- 获取字符串中字符的个数，只计算第一个 `\0` 之前的字符
- 对比 `sizeof` 是获取一个变量所分配的字节数，数组就是其声明时的大小，指针变量就是4个字节(32位)

## 字符串拷贝
`char *strcpy (char *dest, const char *src)` 
- 将 `src` 的字符串内容拷贝到 `dest` 的空间中，包括 `\0`
- 拷贝时从头拷贝，并且时直接替换掉原有的字符，若目标字符串原本的字符串长度比新的长，则还是会保留后面的所有字符
- 拷贝时必须保证目标字符串有足够的空间，不然可能会造成内存污染

`char *strncpy (char *dest, const char *src, size_t n)`
- 将 `src` 的前 n 个字符拷贝到 `dest`, 并不会拷贝 `\0`
- 当 `n > strlen(src)` 时，多出的字符全部填充 `\0`

## 字符串追加
`char *strcat (char *dest, const char *src)`
- 将 `src` 的内容拷贝追加到 `dest` 之后
- 追加的位置时从 `dest` 的第一个 `\0` 开始，`src` 拷贝的部分是到第一个 `\0` 位置(包括 `\0`)
- 使用时要保证 `dest` 后有足够多的空间

`char *strncat (char *dest, const char *src, size_t)`
- 将 `src` 的前 n 个字符拷贝追加到 `dest` 之后
- 当 `n > strlen(src)` 时，多出的字符全部填充 `\0`

## 字符串比较
`int strcmp (const char *s1, const char *s2)`
- 比较 `s1` 和 `s2` 是否相等，各自的第一个字符开始，逐个比较Ascii码，直到第一个大小不相等，或者第一个 `\0` 为止
- 返回的结果有 **0**，**1**，**-1**

`int strncmp (const char *s1, const char *s2, n)`
- 比较 `s1` 和 `s2` 的前 `n` 个字符是否相等

## 字符查找
`char *strchr (const char s*, int chr)`
- 在字符串 `s` 中查找第一个ascii码是 `chr` 的字符，返回该字符的地址指针

`char *strrchr (const char s*, int chr)`
在字符串 `s` 中查找最后一个ascii码是 `chr` 的字符，返回该字符的地址指针

## 字符串查找
`char *strstr (const char haystack*, const char *needle)`
- 在字符串 `haystack` 中找到第一个 `needle` 字符串的，返回其首字符的地址指针
- 对于 `needle` 是去 `\0` 前的内容进行匹配

## 字符串转数字
`int atoi (const char *)`
- 字符串转 int 数字

`long atol (const char *)`
- 字符串转 long 数字

`double atof (const char *)`
- 字符串转 double 数字

