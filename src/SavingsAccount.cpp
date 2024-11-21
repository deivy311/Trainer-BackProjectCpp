#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(int accountNumber, const std::string& accountHolderName, double initialBalance, double interestRate)
    : BankAccount(accountNumber, accountHolderName, initialBalance), interestRate(interestRate) {}

void SavingsAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    } else {
        throw std::invalid_argument("Deposit amount must be positive.");
    }
}

bool SavingsAccount::withdraw(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Withdrawal amount must be positive.");
    }

    if (amount <= balance) {
        balance -= amount;
        return true;
    }

    return false; // Insufficient balance
}

void SavingsAccount::applyInterest() {
    balance += balance * (interestRate / 100.0);
}

void SavingsAccount::displayAccountInfo() const {
    std::cout << "Savings Account [" << accountNumber << "]\n"
              << "Holder: " << accountHolderName << "\n"
              << "Balance: " << balance << "\n"
              << "Interest Rate: " << interestRate << "%\n";
}
