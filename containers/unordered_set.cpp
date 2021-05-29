//
// Created by iouoi on 2021/5/29.
//
// unordered containers
#include "iostream"
#include "unordered_set"

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

    unordered_set<string> c;
    char buf[10];

    clock_t timeStart = clock();
    for (long i = 0; i < 1000000; ++i) {
        try {
            snprintf(buf, 10, "%d", rand());
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
    cout << "unordered_multiset.bucket_count()= " << c.bucket_count() << endl;
    cout << "unordered_multiset.load_factor()= " << c.load_factor() << endl;
    cout << "unordered_multiset.max_load_factor()= " << c.max_load_factor() << endl;
    cout << "unordered_multiset.max_bucket_count()= " << c.max_bucket_count() << endl;
    for (unsigned i = 0; i < 20; ++i) {
        cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements.\n";
    }

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