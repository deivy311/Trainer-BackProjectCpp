#ifndef THREAD_SAFE_ACCOUNT_H
#define THREAD_SAFE_ACCOUNT_H

#include "BankAccount.h" // Base class BankAccount
#include <mutex>         // For std::mutex

// This class adds thread safety to BankAccount
class ThreadSafeAccount : public BankAccount {
private:
    mutable std::mutex accountMutex; // Mutex to lock the account during operations

public:
    // Constructor: Sets up account details
    ThreadSafeAccount(int accNum, const std::string& holderName, double initialBalance);

    // Deposits money into the account (thread-safe)
    void deposit(double amount) override;

    // Withdraws money from the account (thread-safe)
    bool withdraw(double amount) override;

    // Displays account details (thread-safe)
    void displayAccountInfo() const override;
};

#endif // THREAD_SAFE_ACCOUNT_H
