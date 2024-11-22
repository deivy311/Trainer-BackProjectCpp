// Analytics.h
#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <vector>
#include <memory>
#include <numeric>

template <typename T>
class Analytics {
public:
    static double totalBalance(const std::vector<std::shared_ptr<T>>& accounts) {
        return std::accumulate(accounts.begin(), accounts.end(), 0.0,
                               [](double sum, const std::shared_ptr<T>& account) {
                                   return sum + account->getBalance();
                               });
    }

    static double averageBalance(const std::vector<std::shared_ptr<T>>& accounts) {
        if (accounts.empty()) return 0.0;
        return totalBalance(accounts) / accounts.size();
    }
};

#endif // ANALYTICS_H
