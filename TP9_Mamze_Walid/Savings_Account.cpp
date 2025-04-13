#include <iostream>
#include "Account.h"
#include "Savings_Account.h"
using namespace std;

Savings_Account::Savings_Account(std::string name, double balance, double int_rate) 
    : Account(name.c_str(), balance), int_rate(int_rate) { // Conversion std::string -> const char*
}

bool Savings_Account::deposit(double amount) {
    if (amount < 0) {
        cout << "Deposit amount must be positive" << endl;
        return false;
    }
    balance += amount + (amount * int_rate / 100);
    return true;
}

std::ostream& operator<<(std::ostream& os, const Savings_Account& sv_acc) {
    os << "[Savings Account: Name: " << sv_acc.name 
       << ", Balance: " << sv_acc.balance 
       << ", Interest Rate: " << sv_acc.int_rate << "%]";
    return os;
}