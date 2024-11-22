// ThreadSafeAccount.cpp
#include "ThreadSafeAccount.h"
#include <utility>

ThreadSafeAccount::ThreadSafeAccount(std::shared_ptr<BankAccount> acc)
    : BankAccount(acc->getAccountNumber(), acc->getAccountHolderName(), acc->getBalance()),
      account(std::move(acc)) {}

void ThreadSafeAccount::deposit(double amount) {
    std::lock_guard<std::mutex> lock(mtx);
    account->deposit(amount);
}

bool ThreadSafeAccount::withdraw(double amount) {
    std::lock_guard<std::mutex> lock(mtx);
    return account->withdraw(amount);
}

void ThreadSafeAccount::displayAccountInfo() const {
    std::lock_guard<std::mutex> lock(mtx);
    account->displayAccountInfo();
}

int ThreadSafeAccount::getAccountNumber() const {
    std::lock_guard<std::mutex> lock(mtx);
    return account->getAccountNumber();
}

const std::string& ThreadSafeAccount::getAccountHolderName() const {
    std::lock_guard<std::mutex> lock(mtx);
    return account->getAccountHolderName();
}

double ThreadSafeAccount::getBalance() const {
    std::lock_guard<std::mutex> lock(mtx);
    return account->getBalance();
}
