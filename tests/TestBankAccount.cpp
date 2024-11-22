// TestBankAccount.cpp
#include <gtest/gtest.h>
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "AccountFactory.h"
#include "StudentCode.h"

// Test case for deposit in SavingsAccount
TEST(SavingsAccountTest, DepositIncreasesBalance) {
    SavingsAccount account(1001, "John Doe", 500.0, 5.0);
    account.deposit(200.0);
    EXPECT_DOUBLE_EQ(account.getBalance(), 700.0);
}

// Test case for withdrawal in SavingsAccount
TEST(SavingsAccountTest, WithdrawDecreasesBalance) {
    SavingsAccount account(1001, "John Doe", 500.0, 5.0);
    bool success = account.withdraw(200.0);
    EXPECT_TRUE(success);
    EXPECT_DOUBLE_EQ(account.getBalance(), 300.0);
}

// Test case for insufficient funds in SavingsAccount
TEST(SavingsAccountTest, WithdrawInsufficientFunds) {
    SavingsAccount account(1001, "John Doe", 500.0, 5.0);
    EXPECT_THROW(account.withdraw(600.0), std::runtime_error);
}

// Test case for interest calculation in SavingsAccount
TEST(SavingsAccountTest, AddInterestIncreasesBalance) {
    SavingsAccount account(1001, "John Doe", 1000.0, 5.0); // 5% interest rate
    account.addInterest();
    EXPECT_DOUBLE_EQ(account.getBalance(), 1050.0);
}

// Test case for deposit in CheckingAccount
TEST(CheckingAccountTest, DepositIncreasesBalance) {
    CheckingAccount account(2001, "Jane Smith", 500.0, 100.0);
    account.deposit(300.0);
    EXPECT_DOUBLE_EQ(account.getBalance(), 800.0);
}

// Test case for withdrawal within balance in CheckingAccount
TEST(CheckingAccountTest, WithdrawWithinBalance) {
    CheckingAccount account(2001, "Jane Smith", 500.0, 100.0);
    bool success = account.withdraw(400.0);
    EXPECT_TRUE(success);
    EXPECT_DOUBLE_EQ(account.getBalance(), 100.0);
}

// Test case for withdrawal using overdraft in CheckingAccount
TEST(CheckingAccountTest, WithdrawUsingOverdraft) {
    CheckingAccount account(2001, "Jane Smith", 500.0, 200.0);
    bool success = account.withdraw(650.0); // Withdraw beyond balance but within overdraft limit
    EXPECT_TRUE(success);
    EXPECT_DOUBLE_EQ(account.getBalance(), -150.0);
}

// Test case for exceeding overdraft limit in CheckingAccount
TEST(CheckingAccountTest, ExceedOverdraftLimit) {
    CheckingAccount account(2001, "Jane Smith", 500.0, 200.0);
    EXPECT_THROW(account.withdraw(750.0), std::runtime_error);
}

// Test case for negative deposit amount
TEST(BankAccountTest, NegativeDepositThrowsException) {
    SavingsAccount account(1001, "John Doe", 500.0, 5.0);
    EXPECT_THROW(account.deposit(-100.0), std::invalid_argument);
}

// Test case for negative withdrawal amount
TEST(BankAccountTest, NegativeWithdrawThrowsException) {
    CheckingAccount account(2001, "Jane Smith", 500.0, 100.0);
    EXPECT_THROW(account.withdraw(-50.0), std::invalid_argument);
}

// Test case for zero deposit amount
TEST(BankAccountTest, ZeroDepositThrowsException) {
    SavingsAccount account(1001, "John Doe", 500.0, 5.0);
    EXPECT_THROW(account.deposit(0.0), std::invalid_argument);
}

// Test case for zero withdrawal amount
TEST(BankAccountTest, ZeroWithdrawThrowsException) {
    CheckingAccount account(2001, "Jane Smith", 500.0, 100.0);
    EXPECT_THROW(account.withdraw(0.0), std::invalid_argument);
}

// Test case for displayAccountInfo (output verification can be complex; we can check that it doesn't throw)
TEST(BankAccountTest, DisplayAccountInfoDoesNotThrow) {
    SavingsAccount account(1001, "John Doe", 500.0, 5.0);
    EXPECT_NO_THROW(account.displayAccountInfo());
}

// Test case for AccountFactory creating SavingsAccount
TEST(AccountFactoryTest, CreateSavingsAccount) {
    auto account = AccountFactory::createAccount(AccountType::SAVINGS, 3001, "Alice Wonderland", 1000.0);
    EXPECT_NE(account, nullptr);
    EXPECT_EQ(account->getAccountNumber(), 3001);
    EXPECT_EQ(account->getAccountHolderName(), "Alice Wonderland");
    EXPECT_DOUBLE_EQ(account->getBalance(), 1000.0);

    auto savingsPtr = std::dynamic_pointer_cast<SavingsAccount>(account);
    EXPECT_NE(savingsPtr, nullptr);
}

// Test case for AccountFactory creating CheckingAccount
TEST(AccountFactoryTest, CreateCheckingAccount) {
    auto account = AccountFactory::createAccount(AccountType::CHECKING, 3002, "Bob Builder", 1500.0);
    EXPECT_NE(account, nullptr);
    EXPECT_EQ(account->getAccountNumber(), 3002);
    EXPECT_EQ(account->getAccountHolderName(), "Bob Builder");
    EXPECT_DOUBLE_EQ(account->getBalance(), 1500.0);

    auto checkingPtr = std::dynamic_pointer_cast<CheckingAccount>(account);
    EXPECT_NE(checkingPtr, nullptr);
}

// Test case for findAccountByNumber template function
TEST(TemplateFunctionTest, FindAccountByNumber) {
    std::vector<std::shared_ptr<BankAccount>> accounts;
    accounts.push_back(std::make_shared<SavingsAccount>(1001, "John Doe", 500.0, 5.0));
    accounts.push_back(std::make_shared<CheckingAccount>(2001, "Jane Smith", 800.0, 200.0));

    auto foundAccount = findAccountByNumber(accounts, 2001);
    EXPECT_NE(foundAccount, nullptr);
    EXPECT_EQ(foundAccount->getAccountNumber(), 2001);
}

// Main function for running tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
