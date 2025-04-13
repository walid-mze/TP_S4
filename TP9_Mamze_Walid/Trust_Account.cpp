#include <iostream>
#include "Trust_Account.h"
#include "Savings_Account.h"
using namespace std;

Trust_Account::Trust_Account(std::string name, double balance, double int_rate) 
    : Savings_Account(name, balance, int_rate) {
}

bool Trust_Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        if (amount >= bonus_threshold) {
            balance += bonus_amount; 
        }
        return true;
    } 
    return false;
}

bool Trust_Account::withdraw(double amount) {
    if (num_withdrawals < max_withdrawals && amount <= balance * max_withdraw_percent) {
        balance -= amount;
        num_withdrawals++;
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Trust_Account& tr_acc) {
    os << "Trust Account: " << tr_acc.name 
       << ", Balance: " << tr_acc.balance 
       << ", Interest Rate: " << tr_acc.int_rate << "%, Withdrawals: " 
       << tr_acc.num_withdrawals;
    return os;
}

