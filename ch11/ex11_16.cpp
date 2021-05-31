//
// Created on 2021/5/31.
//
#include "iostream"
#include "map"
#include "string"
using namespace std;
int main() {
  map<string, int> m1{{"good", 1}, {"girl", 2}, {"boy", 3}};

  map<string, int>::iterator it = m1.begin();
  while (it != m1.end()) {
    if ((*it).first == "good")
      (*it).second = 100;
    ++it;
  }

  for (auto &m : m1)
    cout << m.first << " " << m.second << " ";
  cout << endl;
  return 0;
}