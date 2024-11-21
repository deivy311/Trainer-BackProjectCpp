#include "ThreadSafeAccount.h"

ThreadSafeAccount::ThreadSafeAccount(int accountNumber, const std::string& accountHolderName, double initialBalance)
    : BankAccount(accountNumber, accountHolderName, initialBalance) {}

void ThreadSafeAccount::deposit(double amount) {
    std::lock_guard<std::mutex> lock(mtx);
    if (amount > 0) {
        balance += amount;
    } else {
        throw std::invalid_argument("Deposit amount must be positive.");
    }
}

bool ThreadSafeAccount::withdraw(double amount) {
    std::lock_guard<std::mutex> lock(mtx);
    if (amount <= 0) {
        throw std::invalid_argument("Withdrawal amount must be positive.");
    }

    if (amount <= balance) {
        balance -= amount;
        return true;
    }

    return false; // Exceeds balance
}

void ThreadSafeAccount::displayAccountInfo() const {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Thread-Safe Account [" << accountNumber << "]\n"
              << "Holder: " << accountHolderName << "\n"
              << "Balance: " << balance << "\n";
}
