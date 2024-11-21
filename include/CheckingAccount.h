#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "BankAccount.h"

class CheckingAccount : public BankAccount{
    private:
        double overdraftLimit;
    
    public:
        CheckingAccount(int accNum, const std::string& holderName, double initialBalance, double overdraft);
        void deposit(double amount) override;
        bool withdraw(double amount) override;
        void displayAccountInfo() const override;
};

#endif