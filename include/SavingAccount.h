#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H

#include "BankAccount.h"

class SavingAccount : public BankAccount {
    private:
        double interestRate;

    public:
        SavingAccount(int accNum, const std::string& holderName, double initialBalance, double interest);
        void deposit(double amount) override;
        bool withdraw(double amount) override;
        void displayAccountInfo() const override;
        void calculateInterest();
};

#endif