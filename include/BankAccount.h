#pragma once
#include <string>

class BankAccount {
protected:
    int accountNumber;
    std::string accountHolderName;
    double balance;

public:
    // Constructor
    BankAccount(int accountNumber, const std::string& accountHolderName, double initialBalance);

    // Virtual Destructor
    virtual ~BankAccount();

    // Pure Virtual Methods (Abstract Methods)
    virtual void deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void displayAccountInfo() const = 0;

    // Getter for Balance
    double getBalance() const;
};
