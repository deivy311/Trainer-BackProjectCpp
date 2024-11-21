#include "SavingsAccount.h"
#include <iostream>

// Constructor
SavingsAccount::SavingsAccount(int accNum, const std::string& holderName, double initialBalance, double interestRate)
    : BankAccount(accNum, holderName, initialBalance), interestRate(interestRate) {}

// Deposit with interest
void SavingsAccount::deposit(double amount) {
    balance += amount;
    addInterest(); // Add interest after deposit
}

// Withdraw if balance is sufficient
bool SavingsAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false; // Insufficient balance
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
