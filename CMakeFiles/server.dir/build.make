# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.11.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.11.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/fu/work/c_work/TelServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/fu/work/c_work/TelServer

# Include any dependencies generated for this target.
include CMakeFiles/server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server.dir/flags.make

CMakeFiles/server.dir/src/accept_thread.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/accept_thread.c.o: src/accept_thread.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fu/work/c_work/TelServer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/server.dir/src/accept_thread.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/src/accept_thread.c.o   -c /Users/fu/work/c_work/TelServer/src/accept_thread.c

CMakeFiles/server.dir/src/accept_thread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/accept_thread.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/fu/work/c_work/TelServer/src/accept_thread.c > CMakeFiles/server.dir/src/accept_thread.c.i

CMakeFiles/server.dir/src/accept_thread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/accept_thread.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/fu/work/c_work/TelServer/src/accept_thread.c -o CMakeFiles/server.dir/src/accept_thread.c.s

CMakeFiles/server.dir/src/check_authclient_thread.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/check_authclient_thread.c.o: src/check_authclient_thread.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fu/work/c_work/TelServer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/server.dir/src/check_authclient_thread.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/src/check_authclient_thread.c.o   -c /Users/fu/work/c_work/TelServer/src/check_authclient_thread.c

CMakeFiles/server.dir/src/check_authclient_thread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/check_authclient_thread.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/fu/work/c_work/TelServer/src/check_authclient_thread.c > CMakeFiles/server.dir/src/check_authclient_thread.c.i

CMakeFiles/server.dir/src/check_authclient_thread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/check_authclient_thread.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/fu/work/c_work/TelServer/src/check_authclient_thread.c -o CMakeFiles/server.dir/src/check_authclient_thread.c.s

CMakeFiles/server.dir/src/check_client_thread.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/check_client_thread.c.o: src/check_client_thread.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fu/work/c_work/TelServer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/server.dir/src/check_client_thread.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/src/check_client_thread.c.o   -c /Users/fu/work/c_work/TelServer/src/check_client_thread.c

CMakeFiles/server.dir/src/check_client_thread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/check_client_thread.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/fu/work/c_work/TelServer/src/check_client_thread.c > CMakeFiles/server.dir/src/check_client_thread.c.i

CMakeFiles/server.dir/src/check_client_thread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/check_client_thread.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/fu/work/c_work/TelServer/src/check_client_thread.c -o CMakeFiles/server.dir/src/check_client_thread.c.s

CMakeFiles/server.dir/src/client_table.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/client_table.c.o: src/client_table.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fu/work/c_work/TelServer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/server.dir/src/client_table.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/src/client_table.c.o   -c /Users/fu/work/c_work/TelServer/src/client_table.c

CMakeFiles/server.dir/src/client_table.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/client_table.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/fu/work/c_work/TelServer/src/client_table.c > CMakeFiles/server.dir/src/client_table.c.i

CMakeFiles/server.dir/src/client_table.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/client_table.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/fu/work/c_work/TelServer/src/client_table.c -o CMakeFiles/server.dir/src/client_table.c.s

CMakeFiles/server.dir/src/crc.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/crc.c.o: src/crc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fu/work/c_work/TelServer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/server.dir/src/crc.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/src/crc.c.o   -c /Users/fu/work/c_work/TelServer/src/crc.c

CMakeFiles/server.dir/src/crc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/crc.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/fu/work/c_work/TelServer/src/crc.c > CMakeFiles/server.dir/src/crc.c.i

CMakeFiles/server.dir/src/crc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/crc.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/fu/work/c_work/TelServer/src/crc.c -o CMakeFiles/server.dir/src/crc.c.s

CMakeFiles/server.dir/src/h_thread.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/h_thread.c.o: src/h_thread.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fu/work/c_work/TelServer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/server.dir/src/h_thread.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/src/h_thread.c.o   -c /Users/fu/work/c_work/TelServer/src/h_thread.c

CMakeFiles/server.dir/src/h_thread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/h_thread.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/fu/work/c_work/TelServer/src/h_thread.c > CMakeFiles/server.dir/src/h_thread.c.i

CMakeFiles/server.dir/src/h_thread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/h_thread.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/fu/work/c_work/TelServer/src/h_thread.c -o CMakeFiles/server.dir/src/h_thread.c.s

CMakeFiles/server.dir/src/handle_thread.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/handle_thread.c.o: src/handle_thread.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fu/work/c_work/TelServer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/server.dir/src/handle_thread.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/src/handle_thread.c.o   -c /Users/fu/work/c_work/TelServer/src/handle_thread.c

CMakeFiles/server.dir/src/handle_thread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/handle_thread.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/fu/work/c_work/TelServer/src/handle_thread.c > CMakeFiles/server.dir/src/handle_thread.c.i

CMakeFiles/server.dir/src/handle_thread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/handle_thread.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/fu/work/c_work/TelServer/src/handle_thread.c -o CMakeFiles/server.dir/src/handle_thread.c.s

CMakeFiles/server.dir/src/jni_server.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/jni_server.c.o: src/jni_server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fu/work/c_work/TelServer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/server.dir/src/jni_server.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/src/jni_server.c.o   -c /Users/fu/work/c_work/TelServer/src/jni_server.c

CMakeFiles/server.dir/src/jni_server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/jni_server.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/fu/work/c_work/TelServer/src/jni_server.c > CMakeFiles/server.dir/src/jni_server.c.i

CMakeFiles/server.dir/src/jni_server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/jni_server.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/fu/work/c_work/TelServer/src/jni_server.c -o CMakeFiles/server.dir/src/jni_server.c.s

CMakeFiles/server.dir/src/list.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/list.c.o: src/list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fu/work/c_work/TelServer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/server.dir/src/list.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/src/list.c.o   -c /Users/fu/work/c_work/TelServer/src/list.c

CMakeFiles/server.dir/src/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/list.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/fu/work/c_work/TelServer/src/list.c > CMakeFiles/server.dir/src/list.c.i

CMakeFiles/server.dir/src/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/list.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/fu/work/c_work/TelServer/src/list.c -o CMakeFiles/server.dir/src/list.c.s

CMakeFiles/server.dir/src/main.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fu/work/c_work/TelServer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/server.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/src/main.c.o   -c /Users/fu/work/c_work/TelServer/src/main.c

CMakeFiles/server.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/fu/work/c_work/TelServer/src/main.c > CMakeFiles/server.dir/src/main.c.i

CMakeFiles/server.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/fu/work/c_work/TelServer/src/main.c -o CMakeFiles/server.dir/src/main.c.s

CMakeFiles/server.dir/src/map.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/map.c.o: src/map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fu/work/c_work/TelServer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/server.dir/src/map.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/src/map.c.o   -c /Users/fu/work/c_work/TelServer/src/map.c

CMakeFiles/server.dir/src/map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/map.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/fu/work/c_work/TelServer/src/map.c > CMakeFiles/server.dir/src/map.c.i

CMakeFiles/server.dir/src/map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/map.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/fu/work/c_work/TelServer/src/map.c -o CMakeFiles/server.dir/src/map.c.s

CMakeFiles/server.dir/src/read_thread.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/read_thread.c.o: src/read_thread.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fu/work/c_work/TelServer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/server.dir/src/read_thread.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/src/read_thread.c.o   -c /Users/fu/work/c_work/TelServer/src/read_thread.c

CMakeFiles/server.dir/src/read_thread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/read_thread.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/fu/work/c_work/TelServer/src/read_thread.c > CMakeFiles/server.dir/src/read_thread.c.i

CMakeFiles/server.dir/src/read_thread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/read_thread.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/fu/work/c_work/TelServer/src/read_thread.c -o CMakeFiles/server.dir/src/read_thread.c.s

CMakeFiles/server.dir/src/server.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/server.c.o: src/server.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fu/work/c_work/TelServer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/server.dir/src/server.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/src/server.c.o   -c /Users/fu/work/c_work/TelServer/src/server.c

CMakeFiles/server.dir/src/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/server.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/fu/work/c_work/TelServer/src/server.c > CMakeFiles/server.dir/src/server.c.i

CMakeFiles/server.dir/src/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/server.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/fu/work/c_work/TelServer/src/server.c -o CMakeFiles/server.dir/src/server.c.s

CMakeFiles/server.dir/src/socket.c.o: CMakeFiles/server.dir/flags.make
CMakeFiles/server.dir/src/socket.c.o: src/socket.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/fu/work/c_work/TelServer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/server.dir/src/socket.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/server.dir/src/socket.c.o   -c /Users/fu/work/c_work/TelServer/src/socket.c

CMakeFiles/server.dir/src/socket.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/server.dir/src/socket.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/fu/work/c_work/TelServer/src/socket.c > CMakeFiles/server.dir/src/socket.c.i

CMakeFiles/server.dir/src/socket.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/server.dir/src/socket.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/fu/work/c_work/TelServer/src/socket.c -o CMakeFiles/server.dir/src/socket.c.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/src/accept_thread.c.o" \
"CMakeFiles/server.dir/src/check_authclient_thread.c.o" \
"CMakeFiles/server.dir/src/check_client_thread.c.o" \
"CMakeFiles/server.dir/src/client_table.c.o" \
"CMakeFiles/server.dir/src/crc.c.o" \
"CMakeFiles/server.dir/src/h_thread.c.o" \
"CMakeFiles/server.dir/src/handle_thread.c.o" \
"CMakeFiles/server.dir/src/jni_server.c.o" \
"CMakeFiles/server.dir/src/list.c.o" \
"CMakeFiles/server.dir/src/main.c.o" \
"CMakeFiles/server.dir/src/map.c.o" \
"CMakeFiles/server.dir/src/read_thread.c.o" \
"CMakeFiles/server.dir/src/server.c.o" \
"CMakeFiles/server.dir/src/socket.c.o"

# External object files for target server
server_EXTERNAL_OBJECTS =

libserver.dylib: CMakeFiles/server.dir/src/accept_thread.c.o
libserver.dylib: CMakeFiles/server.dir/src/check_authclient_thread.c.o
libserver.dylib: CMakeFiles/server.dir/src/check_client_thread.c.o
libserver.dylib: CMakeFiles/server.dir/src/client_table.c.o
libserver.dylib: CMakeFiles/server.dir/src/crc.c.o
libserver.dylib: CMakeFiles/server.dir/src/h_thread.c.o
libserver.dylib: CMakeFiles/server.dir/src/handle_thread.c.o
libserver.dylib: CMakeFiles/server.dir/src/jni_server.c.o
libserver.dylib: CMakeFiles/server.dir/src/list.c.o
libserver.dylib: CMakeFiles/server.dir/src/main.c.o
libserver.dylib: CMakeFiles/server.dir/src/map.c.o
libserver.dylib: CMakeFiles/server.dir/src/read_thread.c.o
libserver.dylib: CMakeFiles/server.dir/src/server.c.o
libserver.dylib: CMakeFiles/server.dir/src/socket.c.o
libserver.dylib: CMakeFiles/server.dir/build.make
libserver.dylib: CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/fu/work/c_work/TelServer/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking C shared library libserver.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server.dir/build: libserver.dylib

.PHONY : CMakeFiles/server.dir/build

CMakeFiles/server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server.dir/clean

CMakeFiles/server.dir/depend:
	cd /Users/fu/work/c_work/TelServer && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/fu/work/c_work/TelServer /Users/fu/work/c_work/TelServer /Users/fu/work/c_work/TelServer /Users/fu/work/c_work/TelServer /Users/fu/work/c_work/TelServer/CMakeFiles/server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server.dir/depend

