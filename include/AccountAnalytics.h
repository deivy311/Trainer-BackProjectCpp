#ifndef ACCOUNTANALYTICS_H
#define ACCOUNTANALYTICS_H

#include <vector>
#include <algorithm>
#include <numeric>

// 2- Write a class template to create a generic analytics class for bank accounts.


// Class template for generic analytics
template <typename T>
class AccountAnalytics {

 
private:   // Encapsulation:The list of accounts is kept private to ensuring controlled access through public methods.
    std::vector<T*> accounts; //  a dynamic ist of account pointers T* (the data) so can store multiple accounts in one place

public:
    // Add an account to the analytics system
    void addAccount(T* account) {
        accounts.push_back(account);
    }

    // Calculate the total balance of all accounts
    double calculateTotalBalance() const {
        return std::accumulate(accounts.begin(), accounts.end(), 0.0, [](double total, T* account) {   //accumulate is a (STL) algorithm (calculate the total balance of accounts)
            return total + account->getBalance();
        });
    }

    // Find the account with the highest balance
    T* findHighestBalance() const {
        if (accounts.empty()) return nullptr; 
        return *std::max_element(accounts.begin(), accounts.end(), [](T* a, T* b) {    //max_element is a (STL) algorithm (find the account with the highest balance)
            return a->getBalance() < b->getBalance();
        });
    }
};

#endif // ACCOUNTANALYTICS_H



// This is implemented as a class template to work with any type derived from BankAccount (either saving or checking)
// lambda expression was used 
// provide methods to Add accounts to the analytics system/ Calculate the total balance across all accounts/ Find the account with the highest balance
// calculate total balance across all accounts, finds the account with the highest balance




