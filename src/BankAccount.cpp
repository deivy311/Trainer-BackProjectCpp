// BankAccount.cpp
#include "BankAccount.h"

BankAccount::BankAccount(int accountNumber, const std::string& accountHolderName, double balance)
    : accountNumber(accountNumber), accountHolderName(accountHolderName), balance(balance) {}

BankAccount::~BankAccount() {}

int BankAccount::getAccountNumber() const {
    return accountNumber;
}

const std::string& BankAccount::getAccountHolderName() const {
    return accountHolderName;
}

double BankAccount::getBalance() const {
    return balance;
}
