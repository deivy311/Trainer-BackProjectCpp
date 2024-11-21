#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

SavingsAccount::SavingsAccount(int accNum, const std::string& holderName, double initialBalance, double rate)
    : BankAccount(accNum, holderName, initialBalance), interestRate(rate) {}

void SavingsAccount::deposit(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Deposit amount must be greater than zero.");
    }
    balance += amount;
}

bool SavingsAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Withdraw amount must be greater than zero.");
    }
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

void SavingsAccount::displayAccountInfo() const {
    std::cout << "Savings Account: " << accountNumber << "\n"
              << "Holder Name: " << accountHolderName << "\n"
              << "Balance: " << std::fixed << std::setprecision(2) << balance << "\n"
              << "Interest Rate: " << interestRate * 100 << "%\n";
}
