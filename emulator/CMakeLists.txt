# create project name
project(emulator)

# create executable
add_executable(emulator src/main.cpp)

# link static library from projects using alias
# this will bring in there include directories as well
target_link_libraries(emulator
    sub::cpu
    sub::renderer
)
