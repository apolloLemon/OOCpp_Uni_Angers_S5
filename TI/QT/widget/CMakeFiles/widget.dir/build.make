# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/melon/University/S5/COOP/TI/QT/widget

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/melon/University/S5/COOP/TI/QT/widget

# Include any dependencies generated for this target.
include CMakeFiles/widget.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/widget.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/widget.dir/flags.make

CMakeFiles/widget.dir/main.cpp.o: CMakeFiles/widget.dir/flags.make
CMakeFiles/widget.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melon/University/S5/COOP/TI/QT/widget/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/widget.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/widget.dir/main.cpp.o -c /home/melon/University/S5/COOP/TI/QT/widget/main.cpp

CMakeFiles/widget.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/widget.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melon/University/S5/COOP/TI/QT/widget/main.cpp > CMakeFiles/widget.dir/main.cpp.i

CMakeFiles/widget.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/widget.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melon/University/S5/COOP/TI/QT/widget/main.cpp -o CMakeFiles/widget.dir/main.cpp.s

CMakeFiles/widget.dir/widget_autogen/mocs_compilation.cpp.o: CMakeFiles/widget.dir/flags.make
CMakeFiles/widget.dir/widget_autogen/mocs_compilation.cpp.o: widget_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/melon/University/S5/COOP/TI/QT/widget/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/widget.dir/widget_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/widget.dir/widget_autogen/mocs_compilation.cpp.o -c /home/melon/University/S5/COOP/TI/QT/widget/widget_autogen/mocs_compilation.cpp

CMakeFiles/widget.dir/widget_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/widget.dir/widget_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/melon/University/S5/COOP/TI/QT/widget/widget_autogen/mocs_compilation.cpp > CMakeFiles/widget.dir/widget_autogen/mocs_compilation.cpp.i

CMakeFiles/widget.dir/widget_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/widget.dir/widget_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/melon/University/S5/COOP/TI/QT/widget/widget_autogen/mocs_compilation.cpp -o CMakeFiles/widget.dir/widget_autogen/mocs_compilation.cpp.s

# Object files for target widget
widget_OBJECTS = \
"CMakeFiles/widget.dir/main.cpp.o" \
"CMakeFiles/widget.dir/widget_autogen/mocs_compilation.cpp.o"

# External object files for target widget
widget_EXTERNAL_OBJECTS =

widget: CMakeFiles/widget.dir/main.cpp.o
widget: CMakeFiles/widget.dir/widget_autogen/mocs_compilation.cpp.o
widget: CMakeFiles/widget.dir/build.make
widget: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.11.3
widget: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.11.3
widget: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.11.3
widget: CMakeFiles/widget.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/melon/University/S5/COOP/TI/QT/widget/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable widget"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/widget.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/widget.dir/build: widget

.PHONY : CMakeFiles/widget.dir/build

CMakeFiles/widget.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/widget.dir/cmake_clean.cmake
.PHONY : CMakeFiles/widget.dir/clean

CMakeFiles/widget.dir/depend:
	cd /home/melon/University/S5/COOP/TI/QT/widget && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/melon/University/S5/COOP/TI/QT/widget /home/melon/University/S5/COOP/TI/QT/widget /home/melon/University/S5/COOP/TI/QT/widget /home/melon/University/S5/COOP/TI/QT/widget /home/melon/University/S5/COOP/TI/QT/widget/CMakeFiles/widget.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/widget.dir/depend

