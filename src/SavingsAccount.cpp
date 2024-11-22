// SavingsAccount.cpp
#include "SavingsAccount.h"
#include <iostream>
#include <stdexcept>

SavingsAccount::SavingsAccount(int accountNumber, const std::string& accountHolderName, double balance, double interestRate)
    : BankAccount(accountNumber, accountHolderName, balance), interestRate(interestRate) {}

void SavingsAccount::deposit(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Deposit amount must be positive.");
    }
    balance += amount;
}

bool SavingsAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Withdrawal amount must be positive.");
    }
    if (amount > balance) {
        throw std::runtime_error("Insufficient funds.");
    }
    balance -= amount;
    return true;
}

void SavingsAccount::displayAccountInfo() const {
    std::cout << "Savings Account Info:\n"
              << "Account Number: " << accountNumber << "\n"
              << "Account Holder: " << accountHolderName << "\n"
              << "Balance: $" << balance << "\n"
              << "Interest Rate: " << interestRate << "%\n";
}

void SavingsAccount::addInterest() {
    balance += balance * (interestRate / 100);
}

double SavingsAccount::getInterestRate() const {
    return interestRate;
}
