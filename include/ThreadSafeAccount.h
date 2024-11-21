#ifndef THREAD_SAFE_ACCOUNT_H
#define THREAD_SAFE_ACCOUNT_H

#include "BankAccount.h"
#include <mutex> // Needed for std::mutex

// Thread-Safe Wrapper for BankAccount
class ThreadSafeAccount : public BankAccount {
private:
    std::mutex mtx; // A mutex to protect shared data (balance)

public:
    // Inherit BankAccount's constructor
    using BankAccount::BankAccount;

    // Override deposit method
    void deposit(double amount) override {
        std::lock_guard<std::mutex> lock(mtx); // Lock the mutex for this block
        balance += amount; // Safely modify the balance
    }

    // Override withdraw method
    bool withdraw(double amount) override {
        std::lock_guard<std::mutex> lock(mtx); // Lock the mutex for this block
        if (balance >= amount) {
            balance -= amount; // Safely modify the balance
            return true;
        }
        return false; // Insufficient balance
    }

    // Override displayAccountInfo method
    void displayAccountInfo() const override {
        std::lock_guard<std::mutex> lock(mtx); // Lock the mutex for this block
        // Safely display account information
        std::cout << "Thread-Safe Account [" << accountNumber << "]\n"
                  << "Holder: " << accountHolderName << "\n"
                  << "Balance: " << balance << "\n";
    }
};

#endif // THREAD_SAFE_ACCOUNT_H
