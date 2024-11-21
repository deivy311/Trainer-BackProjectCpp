#include "ThreadSafeAccount.h"
#include <iostream>
#include <mutex>

// Thread-safe deposit
void ThreadSafeAccount::deposit(double amount) {
    std::lock_guard<std::mutex> lock(mtx);
    balance += amount;
}

// Thread-safe withdraw
bool ThreadSafeAccount::withdraw(double amount) {
    std::lock_guard<std::mutex> lock(mtx);
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

// Thread-safe display
void ThreadSafeAccount::displayAccountInfo() const {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Thread-Safe Account [" << accountNumber << "]\n"
              << "Holder: " << accountHolderName << "\n"
              << "Balance: " << balance << "\n";
}
