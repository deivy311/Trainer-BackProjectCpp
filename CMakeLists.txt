# Minimum CMake version
cmake_minimum_required(VERSION 3.14)

# Project name
project(EvaluationProject VERSION 1.0 LANGUAGES CXX)

# C++ Standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable testing
enable_testing()

# FetchContent for GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# Download and make available
FetchContent_MakeAvailable(googletest)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)
