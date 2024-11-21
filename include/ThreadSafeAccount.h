#ifndef THREADSAFEACCOUNT_H
#define THREADSAFEACCOUNT_H

#include <mutex>
#include "BankAccount.h"

class ThreadSafeAccount : public BankAccount {
private:
    mutable std::mutex mtx;

public:
    ThreadSafeAccount(int accountNumber, const std::string& accountHolderName, double initialBalance);
    void deposit(double amount) override;
    bool withdraw(double amount) override;
    void displayAccountInfo() const override;
};

#endif
