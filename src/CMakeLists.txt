# Add the library target
add_library(StudentLib
    BankAccount.cpp
    SavingsAccount.cpp
    CheckingAccount.cpp
    ThreadSafeAccount.cpp
    AccountFactory.cpp
    StudentCode.cpp
)

# Include directories
target_include_directories(StudentLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Link Threads (if used in ThreadSafeAccount)
find_package(Threads REQUIRED)
target_link_libraries(StudentLib PRIVATE Threads::Threads)

# Add test executable
add_executable(student  main.cpp)

# Link test executable with GoogleTest and StudentLib
target_link_libraries(student PRIVATE gtest  StudentLib)