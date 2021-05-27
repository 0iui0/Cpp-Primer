#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  for (unsigned g; cin >> g;) {
    // conditional operators
    auto result = g > 90   ? "high pass"
                  : g < 60 ? "fail"
                  : g < 75 ? "low pass"
                           : "pass";
    cout << result << endl;

    // if statements
    if (g > 90)
      cout << "high pass";
    else if (g < 60)
      cout << "fail";
    else if (g < 75)
      cout << "low pass";
    else
      cout << "pass";
    cout << endl;
  }
  int i; double d; const string *ps; char *pc; void *pv;
  pv = (void*)ps; // pv = const_cast<string*>(ps); or pv = static_cast<void*>(const_cast<string*>(ps));
  pv=const_cast<string*>(ps);
  i = int(*pc);   // i = static_cast<int>(*pc);
  i=static_cast<int>(*pc);
  pv = &d;        // pv = static_cast<void*>(&d);
  pv = static_cast<void*>(&d);
  pc = (char*)pv; // pc = static_cast<char*>(pv);
  pc = static_cast<char*>(pv);
  return 0;
}
