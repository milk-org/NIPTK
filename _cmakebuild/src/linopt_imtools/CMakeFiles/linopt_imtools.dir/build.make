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
include src/linopt_imtools/CMakeFiles/linopt_imtools.dir/depend.make

# Include the progress variables for this target.
include src/linopt_imtools/CMakeFiles/linopt_imtools.dir/progress.make

# Include the compile flags for this target's objects.
include src/linopt_imtools/CMakeFiles/linopt_imtools.dir/flags.make

src/linopt_imtools/CMakeFiles/linopt_imtools.dir/linopt_imtools.c.o: src/linopt_imtools/CMakeFiles/linopt_imtools.dir/flags.make
src/linopt_imtools/CMakeFiles/linopt_imtools.dir/linopt_imtools.c.o: ../src/linopt_imtools/linopt_imtools.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data1/src/milk/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/linopt_imtools/CMakeFiles/linopt_imtools.dir/linopt_imtools.c.o"
	cd /data1/src/milk/_build/src/linopt_imtools && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/linopt_imtools.dir/linopt_imtools.c.o   -c /data1/src/milk/src/linopt_imtools/linopt_imtools.c

src/linopt_imtools/CMakeFiles/linopt_imtools.dir/linopt_imtools.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/linopt_imtools.dir/linopt_imtools.c.i"
	cd /data1/src/milk/_build/src/linopt_imtools && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /data1/src/milk/src/linopt_imtools/linopt_imtools.c > CMakeFiles/linopt_imtools.dir/linopt_imtools.c.i

src/linopt_imtools/CMakeFiles/linopt_imtools.dir/linopt_imtools.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/linopt_imtools.dir/linopt_imtools.c.s"
	cd /data1/src/milk/_build/src/linopt_imtools && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /data1/src/milk/src/linopt_imtools/linopt_imtools.c -o CMakeFiles/linopt_imtools.dir/linopt_imtools.c.s

src/linopt_imtools/CMakeFiles/linopt_imtools.dir/linopt_imtools.c.o.requires:

.PHONY : src/linopt_imtools/CMakeFiles/linopt_imtools.dir/linopt_imtools.c.o.requires

src/linopt_imtools/CMakeFiles/linopt_imtools.dir/linopt_imtools.c.o.provides: src/linopt_imtools/CMakeFiles/linopt_imtools.dir/linopt_imtools.c.o.requires
	$(MAKE) -f src/linopt_imtools/CMakeFiles/linopt_imtools.dir/build.make src/linopt_imtools/CMakeFiles/linopt_imtools.dir/linopt_imtools.c.o.provides.build
.PHONY : src/linopt_imtools/CMakeFiles/linopt_imtools.dir/linopt_imtools.c.o.provides

src/linopt_imtools/CMakeFiles/linopt_imtools.dir/linopt_imtools.c.o.provides.build: src/linopt_imtools/CMakeFiles/linopt_imtools.dir/linopt_imtools.c.o


# Object files for target linopt_imtools
linopt_imtools_OBJECTS = \
"CMakeFiles/linopt_imtools.dir/linopt_imtools.c.o"

# External object files for target linopt_imtools
linopt_imtools_EXTERNAL_OBJECTS =

src/linopt_imtools/liblinopt_imtools.so: src/linopt_imtools/CMakeFiles/linopt_imtools.dir/linopt_imtools.c.o
src/linopt_imtools/liblinopt_imtools.so: src/linopt_imtools/CMakeFiles/linopt_imtools.dir/build.make
src/linopt_imtools/liblinopt_imtools.so: src/linopt_imtools/CMakeFiles/linopt_imtools.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data1/src/milk/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library liblinopt_imtools.so"
	cd /data1/src/milk/_build/src/linopt_imtools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linopt_imtools.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/linopt_imtools/CMakeFiles/linopt_imtools.dir/build: src/linopt_imtools/liblinopt_imtools.so

.PHONY : src/linopt_imtools/CMakeFiles/linopt_imtools.dir/build

src/linopt_imtools/CMakeFiles/linopt_imtools.dir/requires: src/linopt_imtools/CMakeFiles/linopt_imtools.dir/linopt_imtools.c.o.requires

.PHONY : src/linopt_imtools/CMakeFiles/linopt_imtools.dir/requires

src/linopt_imtools/CMakeFiles/linopt_imtools.dir/clean:
	cd /data1/src/milk/_build/src/linopt_imtools && $(CMAKE_COMMAND) -P CMakeFiles/linopt_imtools.dir/cmake_clean.cmake
.PHONY : src/linopt_imtools/CMakeFiles/linopt_imtools.dir/clean

src/linopt_imtools/CMakeFiles/linopt_imtools.dir/depend:
	cd /data1/src/milk/_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data1/src/milk /data1/src/milk/src/linopt_imtools /data1/src/milk/_build /data1/src/milk/_build/src/linopt_imtools /data1/src/milk/_build/src/linopt_imtools/CMakeFiles/linopt_imtools.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/linopt_imtools/CMakeFiles/linopt_imtools.dir/depend

