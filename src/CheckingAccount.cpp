// CheckingAccount.cpp
#include "CheckingAccount.h"
#include <iostream>
#include <stdexcept>

CheckingAccount::CheckingAccount(int accountNumber, const std::string& accountHolderName, double balance, double overdraftLimit)
    : BankAccount(accountNumber, accountHolderName, balance), overdraftLimit(overdraftLimit) {}

void CheckingAccount::deposit(double amount) {
    // if (amount <= 0) {
    //     throw std::invalid_argument("Deposit amount must be positive.");
    // }
    balance += amount;
}

bool CheckingAccount::withdraw(double amount) {
    if (amount <= 0) {
        // throw std::invalid_argument("Withdrawal amount must be positive.");
             return false;

    }
    if (balance + overdraftLimit < amount) {
        // throw std::runtime_error("Overdraft limit exceeded.");
              return false;
    }
    balance -= amount;
    return true;
}

void CheckingAccount::displayAccountInfo() const {
    std::cout << "Checking Account Info:\n"
              << "Account Number: " << accountNumber << "\n"
              << "Account Holder: " << accountHolderName << "\n"
              << "Balance: $" << balance << "\n"
              << "Overdraft Limit: $" << overdraftLimit << "\n";
}

double CheckingAccount::getOverdraftLimit() const {
    return overdraftLimit;
}
