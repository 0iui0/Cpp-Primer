//
// Created by iouoi on 2021/5/29.
//
#ifndef _COMPLEX_H
#define _COMPLEX_H

template<typename T>

class complex {
public:
    typedef T value_type;

    complex(T r = 0, T i = 0) : re(r), im(i) {};

    complex &operator+=(const complex &r);
    //结果是新创建的对象，return by value
//    complex operator+(const complex &x, const complex &y);

    // default inline
    T real() const { return re; }

    T imag() const { return im; }

private:
    T re, im;

    //do assignment plus
    friend complex &__doapl(complex *ths, const complex &r);
};

inline double imag(const complex<double> &x) {
    return x.imag();
}

inline double real(const complex<double> &x) {
    return x.real();
}

inline complex<double> &__doapl(complex<double> *ths, const complex<double> &r) {
    ths->re += r.re;
    ths->im += r.im;
    //传出去的人，不必知道接受端用什么形式接收
    return *ths;
}

// 右边加到左边，右边不动，const； 左边本来存在，不是local，所以传引用；建议inline
template<> inline complex<double> & complex<double>::operator+=(const complex<double> &r) {
    return __doapl(this, r);
}

inline complex<double> operator+(const complex<double> &x, const complex<double> &y) {
    //创建一个临时对象
    // return complex(real(x) + real(y), imag(x) + imag(y));
    return complex<double>(x.real() + y.real(), x.imag() + y.imag());
}

using namespace std;

// cout << c1 << endl; << 应该传回os 可以接受 endl
ostream &operator<<(ostream &os, const complex<double> &x) {
    return os << '(' << real(x) << ',' << imag(x) << ')';
};

#endif //_COMPLEX_H