# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/kitty/cg/msu_cmc_cg_2021-master/template1_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kitty/cg/msu_cmc_cg_2021-master/template1_cpp

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/kitty/cg/msu_cmc_cg_2021-master/template1_cpp/CMakeFiles /home/kitty/cg/msu_cmc_cg_2021-master/template1_cpp/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/kitty/cg/msu_cmc_cg_2021-master/template1_cpp/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

Enemy.o: Enemy.cpp.o

.PHONY : Enemy.o

# target to build an object file
Enemy.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Enemy.cpp.o
.PHONY : Enemy.cpp.o

Enemy.i: Enemy.cpp.i

.PHONY : Enemy.i

# target to preprocess a source file
Enemy.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Enemy.cpp.i
.PHONY : Enemy.cpp.i

Enemy.s: Enemy.cpp.s

.PHONY : Enemy.s

# target to generate assembly for a file
Enemy.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Enemy.cpp.s
.PHONY : Enemy.cpp.s

GameObject.o: GameObject.cpp.o

.PHONY : GameObject.o

# target to build an object file
GameObject.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/GameObject.cpp.o
.PHONY : GameObject.cpp.o

GameObject.i: GameObject.cpp.i

.PHONY : GameObject.i

# target to preprocess a source file
GameObject.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/GameObject.cpp.i
.PHONY : GameObject.cpp.i

GameObject.s: GameObject.cpp.s

.PHONY : GameObject.s

# target to generate assembly for a file
GameObject.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/GameObject.cpp.s
.PHONY : GameObject.cpp.s

Image.o: Image.cpp.o

.PHONY : Image.o

# target to build an object file
Image.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Image.cpp.o
.PHONY : Image.cpp.o

Image.i: Image.cpp.i

.PHONY : Image.i

# target to preprocess a source file
Image.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Image.cpp.i
.PHONY : Image.cpp.i

Image.s: Image.cpp.s

.PHONY : Image.s

# target to generate assembly for a file
Image.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Image.cpp.s
.PHONY : Image.cpp.s

Level.o: Level.cpp.o

.PHONY : Level.o

# target to build an object file
Level.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Level.cpp.o
.PHONY : Level.cpp.o

Level.i: Level.cpp.i

.PHONY : Level.i

# target to preprocess a source file
Level.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Level.cpp.i
.PHONY : Level.cpp.i

Level.s: Level.cpp.s

.PHONY : Level.s

# target to generate assembly for a file
Level.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Level.cpp.s
.PHONY : Level.cpp.s

Map.o: Map.cpp.o

.PHONY : Map.o

# target to build an object file
Map.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Map.cpp.o
.PHONY : Map.cpp.o

Map.i: Map.cpp.i

.PHONY : Map.i

# target to preprocess a source file
Map.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Map.cpp.i
.PHONY : Map.cpp.i

Map.s: Map.cpp.s

.PHONY : Map.s

# target to generate assembly for a file
Map.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Map.cpp.s
.PHONY : Map.cpp.s

Player.o: Player.cpp.o

.PHONY : Player.o

# target to build an object file
Player.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Player.cpp.o
.PHONY : Player.cpp.o

Player.i: Player.cpp.i

.PHONY : Player.i

# target to preprocess a source file
Player.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Player.cpp.i
.PHONY : Player.cpp.i

Player.s: Player.cpp.s

.PHONY : Player.s

# target to generate assembly for a file
Player.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Player.cpp.s
.PHONY : Player.cpp.s

Tile.o: Tile.cpp.o

.PHONY : Tile.o

# target to build an object file
Tile.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Tile.cpp.o
.PHONY : Tile.cpp.o

Tile.i: Tile.cpp.i

.PHONY : Tile.i

# target to preprocess a source file
Tile.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Tile.cpp.i
.PHONY : Tile.cpp.i

Tile.s: Tile.cpp.s

.PHONY : Tile.s

# target to generate assembly for a file
Tile.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/Tile.cpp.s
.PHONY : Tile.cpp.s

glad.o: glad.c.o

.PHONY : glad.o

# target to build an object file
glad.c.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/glad.c.o
.PHONY : glad.c.o

glad.i: glad.c.i

.PHONY : glad.i

# target to preprocess a source file
glad.c.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/glad.c.i
.PHONY : glad.c.i

glad.s: glad.c.s

.PHONY : glad.s

# target to generate assembly for a file
glad.c.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/glad.c.s
.PHONY : glad.c.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... main"
	@echo "... Enemy.o"
	@echo "... Enemy.i"
	@echo "... Enemy.s"
	@echo "... GameObject.o"
	@echo "... GameObject.i"
	@echo "... GameObject.s"
	@echo "... Image.o"
	@echo "... Image.i"
	@echo "... Image.s"
	@echo "... Level.o"
	@echo "... Level.i"
	@echo "... Level.s"
	@echo "... Map.o"
	@echo "... Map.i"
	@echo "... Map.s"
	@echo "... Player.o"
	@echo "... Player.i"
	@echo "... Player.s"
	@echo "... Tile.o"
	@echo "... Tile.i"
	@echo "... Tile.s"
	@echo "... glad.o"
	@echo "... glad.i"
	@echo "... glad.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

