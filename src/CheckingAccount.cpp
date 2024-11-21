#include "CheckingAccount.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

CheckingAccount::CheckingAccount(int accNum, const std::string& holderName, double initialBalance, double limit)
    : BankAccount(accNum, holderName, initialBalance), overdraftLimit(limit) {}

void CheckingAccount::deposit(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Deposit amount must be greater than zero.");
    }
    balance += amount;
}

bool CheckingAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Withdraw amount must be greater than zero.");
    }
    if (balance - amount >= -overdraftLimit) {
        balance -= amount;
        return true;
    }
    return false;
}

void CheckingAccount::displayAccountInfo() const {
    std::cout << "Checking Account: " << accountNumber << "\n"
              << "Holder Name: " << accountHolderName << "\n"
              << "Balance: " << std::fixed << std::setprecision(2) << balance << "\n"
              << "Overdraft Limit: " << overdraftLimit << "\n";
}
