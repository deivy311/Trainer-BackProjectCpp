#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>

class BankAccount {
protected:
    int accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount(int accNum, const std::string& holderName, double initialBalance);
    virtual ~BankAccount() = default;

    virtual void deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void displayAccountInfo() const = 0;

    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
};

#endif // BANK_ACCOUNT_H
