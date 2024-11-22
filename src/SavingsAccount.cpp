#include "SavingsAccount.h"
#include <iostream> // For std::cout and std::cerr

// Constructor: Initializes base class and specific attributes
SavingsAccount::SavingsAccount(int accNum, const std::string& holderName, double initialBalance, double interestRate)
    : BankAccount(accNum, holderName, initialBalance), interestRate(interestRate) {}

// Deposit: Adds money to the account
void SavingsAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount; // Updates balance (protected member)
        std::cout << "Savings Account: Deposited " << amount << ". New Balance: " << balance << "\n";
    } else {
        throw std::invalid_argument("Deposit amount must be positive."); // Error handling
    }
}

// Withdraw: Removes money from the account
bool SavingsAccount::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount; // Updates balance (protected member)
        std::cout << "Savings Account: Withdrew " << amount << ". Remaining Balance: " << balance << "\n";
        return true;
    } else {
        std::cerr << "Insufficient funds.\n";
        return false;
    }
}

// DisplayAccountInfo: Prints account details
void SavingsAccount::displayAccountInfo() const {
    std::cout << "Savings Account Number:" << accountNumber << "\n"
              << "Holder Name: " << accountHolderName << "\n"
              << "Balance: AED" << balance << "\n"
              << "Interest Rate: " << interestRate << "%\n";
}

// ApplyInterest: Adds interest to the balance
void SavingsAccount::applyInterest() {
    balance += (balance * interestRate / 100); // Calculates and adds interest
    std::cout << "Applied interest of " << interestRate << "%. New Balance is " << balance << "\n";
}
