#include "CheckingAccount.h"
#include <iostream>
#include <stdexcept>

// Constructor
CheckingAccount::CheckingAccount(int accountNumber, const std::string &accountHolderName, double initialBalance, double overdraftLimit)
    : BankAccount(accountNumber, accountHolderName, initialBalance), overdraftLimit(overdraftLimit) {}

// Deposit
void CheckingAccount::deposit(double amount_to_deposit)
{
    if (amount_to_deposit <= 0)
    {
        throw std::invalid_argument("\033[31mERROR!! You can't DEPOSIT less than or equal to 0.\033[0m");
    }
    balance += amount_to_deposit;
    std::cout << "\033[32mDeposit completed.\033[0m" << std::endl;
}

// Withdraw with overdraft limit logic
bool CheckingAccount::withdraw(double amount_to_withdraw)
{
    if (amount_to_withdraw <= 0)
    {
        throw std::invalid_argument("\033[31mERROR!! You can't WITHDRAW less than or equal to 0.\033[0m");
    }
    else if (amount_to_withdraw > (balance + overdraftLimit))
    {
        throw std::invalid_argument("\033[31mERROR!! You can't WITHDRAW more than the balance and overdraft limit.\033[0m");
    }
    balance -= amount_to_withdraw;
    std::cout << "\033[32mWithdraw completed.\033[0m" << std::endl;
    return true; // succeeded
}

// Display Account Info
void CheckingAccount::displayAccountInfo() const
{
    std::cout << "Account Number:      " << accountNumber << "\n"
              << "Account Holder Name: " << accountHolderName << "\n"
              << "Balance:             " << balance << " AED\n"
              << "Overdraft Limit:     " << overdraftLimit << " AED\n";
}
