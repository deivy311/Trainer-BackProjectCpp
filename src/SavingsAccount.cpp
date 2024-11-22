#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(int accNum, const std::string& holderName, double initialBalance, double rate)
    : BankAccount(accNum, holderName, initialBalance), interestRate(rate) {}

void SavingsAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    } else {
        std::cerr << "Cannot deposit a negative amount!" << std::endl;
    }
}

bool SavingsAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    } else {
        std::cerr << "Insufficient balance or invalid amount!" << std::endl;
        return false;
    }
}

void SavingsAccount::displayAccountInfo() const {
    std::cout << "Savings Account #" << accountNumber << std::endl;
    std::cout << "Holder: " << accountHolderName << std::endl;
    std::cout << "Balance: $" << balance << std::endl;
    std::cout << "Interest Rate: " << interestRate << "%" << std::endl;
}

void SavingsAccount::applyInterest() {
    balance += balance * (interestRate / 100.0);
}
