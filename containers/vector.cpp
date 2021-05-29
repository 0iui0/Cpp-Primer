//
// Created by iouoi on 2021/5/29.
//
// sequence containers
#include "iostream"
#include "vector"
#include "ctime"

using namespace std;

int main() {
    long n = 12;
    char buf[10];
    vector<string> v;
    auto start = clock();
    for (long i = 0; i < n; ++i) {
        try {
            snprintf(buf, 10, "%d", rand());
            v.push_back(string(buf));
        } catch (exception &p) {
            cout << "i=" << i << " " << p.what() << endl;
            abort();

        }
    }
    cout << "milli-seconds: " << clock() - start << endl;
    cout << "v.size()" << v.size() << endl;
    cout << "v.front()" << v.front() << endl;
    cout << "v.back()" << v.back() << endl;
    cout << "v.data()" << v.data() << endl;
    cout << "v.capacity()" << v.capacity() << endl;


}