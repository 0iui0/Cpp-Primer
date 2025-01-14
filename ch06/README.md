Ex6.1

> 实参和形参的区别的什么？

实参是函数调用的实际值，是形参的初始值。

Ex6.2

> 请指出下列函数哪个有错误，为什么？应该如何修改这些错误呢？
```cpp
(a) int f() {
          string s;
          // ...
          return s;
    }
(b) f2(int i) { /* ... */ }
(c) int calc(int v1, int v1) { /* ... */ }
(d) double square (double x)  return x * x; 
```

应该改为下面这样：
```cpp
(a) string f() {
          string s;
          // ...
          return s;
    }
(b) void f2(int i) { /* ... */ }
(c) int calc(int v1, int v2) { /* ... */ }
(d) double square (double x) { return x * x; }
```

## [ex6.3](ex6_3.cpp)

> 编写你自己的fact函数，上机检查是否正确。

## [ex6.4](ex6_4.cpp)

> 编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。在main函数中调用该函数。

Ex6.5

> 编写一个函数输出其实参的绝对值。

```cpp
#include <iostream>

int abs(int i)
{
    return i > 0 ? i : -i;
}

int main()
{
    std::cout << abs(-5) << std::endl;
    return 0;
}
```

Ex6.6

> 说明形参、局部变量以及局部静态变量的区别。编写一个函数，同时达到这三种形式。

**形参**定义在函数形参列表里面；**局部变量**定义在代码块里面；**局部静态变量**在程序的执行路径第一次经过对象定义语句时初始化，并且直到程序终止时才被销毁。
```cpp
// 例子
int count_add(int n)       // n是形参
{
    static int ctr = 0;    // ctr 是局部静态变量
    ctr += n;
    return ctr;
}

int main()
{
    for (int i = 0; i != 10; ++i)  // i 是局部变量
      cout << count_add(i) << endl;

    return 0;
}
```

Ex6.7

> 编写一个函数，当它第一次被调用时返回0，以后每次被调用返回值加1。

```cpp
int generate()
{
    static int ctr = 0;
    return ctr++;
}
```

## [ex6.8](Chapter6.h)

> 编写一个名为Chapter6.h 的头文件，令其包含6.1节exercise中的函数声明。

Ex6.9 : [fact.cc](fact.cc) | [factMain.cc](factMain.cc)

> 编写你自己的fact.cc 和factMain.cc ，这两个文件都应该包含上一小节的exercise中编写的 Chapter6.h 头文件。通过这些文件，理解你的编译器是如何支持分离式编译的。

## [ex6.10](ex6_10.cpp)

> 编写一个函数，使用指针形参交换两个整数的值。在代码中调用该函数并输出交换后的结果，以此验证函数的正确性。

## [ex6.11](ex6_11.cpp)

> 编写并验证你自己的reset函数，使其作用于引用类型的参数。

## [ex6.12](ex6_12.cpp)

> 改写6.2.1节exercise中的程序，使其引用而非指针交换两个整数的值。你觉得哪种方法更易于使用呢？为什么？

很明显引用更好。

Ex6.13

> 假设 T 是某种类型的名字，说明以下两个函数声明的区别：一个是void f(T), 另一个是 void f(&T)。

* `void f(T)` 的参数通过值传递，在函数中 T 是实参的副本，改变T不会影响到原来的实参。
* `void f(&T)` 的参数通过引用传递，在函数中的T是实参的引用，T的改变也就是实参的改变。

Ex6.14

> 举一个形参应该是引用类型的例子，再举一个形参不能是引用类型的例子。

例如交换两个整数的函数，形参应该是引用
```cpp
void swap(int& lhs, int& rhs)
{
	int temp = lhs;
	lhs = rhs;
	rhs = temp;
}
```
当实参的值是右值时，形参不能为引用类型
```cpp
int add(int a, int b)
{
	return a + b;
}

int main()
{
	int i = add(1,2);
	return 0;
}
```

Ex6.15

> 说明find_char 函数中的三个形参为什么是现在的类型，特别说明为什么s是常量引用而occurs是普通引用？为什么s和occurs是引用类型而c不是？如果令s是普通引用会发生什么情况？如果令occurs是常量引用会发生什么情况？

* 因为字符串可能很长，因此使用引用避免拷贝；而在函数中我们不希望改变 s 的内容，所以令 s 为常量。
* occurs 是要传到函数外部的变量，所以使用引用，occurs 的值会改变，所以是普通引用。
* 因为我们只需要 c 的值，这个实参可能是右值(右值实参无法用于引用形参)，所以 c 不能用引用类型。
* 如果 s 是普通引用，也可能会意外改变原来字符串的内容。
* occurs 如果是常量引用，那么意味着不能改变它的值，那也就失去意义了。

Ex6.16

> 下面的这个函数虽然合法，但是不算特别有用。指出它的局限性并设法改善。
```cpp
bool is_empty(string& s) { return s.empty(); }
```

局限性在于**常量字符串**和**字符串字面值**无法作为该函数的实参，如果下面这样调用是非法的：
```cpp
const string str;
bool flag = is_empty(str); //非法
bool flag = is_empty("hello"); //非法
```
所以要将这个函数的形参定义为常量引用：
```cpp
bool is_empty(const string& s) { return s.empty(); }
```

## [ex6.17](ex6_17.cpp)

> 编写一个函数，判断string对象中是否含有大写字母。编写另一个函数，把string对象全部改写成小写形式。在这两个函数中你使用的形参类型相同吗？为什么？

两个函数的形参不一样。第一个函数使用常量引用，第二个函数使用普通引用。

Ex6.18

> 为下面的函数编写函数声明，从给定的名字中推测函数具备的功能。
* (a) 名为 compare 的函数，返回布尔值，两个参数都是 matrix 类的引用。 
* (b) 名为 change_val 的函数，返回vector<int>的迭代器，有两个参数：一个是int，另一个是vector<int>的迭代器。

```cpp
(a) bool compare(matrix &m1, matrix &m2);
(b) vector<int>::iterator change_val(int, vector<int>::iterator);
```

Ex6.19

> 假定有如下声明，判断哪个调用合法、哪个调用不合法。对于不合法的函数调用，说明原因。
```cpp
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
(a) calc(23.4, 55.1);
(b) count("abcda",'a');
(c) calc(66);
(d) sum(vec.begin(), vec.end(), 3.8);
```

* (a) 不合法。calc只有一个参数。
* (b) 合法。
* (c) 合法。
* (d) 合法。

Ex6.20

> 引用形参什么时候应该是常量引用？如果形参应该是常量引用，而我们将其设为了普通引用，会发生什么情况？

应该尽量将引用形参设为常量引用，除非有明确的目的是为了**改变**这个引用变量。如果形参应该是常量引用，而我们将其设为了普通引用，那么常量实参将无法作用于普通引用形参。

## [ex6.21](ex6_21.cpp)

> 编写一个函数，令其接受两个参数：一个是int型的数，另一个是int指针。函数比较int的值和指针所指的值，返回较大的那个。在该函数中指针的类型应该是什么？

应该是 `const int *` 类型。

## [ex6.22](ex6_22.cpp)

> 编写一个函数，令其交换两个int指针。

## [ex6.23](ex6_23.cpp)

> 参考本节介绍的几个print函数，根据理解编写你自己的版本。依次调用每个函数使其输入下面定义的i和j:
```cpp
int i = 0, j[2] = { 0, 1 };
```

Ex6.24

> 描述下面这个函数的行为。如果代码中存在问题，请指出并改正。
```cpp
void print(const int ia[10])
{
	for (size_t i = 0; i != 10; ++i)
		cout << ia[i] << endl;
}
```

当数组作为实参的时候，会被自动转换为指向首元素的指针。因此函数形参接受的是一个指针。如果要让这个代码成功运行，可以将实参改为数组的引用。
```cpp
void print(const int (&ia)[10])
{
	for (size_t i = 0; i != 10; ++i)
		cout << ia[i] << endl;
}
```

## [ex6.25](ex6_25.cpp)

> 编写一个main函数，令其接受两个实参。把实参的内容连接成一个string对象并输出出来。

## [ex6.26](ex6_25.cpp)

> 编写一个程序，使其接受本节所示的选项；输出传递给main函数的实参内容。

## [ex6.27](ex6_27.cpp)

> 编写一个函数，它的参数是initializer_list<int>类型的对象，函数的功能是计算列表中所有元素的和。

Ex6.28

> 在error_msg函数的第二个版本中包含ErrCode类型的参数，其中循环内的elem是什么类型？

`elem` 是 `const string &` 类型。

Ex6.29

> 在范围for循环中使用initializer_list对象时，应该将循环控制变量声明成引用类型吗？为什么？

应该使用**常量引用**类型。`initializer_list` 对象中的元素都是常量，我们无法修改`initializer_list` 对象中的元素的值。

Ex6.30

> 编译第200页的str_subrange函数，看看你的编译器是如何处理函数中的错误的。

错误信息（vs2013）：
> 错误  1 error C2561: “str_subrange”: 函数必须返回值  

Ex6.31

> 什么情况下返回的引用无效？什么情况下返回常量的引用无效？

当返回的引用的对象是局部变量时，返回的引用无效；当我们希望返回的对象被修改时，返回常量的引用无效。

Ex6.32

> 下面的函数合法吗？如果合法，说明其功能；如果不合法，修改其中的错误并解释原因。
```cpp
int &get(int *array, int index) { return array[index]; }
int main()
{
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
}
```

合法。get 函数根据索引取得数组中的元素的引用。

## [ex6.33](ex6_33.cpp)

> 编写一个递归函数，输出vector对象的内容。

Ex6.34

> 如果factorial 函数的停止条件如下所示，将发生什么？
```cpp
if (val != 0)
```

如果val为正数，从结果上来说没有区别（多乘了个 1）; 如果val为负数，那么递归永远不会结束。

Ex6.35

> 在调用factorial 函数时，为什么我们传入的值是 val-1 而非 val--？

如果传入的值是 val--，那么将会永远传入相同的值来调用该函数，递归将永远不会结束。

Ex6.36

> 编写一个函数声明，使其返回数组的引用并且该数组包含10个string对象。不用使用尾置返回类型、decltype或者类型别名。

```cpp
string (&fun())[10];
```

Ex6.37

> 为上一题的函数再写三个声明，一个使用类型别名，另一个使用尾置返回类型，最后一个使用decltype关键字。你觉得哪种形式最好？为什么？

```cpp
typedef string str_arr[10];
str_arr& fun();

auto fun()->string(&)[10];

string s[10];
decltype(s)& fun();
```
我觉得尾置返回类型最好。

Ex6.38

> 修改arrPtr函数，使其返回数组的引用。

```cpp
decltype(odd)& arrPtr(int i)
{
    return (i % 2) ? odd : even;
}
```

Ex6.39

> 说明在下面的每组声明中第二条语句是何含义。如果有非法的声明，请指出来。
```cpp
(a) int calc(int, int);
	int calc(const int, const int);
(b) int get();
	double get();
(c) int *reset(int *);
	double *reset(double *);
```

* (a) 非法。因为顶层const 不影响传入函数的对象，所以第二个声明无法与第一个声明区分开来。
* (b) 非法。对于重载的函数来说，它们应该只有形参的数量和形参的类型不同。返回值与重载无关。
* (c) 合法。

Ex6.40

> 下面的哪个声明是错误的？为什么？
```cpp
(a) int ff(int a, int b = 0, int c = 0);
(b) char *init(int ht = 24, int wd, char bckgrnd);		
```

* (a) 正确。
* (b) 错误。因为一旦某个形参被赋予了默认值，那么它之后的形参都必须要有默认值。

Ex6.41

> 下面的哪个调用是非法的？为什么？哪个调用虽然合法但显然与程序员的初衷不符？为什么？
```cpp
char *init(int ht, int wd = 80, char bckgrnd = ' ');
(a) init();
(b) init(24,10);
(c) init(14,'*');
```

* (a) 非法。第一个参数不是默认参数，最少需要一个实参。
* (b) 合法。
* (c) 合法，但与初衷不符。字符 `*` 被解释成 `int` 传入到了第二个参数。而初衷是要传给第三个参数。

## [ex6.42](ex6_42.cpp)

> 给make_plural函数的第二个形参赋予默认实参's', 利用新版本的函数输出单词success和failure的单数和复数形式。

Ex6.43

> 你会把下面的哪个声明和定义放在头文件中？哪个放在源文件中？为什么？
```cpp
(a) inline bool eq(const BigInt&, const BigInt&) {...}
(b) void putValues(int *arr, int size);
```

全部都放进头文件。(a) 是内联函数，(b) 是声明。

Ex6.44

> 将6.2.2节的isShorter函数改写成内联函数。

```cpp
inline bool is_shorter(const string &lft, const string &rht) 
{
    return lft.size() < rht.size();
}
```

Ex6.45

> 回顾在前面的exercise中你编写的那些函数，它们应该是内联函数吗？如果是，将它们改写成内联函数；如果不是，说明原因。

一般来说，内联机制用于优化规模小、流程直接、频繁调用的函数。

Ex6.46

> 能把isShorter函数定义成constexpr函数吗？如果能，将它改写成constxpre函数；如果不能，说明原因。

不能。constexpr函数的返回值类型及所有形参都得是字面值类型。

## [ex6.47](ex6_47.cpp)

> 改写6.3.2节exercise中使用递归输出vector内容的程序，使其有条件地输出与执行过程有关的信息。例如，每次调用时输出vector对象的大小。分别在打开和关闭调试器的情况下编译并执行这个程序。

Ex6.48

> 说明下面这个循环的含义，它对assert的使用合理吗？
```cpp
string s;
while (cin >> s && s != sought) { } //空函数体
assert(cin);
```

不合理。从这个程序的意图来看，应该用 
```cpp
assert(s == sought);
```

Ex6.49

> 什么是候选函数？什么是可行函数？

* **候选函数**：与被调用函数同名，并且其声明在调用点可见。
* **可行函数**：形参与实参的数量相等，并且每个实参类型与对应的形参类型相同或者能转换成形参的类型。

Ex6.50

> 已知有第217页对函数 f 的声明，对于下面的每一个调用列出可行函数。其中哪个函数是最佳匹配？如果调用不合法，是因为没有可匹配的函数还是因为调用具有二义性？
```cpp
(a) f(2.56, 42)
(b) f(42)
(c) f(42, 0)
(d) f(2.56, 3.14)
```

* (a) `void f(int, int);` 和 `void f(double, double = 3.14);` 是可行函数。该调用具有二义性而不合法。
* (b) `void f(int);` 是可行函数。调用合法。
* (c) `void f(int, int);` 和 `void f(double, double = 3.14);` 是可行函数。`void f(int, int);` 是最佳匹配。
* (d) `void f(int, int);` 和 `void f(double, double = 3.14);` 是可行函数。`void f(double, double = 3.14);` 是最佳匹配。

## [ex6.51](ex6_51.cpp)

> 编写函数f的4版本，令其各输出一条可以区分的消息。验证上一个exercise的答案，如果你的回答错了，反复研究本节内容直到你弄清自己错在何处。

Ex6.52

> 已知有如下声明：
```cpp
void manip(int ,int);
double dobj;
```
请指出下列调用中每个类型转换的等级。
```cpp
(a) manip('a', 'z');
(b) manip(55.4, dobj);
```

* (a) 第3级。类型提升实现的匹配。
* (b) 第4级。算术类型转换实现的匹配。

Ex6.53

> 说明下列每组声明中的第二条语句会产生什么影响，并指出哪些不合法（如果有的话）。
```cpp
(a) int calc(int&, int&); 
	int calc(const int&, const int&); 
(b) int calc(char*, char*);
	int calc(const char*, const char*);
(c) int calc(char*, char*);
	int calc(char* const, char* const);
```

(c) 不合法。顶层const不影响传入函数的对象。

Ex6.54

> 编写函数的声明，令其接受两个int形参并返回类型也是int；然后声明一个vector对象，令其元素是指向该函数的指针。

```cpp
int func(int, int);
vector<decltype(func)*> v;
```

Ex6.55

> 编写4个函数，分别对两个int值执行加、减、乘、除运算；在上一题创建的vector对象中保存指向这些函数的指针。

```cpp
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

v.push_back(add);
v.push_back(subtract);
v.push_back(multiply);
v.push_back(divide);
```

## [ex6.56](ex6_55.cpp)

> 调用上述vector对象中的每个元素并输出结果。