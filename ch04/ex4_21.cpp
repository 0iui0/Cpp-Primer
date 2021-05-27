#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
  vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (auto i : ivec) {
    cout << ((i & 0x1) ? i * 2 : i) << " ";
  }
  // even
  //  cout << (9 & 0x1)<<endl ;
  short svalue = 32767;
  ++svalue; // -32768
  cout << endl << svalue << endl;

  unsigned uivalue = 0;
  --uivalue; // 4294967295
  cout << uivalue << endl;

  unsigned short usvalue = 65535;
  ++usvalue; // 0
  cout << usvalue << endl;

  const char *cp = "hello";
  cout << (*cp) << endl; // h
                         //  if (p = getPtr() != 0);
  return 0;
}
