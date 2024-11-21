#include "SavingAccount.h"
#include <iostream>

SavingAccount::SavingAccount(int accNum, const std::string& holderName, double initialBalance, double interest)
    : BankAccount(accNum, holderName, initialBalance), interestRate(interest) {}

void SavingAccount::deposit(double amount) {
        if (amount > 0) balance += amount;
    }

bool SavingAccount::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

void SavingAccount::calculateInterest() {
    balance += balance * interestRate;
}

void SavingAccount::displayAccountInfo() const {
    std::cout << "Savings Account - " << accountNumber << " (" << accountHolderName << ")\n";
    std::cout << "Balance: $" << balance << ", Interest Rate: " << interestRate << "%\n";
}
