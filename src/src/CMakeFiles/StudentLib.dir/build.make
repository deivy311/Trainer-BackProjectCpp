# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/latifa/projects/Trainer-BackProjectCpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/latifa/projects/Trainer-BackProjectCpp/src

# Include any dependencies generated for this target.
include src/CMakeFiles/StudentLib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/StudentLib.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/StudentLib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/StudentLib.dir/flags.make

src/CMakeFiles/StudentLib.dir/BankAccount.cpp.o: src/CMakeFiles/StudentLib.dir/flags.make
src/CMakeFiles/StudentLib.dir/BankAccount.cpp.o: BankAccount.cpp
src/CMakeFiles/StudentLib.dir/BankAccount.cpp.o: src/CMakeFiles/StudentLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/latifa/projects/Trainer-BackProjectCpp/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/StudentLib.dir/BankAccount.cpp.o"
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/StudentLib.dir/BankAccount.cpp.o -MF CMakeFiles/StudentLib.dir/BankAccount.cpp.o.d -o CMakeFiles/StudentLib.dir/BankAccount.cpp.o -c /home/latifa/projects/Trainer-BackProjectCpp/src/BankAccount.cpp

src/CMakeFiles/StudentLib.dir/BankAccount.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StudentLib.dir/BankAccount.cpp.i"
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/latifa/projects/Trainer-BackProjectCpp/src/BankAccount.cpp > CMakeFiles/StudentLib.dir/BankAccount.cpp.i

src/CMakeFiles/StudentLib.dir/BankAccount.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StudentLib.dir/BankAccount.cpp.s"
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/latifa/projects/Trainer-BackProjectCpp/src/BankAccount.cpp -o CMakeFiles/StudentLib.dir/BankAccount.cpp.s

src/CMakeFiles/StudentLib.dir/CheckingAccount.cpp.o: src/CMakeFiles/StudentLib.dir/flags.make
src/CMakeFiles/StudentLib.dir/CheckingAccount.cpp.o: CheckingAccount.cpp
src/CMakeFiles/StudentLib.dir/CheckingAccount.cpp.o: src/CMakeFiles/StudentLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/latifa/projects/Trainer-BackProjectCpp/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/StudentLib.dir/CheckingAccount.cpp.o"
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/StudentLib.dir/CheckingAccount.cpp.o -MF CMakeFiles/StudentLib.dir/CheckingAccount.cpp.o.d -o CMakeFiles/StudentLib.dir/CheckingAccount.cpp.o -c /home/latifa/projects/Trainer-BackProjectCpp/src/CheckingAccount.cpp

src/CMakeFiles/StudentLib.dir/CheckingAccount.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StudentLib.dir/CheckingAccount.cpp.i"
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/latifa/projects/Trainer-BackProjectCpp/src/CheckingAccount.cpp > CMakeFiles/StudentLib.dir/CheckingAccount.cpp.i

src/CMakeFiles/StudentLib.dir/CheckingAccount.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StudentLib.dir/CheckingAccount.cpp.s"
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/latifa/projects/Trainer-BackProjectCpp/src/CheckingAccount.cpp -o CMakeFiles/StudentLib.dir/CheckingAccount.cpp.s

src/CMakeFiles/StudentLib.dir/SavingsAccount.cpp.o: src/CMakeFiles/StudentLib.dir/flags.make
src/CMakeFiles/StudentLib.dir/SavingsAccount.cpp.o: SavingsAccount.cpp
src/CMakeFiles/StudentLib.dir/SavingsAccount.cpp.o: src/CMakeFiles/StudentLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/latifa/projects/Trainer-BackProjectCpp/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/StudentLib.dir/SavingsAccount.cpp.o"
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/StudentLib.dir/SavingsAccount.cpp.o -MF CMakeFiles/StudentLib.dir/SavingsAccount.cpp.o.d -o CMakeFiles/StudentLib.dir/SavingsAccount.cpp.o -c /home/latifa/projects/Trainer-BackProjectCpp/src/SavingsAccount.cpp

src/CMakeFiles/StudentLib.dir/SavingsAccount.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StudentLib.dir/SavingsAccount.cpp.i"
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/latifa/projects/Trainer-BackProjectCpp/src/SavingsAccount.cpp > CMakeFiles/StudentLib.dir/SavingsAccount.cpp.i

src/CMakeFiles/StudentLib.dir/SavingsAccount.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StudentLib.dir/SavingsAccount.cpp.s"
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/latifa/projects/Trainer-BackProjectCpp/src/SavingsAccount.cpp -o CMakeFiles/StudentLib.dir/SavingsAccount.cpp.s

src/CMakeFiles/StudentLib.dir/StudentCode.cpp.o: src/CMakeFiles/StudentLib.dir/flags.make
src/CMakeFiles/StudentLib.dir/StudentCode.cpp.o: StudentCode.cpp
src/CMakeFiles/StudentLib.dir/StudentCode.cpp.o: src/CMakeFiles/StudentLib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/latifa/projects/Trainer-BackProjectCpp/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/StudentLib.dir/StudentCode.cpp.o"
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/StudentLib.dir/StudentCode.cpp.o -MF CMakeFiles/StudentLib.dir/StudentCode.cpp.o.d -o CMakeFiles/StudentLib.dir/StudentCode.cpp.o -c /home/latifa/projects/Trainer-BackProjectCpp/src/StudentCode.cpp

src/CMakeFiles/StudentLib.dir/StudentCode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StudentLib.dir/StudentCode.cpp.i"
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/latifa/projects/Trainer-BackProjectCpp/src/StudentCode.cpp > CMakeFiles/StudentLib.dir/StudentCode.cpp.i

src/CMakeFiles/StudentLib.dir/StudentCode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StudentLib.dir/StudentCode.cpp.s"
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/latifa/projects/Trainer-BackProjectCpp/src/StudentCode.cpp -o CMakeFiles/StudentLib.dir/StudentCode.cpp.s

# Object files for target StudentLib
StudentLib_OBJECTS = \
"CMakeFiles/StudentLib.dir/BankAccount.cpp.o" \
"CMakeFiles/StudentLib.dir/CheckingAccount.cpp.o" \
"CMakeFiles/StudentLib.dir/SavingsAccount.cpp.o" \
"CMakeFiles/StudentLib.dir/StudentCode.cpp.o"

# External object files for target StudentLib
StudentLib_EXTERNAL_OBJECTS =

src/libStudentLib.a: src/CMakeFiles/StudentLib.dir/BankAccount.cpp.o
src/libStudentLib.a: src/CMakeFiles/StudentLib.dir/CheckingAccount.cpp.o
src/libStudentLib.a: src/CMakeFiles/StudentLib.dir/SavingsAccount.cpp.o
src/libStudentLib.a: src/CMakeFiles/StudentLib.dir/StudentCode.cpp.o
src/libStudentLib.a: src/CMakeFiles/StudentLib.dir/build.make
src/libStudentLib.a: src/CMakeFiles/StudentLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/latifa/projects/Trainer-BackProjectCpp/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libStudentLib.a"
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && $(CMAKE_COMMAND) -P CMakeFiles/StudentLib.dir/cmake_clean_target.cmake
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StudentLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/StudentLib.dir/build: src/libStudentLib.a
.PHONY : src/CMakeFiles/StudentLib.dir/build

src/CMakeFiles/StudentLib.dir/clean:
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && $(CMAKE_COMMAND) -P CMakeFiles/StudentLib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/StudentLib.dir/clean

src/CMakeFiles/StudentLib.dir/depend:
	cd /home/latifa/projects/Trainer-BackProjectCpp/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/latifa/projects/Trainer-BackProjectCpp /home/latifa/projects/Trainer-BackProjectCpp/src /home/latifa/projects/Trainer-BackProjectCpp/src /home/latifa/projects/Trainer-BackProjectCpp/src/src /home/latifa/projects/Trainer-BackProjectCpp/src/src/CMakeFiles/StudentLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/StudentLib.dir/depend

