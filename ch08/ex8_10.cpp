//
//  ex8_10.cpp
//  Exercise 8.10
//
//  Created by pezy on 11/29/14.
//
//  @Brief  Write a program to store each line from a file in a vector<string>.
//          Now use an istringstream to read each element from the vector a word
//          at a time.

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

int main() {
  ifstream ifs("../data/book.txt");
  if (!ifs) {
    cerr << "No data?" << endl;
    return -1;
  }

  vector<string> vecLine;
  string line;
  while (getline(ifs, line))
    vecLine.push_back(line);

  for (auto &s : vecLine) {
    istringstream iss(s);
    string word;
    while (iss >> word)
      cout << word << endl;
  }

  return 0;
}
