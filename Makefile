# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/linux/Desktop/TelServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/linux/Desktop/TelServer

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/linux/Desktop/TelServer/CMakeFiles /home/linux/Desktop/TelServer/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/linux/Desktop/TelServer/CMakeFiles 0
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
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named server

# Build rule for target.
server: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 server
.PHONY : server

# fast build rule for target.
server/fast:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/build
.PHONY : server/fast

#=============================================================================
# Target rules for targets named smartServer

# Build rule for target.
smartServer: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 smartServer
.PHONY : smartServer

# fast build rule for target.
smartServer/fast:
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/build
.PHONY : smartServer/fast

src/accept_thread.o: src/accept_thread.c.o
.PHONY : src/accept_thread.o

# target to build an object file
src/accept_thread.c.o:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/accept_thread.c.o
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/accept_thread.c.o
.PHONY : src/accept_thread.c.o

src/accept_thread.i: src/accept_thread.c.i
.PHONY : src/accept_thread.i

# target to preprocess a source file
src/accept_thread.c.i:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/accept_thread.c.i
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/accept_thread.c.i
.PHONY : src/accept_thread.c.i

src/accept_thread.s: src/accept_thread.c.s
.PHONY : src/accept_thread.s

# target to generate assembly for a file
src/accept_thread.c.s:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/accept_thread.c.s
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/accept_thread.c.s
.PHONY : src/accept_thread.c.s

src/check_authclient_thread.o: src/check_authclient_thread.c.o
.PHONY : src/check_authclient_thread.o

# target to build an object file
src/check_authclient_thread.c.o:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/check_authclient_thread.c.o
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/check_authclient_thread.c.o
.PHONY : src/check_authclient_thread.c.o

src/check_authclient_thread.i: src/check_authclient_thread.c.i
.PHONY : src/check_authclient_thread.i

# target to preprocess a source file
src/check_authclient_thread.c.i:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/check_authclient_thread.c.i
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/check_authclient_thread.c.i
.PHONY : src/check_authclient_thread.c.i

src/check_authclient_thread.s: src/check_authclient_thread.c.s
.PHONY : src/check_authclient_thread.s

# target to generate assembly for a file
src/check_authclient_thread.c.s:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/check_authclient_thread.c.s
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/check_authclient_thread.c.s
.PHONY : src/check_authclient_thread.c.s

src/check_client_thread.o: src/check_client_thread.c.o
.PHONY : src/check_client_thread.o

# target to build an object file
src/check_client_thread.c.o:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/check_client_thread.c.o
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/check_client_thread.c.o
.PHONY : src/check_client_thread.c.o

src/check_client_thread.i: src/check_client_thread.c.i
.PHONY : src/check_client_thread.i

# target to preprocess a source file
src/check_client_thread.c.i:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/check_client_thread.c.i
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/check_client_thread.c.i
.PHONY : src/check_client_thread.c.i

src/check_client_thread.s: src/check_client_thread.c.s
.PHONY : src/check_client_thread.s

# target to generate assembly for a file
src/check_client_thread.c.s:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/check_client_thread.c.s
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/check_client_thread.c.s
.PHONY : src/check_client_thread.c.s

src/h_thread.o: src/h_thread.c.o
.PHONY : src/h_thread.o

# target to build an object file
src/h_thread.c.o:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/h_thread.c.o
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/h_thread.c.o
.PHONY : src/h_thread.c.o

src/h_thread.i: src/h_thread.c.i
.PHONY : src/h_thread.i

# target to preprocess a source file
src/h_thread.c.i:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/h_thread.c.i
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/h_thread.c.i
.PHONY : src/h_thread.c.i

src/h_thread.s: src/h_thread.c.s
.PHONY : src/h_thread.s

# target to generate assembly for a file
src/h_thread.c.s:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/h_thread.c.s
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/h_thread.c.s
.PHONY : src/h_thread.c.s

src/handle_thread.o: src/handle_thread.c.o
.PHONY : src/handle_thread.o

# target to build an object file
src/handle_thread.c.o:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/handle_thread.c.o
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/handle_thread.c.o
.PHONY : src/handle_thread.c.o

src/handle_thread.i: src/handle_thread.c.i
.PHONY : src/handle_thread.i

# target to preprocess a source file
src/handle_thread.c.i:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/handle_thread.c.i
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/handle_thread.c.i
.PHONY : src/handle_thread.c.i

src/handle_thread.s: src/handle_thread.c.s
.PHONY : src/handle_thread.s

# target to generate assembly for a file
src/handle_thread.c.s:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/handle_thread.c.s
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/handle_thread.c.s
.PHONY : src/handle_thread.c.s

src/jni_server.o: src/jni_server.c.o
.PHONY : src/jni_server.o

# target to build an object file
src/jni_server.c.o:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/jni_server.c.o
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/jni_server.c.o
.PHONY : src/jni_server.c.o

src/jni_server.i: src/jni_server.c.i
.PHONY : src/jni_server.i

# target to preprocess a source file
src/jni_server.c.i:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/jni_server.c.i
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/jni_server.c.i
.PHONY : src/jni_server.c.i

src/jni_server.s: src/jni_server.c.s
.PHONY : src/jni_server.s

# target to generate assembly for a file
src/jni_server.c.s:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/jni_server.c.s
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/jni_server.c.s
.PHONY : src/jni_server.c.s

src/list.o: src/list.c.o
.PHONY : src/list.o

# target to build an object file
src/list.c.o:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/list.c.o
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/list.c.o
.PHONY : src/list.c.o

src/list.i: src/list.c.i
.PHONY : src/list.i

# target to preprocess a source file
src/list.c.i:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/list.c.i
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/list.c.i
.PHONY : src/list.c.i

src/list.s: src/list.c.s
.PHONY : src/list.s

# target to generate assembly for a file
src/list.c.s:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/list.c.s
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/list.c.s
.PHONY : src/list.c.s

src/main.o: src/main.c.o
.PHONY : src/main.o

# target to build an object file
src/main.c.o:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/main.c.o
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/main.c.o
.PHONY : src/main.c.o

src/main.i: src/main.c.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.c.i:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/main.c.i
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/main.c.i
.PHONY : src/main.c.i

src/main.s: src/main.c.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.c.s:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/main.c.s
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/main.c.s
.PHONY : src/main.c.s

src/map.o: src/map.c.o
.PHONY : src/map.o

# target to build an object file
src/map.c.o:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/map.c.o
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/map.c.o
.PHONY : src/map.c.o

src/map.i: src/map.c.i
.PHONY : src/map.i

# target to preprocess a source file
src/map.c.i:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/map.c.i
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/map.c.i
.PHONY : src/map.c.i

src/map.s: src/map.c.s
.PHONY : src/map.s

# target to generate assembly for a file
src/map.c.s:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/map.c.s
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/map.c.s
.PHONY : src/map.c.s

src/read_thread.o: src/read_thread.c.o
.PHONY : src/read_thread.o

# target to build an object file
src/read_thread.c.o:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/read_thread.c.o
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/read_thread.c.o
.PHONY : src/read_thread.c.o

src/read_thread.i: src/read_thread.c.i
.PHONY : src/read_thread.i

# target to preprocess a source file
src/read_thread.c.i:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/read_thread.c.i
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/read_thread.c.i
.PHONY : src/read_thread.c.i

src/read_thread.s: src/read_thread.c.s
.PHONY : src/read_thread.s

# target to generate assembly for a file
src/read_thread.c.s:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/read_thread.c.s
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/read_thread.c.s
.PHONY : src/read_thread.c.s

src/server.o: src/server.c.o
.PHONY : src/server.o

# target to build an object file
src/server.c.o:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/server.c.o
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/server.c.o
.PHONY : src/server.c.o

src/server.i: src/server.c.i
.PHONY : src/server.i

# target to preprocess a source file
src/server.c.i:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/server.c.i
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/server.c.i
.PHONY : src/server.c.i

src/server.s: src/server.c.s
.PHONY : src/server.s

# target to generate assembly for a file
src/server.c.s:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/server.c.s
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/server.c.s
.PHONY : src/server.c.s

src/socket.o: src/socket.c.o
.PHONY : src/socket.o

# target to build an object file
src/socket.c.o:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/socket.c.o
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/socket.c.o
.PHONY : src/socket.c.o

src/socket.i: src/socket.c.i
.PHONY : src/socket.i

# target to preprocess a source file
src/socket.c.i:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/socket.c.i
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/socket.c.i
.PHONY : src/socket.c.i

src/socket.s: src/socket.c.s
.PHONY : src/socket.s

# target to generate assembly for a file
src/socket.c.s:
	$(MAKE) -f CMakeFiles/server.dir/build.make CMakeFiles/server.dir/src/socket.c.s
	$(MAKE) -f CMakeFiles/smartServer.dir/build.make CMakeFiles/smartServer.dir/src/socket.c.s
.PHONY : src/socket.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... smartServer"
	@echo "... server"
	@echo "... src/accept_thread.o"
	@echo "... src/accept_thread.i"
	@echo "... src/accept_thread.s"
	@echo "... src/check_authclient_thread.o"
	@echo "... src/check_authclient_thread.i"
	@echo "... src/check_authclient_thread.s"
	@echo "... src/check_client_thread.o"
	@echo "... src/check_client_thread.i"
	@echo "... src/check_client_thread.s"
	@echo "... src/h_thread.o"
	@echo "... src/h_thread.i"
	@echo "... src/h_thread.s"
	@echo "... src/handle_thread.o"
	@echo "... src/handle_thread.i"
	@echo "... src/handle_thread.s"
	@echo "... src/jni_server.o"
	@echo "... src/jni_server.i"
	@echo "... src/jni_server.s"
	@echo "... src/list.o"
	@echo "... src/list.i"
	@echo "... src/list.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/map.o"
	@echo "... src/map.i"
	@echo "... src/map.s"
	@echo "... src/read_thread.o"
	@echo "... src/read_thread.i"
	@echo "... src/read_thread.s"
	@echo "... src/server.o"
	@echo "... src/server.i"
	@echo "... src/server.s"
	@echo "... src/socket.o"
	@echo "... src/socket.i"
	@echo "... src/socket.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

