//
//  ex11_32.cpp
//  Exercise 11.32
//
//  Created by pezy on 12/17/14.
//
//  Using the multimap from the previous exercise, write a program to print the
//  list of **authors and their works** alphabetically.

#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
  std::multimap<string, string> authors{
      {"alan", "DMA"}, {"pezy", "LeetCode"}, {"alan", "CLRS"},
      {"wang", "FTP"}, {"pezy", "CP5"},      {"wang", "CPP-Concurrency"}};
  std::map<string, std::multiset<string>> order_authors;
  for (auto author : authors) {
    order_authors[author.first].insert(author.second);
  }
  for (auto author : order_authors) {
    cout << author.first << ": ";
    for (auto book : author.second) {
      cout << book << " ";
    }
    cout << endl;
  }
}
