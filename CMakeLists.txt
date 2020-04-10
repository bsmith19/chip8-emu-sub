# set the minimum cmake version first
cmake_minimum_required(VERSION 3.5)

# set project name
project(chip8-emu-sub)

# add sub project directories
add_subdirectory(cpu)
add_subdirectory(renderer)
add_subdirectory(emulator)
