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
CMAKE_SOURCE_DIR = /home/vlpakhomov/mipt-cpp/matrix/tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vlpakhomov/mipt-cpp/matrix/tests/build

# Include any dependencies generated for this target.
include CMakeFiles/matrix.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/matrix.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/matrix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/matrix.dir/flags.make

CMakeFiles/matrix.dir/tests.cpp.o: CMakeFiles/matrix.dir/flags.make
CMakeFiles/matrix.dir/tests.cpp.o: ../tests.cpp
CMakeFiles/matrix.dir/tests.cpp.o: CMakeFiles/matrix.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vlpakhomov/mipt-cpp/matrix/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/matrix.dir/tests.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/matrix.dir/tests.cpp.o -MF CMakeFiles/matrix.dir/tests.cpp.o.d -o CMakeFiles/matrix.dir/tests.cpp.o -c /home/vlpakhomov/mipt-cpp/matrix/tests/tests.cpp

CMakeFiles/matrix.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/matrix.dir/tests.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vlpakhomov/mipt-cpp/matrix/tests/tests.cpp > CMakeFiles/matrix.dir/tests.cpp.i

CMakeFiles/matrix.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/matrix.dir/tests.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vlpakhomov/mipt-cpp/matrix/tests/tests.cpp -o CMakeFiles/matrix.dir/tests.cpp.s

# Object files for target matrix
matrix_OBJECTS = \
"CMakeFiles/matrix.dir/tests.cpp.o"

# External object files for target matrix
matrix_EXTERNAL_OBJECTS =

matrix: CMakeFiles/matrix.dir/tests.cpp.o
matrix: CMakeFiles/matrix.dir/build.make
matrix: /usr/lib/x86_64-linux-gnu/libgtest.a
matrix: CMakeFiles/matrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vlpakhomov/mipt-cpp/matrix/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable matrix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/matrix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/matrix.dir/build: matrix
.PHONY : CMakeFiles/matrix.dir/build

CMakeFiles/matrix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/matrix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/matrix.dir/clean

CMakeFiles/matrix.dir/depend:
	cd /home/vlpakhomov/mipt-cpp/matrix/tests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vlpakhomov/mipt-cpp/matrix/tests /home/vlpakhomov/mipt-cpp/matrix/tests /home/vlpakhomov/mipt-cpp/matrix/tests/build /home/vlpakhomov/mipt-cpp/matrix/tests/build /home/vlpakhomov/mipt-cpp/matrix/tests/build/CMakeFiles/matrix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/matrix.dir/depend

