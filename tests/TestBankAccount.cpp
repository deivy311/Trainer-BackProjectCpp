#include <gtest/gtest.h>
#include "SavingsAccount.h"
#include "CheckingAccount.h"

TEST(SavingsAccountTest, DepositLargeAmount) {
    SavingsAccount account(1, "Alice", 1000, 5);
    account.deposit(1e6); // Deposit 1,000,000
    EXPECT_EQ(account.getBalance(), 1001000);
}


TEST(SavingsAccountTest, Withdraw) {
    SavingsAccount account(1, "Alice", 1000, 5);

    EXPECT_TRUE(account.withdraw(500));
    EXPECT_EQ(account.getBalance(), 500);

    EXPECT_FALSE(account.withdraw(600)); // Insufficient balance
    EXPECT_THROW(account.withdraw(-100), std::invalid_argument);
}

TEST(SavingsAccountTest, ApplyInterest) {
    SavingsAccount account(1, "Alice", 1000, 5);
    account.applyInterest();
    EXPECT_EQ(account.getBalance(), 1050);
}

TEST(CheckingAccountTest, WithdrawWithOverdraft) {
    CheckingAccount account(2, "Bob", 1000, 500);

    EXPECT_TRUE(account.withdraw(1200)); // Uses overdraft
    EXPECT_EQ(account.getBalance(), 0);
    EXPECT_EQ(account.getOverdraftLimit(), 300);

    EXPECT_FALSE(account.withdraw(600)); // Exceeds overdraft
}
