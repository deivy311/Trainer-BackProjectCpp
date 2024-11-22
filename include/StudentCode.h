#ifndef STUDENT_CODE_H
#define STUDENT_CODE_H

#include <vector>
#include <algorithm>
#include "BankAccount.h"
#include <stdexcept>

// sortByBalance
template <typename T>
void sortByBalance(std::vector<T> &accounts)
{
    std::sort(accounts.begin(), accounts.end(), [](const T &a, const T &b)
              { return a.getBalance() < b.getBalance(); });
}

template <typename T>
class AccountAnalytics
{
public:
    // averageBalance
    double averageBalance(const std::vector<T> &accounts)
    {
        if (accounts.empty())
        {
            return 0.0;
        }
        double totalBalance = 0.0;
        for (const auto &account : accounts)
        {
            totalBalance += account.getBalance();
        }
        return totalBalance / accounts.size();
    }

    // highestBalance
    T highestBalance(const std::vector<T> &accounts)
    {
        if (accounts.empty())
        {
            throw std::runtime_error("There are no accounts");
        }
        return *std::max_element(accounts.begin(), accounts.end(), [](const T &a, const T &b)
                                 { return a.getBalance() < b.getBalance(); });
    }
};

#endif // STUDENT_CODE_H
