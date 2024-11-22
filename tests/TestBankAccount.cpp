// TestBankAccount.cpp
#include <iostream>
#include <thread>
#include "ThreadSafeAccount.h"
#include "AccountFactory.h"

void performTransactions(ThreadSafeAccount& account) {
    try {
        account.deposit(100.0);
        account.withdraw(50.0);
        account.deposit(200.0);
        account.withdraw(150.0);
    } catch (const std::exception& e) {
        std::cerr << "Transaction error: " << e.what() << "\n";
    }
}

int main() {
    auto account = AccountFactory::createAccount(AccountType::SAVINGS, 12345, "Alice", 1000.0);
    ThreadSafeAccount tsAccount(account);  // Pass shared_ptr directly

    std::thread t1(performTransactions, std::ref(tsAccount));
    std::thread t2(performTransactions, std::ref(tsAccount));
    std::thread t3(performTransactions, std::ref(tsAccount));

    t1.join();
    t2.join();
    t3.join();

    tsAccount.displayAccountInfo();

    return 0;
}
