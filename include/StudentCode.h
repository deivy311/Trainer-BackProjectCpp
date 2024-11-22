#ifndef STUDENT_CODE_H
#define STUDENT_CODE_H

#include <vector>     // To use std::vector
#include <memory>     // For std::shared_ptr
#include <algorithm>  // For std::sort
#include "BankAccount.h" // Base class BankAccount

// This function sorts accounts by balance in ascending order
template <typename T>
void sortAccounts(std::vector<std::shared_ptr<T>>& accounts) {
    // Sorting the accounts using std::sort
    std::sort(accounts.begin(), accounts.end(), [](const std::shared_ptr<T>& a, const std::shared_ptr<T>& b) {
        return a->getBalance() < b->getBalance(); // Compare balance of two accounts
    });
}

// This class analyzes a group of accounts
template <typename T>
class AccountAnalytics {
private:
    std::vector<std::shared_ptr<T>> accounts; // Holds all accounts

public:
    // Add an account to the list
    void addAccount(const std::shared_ptr<T>& account) {
        accounts.push_back(account); // Add account to the vector
    }

    // Calculate the total balance of all accounts
    double calculateTotalBalance() const {
        double total = 0; // Start with 0
        // Loop through all accounts and add their balances
        for (const auto& account : accounts) {
            total += account->getBalance();
        }
        return total; // Return the total balance
    }
};

#endif // STUDENT_CODE_H
