#pragma once
#include "BankAccount.h"

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accountNumber, const std::string& accountHolderName, double initialBalance, double interestRate);

    void deposit(double amount) override;
    bool withdraw(double amount) override;
    void displayAccountInfo() const override;

    void applyInterest();
};
