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
CMAKE_COMMAND = C:\Users\86150\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\191.7141.37\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\86150\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\191.7141.37\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\86150\CLionProjects\4072_02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\86150\CLionProjects\4072_02\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/4072_02.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/4072_02.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/4072_02.dir/flags.make

CMakeFiles/4072_02.dir/main.cpp.obj: CMakeFiles/4072_02.dir/flags.make
CMakeFiles/4072_02.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\86150\CLionProjects\4072_02\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/4072_02.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\4072_02.dir\main.cpp.obj -c C:\Users\86150\CLionProjects\4072_02\main.cpp

CMakeFiles/4072_02.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/4072_02.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\86150\CLionProjects\4072_02\main.cpp > CMakeFiles\4072_02.dir\main.cpp.i

CMakeFiles/4072_02.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/4072_02.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\86150\CLionProjects\4072_02\main.cpp -o CMakeFiles\4072_02.dir\main.cpp.s

# Object files for target 4072_02
4072_02_OBJECTS = \
"CMakeFiles/4072_02.dir/main.cpp.obj"

# External object files for target 4072_02
4072_02_EXTERNAL_OBJECTS =

4072_02.exe: CMakeFiles/4072_02.dir/main.cpp.obj
4072_02.exe: CMakeFiles/4072_02.dir/build.make
4072_02.exe: CMakeFiles/4072_02.dir/linklibs.rsp
4072_02.exe: CMakeFiles/4072_02.dir/objects1.rsp
4072_02.exe: CMakeFiles/4072_02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\86150\CLionProjects\4072_02\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 4072_02.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\4072_02.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/4072_02.dir/build: 4072_02.exe

.PHONY : CMakeFiles/4072_02.dir/build

CMakeFiles/4072_02.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\4072_02.dir\cmake_clean.cmake
.PHONY : CMakeFiles/4072_02.dir/clean

CMakeFiles/4072_02.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\86150\CLionProjects\4072_02 C:\Users\86150\CLionProjects\4072_02 C:\Users\86150\CLionProjects\4072_02\cmake-build-debug C:\Users\86150\CLionProjects\4072_02\cmake-build-debug C:\Users\86150\CLionProjects\4072_02\cmake-build-debug\CMakeFiles\4072_02.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/4072_02.dir/depend

