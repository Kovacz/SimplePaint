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
include tests/CMakeFiles/Outside.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/Outside.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/Outside.dir/flags.make

tests/CMakeFiles/Outside.dir/__/src/main.cpp.o: tests/CMakeFiles/Outside.dir/flags.make
tests/CMakeFiles/Outside.dir/__/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/akukh/Documents/Projects/simple-paint/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/Outside.dir/__/src/main.cpp.o"
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Outside.dir/__/src/main.cpp.o -c /Users/akukh/Documents/Projects/simple-paint/src/main.cpp

tests/CMakeFiles/Outside.dir/__/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Outside.dir/__/src/main.cpp.i"
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/akukh/Documents/Projects/simple-paint/src/main.cpp > CMakeFiles/Outside.dir/__/src/main.cpp.i

tests/CMakeFiles/Outside.dir/__/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Outside.dir/__/src/main.cpp.s"
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/akukh/Documents/Projects/simple-paint/src/main.cpp -o CMakeFiles/Outside.dir/__/src/main.cpp.s

tests/CMakeFiles/Outside.dir/__/src/renderwindow.cpp.o: tests/CMakeFiles/Outside.dir/flags.make
tests/CMakeFiles/Outside.dir/__/src/renderwindow.cpp.o: ../src/renderwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/akukh/Documents/Projects/simple-paint/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/Outside.dir/__/src/renderwindow.cpp.o"
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Outside.dir/__/src/renderwindow.cpp.o -c /Users/akukh/Documents/Projects/simple-paint/src/renderwindow.cpp

tests/CMakeFiles/Outside.dir/__/src/renderwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Outside.dir/__/src/renderwindow.cpp.i"
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/akukh/Documents/Projects/simple-paint/src/renderwindow.cpp > CMakeFiles/Outside.dir/__/src/renderwindow.cpp.i

tests/CMakeFiles/Outside.dir/__/src/renderwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Outside.dir/__/src/renderwindow.cpp.s"
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/akukh/Documents/Projects/simple-paint/src/renderwindow.cpp -o CMakeFiles/Outside.dir/__/src/renderwindow.cpp.s

tests/CMakeFiles/Outside.dir/__/src/opengl.cpp.o: tests/CMakeFiles/Outside.dir/flags.make
tests/CMakeFiles/Outside.dir/__/src/opengl.cpp.o: ../src/opengl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/akukh/Documents/Projects/simple-paint/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests/CMakeFiles/Outside.dir/__/src/opengl.cpp.o"
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Outside.dir/__/src/opengl.cpp.o -c /Users/akukh/Documents/Projects/simple-paint/src/opengl.cpp

tests/CMakeFiles/Outside.dir/__/src/opengl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Outside.dir/__/src/opengl.cpp.i"
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/akukh/Documents/Projects/simple-paint/src/opengl.cpp > CMakeFiles/Outside.dir/__/src/opengl.cpp.i

tests/CMakeFiles/Outside.dir/__/src/opengl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Outside.dir/__/src/opengl.cpp.s"
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/akukh/Documents/Projects/simple-paint/src/opengl.cpp -o CMakeFiles/Outside.dir/__/src/opengl.cpp.s

# Object files for target Outside
Outside_OBJECTS = \
"CMakeFiles/Outside.dir/__/src/main.cpp.o" \
"CMakeFiles/Outside.dir/__/src/renderwindow.cpp.o" \
"CMakeFiles/Outside.dir/__/src/opengl.cpp.o"

# External object files for target Outside
Outside_EXTERNAL_OBJECTS =

tests/libOutside.a: tests/CMakeFiles/Outside.dir/__/src/main.cpp.o
tests/libOutside.a: tests/CMakeFiles/Outside.dir/__/src/renderwindow.cpp.o
tests/libOutside.a: tests/CMakeFiles/Outside.dir/__/src/opengl.cpp.o
tests/libOutside.a: tests/CMakeFiles/Outside.dir/build.make
tests/libOutside.a: tests/CMakeFiles/Outside.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/akukh/Documents/Projects/simple-paint/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libOutside.a"
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/Outside.dir/cmake_clean_target.cmake
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Outside.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/Outside.dir/build: tests/libOutside.a

.PHONY : tests/CMakeFiles/Outside.dir/build

tests/CMakeFiles/Outside.dir/clean:
	cd /Users/akukh/Documents/Projects/simple-paint/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/Outside.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/Outside.dir/clean

tests/CMakeFiles/Outside.dir/depend:
	cd /Users/akukh/Documents/Projects/simple-paint/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/akukh/Documents/Projects/simple-paint /Users/akukh/Documents/Projects/simple-paint/tests /Users/akukh/Documents/Projects/simple-paint/build /Users/akukh/Documents/Projects/simple-paint/build/tests /Users/akukh/Documents/Projects/simple-paint/build/tests/CMakeFiles/Outside.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/Outside.dir/depend
