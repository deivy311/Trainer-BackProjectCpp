#include "BankAccount.h"

BankAccount::BankAccount(int accNum, const std::string& holderName, double initialBalance)
    : accountNumber(accNum), accountHolderName(holderName), balance(initialBalance) {}


int BankAccount::getAccountNumber() const {
    return accountNumber;
}

std::string BankAccount::getAccountHolderName() const {
    return accountHolderName;
}

double BankAccount::getBalance() const {
    return balance;
}

