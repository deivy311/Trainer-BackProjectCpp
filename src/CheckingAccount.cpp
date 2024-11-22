#include "CheckingAccount.h"
#include <iostream> // For std::cout and std::cerr

// Constructor: Initializes base class and specific attributes
CheckingAccount::CheckingAccount(int accNum, const std::string& holderName, double initialBalance, double overdraftLimit)
    : BankAccount(accNum, holderName, initialBalance), overdraftLimit(overdraftLimit) {}

// Deposit: Adds money to the account
void CheckingAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount; // Updates balance (protected member)
        std::cout << "Checking Account: Deposited " << amount << ". New Balance: " << balance << "\n";
    } else {
        throw std::invalid_argument("Deposit amount must be positive."); // Error handling
    }
}

// Withdraw: Removes money from the account, considering overdraft limit
bool CheckingAccount::withdraw(double amount) {
    if (amount <= balance + overdraftLimit) {
        balance -= amount; // Updates balance (protected member)
        std::cout << "Checking Account: Withdrew " << amount << ". Remaining Balance: " << balance << "\n";
        return true;
    } else {
        std::cerr << "Exceeded overdraft limit.\n";
        return false;
    }
}

// DisplayAccountInfo: Prints account details
void CheckingAccount::displayAccountInfo() const {
    std::cout << "Checking Account Number: " << accountNumber << "\n"
              << "Holder Name: " << accountHolderName << "\n"
              << "Balance: AED" << balance << "\n"
              << "Overdraft Limit: " << overdraftLimit << "\n";
}
