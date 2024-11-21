#pragma once
#include <vector>
#include <algorithm>

template <typename T>
void sortAccountsByBalance(std::vector<T>& accounts) {
    std::sort(accounts.begin(), accounts.end(), [](const T& a, const T& b) {
        return a.getBalance() < b.getBalance();
    });
}
