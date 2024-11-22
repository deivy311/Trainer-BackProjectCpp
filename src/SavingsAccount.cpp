#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(int accNum, const std::string& holderName, double initialBalance, double interest)
    : BankAccount(accNum, holderName, initialBalance), interestRate(interest) {}

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
        throw std::invalid_argument("Withdrawal amount cannot be zero.");
    }
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false; // Insufficient balance.
}
void SavingsAccount::displayAccountInfo() const {
    std::cout << "Savings Account - " << accountNumber << " (" << accountHolderName << ")\n";
    std::cout << "Balance: $" << balance << ", Interest Rate: " << interestRate << "%\n";
}

void SavingsAccount::calculateInterest() {
    balance += balance * (interestRate / 100.0);
}
