#include <vector>
#include <algorithm>

// Function Template for Searching Accounts
template <typename T>
T* findAccount(const std::vector<T*>& accounts, int accountNumber) {
    auto it = std::find_if(accounts.begin(), accounts.end(), [accountNumber](T* account) {
        return account->getAccountNumber() == accountNumber;
    });
    return it != accounts.end() ? *it : nullptr;
}

// Class Template for Analytics
template <typename T>
class AccountAnalytics {
private:
    std::vector<T*> accounts;

public:
    void addAccount(T* account) { accounts.push_back(account); }
    double getTotalBalance() const {
        double total = 0.0;
        for (const auto& account : accounts) {
            total += account->getBalance();
        }
        return total;
    }
};
