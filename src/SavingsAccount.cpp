#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(int accountNumber, const std::string& accountHolderName, double initialBalance, double interestRate)
    : BankAccount(accountNumber, accountHolderName, initialBalance), interestRate(interestRate) {}

void SavingsAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount; // Add the amount to the balance
    } else {
        throw std::invalid_argument("Deposit amount must be positive."); // Handle invalid deposits
    }
}


bool SavingsAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Withdrawal amount must be positive."); // Handle invalid withdrawals
    }

    if (amount <= balance) {
        balance -= amount; // Deduct from balance
        return true;
    }

    return false; // Insufficient balance
}


void SavingsAccount::displayAccountInfo() const {
    std::cout << "Savings Account [" << accountNumber << "]\n"
              << "Holder: " << accountHolderName << "\n"
              << "Balance: " << balance << "\n"
              << "Interest Rate: " << interestRate << "%\n";
}

void SavingsAccount::applyInterest() {
    balance += (balance * interestRate / 100);
}
