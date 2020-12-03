# Fix behavior of CMAKE_CXX_STANDARD when targeting macOS.
if (POLICY CMP0025)
  cmake_policy(SET CMP0025 NEW)
endif ()

#Set cpp standard as C++11
set(CMAKE_CXX_STANDARD 14)

# set the minimum cmake version first
cmake_minimum_required(VERSION 3.19)

# set Xcode build system
set(CMAKE_XCODE_BUILD_SYSTEM 12)

# set project name
project(chip8-emu-sub)

# enable unit tests for all sub folders
enable_testing()

# add third_party directories
add_subdirectory(thirdparty/google-test)

# add sub project directories
add_subdirectory(cpu)
add_subdirectory(renderer)
add_subdirectory(emulator)
add_subdirectory(test)
