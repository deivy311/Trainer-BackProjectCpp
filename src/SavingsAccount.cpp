#include "SavingsAccount.h"
#include <iostream>
#include <stdexcept>

// Constructor for SavingsAccount
SavingsAccount::SavingsAccount(int accountNumber, const std::string &accountHolderName, double initialBalance, double interestRate)
    : BankAccount(accountNumber, accountHolderName, initialBalance), interestRate(interestRate) {}

// Deposit
void SavingsAccount::deposit(double amount_to_deposit)
{
    if (amount_to_deposit <= 0)
    {
        throw std::invalid_argument("\033[31mERROR!! You can't DEPOSIT less than or equal to 0.\033[0m");
    }
    balance += amount_to_deposit;
    std::cout << "\033[32mDeposit completed.\033[0m" << std::endl;
}

// Withdraw
bool SavingsAccount::withdraw(double amount_to_withdraw)
{
    if (amount_to_withdraw <= 0)
    {
        throw std::invalid_argument("\033[31mERROR!! You can't WITHDRAW less than or equal to 0.\033[0m");
    }
    else if (amount_to_withdraw > balance)
    {
        throw std::invalid_argument("\033[31mERROR!! There is not enough money to withdraw.\033[0m");
    }
    balance -= amount_to_withdraw;
    std::cout << "\033[32mWithdraw completed.\033[0m" << std::endl;
    return true; // succeeded
}

// Display Account Info
void SavingsAccount::displayAccountInfo() const
{
    std::cout << "Account Number:      " << accountNumber << "\n"
              << "Account Holder Name: " << accountHolderName << "\n"
              << "Balance:             " << balance << " AED\n"
              << "Interest Rate:       " << interestRate << "%\n";
}

// Apply Interest
void SavingsAccount::applyInterest()
{
    if (balance > 0)
    {
        double interest = balance * (interestRate / 100.0);
        balance += interest;
        std::cout << "\033[32mInterest applied: " << interest << " AED\033[0m" << std::endl;
    }
}
