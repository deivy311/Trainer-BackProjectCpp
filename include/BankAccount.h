#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <iostream>


////////////////////////////////////////////////////////

class BankAccount {  //Abstract Base Class (to define the common attributes & behaviour / leave the implementatino to derived class)
protected:
// Attributes 
    int accountNumber;
    std::string accountHolderName;
    double balance;


public:
// here the goal of this (to define the pure virtual methods)

    // Constructor
    BankAccount(int accNum, const std::string& holderName, double initialBalance)
            : accountNumber(accNum), accountHolderName(holderName), balance(initialBalance) {}

    // Virtual destructor  (Ensures that the correct destructor is called for derived class objects when accessed via a BankAccount pointer)      
    virtual ~BankAccount() = default;  // Polymorphic behavior


    // Pure virtual methods = 0 (must be implemented by derived classes) so it "must" override them
    virtual void deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void displayAccountInfo() const = 0;

    double getBalance() const { return balance; }   // Encapsulation: Accessor
};

#endif // BANK_ACCOUNT_H



// Abstract classes: cannot be instantiated and are designed to act as a blueprint for derived classes
// Encapsulation: Attributes like accountNumber, accountHolderName, and balance are declared as "protected" to hide them from external access but allow derived classes to use them.
// Polymorphism: The "virtual" keyword ensures runtime polymorphism, enabling derived classes to "override" deposit, withdraw, and displayAccountInfo
