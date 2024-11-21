#include "CheckingAccount.h"
#include <iostream>

// Constructor Implementation
CheckingAccount::CheckingAccount(int accountNumber, const std::string& accountHolderName, double initialBalance, double overdraftLimit)
    : BankAccount(accountNumber, accountHolderName, initialBalance), overdraftLimit(overdraftLimit) {}

void CheckingAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount; // Add the amount to the balance
    } else {
        throw std::invalid_argument("Deposit amount must be positive."); // Handle invalid deposits
    }
}


bool CheckingAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Withdrawal amount must be positive."); // Handle invalid withdrawals
    }

    if (amount <= balance) {
        balance -= amount; // Deduct directly from balance
        return true;
    } else if (amount <= balance + overdraftLimit) {
        double overdraftUsed = amount - balance;
        balance = 0; // Fully use the balance
        overdraftLimit -= overdraftUsed; // Deduct the rest from overdraft limit
        return true;
    }

    return false; // Exceeds overdraft protection
}


void CheckingAccount::displayAccountInfo() const {
    std::cout << "Checking Account [" << accountNumber << "]\n"
              << "Holder: " << accountHolderName << "\n"
              << "Balance: " << balance << "\n"
              << "Overdraft Limit: " << overdraftLimit << "\n";
}
