// Print each number in the range specified by two integers.

#include <iostream>

void print_range(int lo, int hi);
using std::cin;
using std::cout;

int main() {
  int lo = 0, hi = 0;
  cout << "please input two number:\n";
  cin >> lo >> hi;
  print_range(lo, hi);
  return 0;
}

void print_range(int lo, int hi) {
  if (lo > hi) {
    print_range(hi, lo);
    return;
  }
  for (int i = lo; i <= hi; i++) {
    cout << i << " ";
  }
}
