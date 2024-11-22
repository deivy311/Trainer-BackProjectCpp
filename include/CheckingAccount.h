#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "BankAccount.h"

class CheckingAccount : public BankAccount{
    
//specific to this class 
private:
    double overdraftLimit; // Overdraft feature specific for this Account type which is the Checking Account 

public: 

//constructor 
CheckingAccount(int accNum, const std::string& holderName, double initialBalance, double overdraft);

//override the inhereted methods from the base class (BankAccount)
    void deposit(double amount) override;
    bool withdraw(double amount) override;
    void displayAccountInfo() const override;

};


#endif // CHECKINGACCOUNT_H