#pragma once
#include <string>

class BankAccount {
protected:
    int accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount(int accountNumber, const std::string& accountHolderName, double initialBalance);
    virtual ~BankAccount();

    virtual void deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void displayAccountInfo() const = 0;

    double getBalance() const;
};
