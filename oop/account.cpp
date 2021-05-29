//
// Created by iouoi on 2021/5/29.
//

#include "account.h"

double Account::m_rate = 8.0;

int main() {
    Account::set_rate(5.);
    Account a;
    a.set_rate(7.);
}