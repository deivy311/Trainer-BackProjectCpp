// SavingsAccount.h
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "BankAccount.h"

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accountNumber, const std::string& accountHolderName, double balance, double interestRate);

    void deposit(double amount) override;
    bool withdraw(double amount) override;
    void displayAccountInfo() const override;

    void addInterest();
    double getInterestRate() const;
};

#endif // SAVINGSACCOUNT_H
