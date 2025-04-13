#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include <iostream>
#include <string>
#include "Account.h"

class Savings_Account: public Account {
private: 
    static constexpr double def_int_rate = 0.0; // Définition correcte d'une constante
public:
    double int_rate;

    Savings_Account(std::string name = "", double balance = 0.0, double int_rate = def_int_rate);

    bool deposit(double amount);

    friend std::ostream& operator<<(std::ostream& os, const Savings_Account& sv_acc);
};

#endif // SAVINGS_ACCOUNT_H