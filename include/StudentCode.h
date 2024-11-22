// StudentCode.h
#ifndef STUDENTCODE_H
#define STUDENTCODE_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "SavingsAccount.h"
#include "CheckingAccount.h"

// Function template to search for an account by account number
template <typename T>
std::shared_ptr<T> findAccountByNumber(const std::vector<std::shared_ptr<T>>& accounts, int accountNumber) {
    auto it = std::find_if(accounts.begin(), accounts.end(),
                           [accountNumber](const std::shared_ptr<T>& account) {
                               return account->getAccountNumber() == accountNumber;
                           });
    return (it != accounts.end()) ? *it : nullptr;
}

// General template
template <typename AccountType>
void processAccount(const AccountType& account) {
    std::cout << "Processing general account.\n";
}

// Declaration of specializations
template <>
void processAccount<SavingsAccount>(const SavingsAccount& account);

template <>
void processAccount<CheckingAccount>(const CheckingAccount& account);

// Declaration of runBankingDemo()
void runBankingDemo();

#endif // STUDENTCODE_H
