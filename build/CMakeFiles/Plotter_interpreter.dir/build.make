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
CMAKE_SOURCE_DIR = /home/littlechai/University/XDU-Compilers--Principles

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/littlechai/University/XDU-Compilers--Principles/build

# Include any dependencies generated for this target.
include CMakeFiles/Plotter_interpreter.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Plotter_interpreter.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Plotter_interpreter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Plotter_interpreter.dir/flags.make

CMakeFiles/Plotter_interpreter.dir/main.cpp.o: CMakeFiles/Plotter_interpreter.dir/flags.make
CMakeFiles/Plotter_interpreter.dir/main.cpp.o: ../main.cpp
CMakeFiles/Plotter_interpreter.dir/main.cpp.o: CMakeFiles/Plotter_interpreter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/littlechai/University/XDU-Compilers--Principles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Plotter_interpreter.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Plotter_interpreter.dir/main.cpp.o -MF CMakeFiles/Plotter_interpreter.dir/main.cpp.o.d -o CMakeFiles/Plotter_interpreter.dir/main.cpp.o -c /home/littlechai/University/XDU-Compilers--Principles/main.cpp

CMakeFiles/Plotter_interpreter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Plotter_interpreter.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/littlechai/University/XDU-Compilers--Principles/main.cpp > CMakeFiles/Plotter_interpreter.dir/main.cpp.i

CMakeFiles/Plotter_interpreter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Plotter_interpreter.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/littlechai/University/XDU-Compilers--Principles/main.cpp -o CMakeFiles/Plotter_interpreter.dir/main.cpp.s

# Object files for target Plotter_interpreter
Plotter_interpreter_OBJECTS = \
"CMakeFiles/Plotter_interpreter.dir/main.cpp.o"

# External object files for target Plotter_interpreter
Plotter_interpreter_EXTERNAL_OBJECTS =

Plotter_interpreter: CMakeFiles/Plotter_interpreter.dir/main.cpp.o
Plotter_interpreter: CMakeFiles/Plotter_interpreter.dir/build.make
Plotter_interpreter: CMakeFiles/Plotter_interpreter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/littlechai/University/XDU-Compilers--Principles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Plotter_interpreter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Plotter_interpreter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Plotter_interpreter.dir/build: Plotter_interpreter
.PHONY : CMakeFiles/Plotter_interpreter.dir/build

CMakeFiles/Plotter_interpreter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Plotter_interpreter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Plotter_interpreter.dir/clean

CMakeFiles/Plotter_interpreter.dir/depend:
	cd /home/littlechai/University/XDU-Compilers--Principles/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/littlechai/University/XDU-Compilers--Principles /home/littlechai/University/XDU-Compilers--Principles /home/littlechai/University/XDU-Compilers--Principles/build /home/littlechai/University/XDU-Compilers--Principles/build /home/littlechai/University/XDU-Compilers--Principles/build/CMakeFiles/Plotter_interpreter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Plotter_interpreter.dir/depend

