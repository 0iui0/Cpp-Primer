#include <__bit_reference>
// Use a range for to change all the characters in a string to X.

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;
int main() {
  string str("a simple string");
  // for (char c : str) c = 'X';
  for (auto &c : str)
    c = 'X';
  cout << str << endl;
  string s;
  cout << s[0] << endl;
  vector<string> vector1(10, "null");
  cout << vector1[0] << endl;
  //  char st[11] = "fundamental";
  return 0;
}
