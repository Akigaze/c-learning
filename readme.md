## Learning Resource
[Bilibili 千锋-嵌入式物联网教程](https://www.bilibili.com/video/BV1FA411v7YW)

## CLion
#### 使用CMake构建执行项目
编写CMakeLists.txt 文件，右键该文件，点击 `Reload CMake Project` 可以重新构建 **cmake-build-debug** folder，
里面包含了 **Makefile** 和其他编译运行项目所需的配置，后面编译生成的 **.exe** 也会放在该目录下

每个项目只能有个一个主的 **CMakeLists.txt** 文件，可以为不同的执行或者测试模块单独编写 **CMakeLists.txt** 文件(放在对应的模块文件夹下)，
在主 **CMakeLists.txt** 文件中去引用各个模块的 **CMakeLists.txt** 文件

## project build
#### MinGW 的 `gcc` 命令
> gcc xxx.c yyy.c     编译链接生成 a.exe  
> gcc xxx.c yyy.c -o 文件名.exe   编译链接生成 文件名.exe

---
> 预编译处理，生成 main.i 文件：gcc -E main.c -o main.i  
编译处理，生成 main.s 文件：gcc -S main.i -o main.s  
汇编处理，生成 main.o 文件：gcc -c main.i -o main.o  
链接处理，生成 main.exe 文件：gcc main.o -o main  
执行main.exe：main   

#### CMake 跨平台自动化建构系统
CMake(Cross platform MAke). 
编写一种平台无关的 **CMakeList.txt** 文件来定制整个编译流程，然后再根据目标用户的平台进一步生成所需的本地化 **Makefile** 和工程文件

**CMakeLists.txt** 的语法比较简单，由命令、注释和空格组成
1. 命令: 不区分大小写，由命令名称、小括号和参数组成，参数之间使用空格进行间隔，使用 `${变量名}` 引用变量
2. 注释：符号 `#` 后面的内容被认为是注释

### 常用命令
- `add_executable(exe文件名 要参与编译的C文件)` 添加可执行文件
- `aux_source_directory(<dir> <variable>)` 定义目录下所以源文件的引用

### Link
[简书 - CMake 入门实战](https://www.jianshu.com/p/6e6569ba2237?tdsourcetag=s_pcqq_aiomsg)


## C programming language
#### 1. 引用标准库
```c
#include <标准库名称.h>
```
常用标准库：
- stdio.h

#### 程序入口
```c
int main() {
    return 0; // return 可有可无
}
```