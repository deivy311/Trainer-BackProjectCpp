#include "SavingsAccount.h"
#include <iostream>

// Constructor
SavingsAccount::SavingsAccount(int accNum, const std::string& holderName, double initialBalance, double interestRate)
    : BankAccount(accNum, holderName, initialBalance), interestRate(interestRate) {}

void SavingsAccount::deposit(double amount) {
     if (amount < 0) {
        throw std::invalid_argument("Deposit amount cannot be negative.");
    }
    balance += amount;
}

bool SavingsAccount::withdraw(double amount) {
    if (amount < 0) {
        throw std::invalid_argument("Withdrawal amount cannot be negative.");
    }
    if (amount == 0) {
        return false;
    }
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false; // Insufficient balance.
}

// Display account information
void SavingsAccount::displayAccountInfo() const {
    std::cout << "Savings Account [" << accountNumber << "]\n"
              << "Holder: " << accountHolderName << "\n"
              << "Balance: " << balance << "\n"
              << "Interest Rate: " << interestRate << "%\n";
}

// Add interest to balance
void SavingsAccount::addInterest() {
    balance += balance * (interestRate / 100.0);
}
