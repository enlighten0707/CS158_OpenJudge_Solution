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
CMAKE_SOURCE_DIR = C:\Users\86150\CLionProjects\segTreeC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\86150\CLionProjects\segTreeC\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/segTreeC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/segTreeC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/segTreeC.dir/flags.make

CMakeFiles/segTreeC.dir/main.cpp.obj: CMakeFiles/segTreeC.dir/flags.make
CMakeFiles/segTreeC.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\86150\CLionProjects\segTreeC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/segTreeC.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\segTreeC.dir\main.cpp.obj -c C:\Users\86150\CLionProjects\segTreeC\main.cpp

CMakeFiles/segTreeC.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/segTreeC.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\86150\CLionProjects\segTreeC\main.cpp > CMakeFiles\segTreeC.dir\main.cpp.i

CMakeFiles/segTreeC.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/segTreeC.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\86150\CLionProjects\segTreeC\main.cpp -o CMakeFiles\segTreeC.dir\main.cpp.s

# Object files for target segTreeC
segTreeC_OBJECTS = \
"CMakeFiles/segTreeC.dir/main.cpp.obj"

# External object files for target segTreeC
segTreeC_EXTERNAL_OBJECTS =

segTreeC.exe: CMakeFiles/segTreeC.dir/main.cpp.obj
segTreeC.exe: CMakeFiles/segTreeC.dir/build.make
segTreeC.exe: CMakeFiles/segTreeC.dir/linklibs.rsp
segTreeC.exe: CMakeFiles/segTreeC.dir/objects1.rsp
segTreeC.exe: CMakeFiles/segTreeC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\86150\CLionProjects\segTreeC\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable segTreeC.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\segTreeC.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/segTreeC.dir/build: segTreeC.exe

.PHONY : CMakeFiles/segTreeC.dir/build

CMakeFiles/segTreeC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\segTreeC.dir\cmake_clean.cmake
.PHONY : CMakeFiles/segTreeC.dir/clean

CMakeFiles/segTreeC.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\86150\CLionProjects\segTreeC C:\Users\86150\CLionProjects\segTreeC C:\Users\86150\CLionProjects\segTreeC\cmake-build-debug C:\Users\86150\CLionProjects\segTreeC\cmake-build-debug C:\Users\86150\CLionProjects\segTreeC\cmake-build-debug\CMakeFiles\segTreeC.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/segTreeC.dir/depend

