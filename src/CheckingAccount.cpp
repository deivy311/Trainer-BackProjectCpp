#include "CheckingAccount.h"
#include <iostream>

// Constructor
CheckingAccount::CheckingAccount(int accNum, const std::string& holderName, double initialBalance, double overdraftLimit)
    : BankAccount(accNum, holderName, initialBalance), overdraftLimit(overdraftLimit) {}

// Deposit money
void CheckingAccount::deposit(double amount) {
    balance += amount;
}

// Withdraw with overdraft protection
bool CheckingAccount::withdraw(double amount) {
    if (balance - amount >= -overdraftLimit) {
        balance -= amount;
        return true;
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
