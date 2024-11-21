#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H



#include "BankAccount.h"

class CheckingAccount : public BankAccount {
    private:

    double overdraftLimit;

    public:
    //constructor

    CheckingAccount(int accountNumber,const std::string& name,double initialBalance,double overdraftLimit):
    BankAccount(accountNumber,name,initialBalance),overdraftLimit(overdraftLimit){}
    

    //deposit
    void deposit(double amount) override{
        balance+=amount;
    }

    bool withdraw(double amount)override{
        if(balance+overdraftLimit >= amount){
            balance-=amount;
            return true;
        }
        return false; //Exceeds overdraft limit
    }

    // Display account info
    void displayAccountInfo() const override {
        std::cout << "Checking Account [" << accountNumber << "]\n"
                  << "Holder: " << accountHolderName << "\n"
                  << "Balance: " << balance << "\n"
                  << "Overdraft Limit: " << overdraftLimit << "\n";
    }

    
};
#endif