//
// Created by iouoi on 2021/5/29.
//
// sequence containers
#include "iostream"
#include "deque"

using namespace std;
//  <-| | | | | | | | |->
//  map--> 每一段八个元素，分段连续（让使用者感觉连续）；段和段直接怎么联系
using namespace std;

int main() {
    long n = 10000000;
    char buf[10];
    deque<string> c;
    auto start = clock();
    for (long i = 0; i < n; ++i) {
        try {
            snprintf(buf, 10, "%d", rand());
            c.push_front(string(buf));
        } catch (exception &p) {
            cout << "i=" << i << " " << p.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds: " << clock() - start << endl;
    cout << "c.front()" << c.front() << endl;
    cout << "c.data()" << c.max_size() << endl;
}