set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the library target
add_library(StudentLib
    BankAccount.cpp
    CheckingAccount.cpp
    SavingsAccount.cpp
    ThreadSafeAccount.cpp
    StudentCode.cpp
)

# Include directories
target_include_directories(StudentLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
