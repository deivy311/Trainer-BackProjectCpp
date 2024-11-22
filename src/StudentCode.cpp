#include "StudentCode.h"

// Implement your functions here.



#include "../include/StudentCode.h"
#include <stdexcept>

// Find an account by account number
std::shared_ptr<BankAccount> findAccountByNumber(const std::vector<std::shared_ptr<BankAccount>>& accounts, int accountNumber) {
    auto it = std::find_if(accounts.begin(), accounts.end(), [accountNumber](const std::shared_ptr<BankAccount>& account) {
        return account->getAccountNumber() == accountNumber;
    });

    if (it != accounts.end()) {
        return *it; // Return the found account
    }

    throw std::runtime_error("Account not found!");
}

// Print all accounts with a balance above a certain threshold
void printAccountsAboveBalance(const std::vector<std::shared_ptr<BankAccount>>& accounts, double threshold) {
    for (const auto& account : accounts) {
        if (account->getBalance() > threshold) {
            account->displayAccountInfo();
            std::cout << "-----------------------------------\n";
        }
    }
}






























// Functions used is template: 
//     - allows the same function to operate on different data types without rewriting it
//     - generic code ensures reusability and type safety
//     - here used to sort & search accounts based on criteria (from STL used std::sort & std::find_if  for searching)
//     - used lambda expression as well  for custom logic like comparing balances or searching by account holder name

