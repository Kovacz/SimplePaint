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
CMAKE_SOURCE_DIR = /Users/akukh/Documents/Projects/simple-paint/tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/akukh/Documents/Projects/simple-paint/tests/build

# Utility rule file for Catch2.

# Include the progress variables for this target.
include CMakeFiles/Catch2.dir/progress.make

CMakeFiles/Catch2: CMakeFiles/Catch2-complete


CMakeFiles/Catch2-complete: Catch2-prefix/src/Catch2-stamp/Catch2-install
CMakeFiles/Catch2-complete: Catch2-prefix/src/Catch2-stamp/Catch2-mkdir
CMakeFiles/Catch2-complete: Catch2-prefix/src/Catch2-stamp/Catch2-download
CMakeFiles/Catch2-complete: Catch2-prefix/src/Catch2-stamp/Catch2-update
CMakeFiles/Catch2-complete: Catch2-prefix/src/Catch2-stamp/Catch2-patch
CMakeFiles/Catch2-complete: Catch2-prefix/src/Catch2-stamp/Catch2-configure
CMakeFiles/Catch2-complete: Catch2-prefix/src/Catch2-stamp/Catch2-build
CMakeFiles/Catch2-complete: Catch2-prefix/src/Catch2-stamp/Catch2-install
CMakeFiles/Catch2-complete: Catch2-prefix/src/Catch2-stamp/Catch2-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/akukh/Documents/Projects/simple-paint/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'Catch2'"
	/usr/local/Cellar/cmake/3.12.3/bin/cmake -E make_directory /Users/akukh/Documents/Projects/simple-paint/tests/build/CMakeFiles
	/usr/local/Cellar/cmake/3.12.3/bin/cmake -E touch /Users/akukh/Documents/Projects/simple-paint/tests/build/CMakeFiles/Catch2-complete
	/usr/local/Cellar/cmake/3.12.3/bin/cmake -E touch /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-stamp/Catch2-done

Catch2-prefix/src/Catch2-stamp/Catch2-install: Catch2-prefix/src/Catch2-stamp/Catch2-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/akukh/Documents/Projects/simple-paint/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No install step for 'Catch2'"
	cd /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-build && /usr/local/Cellar/cmake/3.12.3/bin/cmake -E echo_append
	cd /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-build && /usr/local/Cellar/cmake/3.12.3/bin/cmake -E touch /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-stamp/Catch2-install

Catch2-prefix/src/Catch2-stamp/Catch2-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/akukh/Documents/Projects/simple-paint/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'Catch2'"
	/usr/local/Cellar/cmake/3.12.3/bin/cmake -E make_directory /Users/akukh/Documents/Projects/simple-paint/tests/../external/Catch2-master
	/usr/local/Cellar/cmake/3.12.3/bin/cmake -E make_directory /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-build
	/usr/local/Cellar/cmake/3.12.3/bin/cmake -E make_directory /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix
	/usr/local/Cellar/cmake/3.12.3/bin/cmake -E make_directory /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/tmp
	/usr/local/Cellar/cmake/3.12.3/bin/cmake -E make_directory /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-stamp
	/usr/local/Cellar/cmake/3.12.3/bin/cmake -E make_directory /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src
	/usr/local/Cellar/cmake/3.12.3/bin/cmake -E touch /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-stamp/Catch2-mkdir

Catch2-prefix/src/Catch2-stamp/Catch2-download: Catch2-prefix/src/Catch2-stamp/Catch2-gitinfo.txt
Catch2-prefix/src/Catch2-stamp/Catch2-download: Catch2-prefix/src/Catch2-stamp/Catch2-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/akukh/Documents/Projects/simple-paint/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'Catch2'"
	cd /Users/akukh/Documents/Projects/simple-paint/external && /usr/local/Cellar/cmake/3.12.3/bin/cmake -P /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/tmp/Catch2-gitclone.cmake
	cd /Users/akukh/Documents/Projects/simple-paint/external && /usr/local/Cellar/cmake/3.12.3/bin/cmake -E touch /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-stamp/Catch2-download

Catch2-prefix/src/Catch2-stamp/Catch2-update: Catch2-prefix/src/Catch2-stamp/Catch2-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/akukh/Documents/Projects/simple-paint/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No update step for 'Catch2'"
	cd /Users/akukh/Documents/Projects/simple-paint/external/Catch2-master && /usr/local/Cellar/cmake/3.12.3/bin/cmake -E echo_append
	cd /Users/akukh/Documents/Projects/simple-paint/external/Catch2-master && /usr/local/Cellar/cmake/3.12.3/bin/cmake -E touch /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-stamp/Catch2-update

Catch2-prefix/src/Catch2-stamp/Catch2-patch: Catch2-prefix/src/Catch2-stamp/Catch2-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/akukh/Documents/Projects/simple-paint/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "No patch step for 'Catch2'"
	cd /Users/akukh/Documents/Projects/simple-paint/external/Catch2-master && /usr/local/Cellar/cmake/3.12.3/bin/cmake -E echo_append
	cd /Users/akukh/Documents/Projects/simple-paint/external/Catch2-master && /usr/local/Cellar/cmake/3.12.3/bin/cmake -E touch /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-stamp/Catch2-patch

Catch2-prefix/src/Catch2-stamp/Catch2-configure: Catch2-prefix/tmp/Catch2-cfgcmd.txt
Catch2-prefix/src/Catch2-stamp/Catch2-configure: Catch2-prefix/src/Catch2-stamp/Catch2-update
Catch2-prefix/src/Catch2-stamp/Catch2-configure: Catch2-prefix/src/Catch2-stamp/Catch2-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/akukh/Documents/Projects/simple-paint/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No configure step for 'Catch2'"
	cd /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-build && /usr/local/Cellar/cmake/3.12.3/bin/cmake -E echo_append
	cd /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-build && /usr/local/Cellar/cmake/3.12.3/bin/cmake -E touch /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-stamp/Catch2-configure

Catch2-prefix/src/Catch2-stamp/Catch2-build: Catch2-prefix/src/Catch2-stamp/Catch2-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/akukh/Documents/Projects/simple-paint/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No build step for 'Catch2'"
	cd /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-build && /usr/local/Cellar/cmake/3.12.3/bin/cmake -E echo_append
	cd /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-build && /usr/local/Cellar/cmake/3.12.3/bin/cmake -E touch /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-stamp/Catch2-build

Catch2-prefix/src/Catch2-stamp/Catch2-test: Catch2-prefix/src/Catch2-stamp/Catch2-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/akukh/Documents/Projects/simple-paint/tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "No test step for 'Catch2'"
	cd /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-build && /usr/local/Cellar/cmake/3.12.3/bin/cmake -E echo_append
	cd /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-build && /usr/local/Cellar/cmake/3.12.3/bin/cmake -E touch /Users/akukh/Documents/Projects/simple-paint/tests/build/Catch2-prefix/src/Catch2-stamp/Catch2-test

Catch2: CMakeFiles/Catch2
Catch2: CMakeFiles/Catch2-complete
Catch2: Catch2-prefix/src/Catch2-stamp/Catch2-install
Catch2: Catch2-prefix/src/Catch2-stamp/Catch2-mkdir
Catch2: Catch2-prefix/src/Catch2-stamp/Catch2-download
Catch2: Catch2-prefix/src/Catch2-stamp/Catch2-update
Catch2: Catch2-prefix/src/Catch2-stamp/Catch2-patch
Catch2: Catch2-prefix/src/Catch2-stamp/Catch2-configure
Catch2: Catch2-prefix/src/Catch2-stamp/Catch2-build
Catch2: Catch2-prefix/src/Catch2-stamp/Catch2-test
Catch2: CMakeFiles/Catch2.dir/build.make

.PHONY : Catch2

# Rule to build all files generated by this target.
CMakeFiles/Catch2.dir/build: Catch2

.PHONY : CMakeFiles/Catch2.dir/build

CMakeFiles/Catch2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Catch2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Catch2.dir/clean

CMakeFiles/Catch2.dir/depend:
	cd /Users/akukh/Documents/Projects/simple-paint/tests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/akukh/Documents/Projects/simple-paint/tests /Users/akukh/Documents/Projects/simple-paint/tests /Users/akukh/Documents/Projects/simple-paint/tests/build /Users/akukh/Documents/Projects/simple-paint/tests/build /Users/akukh/Documents/Projects/simple-paint/tests/build/CMakeFiles/Catch2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Catch2.dir/depend

