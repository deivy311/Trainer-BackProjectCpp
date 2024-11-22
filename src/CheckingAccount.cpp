#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(int accNum, const std::string& holderName, double initialBalance, double overdraft)
    : BankAccount(accNum, holderName, initialBalance), overdraftLimit(overdraft) {}

void CheckingAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    } else {
        std::cerr << "Cannot deposit a negative amount!" << std::endl;
    }
}

bool CheckingAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance + overdraftLimit) {
        balance -= amount;
        return true;
    } else {
        std::cerr << "Withdrawal exceeds overdraft limit or invalid amount!" << std::endl;
        return false;
    }
}

void CheckingAccount::displayAccountInfo() const {
    std::cout << "Checking Account #" << accountNumber << std::endl;
    std::cout << "Holder: " << accountHolderName << std::endl;
    std::cout << "Balance: $" << balance << std::endl;
    std::cout << "Overdraft Limit: $" << overdraftLimit << std::endl;
}
