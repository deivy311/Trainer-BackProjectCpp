// AccountCollection.h
#ifndef ACCOUNTCOLLECTION_H
#define ACCOUNTCOLLECTION_H

#include <vector>
#include <memory>
#include <mutex>
#include "BankAccount.h"

template <typename... Accounts>
class AccountCollection {
private:
    std::vector<std::shared_ptr<BankAccount>> accounts;

public:
    AccountCollection(std::shared_ptr<Accounts>... accs) {
        addAccounts(accs...);
    }

    template <typename Account>
    void addAccount(std::shared_ptr<Account> account) {
        accounts.push_back(account);
    }

    template <typename First, typename... Rest>
    void addAccounts(std::shared_ptr<First> first, std::shared_ptr<Rest>... rest) {
        addAccount(first);
        addAccounts(rest...);
    }

    void addAccounts() {} // Base case for recursion

    void displayAllAccounts() const {
        for (const auto& account : accounts) {
            account->displayAccountInfo();
        }
    }
};

#endif // ACCOUNTCOLLECTION_H
