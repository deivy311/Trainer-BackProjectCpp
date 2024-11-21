#include "SavingsAccount.h"
#include "CheckingAccount.h"

int main() {
    // Polymorphism: Base class pointer pointing to derived objects
    BankAccount* savings = new SavingsAccount(101, "Alice", 500.0, 2.5);
    BankAccount* checking = new CheckingAccount(201, "Bob", 200.0, 100.0);

    // Savings account operations
    savings->deposit(100);
    dynamic_cast<SavingsAccount*>(savings)->calculateInterest(); // Specific to savings
    savings->displayAccountInfo();

    // Checking account operations
    checking->withdraw(300); // Overdraft allowed
    checking->displayAccountInfo();

    // Cleanup
    delete savings;
    delete checking;

    return 0;
}
