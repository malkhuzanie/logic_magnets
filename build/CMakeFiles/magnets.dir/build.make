# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_SOURCE_DIR = /home/tomato/pr/search_algo/magnets_game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tomato/pr/search_algo/magnets_game/build

# Include any dependencies generated for this target.
include CMakeFiles/magnets.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/magnets.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/magnets.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/magnets.dir/flags.make

CMakeFiles/magnets.dir/main.cpp.o: CMakeFiles/magnets.dir/flags.make
CMakeFiles/magnets.dir/main.cpp.o: /home/tomato/pr/search_algo/magnets_game/main.cpp
CMakeFiles/magnets.dir/main.cpp.o: CMakeFiles/magnets.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/tomato/pr/search_algo/magnets_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/magnets.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/magnets.dir/main.cpp.o -MF CMakeFiles/magnets.dir/main.cpp.o.d -o CMakeFiles/magnets.dir/main.cpp.o -c /home/tomato/pr/search_algo/magnets_game/main.cpp

CMakeFiles/magnets.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/magnets.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tomato/pr/search_algo/magnets_game/main.cpp > CMakeFiles/magnets.dir/main.cpp.i

CMakeFiles/magnets.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/magnets.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tomato/pr/search_algo/magnets_game/main.cpp -o CMakeFiles/magnets.dir/main.cpp.s

# Object files for target magnets
magnets_OBJECTS = \
"CMakeFiles/magnets.dir/main.cpp.o"

# External object files for target magnets
magnets_EXTERNAL_OBJECTS =

magnets: CMakeFiles/magnets.dir/main.cpp.o
magnets: CMakeFiles/magnets.dir/build.make
magnets: /usr/lib64/libncurses.so
magnets: /usr/lib64/libtinfo.so
magnets: /usr/lib64/libform.so
magnets: CMakeFiles/magnets.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/tomato/pr/search_algo/magnets_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable magnets"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/magnets.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/magnets.dir/build: magnets
.PHONY : CMakeFiles/magnets.dir/build

CMakeFiles/magnets.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/magnets.dir/cmake_clean.cmake
.PHONY : CMakeFiles/magnets.dir/clean

CMakeFiles/magnets.dir/depend:
	cd /home/tomato/pr/search_algo/magnets_game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tomato/pr/search_algo/magnets_game /home/tomato/pr/search_algo/magnets_game /home/tomato/pr/search_algo/magnets_game/build /home/tomato/pr/search_algo/magnets_game/build /home/tomato/pr/search_algo/magnets_game/build/CMakeFiles/magnets.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/magnets.dir/depend
