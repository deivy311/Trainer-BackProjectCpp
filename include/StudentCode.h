#ifndef STUDENTCODE_H
#define STUDENTCODE_H

#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>

// Template function to sort accounts by balance
template <typename T>
void sortAccountsByBalance(std::vector<std::shared_ptr<T>>& accounts) {
    std::sort(accounts.begin(), accounts.end(), [](const std::shared_ptr<T>& a, const std::shared_ptr<T>& b) {
        return a->getBalance() < b->getBalance();
    });
}

// Template class for generic analytics
template <typename T>
class AccountAnalytics {
private:
    std::vector<std::shared_ptr<T>> accounts;

public:
    void addAccount(const std::shared_ptr<T>& account) {
        accounts.push_back(account);
    }

    double calculateTotalBalance() const {
        double total = 0.0;
        for (const auto& account : accounts) {
            total += account->getBalance();
        }
        return total;
    }

    void printAccounts() const {
        for (const auto& account : accounts) {
            account->displayAccountInfo();
            std::cout << "-----------------------------------\n";
        }
    }
};

// Declaration of helper functions to be implemented in StudentCode.cpp
std::shared_ptr<BankAccount> findAccountByNumber(const std::vector<std::shared_ptr<BankAccount>>& accounts, int accountNumber);
void printAccountsAboveBalance(const std::vector<std::shared_ptr<BankAccount>>& accounts, double threshold);

#endif // STUDENTCODE_H





















// #ifndef STUDENT_CODE_H
// #define STUDENT_CODE_H
// #include <vector>
// #include <algorithm>
// #include <BankAccount.h>

// // Add your derived classes and functions here.


// ///////////// Template /////////////

// // 1- Write a function template to implement reusable operations like sorting or searching accounts.


// // // Function template to ((sort accounts by a custom comparator))
// // template <typename T>
// // void sortAccounts(std::vector<T*>& accounts, bool (*comparator) (T*, T*)){   //Accepts a vector of pointers (*) to accounts and a custom comparator function
// //     std::sort(accounts.begin(), accounts.end(), comparator);  //to sort accounts based on the comparator
// // }
// // // If T is BankAccount, then T* is a pointer to a BankAccount object (BankAccount*)


// // Template function to sort accounts by balance
// template <typename T>
// void sortAccountsByBalance(std::vector<T>& accounts) {
//     std::sort(accounts.begin(), accounts.end(), [](const T& a, const T& b) {
//         return a->getBalance() < b->getBalance();
//     });
// }

// // ----------------------------

// // 2- Function template to ((search for a matching account by a predicate))
// // template <typename T>
// // T* searchAccount(std::vector<T*>& accounts, bool (*predicate)(T*)) {  //Accepts a vector of pointers (*) to accounts and a predicate 
// //     auto it = std::find_if(accounts.begin(), accounts.end(), predicate);
// //     return (it != accounts.end()) ? *it : nullptr;
// // }
// // This function searches for an account in a vector of accounts using a condition provided by a predicate function
// // a predicate is a function or callable object that takes one/+ argument and returns a boolean value (T/F)
// // in our case it checks a condition for each account in the vector and return T if the condition is satisfied 
// // T could be BankAcoount/SAvingAccount/CheckingAccount
// // A predicate can check if an account's balance is above a certain threshold
// // If it finds an account that satisfies the condition, it returns a pointer to that account. If no account satisfies the condition, it returns nullptr



// // ---------------------------------------------------------------------------------------------------------------------------------------------------------


// #endif // STUDENT_CODE_H
