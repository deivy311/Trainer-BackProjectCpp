include(FetchContent)

# Fetch GoogleTest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Add test executable
add_executable(TestBankAccount TestBankAccount.cpp)

# Link test executable with GoogleTest and the library
target_link_libraries(TestBankAccount PRIVATE gtest gtest_main StudentLib)

# Discover tests
include(GoogleTest)
gtest_discover_tests(TestBankAccount)
