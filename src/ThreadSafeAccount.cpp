#include "ThreadSafeAccount.h"
#include <iostream>

// Constructor
ThreadSafeAccount::ThreadSafeAccount(int accountNumber, const std::string& accountHolderName, double initialBalance)
    : BankAccount(accountNumber, accountHolderName, initialBalance) {}

// Deposit
void ThreadSafeAccount::deposit(double amount) {
    std::lock_guard<std::mutex> lock(mtx);
    if (amount > 0) {
        balance += amount;
    }
}

// Withdraw
bool ThreadSafeAccount::withdraw(double amount) {
    std::lock_guard<std::mutex> lock(mtx);
    if (amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

// Display Account Info
void ThreadSafeAccount::displayAccountInfo() const {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Thread-Safe Account [" << accountNumber << "]: " << accountHolderName
              << " | Balance: $" << balance << "\n";
}
