Ex2.1

> 类型 int、long、long long 和 short 的区别是什么？无符号类型和带符号类型的区别是什么？float 和 double的区别是什么？

C++ 规定 `short` 和 `int` 至少16位，`long` 至少32位，`long long` 至少64位。
带符号类型能够表示正数、负数和 0 ，而无符号类型只能够表示 0 和正整数。

用法：
* 一般使用 `int` 做整数运算，`short` 因为太小在实际中用的少，`long` 通常和 `int` 有着相同的大小。如果数据非常大，可以使用 `long long` 。
* 如果你确认数据是非负的，那么就使用 `unsigned` 无符号类型。
* 执行浮点运算时用 `double` ，因为 `float` 通常精度不够而且双精度浮点数和单精度浮点数的计算代价相差无几。

参考：
* [What are the criteria for choosing between short / int / long data types?](http://www.parashift.com/c++-faq/choosing-int-size.html)
* [Difference between float and double](http://stackoverflow.com/questions/2386772/difference-between-float-and-double)

Ex2.2

> 计算按揭贷款时，对于利率、本金和付款分别应选择何种数据类型？说明你的理由。

使用 `double` 或 `float` 。

Ex2.3

> 读程序写结果。
```cpp
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```

输出：
```
32
4294967264
32
-32
0
0
```

## [ex2.4](ex2_4.cpp)

> 编写程序检查你的估计是否正确，如果不正确，请仔细研读本节直到弄明白问题所在。

Ex2.5

> 指出下述字面值的数据类型并说明每一组内几种字面值的区别：
- (a) 'a', L'a', "a", L"a"
- (b) 10, 10u, 10L, 10uL, 012, 0xC
- (c) 3.14, 3.14f, 3.14L
- (d) 10, 10u, 10., 10e-2

(a): 字符字面值，宽字符字面值，字符串字面值，宽字符串字面值。

(b): 十进制整型，十进制无符号整型，十进制长整型，十进制无符号长整型，八进制整型，十六进制整型。

(c): double, float, long double

(d): 十进制整型，十进制无符号整型，double, double

Ex2.6

> 下面两组定义是否有区别，如果有，请叙述之：
```cpp
int month = 9, day = 7;
int month = 09, day = 07;
```

第一行定义的是十进制整型。
第二行定义的是八进制整型，但是 month 变量无效，因为八进制没有 9 。

Ex2.7

> 下述字面值表示何种含义？它们各自的数据类型是什么？
- (a) "Who goes with F\145rgus?\012"
- (b) 3.14e1L
- (c) 1024f
- (d) 3.14L

(a): Who goes with Fergus?(换行)，string 类型

(b): long double

(c): 无效，因为后缀 f 只能用于浮点字面量，而 1024 是整型。

(d): long double

参考：
* [ASCII Table](http://www.asciitable.com/)

Ex2.8

> 请利用转义序列编写一段程序，要求先输出 2M，然后转到新一行。修改程序使其先输出 2，然后输出制表符，再输出 M，最后转到新一行。

```cpp
#include <iostream>

int main()
{
    std::cout << 2 << "\115\012";
    std::cout << 2 << "\t\115\012";
    return 0;
}
```

Ex2.9

> 解释下列定义的含义，对于非法的定义，请说明错在何处并将其改正。
- (a) std::cin >> int input_value;
- (b) int i = { 3.14 };
- (c) double salary = wage = 9999.99;
- (d) int i = 3.14;

(a): 应该先定义再使用。
```cpp
int input_value = 0;
std::cin >> input_value;
```

(b): 用列表初始化内置类型的变量时，如果存在丢失信息的风险，则编译器将报错。
```cpp
double i = { 3.14 };
```

(c): 在这里 wage 是未定义的，应该在此之前将其定义。
```cpp
double wage;
double salary = wage = 9999.99;
```

(d): 不报错，但是小数部分会被截断。
```cpp
double i = 3.14;
```

Ex2.10

> 下列变量的初值分别是什么？
```cpp
std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
}
```

`global_int` 是全局变量，所以初值为 0 。
`local_int` 是局部变量并且没有初始化，它的初值是未定义的。
`global_str` 和 `local_str` 是 string 类的对象，该对象定义了默认的初始化方式，即初始化为空字符串。 

Ex2.11

> 指出下面的语句是声明还是定义：
- (a) extern int ix = 1024;
- (b) int iy;
- (c) extern int iz;

```
(a): 定义
(b): 定义
(c): 声明
```

Ex2.12

> 请指出下面的名字中哪些是非法的？
- (a) int double = 3.14;
- (b) int _;
- (c) int catch-22;
- (d) int 1_or_2 = 1;
- (e) double Double = 3.14;

`(a)`, `(c)`, `(d)` 非法。

Ex2.13

> 下面程序中 j 的值是多少？
```cpp
int i = 42;
int main()
{
    int i = 100;
    int j = i;
}
```

`j` 的值是 `100` ，局部变量 `i` 覆盖了全局变量 `i` 。

Ex2.14

> 下面的程序合法吗？如果合法，它将输出什么？
```cpp
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;
    std::cout << i << " " << sum << std::endl;
```

合法。输出是 ` 100 45 ` 。

Ex2.15

> 下面的哪个定义是不合法的？为什么？
- (a) int ival = 1.01;
- (b) int &rval1 = 1.01;
- (c) int &rval2 = ival;
- (d) int &rval3;

`(b)` 和 `(d)` 不合法，`(b)` 引用必须绑定在对象上，`(d)` 引用必须初始化。

Ex2.16

> 考察下面的所有赋值然后回答：哪些赋值是不合法的？为什么？哪些赋值是合法的？它们执行了哪些操作？
```
int i = 0, &r1 = i; double d = 0, &r2 = d;
- (a) r2 = 3.14159;
- (b) r2 = r1;
- (c) i = r2;
- (d) r1 = d;
```

```
(a): 合法。给 d 赋值为 3.14159。
(b): 合法。会执行自动转换（int->double）。
(c): 合法。会发生小数截取。
(d): 合法。会发生小数截取。
```

Ex2.17

> 执行下面的代码段将输出什么结果？
```cpp
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```

输出：
```
10, 10
```

Ex2.18

> 编写代码分别改变指针的值以及指针所指对象的值。

```cpp
int a = 0, b = 1;
int *p1 = &a, *p2 = p1;

// change the value of a pointer.
p1 = &b;
// change the value to which the pointer points
*p2 = b;
```

Ex2.19

> 说明指针和引用的主要区别

1. 引用是另一个对象的别名，而指针本身就是一个对象。
2. 引用必须初始化，并且一旦定义了引用就无法再绑定到其他对象。而指针无须在定义时赋初值，也可以重新赋值让其指向其他对象。

Ex2.20

> 请叙述下面这段代码的作用。
```cpp
int i = 42;
int *p1 = &i; 
*p1 = *p1 * *p1;
```

让指针 `pi` 指向 `i`，然后将 `i` 的值重新赋值为 42 * 42 (1764)。

Ex2.21

> 请解释下述定义。在这些定义中有非法的吗？如果有，为什么？
```
int i = 0;
(a) double* dp = &i;
(b) int *ip = i;
(c) int *p = &i;
```

```
(a): 非法。不能将一个指向 `double` 的指针指向 `int` 。
(b): 非法。不能将 `int` 变量赋给指针。
(c): 合法。
```

Ex2.22

> 假设 p 是一个 int 型指针，请说明下述代码的含义。
```cpp
if (p) // ...
if (*p) // ...
```
`if (p) // ...`  判断 p 是不是一个空指针, 
`if (*p) // ...` 判断 p 所指向的对象的值是不是为 0

Ex2.23

> 给定指针 p，你能知道它是否指向了一个合法的对象吗？如果能，叙述判断的思路；如果不能，也请说明原因。

不能，因为首先要确定这个指针是不是合法的，才能判断它所指向的对象是不是合法的。

Ex2.24

> 在下面这段代码中为什么 p 合法而 lp 非法？
```cpp
int i = 42;
void *p = &i;
long *lp = &i;
```

`void *` 是从 C语言那里继承过来的，可以指向任何类型的对象。而其他指针类型必须要与所指对象严格匹配。

Ex2.25

> 说明下列变量的类型和值。
- (a) int* ip, i, &r = i;
- (b) int i, *ip = 0;
- (c) int* ip, ip2;

```
(a): ip 是一个指向 int 的指针, i 是一个 int, r 是 i 的引用。
(b): i 是 int , ip 是一个空指针。
(c): ip 是一个指向 int 的指针, ip2 是一个 int。
```

Ex2.26

> 下面哪些语句是合法的？如果不合法，请说明为什么？
```cpp
const int buf;      // 不合法, const 对象必须初始化
int cnt = 0;        // 合法
const int sz = cnt; // 合法
++cnt; ++sz;        // 不合法, const 对象不能被改变
```

Ex2.27

> 下面的哪些初始化是合法的？请说明原因。
```cpp
int i = -1, &r = 0;         // 不合法, r 必须引用一个对象
int *const p2 = &i2;        // 合法
const int i = -1, &r = 0;   // 合法
const int *const p3 = &i2;  // 合法
const int *p1 = &i2;        // 合法
const int &const r2;        // 不合法, r2 是引用，引用没有顶层 const
const int i2 = i, &r = i;   // 合法
```

Ex2.28

> 说明下面的这些定义是什么意思，挑出其中不合法的。
```cpp
int i, *const cp;       // 不合法, const 指针必须初始化
int *p1, *const p2;     // 不合法, const 指针必须初始化
const int ic, &r = ic;  // 不合法, const int 必须初始化
const int *const p3;    // 不合法, const 指针必须初始化
const int *p;           // 合法. 一个指针，指向 const int
```

Ex2.29

> 假设已有上一个exercise中定义的那些变量，则下面的哪些语句是合法的？请说明原因。
```cpp
i = ic;     // 合法, 常量赋值给普通变量
p1 = p3;    // 不合法, p3 是const指针不能赋值给普通指针
p1 = &ic;   // 不合法, 普通指针不能指向常量
p3 = &ic;   // 合法, p3 是常量指针且指向常量
p2 = p1;    // 合法, 可以将普通指针赋值给常量指针
ic = *p3;   // 合法, 对 p3 取值后是一个 int 然后赋值给 ic
```

Ex2.30

> 对于下面的这些语句，请说明对象被声明成了顶层const还是底层const？
```cpp
const int v2 = 0; int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```

v2 是顶层const，p2 是底层const，p3 既是顶层const又是底层const，r2 是底层const。

Ex2.31

> 假设已有上一个exercise中所做的那些声明，则下面的哪些语句是合法的？请说明顶层const和底层const在每个例子中有何体现。
```cpp
r1 = v2; // 合法, 顶层const在拷贝时不受影响
p1 = p2; // 不合法, p2 是底层const，如果要拷贝必须要求 p1 也是底层const
p2 = p1; // 合法, int* 可以转换成const int*
p1 = p3; // 不合法, p3 是一个底层const，p1 不是
p2 = p3; // 合法, p2 和 p3 都是底层const，拷贝时忽略掉顶层const
```

Ex2.32

> 下面的代码是否合法？如果非法，请设法将其修改正确。
```
int null = 0, *p = null;
```
非法.  
把int变量直接赋给指针是错误的操作,即使int变量的值恰好等于0也不行.
```
int null = 0, *p = 0;
```

Ex2.33

> 利用本节定义的变量，判断下列语句的运行结果。
```cpp
a=42; // a 是 int
b=42; // b 是一个 int,(ci的顶层const在拷贝时被忽略掉了)
c=42; // c 也是一个int
d=42; // d 是一个 int *,所以语句非法
e=42; // e 是一个 const int *, 所以语句非法
g=42; // g 是一个 const int 的引用，引用都是底层const，所以不能被赋值
```

## [ex2.34](ex2_34.cpp)

> 基于上一个exercise中的变量和语句编写一段程序，输出赋值前后变量的内容，你刚才的推断正确吗？如果不对，请反复研读本节的示例直到你明白错在何处为止。

Ex2.35

> 判断下列定义推断出的类型是什么，然后编写程序进行验证。
```cpp
const int i = 42;
auto j = i; const auto &k = i; auto *p = &i; 
const auto j2 = i, &k2 = i;
```

j 是 int，k 是 const int的引用，p 是const int *，j2 是const int，k2 是 const int 的引用。

至于验证，鼠标移到变量上就出来了......


Ex2.36

> 关于下面的代码，请指出每一个变量的类型以及程序结束时它们各自的值。
```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;
```

c 是 int 类型，值为 4。d 是 int & 类型，绑定到 a，a 的值为 4 。

Ex2.37

> 赋值是会产生引用的一类典型表达式，引用的类型就是左值的类型。也就是说，如果 i 是 int，则表达式 i=x 的类型是 int&。根据这一特点，请指出下面的代码中每一个变量的类型和值。
```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;
```

c 是 int 类型，值为 3。d 是 int& 类型，绑定到 a。

Ex2.38

> 说明由decltype 指定类型和由auto指定类型有何区别。请举一个例子，decltype指定的类型与auto指定的类型一样；再举一个例子，decltype指定的类型与auto指定的类型不一样。

decltype 处理顶层const和引用的方式与 auto不同，decltype会将顶层const和引用保留起来。
```cpp
int i = 0, &r = i;
//相同
auto a = i;
decltype(i) b = i;

//不同 d 是一个 int&
auto c = r;
decltype(r) d = r;
```

[这里](http://stackoverflow.com/questions/21369113/what-is-the-difference-between-auto-and-decltypeauto-when-returning-from-a-fun)和[这里](http://stackoverflow.com/questions/12084040/decltype-vs-auto)还有更多的讨论。

Ex2.39

> 编译下面的程序观察其运行结果，注意，如果忘记写类定义体后面的分号会发生什么情况？记录下相关的信息，以后可能会有用。
```cpp
struct Foo { /* 此处为空  */ } // 注意：没有分号
int main()
{
    return 0;
}
```

提示应输入分号。

Ex2.40

> 根据自己的理解写出 Sales_data 类，最好与书中的例子有所区别。

```cpp
struct Sale_data
{
    std::string bookNo;
    std::string bookName;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double price = 0.0;
    //...
}
```

Ex2.41

> 使用你自己的Sale_data类重写1.5.1节（第20页）、1.5.2节（第21页）和1.6节（第22页）的exercise。眼下先把Sales_data类的定义和main函数放在一个文件里。

####1.5.1

```cpp
#include <iostream>
#include <string>

struct Sale_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sale_data book;
    double price;
    std::cin >> book.bookNo >> book.units_sold >> price;
    book.revenue = book.units_sold * price;
    std::cout << book.bookNo << " " << book.units_sold << " " << book.revenue << " " << price;

    return 0;
}
```

####1.5.2

```cpp
#include <iostream>
#include <string>

struct Sale_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sale_data book1, book2;
    double price1, price2;
    std::cin >> book1.bookNo >> book1.units_sold >> price1;
    std::cin >> book2.bookNo >> book2.units_sold >> price2;
    book1.revenue = book1.units_sold * price1;
    book2.revenue = book2.units_sold * price2;

    if (book1.bookNo == book2.bookNo)
    {
        unsigned totalCnt = book1.units_sold + book2.units_sold;
        double totalRevenue = book1.revenue + book2.revenue;
        std::cout << book1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        if (totalCnt != 0)
            std::cout << totalRevenue / totalCnt << std::endl;
        else
            std::cout << "(no sales)" << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "Data must refer to same ISBN" << std::endl;
        return -1;  // indicate failure
    }
}
```

####1.6

```cpp
#include <iostream>
#include <string>

struct Sale_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sale_data total;
    double totalPrice;
    if (std::cin >> total.bookNo >> total.units_sold >> totalPrice)
    {
        total.revenue = total.units_sold * totalPrice;

        Sale_data trans;
        double transPrice;
        while (std::cin >> trans.bookNo >> trans.units_sold >> transPrice)
        {
            trans.revenue = trans.units_sold * transPrice;

            if (total.bookNo == trans.bookNo)
            {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
            else
            {
                std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
                if (total.units_sold != 0)
                    std::cout << total.revenue / total.units_sold << std::endl;
                else
                    std::cout << "(no sales)" << std::endl;

                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }

        std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " ";
        if (total.units_sold != 0)
            std::cout << total.revenue / total.units_sold << std::endl;
        else
            std::cout << "(no sales)" << std::endl;

        return 0;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;  // indicate failure
    }
}
```

Ex2.42

> 根据你自己的理解重写一个Sales_data.h头文件，并以此为基础重做2.6.2节（第67页）的exercise。


- [1.5.1](ex2_42_1.cpp)
- [1.5.2](ex2_42_2.cpp)
- [1.6](ex2_42_3.cpp)

