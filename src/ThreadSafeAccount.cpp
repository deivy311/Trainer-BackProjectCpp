#include "ThreadSafeAccount.h"
#include <iostream>

ThreadSafeAccount::ThreadSafeAccount(int accNum, const std::string& holderName, double initialBalance)
    : BankAccount(accNum, holderName, initialBalance) {}

void ThreadSafeAccount::deposit(double amount) {
    std::lock_guard<std::mutex> lock(accountMutex);
    balance += amount;
}

bool ThreadSafeAccount::withdraw(double amount) {
    std::lock_guard<std::mutex> lock(accountMutex);
    if (amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

void ThreadSafeAccount::displayAccountInfo() const {
    std::lock_guard<std::mutex> lock(accountMutex);
    std::cout << "Thread-Safe Account Number" << accountNumber << "\n"
              << "Holder: " << accountHolderName << "\n"
              << "Balance: AED" << balance << "\n";
}
