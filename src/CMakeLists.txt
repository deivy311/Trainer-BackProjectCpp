# Add the library target
add_library(StudentLib
    BankAccount.cpp
    CheckingAccount.cpp
    SavingsAccount.cpp
    StudentCode.cpp
)

# Add the executable target for StudentCode
add_executable(StudentExecutable StudentCode.cpp)

# Link the library to the executable
target_link_libraries(StudentExecutable PRIVATE StudentLib)

# Include directories where header files are located
target_include_directories(StudentLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

