// ThreadSafeAccount.h
#ifndef THREADSAFEACCOUNT_H
#define THREADSAFEACCOUNT_H

#include "BankAccount.h"
#include <mutex>
#include <memory>
#include <string>

class ThreadSafeAccount : public BankAccount {
private:
    std::shared_ptr<BankAccount> account;
    mutable std::mutex mtx;

public:
    ThreadSafeAccount(std::shared_ptr<BankAccount> account);

    void deposit(double amount) override;
    bool withdraw(double amount) override;
    void displayAccountInfo() const override;

    int getAccountNumber() const override;
    const std::string& getAccountHolderName() const override;
    double getBalance() const override;
};

#endif // THREADSAFEACCOUNT_H
