# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /opt/clion-2020.3.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2020.3.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/junyong/CLionProjects/StarCraft

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/junyong/CLionProjects/StarCraft/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Reference.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Reference.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Reference.dir/flags.make

CMakeFiles/Reference.dir/main.cpp.o: CMakeFiles/Reference.dir/flags.make
CMakeFiles/Reference.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/junyong/CLionProjects/StarCraft/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Reference.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Reference.dir/main.cpp.o -c /home/junyong/CLionProjects/StarCraft/main.cpp

CMakeFiles/Reference.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Reference.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/junyong/CLionProjects/StarCraft/main.cpp > CMakeFiles/Reference.dir/main.cpp.i

CMakeFiles/Reference.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Reference.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/junyong/CLionProjects/StarCraft/main.cpp -o CMakeFiles/Reference.dir/main.cpp.s

# Object files for target Reference
Reference_OBJECTS = \
"CMakeFiles/Reference.dir/main.cpp.o"

# External object files for target Reference
Reference_EXTERNAL_OBJECTS =

Reference: CMakeFiles/Reference.dir/main.cpp.o
Reference: CMakeFiles/Reference.dir/build.make
Reference: CMakeFiles/Reference.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/junyong/CLionProjects/StarCraft/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Reference"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Reference.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Reference.dir/build: Reference

.PHONY : CMakeFiles/Reference.dir/build

CMakeFiles/Reference.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Reference.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Reference.dir/clean

CMakeFiles/Reference.dir/depend:
	cd /home/junyong/CLionProjects/StarCraft/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/junyong/CLionProjects/StarCraft /home/junyong/CLionProjects/StarCraft /home/junyong/CLionProjects/StarCraft/cmake-build-debug /home/junyong/CLionProjects/StarCraft/cmake-build-debug /home/junyong/CLionProjects/StarCraft/cmake-build-debug/CMakeFiles/Reference.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Reference.dir/depend

