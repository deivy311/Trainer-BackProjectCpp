#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "BankAccount.h"

// Derived class representing a checking account
class CheckingAccount : public BankAccount {
private:
    double overdraftLimit; // Overdraft limit specific to checking accounts

public:
    CheckingAccount(int accNum, const std::string& holderName, double initialBalance, double overdraftLimit); // Constructor to set up checking account
    void deposit(double amount) override; 
    bool withdraw(double amount) override; 
    void displayAccountInfo() const override; 
};

#endif // CHECKING_ACCOUNT_H
