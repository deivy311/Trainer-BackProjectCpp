#pragma once
#include "BankAccount.h"
#include <mutex>

class ThreadSafeAccount : public BankAccount {
private:
    mutable std::mutex mtx;

public:
    ThreadSafeAccount(int accountNumber, const std::string& accountHolderName, double initialBalance)
        : BankAccount(accountNumber, accountHolderName, initialBalance) {}

    void deposit(double amount) override;
    bool withdraw(double amount) override;
    void displayAccountInfo() const override;
};
