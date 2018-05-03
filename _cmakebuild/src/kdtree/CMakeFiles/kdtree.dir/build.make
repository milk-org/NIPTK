# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /data1/src/milk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /data1/src/milk/_cmakebuild

# Include any dependencies generated for this target.
include src/kdtree/CMakeFiles/kdtree.dir/depend.make

# Include the progress variables for this target.
include src/kdtree/CMakeFiles/kdtree.dir/progress.make

# Include the compile flags for this target's objects.
include src/kdtree/CMakeFiles/kdtree.dir/flags.make

src/kdtree/CMakeFiles/kdtree.dir/kdtree.c.o: src/kdtree/CMakeFiles/kdtree.dir/flags.make
src/kdtree/CMakeFiles/kdtree.dir/kdtree.c.o: ../src/kdtree/kdtree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data1/src/milk/_cmakebuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/kdtree/CMakeFiles/kdtree.dir/kdtree.c.o"
	cd /data1/src/milk/_cmakebuild/src/kdtree && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/kdtree.dir/kdtree.c.o   -c /data1/src/milk/src/kdtree/kdtree.c

src/kdtree/CMakeFiles/kdtree.dir/kdtree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/kdtree.dir/kdtree.c.i"
	cd /data1/src/milk/_cmakebuild/src/kdtree && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /data1/src/milk/src/kdtree/kdtree.c > CMakeFiles/kdtree.dir/kdtree.c.i

src/kdtree/CMakeFiles/kdtree.dir/kdtree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/kdtree.dir/kdtree.c.s"
	cd /data1/src/milk/_cmakebuild/src/kdtree && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /data1/src/milk/src/kdtree/kdtree.c -o CMakeFiles/kdtree.dir/kdtree.c.s

src/kdtree/CMakeFiles/kdtree.dir/kdtree.c.o.requires:

.PHONY : src/kdtree/CMakeFiles/kdtree.dir/kdtree.c.o.requires

src/kdtree/CMakeFiles/kdtree.dir/kdtree.c.o.provides: src/kdtree/CMakeFiles/kdtree.dir/kdtree.c.o.requires
	$(MAKE) -f src/kdtree/CMakeFiles/kdtree.dir/build.make src/kdtree/CMakeFiles/kdtree.dir/kdtree.c.o.provides.build
.PHONY : src/kdtree/CMakeFiles/kdtree.dir/kdtree.c.o.provides

src/kdtree/CMakeFiles/kdtree.dir/kdtree.c.o.provides.build: src/kdtree/CMakeFiles/kdtree.dir/kdtree.c.o


# Object files for target kdtree
kdtree_OBJECTS = \
"CMakeFiles/kdtree.dir/kdtree.c.o"

# External object files for target kdtree
kdtree_EXTERNAL_OBJECTS =

src/kdtree/libkdtree.so: src/kdtree/CMakeFiles/kdtree.dir/kdtree.c.o
src/kdtree/libkdtree.so: src/kdtree/CMakeFiles/kdtree.dir/build.make
src/kdtree/libkdtree.so: src/kdtree/CMakeFiles/kdtree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data1/src/milk/_cmakebuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libkdtree.so"
	cd /data1/src/milk/_cmakebuild/src/kdtree && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kdtree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/kdtree/CMakeFiles/kdtree.dir/build: src/kdtree/libkdtree.so

.PHONY : src/kdtree/CMakeFiles/kdtree.dir/build

src/kdtree/CMakeFiles/kdtree.dir/requires: src/kdtree/CMakeFiles/kdtree.dir/kdtree.c.o.requires

.PHONY : src/kdtree/CMakeFiles/kdtree.dir/requires

src/kdtree/CMakeFiles/kdtree.dir/clean:
	cd /data1/src/milk/_cmakebuild/src/kdtree && $(CMAKE_COMMAND) -P CMakeFiles/kdtree.dir/cmake_clean.cmake
.PHONY : src/kdtree/CMakeFiles/kdtree.dir/clean

src/kdtree/CMakeFiles/kdtree.dir/depend:
	cd /data1/src/milk/_cmakebuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data1/src/milk /data1/src/milk/src/kdtree /data1/src/milk/_cmakebuild /data1/src/milk/_cmakebuild/src/kdtree /data1/src/milk/_cmakebuild/src/kdtree/CMakeFiles/kdtree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/kdtree/CMakeFiles/kdtree.dir/depend

