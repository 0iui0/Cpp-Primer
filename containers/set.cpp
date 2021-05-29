//
// Created by iouoi on 2021/5/29.
//
#include "iostream"
#include "set"

using namespace std;

string get_a_target_string() {
    long target = 0;
    char buf[10];

    cout << "target (0~" << RAND_MAX << "): ";
    cin >> target;
    snprintf(buf, 10, "%d", target);
    return string(buf);
}

int main() {

    set<string> c;
    char buf[10];

    clock_t timeStart = clock();
    for (long i = 0; i < 1000000; ++i) {
        try {
            snprintf(buf, 10, "%d", rand());
            c.insert(string(buf));
            c.insert(string(buf));
        }
        catch (exception &p) {
            cout << "i=" << i << " " << p.what() << endl;
            abort();
        }
    }
    cout << "milli-seconds : " << (clock() - timeStart) << endl;
    cout << "unordered_multiset.ASIZE()= " << c.size() << endl;
    cout << "unordered_multiset.max_size()= " << c.max_size() << endl;    //357913941

    string target = get_a_target_string();
    {
        timeStart = clock();
        auto pItem = find(c.begin(), c.end(), target);    //比 c.find(...) 慢很多
        cout << "std::find(), milli-seconds : " << (clock() - timeStart) << endl;
        if (pItem != c.end())
            cout << "found, " << *pItem << endl;
        else
            cout << "not found! " << endl;
    }

    {
        timeStart = clock();
        auto pItem = c.find(target);        //比 std::find(...) 快很多
        cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
        if (pItem != c.end())
            cout << "found, " << *pItem << endl;
        else
            cout << "not found! " << endl;
    }

}