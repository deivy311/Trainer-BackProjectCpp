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
include src/CMakeFiles/StudentExecutable.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/StudentExecutable.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/StudentExecutable.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/StudentExecutable.dir/flags.make

src/CMakeFiles/StudentExecutable.dir/StudentCode.cpp.o: src/CMakeFiles/StudentExecutable.dir/flags.make
src/CMakeFiles/StudentExecutable.dir/StudentCode.cpp.o: StudentCode.cpp
src/CMakeFiles/StudentExecutable.dir/StudentCode.cpp.o: src/CMakeFiles/StudentExecutable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/latifa/projects/Trainer-BackProjectCpp/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/StudentExecutable.dir/StudentCode.cpp.o"
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/StudentExecutable.dir/StudentCode.cpp.o -MF CMakeFiles/StudentExecutable.dir/StudentCode.cpp.o.d -o CMakeFiles/StudentExecutable.dir/StudentCode.cpp.o -c /home/latifa/projects/Trainer-BackProjectCpp/src/StudentCode.cpp

src/CMakeFiles/StudentExecutable.dir/StudentCode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StudentExecutable.dir/StudentCode.cpp.i"
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/latifa/projects/Trainer-BackProjectCpp/src/StudentCode.cpp > CMakeFiles/StudentExecutable.dir/StudentCode.cpp.i

src/CMakeFiles/StudentExecutable.dir/StudentCode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StudentExecutable.dir/StudentCode.cpp.s"
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/latifa/projects/Trainer-BackProjectCpp/src/StudentCode.cpp -o CMakeFiles/StudentExecutable.dir/StudentCode.cpp.s

# Object files for target StudentExecutable
StudentExecutable_OBJECTS = \
"CMakeFiles/StudentExecutable.dir/StudentCode.cpp.o"

# External object files for target StudentExecutable
StudentExecutable_EXTERNAL_OBJECTS =

src/StudentExecutable: src/CMakeFiles/StudentExecutable.dir/StudentCode.cpp.o
src/StudentExecutable: src/CMakeFiles/StudentExecutable.dir/build.make
src/StudentExecutable: src/libStudentLib.a
src/StudentExecutable: src/CMakeFiles/StudentExecutable.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/latifa/projects/Trainer-BackProjectCpp/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable StudentExecutable"
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StudentExecutable.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/StudentExecutable.dir/build: src/StudentExecutable
.PHONY : src/CMakeFiles/StudentExecutable.dir/build

src/CMakeFiles/StudentExecutable.dir/clean:
	cd /home/latifa/projects/Trainer-BackProjectCpp/src/src && $(CMAKE_COMMAND) -P CMakeFiles/StudentExecutable.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/StudentExecutable.dir/clean

src/CMakeFiles/StudentExecutable.dir/depend:
	cd /home/latifa/projects/Trainer-BackProjectCpp/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/latifa/projects/Trainer-BackProjectCpp /home/latifa/projects/Trainer-BackProjectCpp/src /home/latifa/projects/Trainer-BackProjectCpp/src /home/latifa/projects/Trainer-BackProjectCpp/src/src /home/latifa/projects/Trainer-BackProjectCpp/src/src/CMakeFiles/StudentExecutable.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/StudentExecutable.dir/depend

