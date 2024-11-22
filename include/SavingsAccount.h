#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "BankAccount.h"

class SavingsAccount : public BankAccount {
private:
    double interestRate; // in percentage

public:
    SavingsAccount(int accNum, const std::string& holderName, double initialBalance, double rate);

    void deposit(double amount) override;
    bool withdraw(double amount) override;
    void displayAccountInfo() const override;

    void applyInterest();
};

#endif // SAVINGS_ACCOUNT_H
