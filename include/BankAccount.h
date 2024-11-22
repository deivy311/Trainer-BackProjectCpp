// BankAccount.h
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
protected:
    int accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount(int accountNumber, const std::string& accountHolderName, double balance);
    virtual ~BankAccount();

    virtual void deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void displayAccountInfo() const = 0;

    virtual int getAccountNumber() const;
    virtual const std::string& getAccountHolderName() const;
    virtual double getBalance() const;
};

#endif // BANKACCOUNT_H
