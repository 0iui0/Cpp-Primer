//
// Created by iouoi on 2021/5/29.
//
// sequence containers
#include "iostream"
#include "array"

using namespace std;

int compareLongs(const void *a, const void *b) {
    return (*(long *) a - *(long *) b);
}
const long asize = 50L;
int main() {
    array<long, asize> arr;
    for (int i = 0; i < asize; ++i) {
        arr[i] = rand();
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    ::qsort(arr.data(), asize, sizeof(long), compareLongs);
    for(auto &j:arr){
        cout<<j<<" ";
    }

}