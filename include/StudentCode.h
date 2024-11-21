#ifndef STUDENTCODE_H
#define STUDENTCODE_H

#include <vector>
#include <algorithm>

// Function Template
template <typename T>
void sortAccountsByBalance(std::vector<T>& accounts) {
    std::sort(accounts.begin(), accounts.end(), [](const T& a, const T& b) {
        return a.getBalance() < b.getBalance();
    });
}

#endif
