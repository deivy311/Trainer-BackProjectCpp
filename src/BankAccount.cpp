#include "BankAccount.h"

BankAccount::BankAccount(int accountNumber, const std::string& accountHolderName, double initialBalance)
    : accountNumber(accountNumber), accountHolderName(accountHolderName), balance(initialBalance) {}

BankAccount::~BankAccount() {}

double BankAccount::getBalance() const {
    return balance;
}
