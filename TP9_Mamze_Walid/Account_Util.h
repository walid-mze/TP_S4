#ifndef ACCOUNT_UTIL_H
#define ACCOUNT_UTIL_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void display(const vector<T>& accounts) {
    cout << "==========================" << endl;
    for (const auto& account : accounts) {
        cout << account << endl;
    }
    cout << "==========================" << endl;
}

template <typename T>
void deposit(vector<T>& accounts, double amount) {
    cout << "==========================" << endl;
    cout << "Depositing " << amount << " to accounts" << endl;
    cout << "==========================" << endl;
    for (auto& account : accounts) {
        if (account.deposit(amount)) {
            cout << "Deposited " << amount << " to " << account << endl;
        } else {
            cout << "Failed to deposit " << amount << " to " << account << endl;
        }
    }
}

template <typename T>
void withdraw(vector<T>& accounts, double amount) {
    cout << "==========================" << endl;
    cout << "Withdrawing " << amount << " from accounts" << endl;
    cout << "==========================" << endl;
    for (auto& account : accounts) {
        if (account.withdraw(amount)) {
            cout << "Withdrew " << amount << " from " << account << endl;
        } else {
            cout << "Failed to withdraw " << amount << " from " << account << endl;
        }
    }
}

#endif // ACCOUNT_UTIL_H

