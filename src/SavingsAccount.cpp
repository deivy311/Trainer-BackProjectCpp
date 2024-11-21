// Implement your functions here.//

#include <string>
#include <iostream>

#include "StudentCode.h"  
#include "SavingsAccount.h"

// Inherits BankAccount attributes and behavior
SavingsAccount::SavingsAccount(int accNum, const std::string& holderName, double initialBalance, double rate)
    : BankAccount(accNum, holderName, initialBalance), interestRate(rate) {}

void SavingsAccount::deposit(double amount) {
    if (amount > 0) balance += amount; // Override with base class attribute (BankAccount)
}


bool SavingsAccount::withdraw(double amount) {   // this withdraw for Saving is the normal but for checking account we have the over draft concept
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true; // Specific withdrawal logic for savings accounts
    }
    return false;
}

void SavingsAccount::calculateInterest() {
    balance += (balance * interestRate / 100.0); // Interest calculation
}

void SavingsAccount::displayAccountInfo() const {
    std::cout << "Savings Account #" << accountNumber << "\n"
              << "Holder: " << accountHolderName << "\n"
              << "Balance: $" << balance << "\n"
              << "Interest Rate: " << interestRate << "%\n";
}



// Add interest rate attribute 
// Inheritance: SavingsAccount inherits from BankAccount using : public BankAccount + override the methods (deposit / withdraw / displayaccIfo).
// Encapsulation: Adds a private member interestRate specific to savings accounts
// Implements calculateInterest as a feature specific to savings accounts
