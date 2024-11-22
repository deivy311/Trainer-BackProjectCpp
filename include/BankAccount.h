#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>

// Base class using inheritance and abstract class concepts
class BankAccount {
protected: //  Encapsulation (protected so subclasses can use it)  
    int accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount(int accNum, const std::string& holderName, double initialBalance);     // Constructor to set up the account (initializer list)
    virtual ~BankAccount() = default;     // Virtual destructor: Ensures proper cleanup in derived classes (Polymorphism)

    // Pure virtual methods: Abstract class concept (Polymorphism)
    virtual void deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void displayAccountInfo() const = 0;

    double getBalance() const { return balance; }      // Getter: Encapsulation to provide controlled access
};

#endif // BANK_ACCOUNT_H
