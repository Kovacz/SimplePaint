# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.12.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.12.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/akukh/Documents/Projects/simple-paint

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/akukh/Documents/Projects/simple-paint/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/SimplePaint_UnitTests.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/SimplePaint_UnitTests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/SimplePaint_UnitTests.dir/flags.make

tests/CMakeFiles/SimplePaint_UnitTests.dir/renderwindow_test.cpp.o: tests/CMakeFiles/SimplePaint_UnitTests.dir/flags.make
tests/CMakeFiles/SimplePaint_UnitTests.dir/renderwindow_test.cpp.o: ../tests/renderwindow_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/akukh/Documents/Projects/simple-paint/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/SimplePaint_UnitTests.dir/renderwindow_test.cpp.o"
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimplePaint_UnitTests.dir/renderwindow_test.cpp.o -c /Users/akukh/Documents/Projects/simple-paint/tests/renderwindow_test.cpp

tests/CMakeFiles/SimplePaint_UnitTests.dir/renderwindow_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimplePaint_UnitTests.dir/renderwindow_test.cpp.i"
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/akukh/Documents/Projects/simple-paint/tests/renderwindow_test.cpp > CMakeFiles/SimplePaint_UnitTests.dir/renderwindow_test.cpp.i

tests/CMakeFiles/SimplePaint_UnitTests.dir/renderwindow_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimplePaint_UnitTests.dir/renderwindow_test.cpp.s"
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/akukh/Documents/Projects/simple-paint/tests/renderwindow_test.cpp -o CMakeFiles/SimplePaint_UnitTests.dir/renderwindow_test.cpp.s

tests/CMakeFiles/SimplePaint_UnitTests.dir/main.cpp.o: tests/CMakeFiles/SimplePaint_UnitTests.dir/flags.make
tests/CMakeFiles/SimplePaint_UnitTests.dir/main.cpp.o: ../tests/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/akukh/Documents/Projects/simple-paint/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/SimplePaint_UnitTests.dir/main.cpp.o"
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SimplePaint_UnitTests.dir/main.cpp.o -c /Users/akukh/Documents/Projects/simple-paint/tests/main.cpp

tests/CMakeFiles/SimplePaint_UnitTests.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SimplePaint_UnitTests.dir/main.cpp.i"
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/akukh/Documents/Projects/simple-paint/tests/main.cpp > CMakeFiles/SimplePaint_UnitTests.dir/main.cpp.i

tests/CMakeFiles/SimplePaint_UnitTests.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SimplePaint_UnitTests.dir/main.cpp.s"
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/akukh/Documents/Projects/simple-paint/tests/main.cpp -o CMakeFiles/SimplePaint_UnitTests.dir/main.cpp.s

# Object files for target SimplePaint_UnitTests
SimplePaint_UnitTests_OBJECTS = \
"CMakeFiles/SimplePaint_UnitTests.dir/renderwindow_test.cpp.o" \
"CMakeFiles/SimplePaint_UnitTests.dir/main.cpp.o"

# External object files for target SimplePaint_UnitTests
SimplePaint_UnitTests_EXTERNAL_OBJECTS =

bin/SimplePaint_UnitTests: tests/CMakeFiles/SimplePaint_UnitTests.dir/renderwindow_test.cpp.o
bin/SimplePaint_UnitTests: tests/CMakeFiles/SimplePaint_UnitTests.dir/main.cpp.o
bin/SimplePaint_UnitTests: tests/CMakeFiles/SimplePaint_UnitTests.dir/build.make
bin/SimplePaint_UnitTests: tests/libOutside.a
bin/SimplePaint_UnitTests: tests/CMakeFiles/SimplePaint_UnitTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/akukh/Documents/Projects/simple-paint/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bin/SimplePaint_UnitTests"
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SimplePaint_UnitTests.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && ../bin/SimplePaint_UnitTests

# Rule to build all files generated by this target.
tests/CMakeFiles/SimplePaint_UnitTests.dir/build: bin/SimplePaint_UnitTests

.PHONY : tests/CMakeFiles/SimplePaint_UnitTests.dir/build

tests/CMakeFiles/SimplePaint_UnitTests.dir/clean:
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/SimplePaint_UnitTests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/SimplePaint_UnitTests.dir/clean

tests/CMakeFiles/SimplePaint_UnitTests.dir/depend:
	cd /Users/akukh/Documents/Projects/simple-paint/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/akukh/Documents/Projects/simple-paint /Users/akukh/Documents/Projects/simple-paint/tests /Users/akukh/Documents/Projects/simple-paint/build /Users/akukh/Documents/Projects/simple-paint/build/tests /Users/akukh/Documents/Projects/simple-paint/build/tests/CMakeFiles/SimplePaint_UnitTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/SimplePaint_UnitTests.dir/depend
