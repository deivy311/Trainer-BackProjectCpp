#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(int accNum, const std::string& holderName, double initialBalance, double interest)
    : BankAccount(accNum, holderName, initialBalance), interestRate(interest) {}

void SavingsAccount::deposit(double amount) {
        if (amount > 0) balance += amount;
    }

bool SavingsAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

void SavingsAccount::calculateInterest() {
    balance += balance * interestRate;
}

void SavingsAccount::displayAccountInfo() const {
    std::cout << "Savings Account - " << accountNumber << " (" << accountHolderName << ")\n";
    std::cout << "Balance: $" << balance << ", Interest Rate: " << interestRate << "%\n";
}
