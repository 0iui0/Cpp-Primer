//
//  ex11_33.cpp
//  Exercise 11.33
//
//  Created by pezy on 12/18/14.
//
//  Implement your own version of the word-transformation program.

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using std::ifstream;
using std::string;

std::map<string, string> buildMap(ifstream &map_file) {
  std::map<string, string> trans_map;
  for (string key, value; map_file >> key && getline(map_file, value);)
    // 当一个转换规则的关键字多次出现的时候，使用下标运算符会保留最后一次添加的规则，而用insert则保留第一次添加的规则。
    if (value.size() > 1)
      trans_map[key] = value.substr(1).substr(0, value.find_last_not_of(' '));
  return trans_map;
}

const string &transform(const string &s, const std::map<string, string> &m) {
  auto map_it = m.find(s);
  return map_it == m.cend() ? s : map_it->second;
}

void word_transform(ifstream &map, ifstream &input) {
  auto trans_map = buildMap(map);
  for (string text; getline(input, text);) {
    std::istringstream iss(text);
    for (string word; iss >> word;)
      std::cout << transform(word, trans_map) << " ";
    std::cout << std::endl;
  }
}

int main() {
  ifstream ifs_map("../data/word_transformation_bad.txt"),
      ifs_content("../data/given_to_transform.txt");
  if (ifs_map && ifs_content)
    word_transform(ifs_map, ifs_content);
  else
    std::cerr << "can't find the documents." << std::endl;
}
