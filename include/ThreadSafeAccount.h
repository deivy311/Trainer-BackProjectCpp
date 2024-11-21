#ifndef THREAD_SAFE_ACCOUNT_H
#define THREAD_SAFE_ACCOUNT_H

#include "BankAccount.h"
#include <mutex>

class ThreadSafeAccount : public BankAccount {
private:
    mutable std::mutex mtx; // `mutable` allows modification in const methods
public:
    using BankAccount::BankAccount;

    void deposit(double amount) override;
    bool withdraw(double amount) override;
    void displayAccountInfo() const override;
};

#endif // THREAD_SAFE_ACCOUNT_H
