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
include Semantic/CMakeFiles/Semantic.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Semantic/CMakeFiles/Semantic.dir/compiler_depend.make

# Include the progress variables for this target.
include Semantic/CMakeFiles/Semantic.dir/progress.make

# Include the compile flags for this target's objects.
include Semantic/CMakeFiles/Semantic.dir/flags.make

Semantic/CMakeFiles/Semantic.dir/main.cpp.o: Semantic/CMakeFiles/Semantic.dir/flags.make
Semantic/CMakeFiles/Semantic.dir/main.cpp.o: ../Semantic/main.cpp
Semantic/CMakeFiles/Semantic.dir/main.cpp.o: Semantic/CMakeFiles/Semantic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/littlechai/University/XDU-Compilers--Principles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Semantic/CMakeFiles/Semantic.dir/main.cpp.o"
	cd /home/littlechai/University/XDU-Compilers--Principles/build/Semantic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Semantic/CMakeFiles/Semantic.dir/main.cpp.o -MF CMakeFiles/Semantic.dir/main.cpp.o.d -o CMakeFiles/Semantic.dir/main.cpp.o -c /home/littlechai/University/XDU-Compilers--Principles/Semantic/main.cpp

Semantic/CMakeFiles/Semantic.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Semantic.dir/main.cpp.i"
	cd /home/littlechai/University/XDU-Compilers--Principles/build/Semantic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/littlechai/University/XDU-Compilers--Principles/Semantic/main.cpp > CMakeFiles/Semantic.dir/main.cpp.i

Semantic/CMakeFiles/Semantic.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Semantic.dir/main.cpp.s"
	cd /home/littlechai/University/XDU-Compilers--Principles/build/Semantic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/littlechai/University/XDU-Compilers--Principles/Semantic/main.cpp -o CMakeFiles/Semantic.dir/main.cpp.s

Semantic/CMakeFiles/Semantic.dir/Semantic.cpp.o: Semantic/CMakeFiles/Semantic.dir/flags.make
Semantic/CMakeFiles/Semantic.dir/Semantic.cpp.o: ../Semantic/Semantic.cpp
Semantic/CMakeFiles/Semantic.dir/Semantic.cpp.o: Semantic/CMakeFiles/Semantic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/littlechai/University/XDU-Compilers--Principles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Semantic/CMakeFiles/Semantic.dir/Semantic.cpp.o"
	cd /home/littlechai/University/XDU-Compilers--Principles/build/Semantic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Semantic/CMakeFiles/Semantic.dir/Semantic.cpp.o -MF CMakeFiles/Semantic.dir/Semantic.cpp.o.d -o CMakeFiles/Semantic.dir/Semantic.cpp.o -c /home/littlechai/University/XDU-Compilers--Principles/Semantic/Semantic.cpp

Semantic/CMakeFiles/Semantic.dir/Semantic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Semantic.dir/Semantic.cpp.i"
	cd /home/littlechai/University/XDU-Compilers--Principles/build/Semantic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/littlechai/University/XDU-Compilers--Principles/Semantic/Semantic.cpp > CMakeFiles/Semantic.dir/Semantic.cpp.i

Semantic/CMakeFiles/Semantic.dir/Semantic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Semantic.dir/Semantic.cpp.s"
	cd /home/littlechai/University/XDU-Compilers--Principles/build/Semantic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/littlechai/University/XDU-Compilers--Principles/Semantic/Semantic.cpp -o CMakeFiles/Semantic.dir/Semantic.cpp.s

Semantic/CMakeFiles/Semantic.dir/Plotter.cpp.o: Semantic/CMakeFiles/Semantic.dir/flags.make
Semantic/CMakeFiles/Semantic.dir/Plotter.cpp.o: ../Semantic/Plotter.cpp
Semantic/CMakeFiles/Semantic.dir/Plotter.cpp.o: Semantic/CMakeFiles/Semantic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/littlechai/University/XDU-Compilers--Principles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Semantic/CMakeFiles/Semantic.dir/Plotter.cpp.o"
	cd /home/littlechai/University/XDU-Compilers--Principles/build/Semantic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Semantic/CMakeFiles/Semantic.dir/Plotter.cpp.o -MF CMakeFiles/Semantic.dir/Plotter.cpp.o.d -o CMakeFiles/Semantic.dir/Plotter.cpp.o -c /home/littlechai/University/XDU-Compilers--Principles/Semantic/Plotter.cpp

Semantic/CMakeFiles/Semantic.dir/Plotter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Semantic.dir/Plotter.cpp.i"
	cd /home/littlechai/University/XDU-Compilers--Principles/build/Semantic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/littlechai/University/XDU-Compilers--Principles/Semantic/Plotter.cpp > CMakeFiles/Semantic.dir/Plotter.cpp.i

Semantic/CMakeFiles/Semantic.dir/Plotter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Semantic.dir/Plotter.cpp.s"
	cd /home/littlechai/University/XDU-Compilers--Principles/build/Semantic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/littlechai/University/XDU-Compilers--Principles/Semantic/Plotter.cpp -o CMakeFiles/Semantic.dir/Plotter.cpp.s

Semantic/CMakeFiles/Semantic.dir/Point.cpp.o: Semantic/CMakeFiles/Semantic.dir/flags.make
Semantic/CMakeFiles/Semantic.dir/Point.cpp.o: ../Semantic/Point.cpp
Semantic/CMakeFiles/Semantic.dir/Point.cpp.o: Semantic/CMakeFiles/Semantic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/littlechai/University/XDU-Compilers--Principles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object Semantic/CMakeFiles/Semantic.dir/Point.cpp.o"
	cd /home/littlechai/University/XDU-Compilers--Principles/build/Semantic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Semantic/CMakeFiles/Semantic.dir/Point.cpp.o -MF CMakeFiles/Semantic.dir/Point.cpp.o.d -o CMakeFiles/Semantic.dir/Point.cpp.o -c /home/littlechai/University/XDU-Compilers--Principles/Semantic/Point.cpp

Semantic/CMakeFiles/Semantic.dir/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Semantic.dir/Point.cpp.i"
	cd /home/littlechai/University/XDU-Compilers--Principles/build/Semantic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/littlechai/University/XDU-Compilers--Principles/Semantic/Point.cpp > CMakeFiles/Semantic.dir/Point.cpp.i

Semantic/CMakeFiles/Semantic.dir/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Semantic.dir/Point.cpp.s"
	cd /home/littlechai/University/XDU-Compilers--Principles/build/Semantic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/littlechai/University/XDU-Compilers--Principles/Semantic/Point.cpp -o CMakeFiles/Semantic.dir/Point.cpp.s

# Object files for target Semantic
Semantic_OBJECTS = \
"CMakeFiles/Semantic.dir/main.cpp.o" \
"CMakeFiles/Semantic.dir/Semantic.cpp.o" \
"CMakeFiles/Semantic.dir/Plotter.cpp.o" \
"CMakeFiles/Semantic.dir/Point.cpp.o"

# External object files for target Semantic
Semantic_EXTERNAL_OBJECTS =

Semantic/Semantic: Semantic/CMakeFiles/Semantic.dir/main.cpp.o
Semantic/Semantic: Semantic/CMakeFiles/Semantic.dir/Semantic.cpp.o
Semantic/Semantic: Semantic/CMakeFiles/Semantic.dir/Plotter.cpp.o
Semantic/Semantic: Semantic/CMakeFiles/Semantic.dir/Point.cpp.o
Semantic/Semantic: Semantic/CMakeFiles/Semantic.dir/build.make
Semantic/Semantic: ../Semantic/../lib/libScanner_lib.so
Semantic/Semantic: ../Semantic/../lib/libParser_lib.so
Semantic/Semantic: ../Semantic/../lib/libExceptionLog_lib.so
Semantic/Semantic: /usr/local/lib/libopencv_gapi.so.4.6.0
Semantic/Semantic: /usr/local/lib/libopencv_highgui.so.4.6.0
Semantic/Semantic: /usr/local/lib/libopencv_ml.so.4.6.0
Semantic/Semantic: /usr/local/lib/libopencv_objdetect.so.4.6.0
Semantic/Semantic: /usr/local/lib/libopencv_photo.so.4.6.0
Semantic/Semantic: /usr/local/lib/libopencv_stitching.so.4.6.0
Semantic/Semantic: /usr/local/lib/libopencv_video.so.4.6.0
Semantic/Semantic: /usr/local/lib/libopencv_videoio.so.4.6.0
Semantic/Semantic: /usr/local/lib/libopencv_imgcodecs.so.4.6.0
Semantic/Semantic: /usr/local/lib/libopencv_dnn.so.4.6.0
Semantic/Semantic: /usr/local/lib/libopencv_calib3d.so.4.6.0
Semantic/Semantic: /usr/local/lib/libopencv_features2d.so.4.6.0
Semantic/Semantic: /usr/local/lib/libopencv_flann.so.4.6.0
Semantic/Semantic: /usr/local/lib/libopencv_imgproc.so.4.6.0
Semantic/Semantic: /usr/local/lib/libopencv_core.so.4.6.0
Semantic/Semantic: Semantic/CMakeFiles/Semantic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/littlechai/University/XDU-Compilers--Principles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Semantic"
	cd /home/littlechai/University/XDU-Compilers--Principles/build/Semantic && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Semantic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Semantic/CMakeFiles/Semantic.dir/build: Semantic/Semantic
.PHONY : Semantic/CMakeFiles/Semantic.dir/build

Semantic/CMakeFiles/Semantic.dir/clean:
	cd /home/littlechai/University/XDU-Compilers--Principles/build/Semantic && $(CMAKE_COMMAND) -P CMakeFiles/Semantic.dir/cmake_clean.cmake
.PHONY : Semantic/CMakeFiles/Semantic.dir/clean

Semantic/CMakeFiles/Semantic.dir/depend:
	cd /home/littlechai/University/XDU-Compilers--Principles/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/littlechai/University/XDU-Compilers--Principles /home/littlechai/University/XDU-Compilers--Principles/Semantic /home/littlechai/University/XDU-Compilers--Principles/build /home/littlechai/University/XDU-Compilers--Principles/build/Semantic /home/littlechai/University/XDU-Compilers--Principles/build/Semantic/CMakeFiles/Semantic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Semantic/CMakeFiles/Semantic.dir/depend

