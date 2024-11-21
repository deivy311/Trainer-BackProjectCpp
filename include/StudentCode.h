#ifndef STUDENT_CODE_H
#define STUDENT_CODE_H

#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <vector>
#include <algorithm>

template <typename T>
void displayAccounts(const std::vector<T>& accounts) {
    for (const auto& account : accounts) {
        account.displayAccountInfo();
    }
}

template <typename T>
T findAccountWithHighestBalance(const std::vector<T>& accounts) {
    return *std::max_element(accounts.begin(), accounts.end(),
                             [](const T& a, const T& b) { return a.getBalance() < b.getBalance(); });
}

#endif // STUDENT_CODE_H
