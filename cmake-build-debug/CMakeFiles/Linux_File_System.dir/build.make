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
CMAKE_COMMAND = /snap/clion/39/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/39/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/mmuazekici/CLionProjects/Linux File System"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/mmuazekici/CLionProjects/Linux File System/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Linux_File_System.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Linux_File_System.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Linux_File_System.dir/flags.make

CMakeFiles/Linux_File_System.dir/main.c.o: CMakeFiles/Linux_File_System.dir/flags.make
CMakeFiles/Linux_File_System.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/mmuazekici/CLionProjects/Linux File System/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Linux_File_System.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Linux_File_System.dir/main.c.o   -c "/home/mmuazekici/CLionProjects/Linux File System/main.c"

CMakeFiles/Linux_File_System.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Linux_File_System.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/mmuazekici/CLionProjects/Linux File System/main.c" > CMakeFiles/Linux_File_System.dir/main.c.i

CMakeFiles/Linux_File_System.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Linux_File_System.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/mmuazekici/CLionProjects/Linux File System/main.c" -o CMakeFiles/Linux_File_System.dir/main.c.s

# Object files for target Linux_File_System
Linux_File_System_OBJECTS = \
"CMakeFiles/Linux_File_System.dir/main.c.o"

# External object files for target Linux_File_System
Linux_File_System_EXTERNAL_OBJECTS =

Linux_File_System: CMakeFiles/Linux_File_System.dir/main.c.o
Linux_File_System: CMakeFiles/Linux_File_System.dir/build.make
Linux_File_System: CMakeFiles/Linux_File_System.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/mmuazekici/CLionProjects/Linux File System/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Linux_File_System"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Linux_File_System.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Linux_File_System.dir/build: Linux_File_System

.PHONY : CMakeFiles/Linux_File_System.dir/build

CMakeFiles/Linux_File_System.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Linux_File_System.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Linux_File_System.dir/clean

CMakeFiles/Linux_File_System.dir/depend:
	cd "/home/mmuazekici/CLionProjects/Linux File System/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/mmuazekici/CLionProjects/Linux File System" "/home/mmuazekici/CLionProjects/Linux File System" "/home/mmuazekici/CLionProjects/Linux File System/cmake-build-debug" "/home/mmuazekici/CLionProjects/Linux File System/cmake-build-debug" "/home/mmuazekici/CLionProjects/Linux File System/cmake-build-debug/CMakeFiles/Linux_File_System.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Linux_File_System.dir/depend

