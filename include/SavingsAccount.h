#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "BankAccount.h"


class SavingsAccount : public BankAccount {
    private:
    double interestRate;


    public:

    // Constructor
    SavingsAccount(int accNum, const std::string& holderName, double initialBalance, double interestRate);

    // Overridden methods
    void deposit(double amount) override;
    bool withdraw(double amount) override;
    void displayAccountInfo() const override;

    // Additional method to calculate interest
    void addInterest();

};


#endif 