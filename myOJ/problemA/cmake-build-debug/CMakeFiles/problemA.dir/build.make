# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = C:\Users\86150\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\191.6707.62\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\86150\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\191.6707.62\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\86150\CLionProjects\problemA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\86150\CLionProjects\problemA\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/problemA.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/problemA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/problemA.dir/flags.make

CMakeFiles/problemA.dir/main.cpp.obj: CMakeFiles/problemA.dir/flags.make
CMakeFiles/problemA.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\86150\CLionProjects\problemA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/problemA.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\problemA.dir\main.cpp.obj -c C:\Users\86150\CLionProjects\problemA\main.cpp

CMakeFiles/problemA.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/problemA.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\86150\CLionProjects\problemA\main.cpp > CMakeFiles\problemA.dir\main.cpp.i

CMakeFiles/problemA.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/problemA.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\86150\CLionProjects\problemA\main.cpp -o CMakeFiles\problemA.dir\main.cpp.s

# Object files for target problemA
problemA_OBJECTS = \
"CMakeFiles/problemA.dir/main.cpp.obj"

# External object files for target problemA
problemA_EXTERNAL_OBJECTS =

problemA.exe: CMakeFiles/problemA.dir/main.cpp.obj
problemA.exe: CMakeFiles/problemA.dir/build.make
problemA.exe: CMakeFiles/problemA.dir/linklibs.rsp
problemA.exe: CMakeFiles/problemA.dir/objects1.rsp
problemA.exe: CMakeFiles/problemA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\86150\CLionProjects\problemA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable problemA.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\problemA.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/problemA.dir/build: problemA.exe

.PHONY : CMakeFiles/problemA.dir/build

CMakeFiles/problemA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\problemA.dir\cmake_clean.cmake
.PHONY : CMakeFiles/problemA.dir/clean

CMakeFiles/problemA.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\86150\CLionProjects\problemA C:\Users\86150\CLionProjects\problemA C:\Users\86150\CLionProjects\problemA\cmake-build-debug C:\Users\86150\CLionProjects\problemA\cmake-build-debug C:\Users\86150\CLionProjects\problemA\cmake-build-debug\CMakeFiles\problemA.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/problemA.dir/depend

