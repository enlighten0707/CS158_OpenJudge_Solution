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
CMAKE_SOURCE_DIR = C:\Users\86150\CLionProjects\LCA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\86150\CLionProjects\LCA\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LCA.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LCA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LCA.dir/flags.make

CMakeFiles/LCA.dir/main.cpp.obj: CMakeFiles/LCA.dir/flags.make
CMakeFiles/LCA.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\86150\CLionProjects\LCA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LCA.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\LCA.dir\main.cpp.obj -c C:\Users\86150\CLionProjects\LCA\main.cpp

CMakeFiles/LCA.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LCA.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\86150\CLionProjects\LCA\main.cpp > CMakeFiles\LCA.dir\main.cpp.i

CMakeFiles/LCA.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LCA.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\86150\CLionProjects\LCA\main.cpp -o CMakeFiles\LCA.dir\main.cpp.s

# Object files for target LCA
LCA_OBJECTS = \
"CMakeFiles/LCA.dir/main.cpp.obj"

# External object files for target LCA
LCA_EXTERNAL_OBJECTS =

LCA.exe: CMakeFiles/LCA.dir/main.cpp.obj
LCA.exe: CMakeFiles/LCA.dir/build.make
LCA.exe: CMakeFiles/LCA.dir/linklibs.rsp
LCA.exe: CMakeFiles/LCA.dir/objects1.rsp
LCA.exe: CMakeFiles/LCA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\86150\CLionProjects\LCA\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LCA.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LCA.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LCA.dir/build: LCA.exe

.PHONY : CMakeFiles/LCA.dir/build

CMakeFiles/LCA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LCA.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LCA.dir/clean

CMakeFiles/LCA.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\86150\CLionProjects\LCA C:\Users\86150\CLionProjects\LCA C:\Users\86150\CLionProjects\LCA\cmake-build-debug C:\Users\86150\CLionProjects\LCA\cmake-build-debug C:\Users\86150\CLionProjects\LCA\cmake-build-debug\CMakeFiles\LCA.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LCA.dir/depend

