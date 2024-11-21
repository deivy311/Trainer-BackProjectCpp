#pragma once
#include <vector>

template <typename T>
class AccountAnalytics {
private:
    std::vector<T> accounts;

public:
    void addAccount(const T& account) {
        accounts.push_back(account);
    }

    double calculateTotalBalance() const {
        double total = 0.0;
        for (const auto& account : accounts) {
            total += account.getBalance();
        }
        return total;
    }
};
