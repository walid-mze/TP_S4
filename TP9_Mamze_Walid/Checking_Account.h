#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

class Checking_Account: public Account {
private: 
    static constexpr double per_check_fee = 1.50;
public: 
    Checking_Account(string name = "", double balance = 0.0);
    bool withdraw(double amount);
    friend std::ostream& operator<<(std::ostream& os, const Checking_Account& check_acc);
};

#endif // CHECKING_ACCOUNT_H