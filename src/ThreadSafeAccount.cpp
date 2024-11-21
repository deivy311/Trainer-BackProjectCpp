#include "ThreadSafeAccount.h"
#include <iostream>

void ThreadSafeAccount::deposit(double amount) {
    std::lock_guard<std::mutex> lock(mtx);
    if (amount > 0) {
        balance += amount;
    }
}

bool ThreadSafeAccount::withdraw(double amount) {
    std::lock_guard<std::mutex> lock(mtx);
    if (amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

void ThreadSafeAccount::displayAccountInfo() const {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Thread-Safe Account [" << accountNumber << "]\n"
              << "Holder: " << accountHolderName << "\n"
              << "Balance: " << balance << "\n";
}
