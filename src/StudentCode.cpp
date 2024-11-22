#include "SavingsAccount.h"
#include "CheckingAccount.h"
// #include "ThreadSafeAccount.h"
#include <iostream>



// SavingsAccount Implementation
// SavingsAccount::SavingsAccount(int accNum, const std::string& holderName, double initialBalance, double interestRate)
//     : BankAccount(accNum, holderName, initialBalance), interestRate(interestRate) {}

// void SavingsAccount::deposit(double amount) {
//     if (amount > 0) {
//         balance += amount;
//     }
// }

// bool SavingsAccount::withdraw(double amount) {
//     if (amount > 0 && balance >= amount) {
//         balance -= amount;
//         return true;
//     }
//     return false;
// }

// void SavingsAccount::displayAccountInfo() const {
//     std::cout << "Savings Account - " << accountNumber << " (" << accountHolderName << ")\n";
//     std::cout << "Balance: $" << balance << ", Interest Rate: " << interestRate << "%\n";
// }

// void SavingsAccount::calculateInterest() {
//     balance += balance * (interestRate / 100.0);
// }

// // CheckingAccount Implementation
// CheckingAccount::CheckingAccount(int accNum, const std::string& holderName, double initialBalance, double overdraftLimit)
//     : BankAccount(accNum, holderName, initialBalance), overdraftLimit(overdraftLimit) {}

// void CheckingAccount::deposit(double amount) {
//     if (amount > 0) {
//         balance += amount;
//     }
// }

// bool CheckingAccount::withdraw(double amount) {
//     if (amount > 0 && balance + overdraftLimit >= amount) {
//         balance -= amount;
//         return true;
//     }
//     return false;
// }

// void CheckingAccount::displayAccountInfo() const {
//     std::cout << "Checking Account - " << accountNumber << " (" << accountHolderName << ")\n";
//     std::cout << "Balance: $" << balance << ", Overdraft Limit: $" << overdraftLimit << "\n";
// }

// // ThreadSafeAccount Implementation
// ThreadSafeAccount::ThreadSafeAccount(int accNum, const std::string& holderName, double initialBalance)
//     : BankAccount(accNum, holderName, initialBalance) {}

// void ThreadSafeAccount::deposit(double amount) {
//     std::lock_guard<std::mutex> lock(accountMutex);
//     if (amount > 0) {
//         balance += amount;
//     }
// }

// bool ThreadSafeAccount::withdraw(double amount) {
//     std::lock_guard<std::mutex> lock(accountMutex);
//     if (amount > 0 && balance >= amount) {
//         balance -= amount;
//         return true;
//     }
//     return false;
// }

// void ThreadSafeAccount::displayAccountInfo() const {
//     std::lock_guard<std::mutex> lock(accountMutex);
//     std::cout << "Thread-Safe Account - " << accountNumber << " (" << accountHolderName << ")\n";
//     std::cout << "Balance: $" << balance << "\n";
// }
