# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = /home/ubuntu/workspace/cserver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/workspace/cserver

# Include any dependencies generated for this target.
include CMakeFiles/cserver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cserver.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cserver.dir/flags.make

CMakeFiles/cserver.dir/cserver/log.cc.o: CMakeFiles/cserver.dir/flags.make
CMakeFiles/cserver.dir/cserver/log.cc.o: cserver/log.cc
CMakeFiles/cserver.dir/cserver/log.cc.o: CMakeFiles/cserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/workspace/cserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cserver.dir/cserver/log.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cserver.dir/cserver/log.cc.o -MF CMakeFiles/cserver.dir/cserver/log.cc.o.d -o CMakeFiles/cserver.dir/cserver/log.cc.o -c /home/ubuntu/workspace/cserver/cserver/log.cc

CMakeFiles/cserver.dir/cserver/log.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cserver.dir/cserver/log.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/workspace/cserver/cserver/log.cc > CMakeFiles/cserver.dir/cserver/log.cc.i

CMakeFiles/cserver.dir/cserver/log.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cserver.dir/cserver/log.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/workspace/cserver/cserver/log.cc -o CMakeFiles/cserver.dir/cserver/log.cc.s

# Object files for target cserver
cserver_OBJECTS = \
"CMakeFiles/cserver.dir/cserver/log.cc.o"

# External object files for target cserver
cserver_EXTERNAL_OBJECTS =

bin/libcserver.so: CMakeFiles/cserver.dir/cserver/log.cc.o
bin/libcserver.so: CMakeFiles/cserver.dir/build.make
bin/libcserver.so: CMakeFiles/cserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/workspace/cserver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library bin/libcserver.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cserver.dir/build: bin/libcserver.so
.PHONY : CMakeFiles/cserver.dir/build

CMakeFiles/cserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cserver.dir/clean

CMakeFiles/cserver.dir/depend:
	cd /home/ubuntu/workspace/cserver && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/workspace/cserver /home/ubuntu/workspace/cserver /home/ubuntu/workspace/cserver /home/ubuntu/workspace/cserver /home/ubuntu/workspace/cserver/CMakeFiles/cserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cserver.dir/depend
