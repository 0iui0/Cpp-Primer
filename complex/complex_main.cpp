#include <iostream>
#include "./complex.h"


int main() {
    complex c1(1, 2);
    complex c2(3, 4);
    cout << c1 << endl;
    cout << c2 << endl;
    cout << c1 + c2 << endl;
    cout << (c1 += c2) << endl;
    return 0;
}
