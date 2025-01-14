// @Yue Wang
//
// Exercise 6.44: Rewrite the isShorter function from § 6.2.2 (p. 211) to be
// inline.
//
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
inline bool is_shorter(const string &lft,
                       const string &rht) { // defining in the header is better.
  return lft.size() < rht.size();
}

int main() {
  cout << is_shorter("pezy", "mooophy") << endl;
  return 0;
}
