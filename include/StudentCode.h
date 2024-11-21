#ifndef STUDENT_CODE_H
#define STUDENT_CODE_H
#include <vector>
#include <algorithm>
#include <BankAccount.h>

// Add your derived classes and functions here.


///////////// Template /////////////

// 1- Write a function template to implement reusable operations like sorting or searching accounts.


// Function template to ((sort accounts by a custom comparator))
template <typename T>
void sortAccounts(std::vector<T*>& accounts, bool (*comparator) (T*, T*)){   //Accepts a vector of pointers (*) to accounts and a custom comparator function
    std::sort(accounts.begin(), accounts.end(), comparator);  //to sort accounts based on the comparator
}
// If T is BankAccount, then T* is a pointer to a BankAccount object (BankAccount*)


// ----------------------------

// 2- Function template to ((search for a matching account by a predicate))
template <typename T>
T* searchAccount(std::vector<T*>& accounts, bool (*predicate)(T*)) {  //Accepts a vector of pointers (*) to accounts and a predicate 
    auto it = std::find_if(accounts.begin(), accounts.end(), predicate);
    return (it != accounts.end()) ? *it : nullptr;
}
// This function searches for an account in a vector of accounts using a condition provided by a predicate function
// a predicate is a function or callable object that takes one/+ argument and returns a boolean value (T/F)
// in our case it checks a condition for each account in the vector and return T if the condition is satisfied 
// T could be BankAcoount/SAvingAccount/CheckingAccount
// A predicate can check if an account's balance is above a certain threshold
// If it finds an account that satisfies the condition, it returns a pointer to that account. If no account satisfies the condition, it returns nullptr



// ---------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // STUDENT_CODE_H
