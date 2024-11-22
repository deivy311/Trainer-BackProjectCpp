// Implement your functions here.//

#include <string>
#include <iostream>

#include "StudentCode.h"  
#include "SavingsAccount.h"

// Inherits BankAccount attributes and behavior
SavingsAccount::SavingsAccount(int accNum, const std::string& holderName, double initialBalance, double rate)
    : BankAccount(accNum, holderName, initialBalance), interestRate(rate) {}

void SavingsAccount::deposit(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Deposit amount must be positive.");
    }
    balance += amount;
} // Override with base class attribute (BankAccount)



bool SavingsAccount::withdraw(double amount) {   // this withdraw for Saving is the normal but for checking account we have the over draft concept
    if (amount <= 0) {
        throw std::invalid_argument("Withdrawal amount must be positive.");
    }
    if (balance < amount) {
        return false; // Insufficient balance
    }
    balance -= amount;
    return true;
}

void SavingsAccount::applyInterest() {
    balance += (balance * interestRate / 100);
}


void SavingsAccount::displayAccountInfo() const {
    std::cout << "Savings Account Info:\n";
    std::cout << "Account Number: " << accountNumber << "\n";
    std::cout << "Account Holder: " << accountHolderName << "\n";
    std::cout << "Balance: " << balance << "\n";
    std::cout << "Interest Rate: " << interestRate << "%\n";
}



// Add interest rate attribute 
// Inheritance: SavingsAccount inherits from BankAccount using : public BankAccount + override the methods (deposit / withdraw / displayaccIfo).
// Encapsulation: Adds a private member interestRate specific to savings accounts
// Implements calculateInterest as a feature specific to savings accounts
