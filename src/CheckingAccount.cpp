
#include <string>
#include <iostream>
#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(int accNum, const std::string& holderName, double initialBalance, double overdraft)
    : BankAccount(accNum, holderName,initialBalance ), overdraftLimit(overdraft) {}

// Inherits BankAccount attributes and behavior (implement the methods (deposit / withdraw with overdraft concept / and the display data))

void CheckingAccount::deposit(double amount) {
       if (amount <= 0) {
        throw std::invalid_argument("Deposit amount must be positive.");
    }
    balance += amount;
} // Override with base class attribute (BankAccount) -- remain the same
}

bool CheckingAccount::withdraw(double amount) { // this withdraw , for checking account we have the over draft concept
    if (amount <= 0) {
        throw std::invalid_argument("Withdrawal amount must be positive.");
    }
    if (balance - amount < -overdraftLimit) {
        return false; // Overdraft limit exceeded
    }
    balance -= amount;
    return true;
}

void CheckingAccount::displayAccountInfo() const {
    std::cout << "Checking Account Info:\n";
    std::cout << "Account Number: " << accountNumber << "\n";
    std::cout << "Account Holder: " << accountHolderName << "\n";
    std::cout << "Balance: " << balance << "\n";
    std::cout << "Overdraft Limit: " << overdraftLimit << "\n";
}


}



