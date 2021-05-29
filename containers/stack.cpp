//
// Created by iouoi on 2021/5/29.
//
#include "iostream"

#include "stack"

using namespace std;
//  | | | | | | | | |->
//  map--> 每一段八个元素，分段连续（让使用者感觉连续）；段和段直接怎么联系

int main() {
    long n = 10000000;
    char buf[10];
    stack<string> c;
    auto start = clock();
    for (long i = 0; i < n; ++i) {
        try {
            snprintf(buf, 10, "%d", rand());
            c.push(string(buf));
        } catch (exception &p) {
            cout << "i=" << i << " " << p.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds: " << clock() - start << endl;
    cout << "c.size()" << c.size() << endl;
}