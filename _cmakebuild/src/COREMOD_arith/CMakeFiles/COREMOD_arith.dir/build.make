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
CMAKE_BINARY_DIR = /data1/src/milk/_build

# Include any dependencies generated for this target.
include src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/depend.make

# Include the progress variables for this target.
include src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/progress.make

# Include the compile flags for this target's objects.
include src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/flags.make

src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.o: src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/flags.make
src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.o: ../src/COREMOD_arith/COREMOD_arith.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data1/src/milk/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.o"
	cd /data1/src/milk/_build/src/COREMOD_arith && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.o   -c /data1/src/milk/src/COREMOD_arith/COREMOD_arith.c

src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.i"
	cd /data1/src/milk/_build/src/COREMOD_arith && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /data1/src/milk/src/COREMOD_arith/COREMOD_arith.c > CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.i

src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.s"
	cd /data1/src/milk/_build/src/COREMOD_arith && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /data1/src/milk/src/COREMOD_arith/COREMOD_arith.c -o CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.s

src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.o.requires:

.PHONY : src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.o.requires

src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.o.provides: src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.o.requires
	$(MAKE) -f src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/build.make src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.o.provides.build
.PHONY : src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.o.provides

src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.o.provides.build: src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.o


# Object files for target COREMOD_arith
COREMOD_arith_OBJECTS = \
"CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.o"

# External object files for target COREMOD_arith
COREMOD_arith_EXTERNAL_OBJECTS =

src/COREMOD_arith/libCOREMOD_arith.so: src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.o
src/COREMOD_arith/libCOREMOD_arith.so: src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/build.make
src/COREMOD_arith/libCOREMOD_arith.so: src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data1/src/milk/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libCOREMOD_arith.so"
	cd /data1/src/milk/_build/src/COREMOD_arith && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/COREMOD_arith.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/build: src/COREMOD_arith/libCOREMOD_arith.so

.PHONY : src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/build

src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/requires: src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/COREMOD_arith.c.o.requires

.PHONY : src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/requires

src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/clean:
	cd /data1/src/milk/_build/src/COREMOD_arith && $(CMAKE_COMMAND) -P CMakeFiles/COREMOD_arith.dir/cmake_clean.cmake
.PHONY : src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/clean

src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/depend:
	cd /data1/src/milk/_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data1/src/milk /data1/src/milk/src/COREMOD_arith /data1/src/milk/_build /data1/src/milk/_build/src/COREMOD_arith /data1/src/milk/_build/src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/COREMOD_arith/CMakeFiles/COREMOD_arith.dir/depend

