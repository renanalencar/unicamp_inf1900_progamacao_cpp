# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/renan/source/repos/unicamp_inf1900_progamacao_cpp/M3/W8/INF1900_M3_Exercicio_3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/renan/source/repos/unicamp_inf1900_progamacao_cpp/M3/W8/INF1900_M3_Exercicio_3/build

# Utility rule file for NightlyStart.

# Include any custom commands dependencies for this target.
include CMakeFiles/NightlyStart.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/NightlyStart.dir/progress.make

CMakeFiles/NightlyStart:
	"C:/Program Files/CMake/bin/ctest.exe" -D NightlyStart

NightlyStart: CMakeFiles/NightlyStart
NightlyStart: CMakeFiles/NightlyStart.dir/build.make
.PHONY : NightlyStart

# Rule to build all files generated by this target.
CMakeFiles/NightlyStart.dir/build: NightlyStart
.PHONY : CMakeFiles/NightlyStart.dir/build

CMakeFiles/NightlyStart.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NightlyStart.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NightlyStart.dir/clean

CMakeFiles/NightlyStart.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/renan/source/repos/unicamp_inf1900_progamacao_cpp/M3/W8/INF1900_M3_Exercicio_3 C:/Users/renan/source/repos/unicamp_inf1900_progamacao_cpp/M3/W8/INF1900_M3_Exercicio_3 C:/Users/renan/source/repos/unicamp_inf1900_progamacao_cpp/M3/W8/INF1900_M3_Exercicio_3/build C:/Users/renan/source/repos/unicamp_inf1900_progamacao_cpp/M3/W8/INF1900_M3_Exercicio_3/build C:/Users/renan/source/repos/unicamp_inf1900_progamacao_cpp/M3/W8/INF1900_M3_Exercicio_3/build/CMakeFiles/NightlyStart.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/NightlyStart.dir/depend

