#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(int accountNumber, const std::string& accountHolderName, double initialBalance, double interestRate)
    : BankAccount(accountNumber, accountHolderName, initialBalance), interestRate(interestRate) {}

void SavingsAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

bool SavingsAccount::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
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
