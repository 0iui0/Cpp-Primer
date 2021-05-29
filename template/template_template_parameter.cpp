//
// Created by iouoi on 2021/5/29.
//

#include "list"
#include "iostream"
#include "string"

using namespace std;

//template<这里typename和class共通 name> ；历史原因，早先没有typename关键字
template<typename T, template<typename> class Container>// container 拿第一个模版参数做参数  第二个T省略  //比如传入一个容器，并传入容器的类型
class XCla {
private:
    Container<T> c;
public:
    XCla() {
        for (long i = 0; i < 100; ++i)
            c.insert(c.end(), T());
    }
};

template<typename T>
using lst = list<T, allocator<T>>;

void test_template_template_parameters_1() {
    cout << "test_template_template_parameters_1()" << endl;

//!	XCls<string, list> mylist;
    //[Error] expected a template of type 'template<class T> class Container', got 'template<class _Tp, class _Alloc> class std::list'
    XCla<string, lst> mylist;        //容器又第二模版参数，第三模版参数
    XCla<int, lst> mylist2;        //容器又第二模版参数，第三模版参数

}

template<typename T, template<typename> class SmartPtr>
class XCls {
private:
    SmartPtr<T> sp;
public:
    XCls() : sp(new T) {}
};

void test_template_template_parameters_2() {
    cout << "test_template_template_parameters_2()" << endl;

    XCls<string, shared_ptr> p1;    //Note: make sure your environment support C++2.0
    XCls<double, auto_ptr> p4;
//!	XCls<double, unique_ptr> p2;  	//unique_ptr has two template parameters
//!	XCls<int, weak_ptr> p3;			//[Error] no matching function for call to 'std::weak_ptr<int>::weak_ptr(int*)'
}

int main() {
    test_template_template_parameters_1();
    test_template_template_parameters_2();
    return 0;
}

#include "stack"

//第二个不是一个模版模版参数
template<class T, class Sequence=deque<T>>
class stack {
protected:
    Sequence c;//底层容器
};