#include "Checking_Account.h"
#include "Account.h"
#include <iostream>
using namespace std;

Checking_Account::Checking_Account(string name, double balance) 
    : Account(name.c_str(), balance) { // Conversion de std::string en const char*
}

bool Checking_Account::withdraw(double amount) {
    if (amount + per_check_fee <= balance) {
        balance -= (amount + per_check_fee);
        return true;
    } else {
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Checking_Account& check_acc) {
    os << "Checking Account: " << check_acc.name << " Balance: " << check_acc.balance;
    return os;
}