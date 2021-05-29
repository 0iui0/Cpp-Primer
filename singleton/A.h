//
// Created by iouoi on 2021/5/29.
//

#ifndef CPP_PRIMER_A_H
#define CPP_PRIMER_A_H

#include "iostream"
class A {
public:
    static A &GetInstance();
    A() {
        std::cout<<"constructor" <<std::endl;
    }
    ~A(){
        std::cout<<"destructor"<<std::endl;
    }
};
A & A::GetInstance() {
    static A instance;
    return instance;
}

#endif //CPP_PRIMER_A_H
