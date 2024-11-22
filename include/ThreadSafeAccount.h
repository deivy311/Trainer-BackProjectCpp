#ifndef THREADSAFEACCOUNT_H
#define THREADSAFEACCOUNT_H

#include "BankAccount.h"
#include <mutex>

class ThreadSafeAccount : public BankAccount {
private:
    mutable std::mutex accountMutex;

public:
    using BankAccount::BankAccount;

    void deposit(double amount) override;
    bool withdraw(double amount) override;
    void displayAccountInfo() const override;
};

#endif // THREADSAFEACCOUNT_H
