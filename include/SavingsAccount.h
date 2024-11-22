#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "BankAccount.h"

class SavingsAccount : public BankAccount {
private:
    double interestRate; // Annual interest rate in percentage

public:
    SavingsAccount(int accNum, const std::string& holderName, double initialBalance, double rate);
    void deposit(double amount) override;
    bool withdraw(double amount) override;
    void displayAccountInfo() const override;
    void applyInterest(); // Specific to SavingsAccount
};

#endif // SAVINGSACCOUNT_H



// Inheritance: SavingsAccount inherits from BankAccount using : public BankAccount + override the methods
// Encapsulation: Adds a private member interestRate specific to savings accounts
// Implements calculateInterest as a feature specific to savings accounts
