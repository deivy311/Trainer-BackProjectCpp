#ifndef THREAD_SAFE_ACCOUNT_H
#define THREAD_SAFE_ACCOUNT_H

#include "BankAccount.h"
#include <mutex>

class ThreadSafeAccount : public BankAccount {
private:
    std::mutex mtx;

public:
    ThreadSafeAccount(int accNum, const std::string& holderName, double initialBalance)
        : BankAccount(accNum, holderName, initialBalance) {}

    void deposit(double amount) override {
        std::lock_guard<std::mutex> lock(mtx);
        balance += amount;
    }

    bool withdraw(double amount) override {
        std::lock_guard<std::mutex> lock(mtx);
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    void displayAccountInfo() const override {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Thread-Safe Account Info:\n"
                  << "Account Number: " << accountNumber << "\n"
                  << "Holder Name: " << accountHolderName << "\n"
                  << "Balance: " << balance << "\n";
    }
};

#endif // THREAD_SAFE_ACCOUNT_H

