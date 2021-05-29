//
// Created by iouoi on 2021/5/30.
//
#include "iostream"

using namespace std;
#include <typeinfo>  //typeid()

template<typename T>
void output_static_data(const T &myStr) {
    cout << typeid(myStr).name() << " -- " << endl;
    cout << " CCtor=" << T::CCtor
         << " MCtor=" << T::MCtor
         << " CAsgn=" << T::CAsgn
         << " MAsgn=" << T::MAsgn
         << " Dtor=" << T::Dtor
         << " Ctor=" << T::Ctor
         << " DCtor=" << T::DCtor
         << endl;
}


template<typename M, typename NM>
void test_moveable(M c1, NM c2, long &value) {
    char buf[10];

    //測試 move
    cout << "\n\ntest, with moveable elements" << endl;
    typedef typename iterator_traits<typename M::iterator>::value_type V1type;
    clock_t timeStart = clock();
    for (long i = 0; i < value; ++i) {
        snprintf(buf, 10, "%d", rand());
        auto ite = c1.end();
        c1.insert(ite, V1type(buf));
    }
    cout << "construction, milli-seconds : " << (clock() - timeStart) << endl;
    cout << "ASIZE()= " << c1.size() << endl;
    output_static_data(*(c1.begin()));

    timeStart = clock();
    M c11(c1);
    cout << "copy, milli-seconds : " << (clock() - timeStart) << endl;

    timeStart = clock();
    M c12(std::move(c1));
    cout << "move copy, milli-seconds : " << (clock() - timeStart) << endl;

    timeStart = clock();
    c11.swap(c12);
    cout << "swap, milli-seconds : " << (clock() - timeStart) << endl;



    //測試 non-moveable
    cout << "\n\ntest, with non-moveable elements" << endl;
    typedef typename iterator_traits<typename NM::iterator>::value_type V2type;
    timeStart = clock();
    for (long i = 0; i < value; ++i) {
        snprintf(buf, 10, "%d", rand());
        auto ite = c2.end();
        c2.insert(ite, V2type(buf));
    }

    cout << "construction, milli-seconds : " << (clock() - timeStart) << endl;
    cout << "ASIZE()= " << c2.size() << endl;
    output_static_data(*(c2.begin()));

    timeStart = clock();
    NM c21(c2);
    cout << "copy, milli-seconds : " << (clock() - timeStart) << endl;

    timeStart = clock();
    NM c22(std::move(c2));
    cout << "move copy, milli-seconds : " << (clock() - timeStart) << endl;

    timeStart = clock();
    c21.swap(c22);
    cout << "swap, milli-seconds : " << (clock() - timeStart) << endl;
}