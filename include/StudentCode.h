#ifndef STUDENT_CODE_H
#define STUDENT_CODE_H

// Add your derived classes and functions here.

#include <vector>
#include <algorithm>

//template function to sort accounts by balance

template<typename T>
void sortAccountsByBalance(std::vector<T>& accounts){
    std::sort(accounts.begin(),accounts.end(), [](const T& a, const T& b){
        return a->getBalance() < b->getBalance();
    });
}

// Template class for analytics
template <typename T>
class AccountAnalytics {
private:
    std::vector<T> accounts;

public:
    void addAccount(const T& account) {
        accounts.push_back(account);
    }

    double calculateTotalBalance() const {
        double total = 0;
        for (const auto& account : accounts) {
            total += account->getBalance();
        }
        return total;
    }
};

#endif // STUDENT_CODE_H
