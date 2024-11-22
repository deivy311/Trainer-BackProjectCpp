#include "CheckingAccount.h"
#include <iostream>

// Constructor
CheckingAccount::CheckingAccount(int accNum, const std::string& holderName, double initialBalance, double overdraftLimit)
    : BankAccount(accNum, holderName, initialBalance), overdraftLimit(overdraftLimit) {}

// Deposit money
void CheckingAccount::deposit(double amount) {
    if (amount > 0) { // Validate that the deposit amount is positive
        balance += amount;
    } else {
        throw std::invalid_argument("Deposit amount must be positive.");
    }
}

// Withdraw with overdraft protection
bool CheckingAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Withdrawal amount must be positive.");
    }

    if (balance - amount >= -overdraftLimit) {
        balance -= amount;
        return true; // Successful withdrawal
    }

    return false; // Exceeds overdraft limit
}
// Display account information
void CheckingAccount::displayAccountInfo() const {
    std::cout << "Checking Account [" << accountNumber << "]\n"
              << "Holder: " << accountHolderName << "\n"
              << "Balance: " << balance << "\n"
              << "Overdraft Limit: " << overdraftLimit << "\n";
}
