// #include "SavingsAccount.h"
// #include "CheckingAccount.h"

// int main() {
//     // Polymorphism: Base class pointer pointing to derived objects
//     BankAccount* savings = new SavingsAccount(101, "Alice", 500.0, 2.5);
//     BankAccount* checking = new CheckingAccount(201, "Bob", 200.0, 100.0);

//     // Savings account operations
//     savings->deposit(100);
//     dynamic_cast<SavingsAccount*>(savings)->calculateInterest(); // Specific to savings
//     savings->displayAccountInfo();

//     // Checking account operations
//     checking->withdraw(300); // Overdraft allowed
//     checking->displayAccountInfo();

//     // Cleanup
//     delete savings;
//     delete checking;

//     return 0;
// }



#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "StudentCode.h"


// int main() {

//     // Polymorphism: Base class pointer pointing to derived objects
//     BankAccount* savingss = new SavingsAccount(101, "Fatmah", 500.0, 2.5);
//     BankAccount* checkingg = new CheckingAccount(201, "Mohamed", 200.0, 100.0);

//     // Savings account operations
//     savingss->deposit(100);
//     dynamic_cast<SavingsAccount*>(savingss)->applyInterest(); // Specific to savings
//     savingss->displayAccountInfo();

//     // Checking account operations
//     checkingg->withdraw(300); // Overdraft allowed
//     checkingg->displayAccountInfo();

//     // Cleanup
//     delete savingss;
//     delete checking;

//     return 0;

//     std::cout << "-----------------------------------------------------------------------\n";

//     //////////////////////////////////////////////////// helper

//     // Create accounts
//     auto checking = std::make_shared<CheckingAccount>(1, "Noura", 1000.0, 500.0);
//     auto savings = std::make_shared<SavingsAccount>(2, "Mariam", 1500.0, 2.5);
//     auto savings2 = std::make_shared<SavingsAccount>(3, "Sara", 500.0, 3.0);

//     // Store accounts in a vector
//     std::vector<std::shared_ptr<BankAccount>> accounts = {checking, savings, savings2};

//     // Use helper functions
//     try {
//         auto account = findAccountByNumber(accounts, 2);
//         std::cout << "Account Found:\n";
//         account->displayAccountInfo();
//     } catch (const std::runtime_error& e) {
//         std::cerr << e.what() << "\n";
//     }

//     std::cout << "Accounts with balance above 1000:\n";
//     printAccountsAboveBalance(accounts, 1000.0);

//     // Sort accounts by balance and print
//     sortAccountsByBalance(accounts);
//     std::cout << "Sorted Accounts by Balance:\n";
//     for (const auto& account : accounts) {
//         account->displayAccountInfo();
//     }

//     return 0;




//       std::cout << "-----------------------------------------------------------------------\n";

// }






int main() {
    testDeposit();
    testWithdraw();
    testOverdraftProtection();
    testDisplayAccountInfo();
    testInterestCalculation();
    testSortingAccounts();
    testEdgeCases();

    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}


    //////////////////////////////////////////////////// senarios

    ////////////Deposit Functionality

void testDeposit() {
    auto savings = std::make_shared<SavingsAccount>(1, "Alice", 1000.0, 2.5);

    // Scenario 1: Valid deposit
    savings->deposit(500.0);
    assert(savings->getBalance() == 1500.0);

    // Scenario 2a: Deposit zero
    savings->deposit(0.0);
    assert(savings->getBalance() == 1500.0);

    // Scenario 2b: Deposit negative amount
    try {
        savings->deposit(-100.0);
    } catch (const std::invalid_argument& e) {
        assert(savings->getBalance() == 1500.0); // Ensure balance is unchanged
    }
}



 //////////////////////////////////////////////////// senarios

    ////////////Withdraw Functionality

void testWithdraw() {
    // SavingsAccount scenarios
    auto savings = std::make_shared<SavingsAccount>(1, "Alice", 1000.0, 2.5);

    // Scenario 1: Sufficient balance
    assert(savings->withdraw(500.0) == true);
    assert(savings->getBalance() == 500.0);

    // Scenario 2: Insufficient balance
    assert(savings->withdraw(600.0) == false);
    assert(savings->getBalance() == 500.0);

    // CheckingAccount scenarios
    auto checking = std::make_shared<CheckingAccount>(2, "Bob", 1000.0, 500.0);

    // Scenario 3a: Within overdraft limit
    assert(checking->withdraw(1200.0) == true);
    assert(checking->getBalance() == -200.0);

    // Scenario 3b: Exceeds overdraft limit
    assert(checking->withdraw(400.0) == false);
    assert(checking->getBalance() == -200.0);

    // Edge cases
    assert(checking->withdraw(0.0) == true); // Withdraw 0
    try {
        checking->withdraw(-100.0); // Negative withdrawal
    } catch (const std::invalid_argument& e) {
        assert(checking->getBalance() == -200.0); // Ensure balance unchanged
    }
}



 //////////////////////////////////////////////////// senarios

    ////////////Overdraft Protection
void testOverdraftProtection() {
    auto checking = std::make_shared<CheckingAccount>(2, "Bob", 1000.0, 500.0);

    // Scenario 1: Within overdraft limit
    assert(checking->withdraw(1200.0) == true);
    assert(checking->getBalance() == -200.0);

    // Scenario 2: Exceeding overdraft limit
    assert(checking->withdraw(400.0) == false);
    assert(checking->getBalance() == -200.0);
}




 //////////////////////////////////////////////////// senarios

    ////////////Display Account Information

void testDisplayAccountInfo() {
    auto savings = std::make_shared<SavingsAccount>(1, "Alice", 1000.0, 2.5);

    // Capture output (if needed) and validate
    savings->displayAccountInfo();

    // Ensure no exceptions are thrown
    assert(true); // Placeholder for success if display works correctly
}





 //////////////////////////////////////////////////// senarios

    ////////////Interest Calculation (SavingsAccount Only)

void testInterestCalculation() {
    auto savings = std::make_shared<SavingsAccount>(1, "Alice", 1000.0, 2.5);

    // Scenario 1: Apply interest
    savings->applyInterest();
    assert(savings->getBalance() == 1025.0);

    // Edge case: Zero balance
    auto zeroBalanceSavings = std::make_shared<SavingsAccount>(2, "Bob", 0.0, 2.5);
    zeroBalanceSavings->applyInterest();
    assert(zeroBalanceSavings->getBalance() == 0.0);

    // Edge case: Large interest rate
    auto largeInterestSavings = std::make_shared<SavingsAccount>(3, "Charlie", 1000.0, 100.0);
    largeInterestSavings->applyInterest();
    assert(largeInterestSavings->getBalance() == 2000.0);
}



 //////////////////////////////////////////////////// senarios

    ////////////Sorting Accounts

void testSortingAccounts() {
    auto acc1 = std::make_shared<SavingsAccount>(1, "Alice", 1000.0, 2.5);
    auto acc2 = std::make_shared<SavingsAccount>(2, "Bob", 500.0, 2.0);
    auto acc3 = std::make_shared<CheckingAccount>(3, "Charlie", 2000.0, 500.0);

    std::vector<std::shared_ptr<BankAccount>> accounts = {acc1, acc2, acc3};
    sortAccountsByBalance(accounts);

    // Ensure sorted order
    assert(accounts[0]->getBalance() == 500.0);
    assert(accounts[1]->getBalance() == 1000.0);
    assert(accounts[2]->getBalance() == 2000.0);
}
ert(accounts[2]->getBalance() == 2000.0);
}




 //////////////////////////////////////////////////// senarios

    ////////////General Cases to handle invalod or unexpected inputs

void testEdgeCases() {
    auto savings = std::make_shared<SavingsAccount>(1, "Alice", 1000.0, 2.5);

    try {
        savings->deposit(-500.0);
    } catch (const std::invalid_argument& e) {
        assert(savings->getBalance() == 1000.0);
    }

    try {
        savings->withdraw(-100.0);
    } catch (const std::invalid_argument& e) {
        assert(savings->getBalance() == 1000.0);
    }
}











