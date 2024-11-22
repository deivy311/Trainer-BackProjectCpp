#include "CheckingAccount.h"
#include <iostream>

// Constructor
CheckingAccount::CheckingAccount(int accNum, const std::string& holderName, double initialBalance, double overdraftLimit)
    : BankAccount(accNum, holderName, initialBalance), overdraftLimit(overdraftLimit) {}

// Deposit money
void CheckingAccount::deposit(double amount) {
    if (amount < 0) {
        throw std::invalid_argument("Deposit amount cannot be negative.");
    }
    balance += amount;
}

bool CheckingAccount::withdraw(double amount) {
    if (amount < 0) {
        throw std::invalid_argument("Withdrawal amount cannot be negative.");
    }
    if (amount == 0) {
        return false; 
    }
    if (balance + overdraftLimit >= amount) {
        balance -= amount;
        return true;
    }
    return false; 
}
// Display account information
void CheckingAccount::displayAccountInfo() const {
    std::cout << "Checking Account [" << accountNumber << "]\n"
              << "Holder: " << accountHolderName << "\n"
              << "Balance: " << balance << "\n"
              << "Overdraft Limit: " << overdraftLimit << "\n";
}
