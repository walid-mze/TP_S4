#include <iostream>
#include "Account.h"
using namespace std;


const char* Account::def_name() {
    return "Unnamed Account";
}

double Account::def_balance() {
    return 0.0;
}

Account::Account(const char* name, double balance) : name{name}, balance{balance} {
}

bool Account::deposit(double amount) {
    if (amount < 0) {
        cout << "Deposit amount must be positive" << endl;
        return false;
    }
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        return true;
    } else {
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "[Account: Nom: " << account.name << ", Solde: " << account.balance << "]";
    return os;
}
