// AccountFactory.cpp
#include "AccountFactory.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <stdexcept>
#include <memory>

std::shared_ptr<BankAccount> AccountFactory::createAccount(AccountType type, int accountNumber,
                                                           const std::string& accountHolderName,
                                                           double balance) {
    switch (type) {
        case AccountType::SAVINGS:
            return std::make_shared<SavingsAccount>(accountNumber, accountHolderName, balance, 2.0); // default interest rate
        case AccountType::CHECKING:
            return std::make_shared<CheckingAccount>(accountNumber, accountHolderName, balance, 500.0); // default overdraft limit
        default:
            throw std::invalid_argument("Invalid account type.");
    }
}
