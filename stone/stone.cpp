//
// Created by iouoi on 2021/5/29.
//

#include "stone.h"
#include "iostream"

int main() {
    stone s1(1, 2, 6);
    stone s2(2, 5, 8);
    auto s3 = min(s1, s2);
    std::cout << s3.getWeigh() << std::endl;
    std::cout << (s1 < s2) << std::endl;
}