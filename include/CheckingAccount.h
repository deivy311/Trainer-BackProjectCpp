#pragma once
#include "BankAccount.h"

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accountNumber, const std::string& accountHolderName, double initialBalance, double overdraftLimit);

    void deposit(double amount) override;
    bool withdraw(double amount) override;
    void displayAccountInfo() const override;

    double getOverdraftLimit() const { return overdraftLimit; }
};
