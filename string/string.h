//
// Created by iouoi on 2021/5/29.
//

#ifndef CPP_PRIMER_STRING_H
#define CPP_PRIMER_STRING_H

class String;

class String {
public:
    String(const char *cstr = 0);

    // copy construct;拷贝构造，以str为蓝本
    String(const String &str);

    // op construct;拷贝赋值，来源端拷贝到目的端
    String &operator=(const String &str);

    //deconstruct;
    ~String();

    char *get_c_str() const { return m_data; }

private:
    // big three; class with pointer member;
    char *m_data;
};

#include <cstring>

inline String::String(const char *cstr) {
    //分配足够大的空间
    if (cstr) {
        //这里用了array new；下面也要array delete
        m_data = new char[strlen(cstr) + 1];
        //传进来的初值cstr的内容，赋给m_data;
        strcpy(m_data, cstr);
    } else {//未指定初值
        m_data = new char[1];
        *m_data = '\0';
    }
};

String::~String() {
    //把使用的资源释放，这里开了一块空间; array delete
    delete[]  m_data;
}

//拷贝构造函数没有返回类型
inline String::String(const String &str) {
    //新东西
    m_data = new char[strlen(str.m_data) + 1];
    //内容拷贝过去
    strcpy(m_data, str.m_data);
}

//赋值构造
inline String &String::operator=(const String &str) {
    //如果两个相等，不用做
    // String &str 放在type后面是reference
    // &str 放在object前面，是取地址 address of
    if (this == &str) {
        return *this;
    }

    //目的端，要先把自己delete
    delete[] m_data;
    //重新分配够大的空间
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    //如果不返回this而是void，连串赋值就不行
    //传出去的东西，不用关注接收的by ref
    return *this;
}

#include "iostream"

using namespace std;

inline ostream &operator<<(ostream &os, const String &str) {
    return os << str.get_c_str();
}

#endif //CPP_PRIMER_STRING_H
