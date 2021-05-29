//
// Created by iouoi on 2021/5/29.
//
// sequence containers
#include "iostream"
#include "list"
// ->|<-|->|<-|->|<-|->|<-|->|<- 
// <-|->|<-|->|<-|->|<-|->|<-|->
using namespace std;

int main() {
    long n = 12;
    char buf[10];
    list<string> c;
    auto start = clock();
    for (long i = 0; i < n; ++i) {
        try {
            snprintf(buf, 10, "%d", rand());
            c.push_back(string(buf));
        } catch (exception &p) {
            cout << "i=" << i << " " << p.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds: " << clock() - start << endl;
    cout << "c.size()" << c.size() << endl;
    cout << "c.front()" << c.front() << endl;
    cout << "c.back()" << c.back() << endl;
    cout << "c.data()" << c.max_size() << endl;
}