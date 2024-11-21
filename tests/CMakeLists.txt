# Add test executable
add_executable(TestBankAccount TestBankAccount.cpp)

# Link test executable with GoogleTest and StudentLib
target_link_libraries(TestBankAccount PRIVATE gtest gtest_main StudentLib)

# Discover tests using GoogleTest
include(GoogleTest)
gtest_discover_tests(TestBankAccount)
