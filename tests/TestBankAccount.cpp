#include <gtest/gtest.h>
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "StudentCode.h"

TEST(StudentCodeTest, PlaceholderTest) {
    EXPECT_TRUE(true); // Placeholder test
}


TEST(DepositTest, ValidDeposit) {
    SavingsAccount account(1, "Alice", 1000.0, 5.0);
    account.deposit(500.0);
    EXPECT_EQ(account.getBalance(), 1500.0);
}

TEST(DepositTest, ZeroDeposit) {
    SavingsAccount account(1, "Alice", 1000.0, 5.0);
    account.deposit(0.0);
    EXPECT_EQ(account.getBalance(), 1000.0);
}

TEST(DepositTest, NegativeDeposit) {
    SavingsAccount account(1, "Alice", 1000.0, 5.0);
    EXPECT_THROW(account.deposit(-500.0), std::invalid_argument);
    EXPECT_EQ(account.getBalance(), 1000.0);
}

TEST(WithdrawTest, SufficientBalanceSavingsAccount) {
    SavingsAccount account(1, "Alice", 1000.0, 5.0);
    EXPECT_TRUE(account.withdraw(500.0));
    EXPECT_EQ(account.getBalance(), 500.0);
}

TEST(WithdrawTest, InsufficientBalanceSavingsAccount) {
    SavingsAccount account(1, "Alice", 1000.0, 5.0);
    EXPECT_FALSE(account.withdraw(1500.0));
    EXPECT_EQ(account.getBalance(), 1000.0);
}

TEST(WithdrawTest, OverdraftSuccessCheckingAccount) {
    CheckingAccount account(2, "Bob", 500.0, 200.0);
    EXPECT_TRUE(account.withdraw(600.0)); // Within overdraft limit
    EXPECT_EQ(account.getBalance(), -100.0);
}

TEST(WithdrawTest, OverdraftFailureCheckingAccount) {
    CheckingAccount account(2, "Bob", 500.0, 200.0);
    EXPECT_FALSE(account.withdraw(800.0)); // Exceeds overdraft limit
    EXPECT_EQ(account.getBalance(), 500.0);
}

TEST(WithdrawTest, ZeroWithdrawal) {
    SavingsAccount account(1, "Alice", 1000.0, 5.0);
    EXPECT_TRUE(account.withdraw(0.0));
    EXPECT_EQ(account.getBalance(), 1000.0);
}

TEST(WithdrawTest, NegativeWithdrawal) {
    CheckingAccount account(2, "Bob", 500.0, 200.0);
    EXPECT_THROW(account.withdraw(-100.0), std::invalid_argument);
    EXPECT_EQ(account.getBalance(), 500.0);
}

TEST(OverdraftProtectionTest, WithinLimit) {
    CheckingAccount account(2, "Bob", 500.0, 200.0);
    EXPECT_TRUE(account.withdraw(600.0)); // Leaves -100 balance
    EXPECT_EQ(account.getBalance(), -100.0);
}

TEST(OverdraftProtectionTest, ExceedsLimit) {
    CheckingAccount account(2, "Bob", 500.0, 200.0);
    EXPECT_FALSE(account.withdraw(800.0)); // Exceeds overdraft
    EXPECT_EQ(account.getBalance(), 500.0);
}

TEST(DisplayInfoTest, SavingsAccountDisplay) {
    SavingsAccount account(1, "Alice", 1000.0, 5.0);
    EXPECT_NO_THROW(account.displayAccountInfo());
}

TEST(DisplayInfoTest, CheckingAccountDisplay) {
    CheckingAccount account(2, "Bob", 500.0, 200.0);
    EXPECT_NO_THROW(account.displayAccountInfo());
}

TEST(InterestCalculationTest, AddInterest) {
    SavingsAccount account(1, "Alice", 1000.0, 5.0);
    double interest = account.getBalance() * (5.0 / 100.0);
    account.deposit(interest);
    EXPECT_EQ(account.getBalance(), 1050.0);
}

TEST(InterestCalculationTest, ZeroBalanceInterest) {
    SavingsAccount account(1, "Alice", 0.0, 5.0);
    double interest = account.getBalance() * (5.0 / 100.0);
    account.deposit(interest);
    EXPECT_EQ(account.getBalance(), 0.0);
}

#include <algorithm>

TEST(SortingTest, SortAccountsByBalance) {
    SavingsAccount savings1(1, "Alice", 1000.0, 5.0);
    CheckingAccount checking1(2, "Bob", 500.0, 200.0);
    SavingsAccount savings2(3, "Charlie", 1500.0, 3.0);

    std::vector<BankAccount*> accounts = {&savings1, &checking1, &savings2};

    std::sort(accounts.begin(), accounts.end(), [](BankAccount* a, BankAccount* b) {
        return a->getBalance() < b->getBalance();
    });

    EXPECT_EQ(accounts[0]->getAccountNumber(), 2); // CheckingAccount (500.0)
    EXPECT_EQ(accounts[1]->getAccountNumber(), 1); // SavingsAccount (1000.0)
    EXPECT_EQ(accounts[2]->getAccountNumber(), 3); // SavingsAccount (1500.0)
}


TEST(EdgeCasesTest, LargeDeposit) {
    SavingsAccount account(1, "Alice", 1000.0, 5.0);
    account.deposit(1e9);
    EXPECT_EQ(account.getBalance(), 1000001000.0);
}

TEST(EdgeCasesTest, LargeWithdrawal) {
    SavingsAccount account(1, "Alice", 1e9, 5.0);
    EXPECT_TRUE(account.withdraw(1e9));
    EXPECT_EQ(account.getBalance(), 0.0);
}

// TEST(TemplateTest, AccountAnalytics) {
//     SavingsAccount savings1(1, "Alice", 1000.0, 5.0);
//     CheckingAccount checking1(2, "Bob", 500.0, 200.0);

//     AccountAnalytics<BankAccount> analytics;
//     analytics.addAccount(&savings1);
//     analytics.addAccount(&checking1);

//     EXPECT_EQ(analytics.getTotalAccounts(), 2);
//     EXPECT_DOUBLE_EQ(analytics.getTotalBalance(), 1500.0);

//     auto highestBalanceAccount = analytics.getHighestBalanceAccount();
//     ASSERT_NE(highestBalanceAccount, nullptr);
//     EXPECT_EQ(highestBalanceAccount->getAccountNumber(), 1);
// }
