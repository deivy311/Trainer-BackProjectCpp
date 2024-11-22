#include "ThreadSafeAccount.h"
#include <iostream>

void ThreadSafeAccount::deposit(double amount) {
    std::lock_guard<std::mutex> lock(accountMutex);
    if (amount > 0) {
        balance += amount;
    }
}

bool ThreadSafeAccount::withdraw(double amount) {
    std::lock_guard<std::mutex> lock(accountMutex);
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

void ThreadSafeAccount::displayAccountInfo() const {
    std::lock_guard<std::mutex> lock(accountMutex);
    std::cout << "Thread-Safe Account\nAccount Number: " << accountNumber
              << "\nHolder Name: " << accountHolderName
              << "\nBalance: " << balance << "\n";
}
