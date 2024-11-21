#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(int accNum, const std::string& holderName, double initialBalance, double overdraft)
    : BankAccount(accNum, holderName, initialBalance), overdraftLimit(overdraft) {}

void CheckingAccount::deposit(double amount) {
        if (amount > 0) balance += amount;
    }

bool CheckingAccount::withdraw(double amount) {
    if (balance + overdraftLimit >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

void CheckingAccount::displayAccountInfo() const {
    std::cout << "Checking Account - " << accountNumber << " (" << accountHolderName << ")\n";
    std::cout << "Balance: $" << balance << ", Overdraft Limit: $" << overdraftLimit << "\n";
}
