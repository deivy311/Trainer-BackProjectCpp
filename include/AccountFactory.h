// AccountFactory.h
#ifndef ACCOUNTFACTORY_H
#define ACCOUNTFACTORY_H

#include "BankAccount.h"
#include <memory>
#include <string>

enum class AccountType {
    SAVINGS,
    CHECKING
};

class AccountFactory {
public:
    static std::shared_ptr<BankAccount> createAccount(AccountType type, int accountNumber,
                                                      const std::string& accountHolderName,
                                                      double balance);
};

#endif // ACCOUNTFACTORY_H
