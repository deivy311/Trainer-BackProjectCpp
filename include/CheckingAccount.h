#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "BankAccount.h"

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    // Constructor
    CheckingAccount(int accNum, const std::string& holderName, double initialBalance, double overdraftLimit);

    // Overridden methods
    void deposit(double amount) override;
    bool withdraw(double amount) override;
    void displayAccountInfo() const override;
};

#endif // CHECKING_ACCOUNT_H
