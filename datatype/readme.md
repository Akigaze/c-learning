## 基本数据类型
- short
- int 
- long
- long long
- float
- double
- char 

## 构造类型
- 数组
- 结构体
- 共用体
- 枚举

> 既不是基本数据类型，也不是指针，由若干相同或不同类型的数据构成的集合

### 结构体
#### 定义结构体
```c
struct Student {
    // 成员列表
    int id;
    char name[10];
    short gender;
};

// 无名结构体
struct {
    int id;
    char type[5];
} t1, t2;

// 声明别名
typedef struct animal {
    char name[20];
    int type;
} Animal;
```

#### 声明结构体变量
```c
// 定义时声明
struct {
    int id;
    char type[5];
} t1, t2;

// 定义后声明
struct Student {
    int id;
    char name[10];
    short gender;
};
struct Student s1, s2;

// 使用别名声明
typedef struct animal {
    char name[20];
    int type;
} Animal;
Animal a1, a2;
```

#### 初始化结构体变量
```c
// 在定义结构体的同时声明初始化结构体变量
struct Student {
    // 成员列表
    int id;
    char name[10];
    char gender;
    int age;
} lily = {1, "Lily", 'f', 19};

// 声明结构体变量并初始化
struct Student bob = {2, "Bob", 'm', 19};

// 先声明，后初始化
struct Student bob;
bob.id = 2;
bob.age = 20;
bob.gender = 'm';
strcpy(bob.name, "Bob");

//相同类型的结构体可以相互赋值
struct Student lucy = bob;
```

#### 结构体变量的使用
> 结构体变量名.成员变量名

支持读取和修改操作

```c
typedef struct {
    int year;
    int month;
    int day;
} Date;

// 结构体嵌套
typedef struct {
    int id;
    char name[20];
    Date birthday;
} STUDENT;

// 嵌套结构体的初始化
STUDENT make = {3, "Make", {2000, 2,4}};
char birthday[20];
sprintf(birthday, "%d-%d-%d", make.birthday.year, make.birthday.month, make.birthday.day);
```

#### 结构体数组
> struct 结构体类型 数组名[元素个数];

#### 结构体变量指针
> struct 结构体类型 *指针名;

```
// 通过结构体变量指针访问成员变量
(*结构体变量指针).成员变量
结构体变量指针 -> 成员变量  更为常用
```

#### 结构体变量的内存分配
以空间换取时间，提高CPU读取效率

- *rule-1*：以占字节数最大的 **基本类型** 或 **指针类型** 为单位分配内存空间
- *rule-2*: 按成员变量定义的顺序依次开辟空间
- *rule-3*: 基本单位对齐原则，一个基本单位的空间只能刚好存放整数各成员变量的数据，如果一个基本单位剩余的空间不够，则要另外开辟一个基本单位的空间

#### 位段
- 位段是结构体成员变量的一种，只能是 **整型** 或者 **字符** 类型
- 位段可以指定该成员变量所使用的 **位(bit)** 数，即该成员变量只使用指定数量的比特数来存储数据
- 声明位段成员变量时，在成员变量名后使用 **冒号(:)** 指定使用的比特数
- 因为位段是以比特为单位的，所以不能对位段成员变量取地址
- 位段成员变量的bit长度必须小于或等于结构天基本内存单位的大小

```
struct {
    unsigned int a:3;
    char c:4;
} d1;
```

### 共用体
共用体的定义方式与结构体相似，只是使用的关键字是 `union`

#### 共用体的内存分配
- 共用体的所有成员变量公用一个内存段，其大小是最大的那个成员变量的字节数
- 每对共用体的一个成员变量进行赋值，就会改变该内存段存储的内容，所以可以认为公用体所有成员变量的值都是相同的

```c
// 定义共用体
union Bucket{
    int wood1;
    int wood2;
    int wood3;
};

// 声明一个共用体变量并初始化，最终所用成员变量都是 300
union Bucket bucket1;
bucket1.wood1 = 100;
bucket1.wood2 = 200;
bucket1.wood3 = 300;

// 声明共用体变量并直接初始化，初始化时只需指定一个成员变量的值
union Bucket bucket2 = {50};

// 共用体中包含不同类型的成员变量
union Flower {
    int num;
    char color;
};
```

### 枚举
使用 `enum` 关键字定义枚举类型和枚举变量