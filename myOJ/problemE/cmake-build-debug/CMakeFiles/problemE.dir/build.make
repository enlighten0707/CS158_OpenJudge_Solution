# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\86150\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\191.6183.77\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\86150\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\191.6183.77\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\86150\CLionProjects\problemE

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\86150\CLionProjects\problemE\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/problemE.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/problemE.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/problemE.dir/flags.make

CMakeFiles/problemE.dir/main.cpp.obj: CMakeFiles/problemE.dir/flags.make
CMakeFiles/problemE.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\86150\CLionProjects\problemE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/problemE.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\problemE.dir\main.cpp.obj -c C:\Users\86150\CLionProjects\problemE\main.cpp

CMakeFiles/problemE.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/problemE.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\86150\CLionProjects\problemE\main.cpp > CMakeFiles\problemE.dir\main.cpp.i

CMakeFiles/problemE.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/problemE.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\86150\CLionProjects\problemE\main.cpp -o CMakeFiles\problemE.dir\main.cpp.s

# Object files for target problemE
problemE_OBJECTS = \
"CMakeFiles/problemE.dir/main.cpp.obj"

# External object files for target problemE
problemE_EXTERNAL_OBJECTS =

problemE.exe: CMakeFiles/problemE.dir/main.cpp.obj
problemE.exe: CMakeFiles/problemE.dir/build.make
problemE.exe: CMakeFiles/problemE.dir/linklibs.rsp
problemE.exe: CMakeFiles/problemE.dir/objects1.rsp
problemE.exe: CMakeFiles/problemE.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\86150\CLionProjects\problemE\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable problemE.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\problemE.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/problemE.dir/build: problemE.exe

.PHONY : CMakeFiles/problemE.dir/build

CMakeFiles/problemE.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\problemE.dir\cmake_clean.cmake
.PHONY : CMakeFiles/problemE.dir/clean

CMakeFiles/problemE.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\86150\CLionProjects\problemE C:\Users\86150\CLionProjects\problemE C:\Users\86150\CLionProjects\problemE\cmake-build-debug C:\Users\86150\CLionProjects\problemE\cmake-build-debug C:\Users\86150\CLionProjects\problemE\cmake-build-debug\CMakeFiles\problemE.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/problemE.dir/depend

