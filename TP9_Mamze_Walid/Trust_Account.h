#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H

#include <iostream>
#include "Savings_Account.h" // Hérite de Savings_Account
using namespace std;

class Trust_Account : public Savings_Account {
private:
    static constexpr double bonus_threshold = 5000.0;
    static constexpr int max_withdrawals = 3;
    static constexpr double max_withdraw_percent = 0.2;
    static constexpr double bonus_amount = 50.0;
    int num_withdrawals = 0;

public:
    Trust_Account(std::string name = "", double balance = 0.0, double int_rate = 0.0);
    bool deposit(double amount);
    bool withdraw(double amount);
    friend std::ostream& operator<<(std::ostream& os, const Trust_Account& tr_acc);
};

#endif // TRUST_ACCOUNT_H