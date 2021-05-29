#include <iostream>
#include "./complex.h"


int main() {
    complex<double> c1(1, 2);
    complex<double> c2(3, 4);
    cout << c1 << endl;
    cout << c2 << endl;
    cout << c1 + c2 << endl;
    cout << (c1 += c2) << endl;
    return 0;
}
