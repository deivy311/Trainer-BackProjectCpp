#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(int accountNumber, const std::string& accountHolderName, double initialBalance, double overdraftLimit)
    : BankAccount(accountNumber, accountHolderName, initialBalance), overdraftLimit(overdraftLimit) {}

void CheckingAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

bool CheckingAccount::withdraw(double amount) {
    if (amount <= balance + overdraftLimit) {
        balance -= amount;
        return true;
    }
    return false;
}

void CheckingAccount::displayAccountInfo() const {
    std::cout << "Checking Account [" << accountNumber << "]\n"
              << "Holder: " << accountHolderName << "\n"
              << "Balance: " << balance << "\n"
              << "Overdraft Limit: " << overdraftLimit << "\n";
}
