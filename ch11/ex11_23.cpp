//
//  ex11_23.cpp
//  Exercise 11.23
//
//  Created by pezy on 12/16/14.
//
//  Rewrite the map that stored vectors of children’s names with a key that is
//  the family last name for the exercises in 11.2.1 (p. 424) to use a multimap.

#include <iostream>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::multimap;
using std::string;

int main() {
  multimap<string, string> families;
  for (string fname, lname; cin >> fname >> lname;
       families.emplace(lname, fname))
    ;
  for (auto const &name : families)
    cout << name.second << " " << name.first << endl;
}
