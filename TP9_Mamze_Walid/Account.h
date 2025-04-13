#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
using namespace std;

class Account {
private:
    static const char* def_name();
    static double def_balance();

protected: 
    const char* name;
    double balance;
    
public:
    Account(const char* name = def_name(), double balance = def_balance());
    bool deposit(double amount);
    bool withdraw(double amount);
    friend std::ostream& operator<<(std::ostream& os, const Account& account);

};

#endif // ACCOUNT_H