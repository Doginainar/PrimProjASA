# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /snap/clion/177/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/177/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nunodendas/Documents/Faculdade/ASA/PrimProjASA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nunodendas/Documents/Faculdade/ASA/PrimProjASA/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PrimProjASA.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PrimProjASA.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PrimProjASA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PrimProjASA.dir/flags.make

CMakeFiles/PrimProjASA.dir/main.cpp.o: CMakeFiles/PrimProjASA.dir/flags.make
CMakeFiles/PrimProjASA.dir/main.cpp.o: ../main.cpp
CMakeFiles/PrimProjASA.dir/main.cpp.o: CMakeFiles/PrimProjASA.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nunodendas/Documents/Faculdade/ASA/PrimProjASA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PrimProjASA.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PrimProjASA.dir/main.cpp.o -MF CMakeFiles/PrimProjASA.dir/main.cpp.o.d -o CMakeFiles/PrimProjASA.dir/main.cpp.o -c /home/nunodendas/Documents/Faculdade/ASA/PrimProjASA/main.cpp

CMakeFiles/PrimProjASA.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PrimProjASA.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nunodendas/Documents/Faculdade/ASA/PrimProjASA/main.cpp > CMakeFiles/PrimProjASA.dir/main.cpp.i

CMakeFiles/PrimProjASA.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PrimProjASA.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nunodendas/Documents/Faculdade/ASA/PrimProjASA/main.cpp -o CMakeFiles/PrimProjASA.dir/main.cpp.s

# Object files for target PrimProjASA
PrimProjASA_OBJECTS = \
"CMakeFiles/PrimProjASA.dir/main.cpp.o"

# External object files for target PrimProjASA
PrimProjASA_EXTERNAL_OBJECTS =

PrimProjASA: CMakeFiles/PrimProjASA.dir/main.cpp.o
PrimProjASA: CMakeFiles/PrimProjASA.dir/build.make
PrimProjASA: CMakeFiles/PrimProjASA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nunodendas/Documents/Faculdade/ASA/PrimProjASA/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PrimProjASA"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PrimProjASA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PrimProjASA.dir/build: PrimProjASA
.PHONY : CMakeFiles/PrimProjASA.dir/build

CMakeFiles/PrimProjASA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PrimProjASA.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PrimProjASA.dir/clean

CMakeFiles/PrimProjASA.dir/depend:
	cd /home/nunodendas/Documents/Faculdade/ASA/PrimProjASA/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nunodendas/Documents/Faculdade/ASA/PrimProjASA /home/nunodendas/Documents/Faculdade/ASA/PrimProjASA /home/nunodendas/Documents/Faculdade/ASA/PrimProjASA/cmake-build-debug /home/nunodendas/Documents/Faculdade/ASA/PrimProjASA/cmake-build-debug /home/nunodendas/Documents/Faculdade/ASA/PrimProjASA/cmake-build-debug/CMakeFiles/PrimProjASA.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PrimProjASA.dir/depend
