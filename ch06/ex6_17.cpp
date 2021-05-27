#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void to_lowercase(string &str) {
  for (auto &ch : str)
    ch = tolower(ch);
}
bool any_capital(string &s) {
  for (auto &chr : s) {
    if (isupper(chr))
      return true;
  }
  return false;
}
int main() {
  string hello("Hello World!");
  cout << any_capital(hello) << endl;

  to_lowercase(hello);
  cout << hello << endl;

  return 0;
}
