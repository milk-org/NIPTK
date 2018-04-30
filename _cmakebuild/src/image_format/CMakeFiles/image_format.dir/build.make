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
include src/image_format/CMakeFiles/image_format.dir/depend.make

# Include the progress variables for this target.
include src/image_format/CMakeFiles/image_format.dir/progress.make

# Include the compile flags for this target's objects.
include src/image_format/CMakeFiles/image_format.dir/flags.make

src/image_format/CMakeFiles/image_format.dir/image_format.c.o: src/image_format/CMakeFiles/image_format.dir/flags.make
src/image_format/CMakeFiles/image_format.dir/image_format.c.o: ../src/image_format/image_format.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data1/src/milk/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/image_format/CMakeFiles/image_format.dir/image_format.c.o"
	cd /data1/src/milk/_build/src/image_format && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/image_format.dir/image_format.c.o   -c /data1/src/milk/src/image_format/image_format.c

src/image_format/CMakeFiles/image_format.dir/image_format.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/image_format.dir/image_format.c.i"
	cd /data1/src/milk/_build/src/image_format && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /data1/src/milk/src/image_format/image_format.c > CMakeFiles/image_format.dir/image_format.c.i

src/image_format/CMakeFiles/image_format.dir/image_format.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/image_format.dir/image_format.c.s"
	cd /data1/src/milk/_build/src/image_format && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /data1/src/milk/src/image_format/image_format.c -o CMakeFiles/image_format.dir/image_format.c.s

src/image_format/CMakeFiles/image_format.dir/image_format.c.o.requires:

.PHONY : src/image_format/CMakeFiles/image_format.dir/image_format.c.o.requires

src/image_format/CMakeFiles/image_format.dir/image_format.c.o.provides: src/image_format/CMakeFiles/image_format.dir/image_format.c.o.requires
	$(MAKE) -f src/image_format/CMakeFiles/image_format.dir/build.make src/image_format/CMakeFiles/image_format.dir/image_format.c.o.provides.build
.PHONY : src/image_format/CMakeFiles/image_format.dir/image_format.c.o.provides

src/image_format/CMakeFiles/image_format.dir/image_format.c.o.provides.build: src/image_format/CMakeFiles/image_format.dir/image_format.c.o


# Object files for target image_format
image_format_OBJECTS = \
"CMakeFiles/image_format.dir/image_format.c.o"

# External object files for target image_format
image_format_EXTERNAL_OBJECTS =

src/image_format/libimage_format.so: src/image_format/CMakeFiles/image_format.dir/image_format.c.o
src/image_format/libimage_format.so: src/image_format/CMakeFiles/image_format.dir/build.make
src/image_format/libimage_format.so: src/image_format/CMakeFiles/image_format.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data1/src/milk/_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libimage_format.so"
	cd /data1/src/milk/_build/src/image_format && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/image_format.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/image_format/CMakeFiles/image_format.dir/build: src/image_format/libimage_format.so

.PHONY : src/image_format/CMakeFiles/image_format.dir/build

src/image_format/CMakeFiles/image_format.dir/requires: src/image_format/CMakeFiles/image_format.dir/image_format.c.o.requires

.PHONY : src/image_format/CMakeFiles/image_format.dir/requires

src/image_format/CMakeFiles/image_format.dir/clean:
	cd /data1/src/milk/_build/src/image_format && $(CMAKE_COMMAND) -P CMakeFiles/image_format.dir/cmake_clean.cmake
.PHONY : src/image_format/CMakeFiles/image_format.dir/clean

src/image_format/CMakeFiles/image_format.dir/depend:
	cd /data1/src/milk/_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data1/src/milk /data1/src/milk/src/image_format /data1/src/milk/_build /data1/src/milk/_build/src/image_format /data1/src/milk/_build/src/image_format/CMakeFiles/image_format.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/image_format/CMakeFiles/image_format.dir/depend

