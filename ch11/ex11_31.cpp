//
//  ex11_31.cpp
//  Exercise 11.31
//
//  Created by pezy on 12/17/14.
//
//  Write a program that defines a multimap of authors and their works.
//  Use **find** to find **an element** in the multimap and erase that element.
//  Be sure your program works correctly if the element you look for is not in
//  the map.

#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
  std::multimap<string, string> authors{
      {"alan", "DMA"}, {"pezy", "LeetCode"}, {"alan", "CLRS"},
      {"wang", "FTP"}, {"pezy", "CP5"},      {"wang", "CPP-Concurrency"}};
  // want to delete an element that author is [Alan], work is [112].
  string author = "wang";
  string work = "FTP";

  auto found = authors.find(author);
  auto count = authors.count(author);
  cout << "found:" << count << endl;
  //  authors.erase(++found);
  while (count) {
    cout << found->second << endl;
    if (found->second == work) {
      authors.erase(found);
      break;
    }
    --count;
    ++found;
  }
  for (const auto &author : authors)
    std::cout << author.first << " " << author.second << std::endl;
}
