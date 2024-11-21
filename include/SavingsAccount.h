#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "BankAccount.h"


class SavingsAccount : public BankAccount {
    private:
    double interestRate;


    public:

    //Constructor
    SavingsAccount(int accountNumber,const std::string& name, double initialBalance,double interestRate):
    BankAccount(accountNumber,name,initialBalance), interestRate(interestRate){}

    // deposit (with interest) function
    void deposit(double amount) override{
        balance+=amount;
        balance+=(balance*interestRate/100); // Add interset
    }

    //withdraw function

    bool withdraw(double amount) override{
        if(balance >= amount){
            balance-=amount;
            return true;
        }
        return false; //insufficient balance
    }
  

    // Display account info
    void displayAccountInfo() const override {
        std::cout << "Savings Account [" << accountNumber << "]\n"
                  << "Holder: " << accountHolderName << "\n"
                  << "Balance: " << balance << "\n"
                  << "Interest Rate: " << interestRate << "%\n";
    }
    

};


#endif 