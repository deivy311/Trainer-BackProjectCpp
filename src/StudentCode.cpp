// StudentCode.cpp
#include "StudentCode.h"
#include "AccountFactory.h"
#include <memory>

// Definition of template specializations

// Specialization for SavingsAccount
template <>
void processAccount<SavingsAccount>(const SavingsAccount& account) {
    std::cout << "Processing Savings Account with interest rate: " << account.getInterestRate() << "%\n";
}

// Specialization for CheckingAccount
template <>
void processAccount<CheckingAccount>(const CheckingAccount& account) {
    std::cout << "Processing Checking Account with overdraft limit: $" << account.getOverdraftLimit() << "\n";
}

void runBankingDemo() {
    auto savingsAccount = AccountFactory::createAccount(AccountType::SAVINGS, 1001, "John Doe", 5000.0);
    auto checkingAccount = AccountFactory::createAccount(AccountType::CHECKING, 1002, "Jane Smith", 3000.0);

    savingsAccount->displayAccountInfo();
    checkingAccount->displayAccountInfo();

    auto savingsPtr = std::dynamic_pointer_cast<SavingsAccount>(savingsAccount);
    if (savingsPtr) {
        processAccount(*savingsPtr);
    }

    auto checkingPtr = std::dynamic_pointer_cast<CheckingAccount>(checkingAccount);
    if (checkingPtr) {
        processAccount(*checkingPtr);
    }
}
