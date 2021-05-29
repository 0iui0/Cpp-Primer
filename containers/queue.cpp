//
// Created by iouoi on 2021/5/29.
//
#include "iostream"
#include "queue"

using namespace std;
//  | | | | | | | | |->
//  map--> 每一段八个元素，分段连续（让使用者感觉连续）；段和段直接怎么联系
// 由于它其实没有自己的元素，借用了dequeue，故称为adapter
int main() {
    long n = 10000000;
    char buf[10];
    queue<string> c;
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
    cout << "milli-seconds: " << clock() - start << endl;
    c.pop();
    cout << "c.size()" << c.size() << endl;
    cout << "c.front()" << c.front() << endl;
    cout << "c.back()" << c.back() << endl;
}