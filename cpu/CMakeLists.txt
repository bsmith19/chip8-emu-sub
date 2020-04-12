#set subproject name first
project(cpu)

# define source list
set(SOURCES
    src/Memory.cpp
    src/Stack.cpp
    src/Cpu.cpp
)

#define header list
set(HEADERS
    include/cpu/Memory.h
    include/cpu/Stack.h
    include/cpu/Cpu.h
)

#create the library
add_library(cpu ${SOURCES} ${HEADERS})
add_library(sub::cpu ALIAS cpu)

target_include_directories( cpu
        PUBLIC ${PROJECT_SOURCE_DIR}/include
)
