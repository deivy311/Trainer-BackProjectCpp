#include "StudentCode.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "Templates.h"
#include "Analytics.h"
#include <iostream>
#include <vector>

void runBankingDemo() {
    // Create accounts
    SavingsAccount savings(1001, "Alice", 1000.0, 5.0); // 5% interest rate
    CheckingAccount checking(2001, "Bob", 500.0, 200.0); // $200 overdraft limit

    // Deposit and withdraw
    savings.deposit(200.0);
    checking.withdraw(600.0);

    // Display account info
    savings.displayAccountInfo();
    savings.applyInterest(); // Apply interest
    savings.displayAccountInfo();

    checking.displayAccountInfo();

    // Create a collection of accounts
    std::vector<SavingsAccount> accounts = {
        SavingsAccount(1002, "Charlie", 1500.0, 3.0),
        SavingsAccount(1003, "Diana", 2000.0, 4.0)
    };

    // Sort accounts by balance
    sortAccountsByBalance(accounts);

    // Display sorted accounts
    std::cout << "\nSorted Savings Accounts by Balance:\n";
    for (const auto& account : accounts) {
        account.displayAccountInfo();
    }

    // Use AccountAnalytics
    AccountAnalytics<SavingsAccount> analytics;
    analytics.addAccount(savings);
    for (const auto& account : accounts) {
        analytics.addAccount(account);
    }

    std::cout << "\nTotal Balance in Savings Accounts: " << analytics.calculateTotalBalance() << "\n";
}
