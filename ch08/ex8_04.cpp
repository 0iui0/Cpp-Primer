//
//  ex8_04.cpp
//  Exercise 8.4
//
//  Created by pezy on 11/9/14.
//
//  @Brief  Write a function to open a file for input and read its contents into
//  a vector of strings,
//          storing each line as a separate element in the vector.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

void ReadFileToVec(const string &fileName, vector<string> &vec) {
  ifstream ifs(fileName);
  if (ifs) {
    string buf;
    while (std::getline(ifs, buf))
      vec.push_back(buf);
  }
}

int main() {
  vector<string> vec;
  ReadFileToVec("../data/letter.txt", vec);
  for (const auto &str : vec) {
    cout << str << endl;
  }
  return 0;
}
