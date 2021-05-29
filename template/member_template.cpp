//
// Created by iouoi on 2021/5/29.
//
#include <memory> //shared_ptr
#include "iostream"

template<class T1, class T2>
class pair {
public:
    typedef T1 first_type;
    typedef T2 second_type;

    T1 first;
    T2 second;

    pair() : first(T1()), second(T2()) {}

    pair(const T1 &a, const T2 &b) : first(a), second(b) {}

    //以下是模版里面的member，而它自己又是一个模版，故称为member tmplate
    template<class U1, class U2>
    pair(const pair<U1, U2> &p):first(p.first), second(p.second) {}//把初值的头尾当本身的头尾

};

class Base1 {
};

class Derived1 : public Base1 {
};

class Base2 {
};

class Derived2 : public Base2 {
};

int main() {
    std::cout << "test_member_template()" << std::endl;
    //子类pair
    pair<Derived1, Derived2> p;
    //父类pair
    pair<Base1, Base2> p0(p);//子类作为父类的初值
    // pair<Base1, Base2> p2(pair<Derived1, Derived2>());

    //shared_ptr 智能指针
    Base1 *ptr = new Derived1;    //up-cast 面向对象模型里，一般父类画在上面，子类在下面；子类转化为父类，call up-cast
    std::cout << ptr << std::endl;

    //template<typename _Tp>
    //class shared_ptr: public __shared_ptr<_Tp>{
    //    template<typename _Tpl>
    //    explicit shared_ptr(_Tpl* __p):__shared_ptr<_Tp>(__p){}
    // };
    // 既然上面的指针*ptr可以，那么下面的智能指针必须可以；所以智能指针写成上面的member template
    std::shared_ptr<Base1> sptr(new Derived1);    //simulate up-cast；模拟向上转型
    std::cout << sptr << std::endl;

}

