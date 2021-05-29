//
// Created by iouoi on 2021/5/29.
//
#include "iostream"
#include "map"
//底层是红黑树
// 这里key不重，multi开头的可以重复
using namespace std;

long get_a_target_long() {
    long target = 0;

    cout << "target (0~" << RAND_MAX << "): ";
    cin >> target;
    return target;
}


int main() {
    long n = 10000;
    char buf[10];
    map<long, string> c;
    auto start = clock();
    for (long i = 0; i < n; ++i) {
        try {
            snprintf(buf, 10, "%d", rand());
            c[i]=string(buf);
            c[i]=string(buf);
        } catch (exception &p) {
            cout << "i=" << i << " " << p.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds: " << clock() - start << endl;
    cout << "c.size()" << c.size() << endl;
    cout << "c.max_size()" << c.max_size() << endl;
    auto target = get_a_target_long();
    auto timeStart = clock();
    auto pItem = c.find(target);        //比 std::find(...) 快很多
    cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
    if (pItem != c.end())
        cout << "found, " << (*pItem).second << endl;
    else
        cout << "not found! " << endl;

}