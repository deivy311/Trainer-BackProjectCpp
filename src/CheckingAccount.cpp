#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(int accountNumber, const std::string& accountHolderName, double initialBalance, double overdraftLimit)
    : BankAccount(accountNumber, accountHolderName, initialBalance), overdraftLimit(overdraftLimit) {}

void CheckingAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    } else {
        throw std::invalid_argument("Deposit amount must be positive.");
    }
}

bool CheckingAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Withdrawal amount must be positive.");
    }

    if (amount <= balance) {
        balance -= amount;
        return true;
    } else if (amount <= balance + overdraftLimit) {
        double overdraftUsed = amount - balance;
        balance = 0;
        overdraftLimit -= overdraftUsed;
        return true;
    }

    return false; // Exceeds overdraft limit
}

void CheckingAccount::displayAccountInfo() const {
    std::cout << "Checking Account [" << accountNumber << "]\n"
              << "Holder: " << accountHolderName << "\n"
              << "Balance: " << balance << "\n"
              << "Overdraft Limit: " << overdraftLimit << "\n";
}
