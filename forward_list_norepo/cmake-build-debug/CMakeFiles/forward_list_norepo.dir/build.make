# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/111/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/111/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/edublo/Desktop/algoritmos_repos/forward_list_norepo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/edublo/Desktop/algoritmos_repos/forward_list_norepo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/forward_list_norepo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/forward_list_norepo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/forward_list_norepo.dir/flags.make

CMakeFiles/forward_list_norepo.dir/main.cpp.o: CMakeFiles/forward_list_norepo.dir/flags.make
CMakeFiles/forward_list_norepo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edublo/Desktop/algoritmos_repos/forward_list_norepo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/forward_list_norepo.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/forward_list_norepo.dir/main.cpp.o -c /home/edublo/Desktop/algoritmos_repos/forward_list_norepo/main.cpp

CMakeFiles/forward_list_norepo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/forward_list_norepo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edublo/Desktop/algoritmos_repos/forward_list_norepo/main.cpp > CMakeFiles/forward_list_norepo.dir/main.cpp.i

CMakeFiles/forward_list_norepo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/forward_list_norepo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edublo/Desktop/algoritmos_repos/forward_list_norepo/main.cpp -o CMakeFiles/forward_list_norepo.dir/main.cpp.s

# Object files for target forward_list_norepo
forward_list_norepo_OBJECTS = \
"CMakeFiles/forward_list_norepo.dir/main.cpp.o"

# External object files for target forward_list_norepo
forward_list_norepo_EXTERNAL_OBJECTS =

forward_list_norepo: CMakeFiles/forward_list_norepo.dir/main.cpp.o
forward_list_norepo: CMakeFiles/forward_list_norepo.dir/build.make
forward_list_norepo: CMakeFiles/forward_list_norepo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/edublo/Desktop/algoritmos_repos/forward_list_norepo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable forward_list_norepo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/forward_list_norepo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/forward_list_norepo.dir/build: forward_list_norepo

.PHONY : CMakeFiles/forward_list_norepo.dir/build

CMakeFiles/forward_list_norepo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/forward_list_norepo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/forward_list_norepo.dir/clean

CMakeFiles/forward_list_norepo.dir/depend:
	cd /home/edublo/Desktop/algoritmos_repos/forward_list_norepo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/edublo/Desktop/algoritmos_repos/forward_list_norepo /home/edublo/Desktop/algoritmos_repos/forward_list_norepo /home/edublo/Desktop/algoritmos_repos/forward_list_norepo/cmake-build-debug /home/edublo/Desktop/algoritmos_repos/forward_list_norepo/cmake-build-debug /home/edublo/Desktop/algoritmos_repos/forward_list_norepo/cmake-build-debug/CMakeFiles/forward_list_norepo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/forward_list_norepo.dir/depend
