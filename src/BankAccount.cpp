#include "BankAccount.h"

// Constructor
BankAccount::BankAccount(int accountNumber, const std::string& accountHolderName, double initialBalance)
    : accountNumber(accountNumber), accountHolderName(accountHolderName), balance(initialBalance) {}

// Virtual Destructor
BankAccount::~BankAccount() {}

// Getter for Balance
double BankAccount::getBalance() const {
    return balance;
}
