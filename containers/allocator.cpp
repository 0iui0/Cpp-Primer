//
// Created by iouoi on 2021/5/30.
//

#include "iostream"

using namespace std;

int main() {
    int choice;
    long value;

    cout << "select: "
         << " (1) std::allocator "
         << " (2) malloc_allocator "
         << " (3) new_allocator "
         << " (4) __pool_alloc "
         << " (5) __mt_alloc "
         << " (6) bitmap_allocator ";

    cin >> choice;
    if (choice != 0) {
        cout << "how many elements: ";
        cin >> value;
    }

    char buf[10];
    clock_t timeStart = clock();
    for (long i = 0; i < value; ++i) {
        try {
            snprintf(buf, 10, "%d", i);
            switch (choice) {
                default:
                    break;
            }
        }
        catch (exception &p) {
            cout << "i=" << i << " " << p.what() << endl;
            abort();
        }
    }
    cout << "a lot of push_back(), milli-seconds : " << (clock() - timeStart) << endl;


//test all allocators' allocate() & deallocate();
    int *p;
    allocator<int> alloc1;
    p = alloc1.allocate(1);
    alloc1.deallocate(p, 1);

}
