#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "BankAccount.h"
#include <iostream>

// A subclass for savings accounts
class SavingsAccount : public BankAccount {
private:
    double interestRate;    //extra for saving class 

public:

    SavingsAccount(int accNum, const std::string& holderName, double initialBalance, double interestRate);  // Constructor to set up savings account
    

    // Override virtual methods
    void deposit(double amount) override;
    bool withdraw(double amount) override;
    void displayAccountInfo() const override;

    // Additional method
    void applyInterest();
};

#endif // SAVINGS_ACCOUNT_H
