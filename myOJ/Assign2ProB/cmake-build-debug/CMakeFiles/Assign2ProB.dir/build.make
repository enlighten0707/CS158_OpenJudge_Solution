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
CMAKE_COMMAND = C:\Users\86150\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\191.6707.69\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\86150\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\191.6707.69\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\86150\CLionProjects\Assign2ProB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\86150\CLionProjects\Assign2ProB\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Assign2ProB.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assign2ProB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assign2ProB.dir/flags.make

CMakeFiles/Assign2ProB.dir/main.cpp.obj: CMakeFiles/Assign2ProB.dir/flags.make
CMakeFiles/Assign2ProB.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\86150\CLionProjects\Assign2ProB\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assign2ProB.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assign2ProB.dir\main.cpp.obj -c C:\Users\86150\CLionProjects\Assign2ProB\main.cpp

CMakeFiles/Assign2ProB.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assign2ProB.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\86150\CLionProjects\Assign2ProB\main.cpp > CMakeFiles\Assign2ProB.dir\main.cpp.i

CMakeFiles/Assign2ProB.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assign2ProB.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\86150\CLionProjects\Assign2ProB\main.cpp -o CMakeFiles\Assign2ProB.dir\main.cpp.s

# Object files for target Assign2ProB
Assign2ProB_OBJECTS = \
"CMakeFiles/Assign2ProB.dir/main.cpp.obj"

# External object files for target Assign2ProB
Assign2ProB_EXTERNAL_OBJECTS =

Assign2ProB.exe: CMakeFiles/Assign2ProB.dir/main.cpp.obj
Assign2ProB.exe: CMakeFiles/Assign2ProB.dir/build.make
Assign2ProB.exe: CMakeFiles/Assign2ProB.dir/linklibs.rsp
Assign2ProB.exe: CMakeFiles/Assign2ProB.dir/objects1.rsp
Assign2ProB.exe: CMakeFiles/Assign2ProB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\86150\CLionProjects\Assign2ProB\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Assign2ProB.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Assign2ProB.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assign2ProB.dir/build: Assign2ProB.exe

.PHONY : CMakeFiles/Assign2ProB.dir/build

CMakeFiles/Assign2ProB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Assign2ProB.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Assign2ProB.dir/clean

CMakeFiles/Assign2ProB.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\86150\CLionProjects\Assign2ProB C:\Users\86150\CLionProjects\Assign2ProB C:\Users\86150\CLionProjects\Assign2ProB\cmake-build-debug C:\Users\86150\CLionProjects\Assign2ProB\cmake-build-debug C:\Users\86150\CLionProjects\Assign2ProB\cmake-build-debug\CMakeFiles\Assign2ProB.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Assign2ProB.dir/depend

