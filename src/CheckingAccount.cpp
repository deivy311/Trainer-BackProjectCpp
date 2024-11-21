
#include <string>
#include <iostream>
#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(int accNum, const std::string& holderName, double initialBalance, double overdraft)
    : BankAccount(accNum, holderName,initialBalance ), overdraftLimit(overdraft) {}

// Inherits BankAccount attributes and behavior (implement the methods (deposit / withdraw with overdraft concept / and the display data))

void CheckingAccount::deposit(double amount) {
    if (amount > 0) balance += amount; // Override with base class attribute (BankAccount) -- remain the same
}

bool CheckingAccount::withdraw(double amount) { // this withdraw , for checking account we have the over draft concept
    if (amount > 0 && (balance - amount) >= -overdraftLimit) { // Allows overdraft
        balance -= amount;
        return true;// Specific withdrawal logic for checking accounts sspecifically (overdraft)
    }
    return false;
}

void CheckingAccount::displayAccountInfo() const {
    std::cout << "Savings Account #" << accountNumber << "\n"
              << "Holder: " << accountHolderName << "\n"
              << "Balance: $" << balance << "\n"
              << "Overdraft Limit: $" << overdraftLimit << "\n";


}



