#set subproject name first
project(cpu)

# define source list
set(SOURCES
    src/Memory.cpp
)

#define header list
set(HEADERS
    include/cpu/Memory.h
)

#create the library
add_library(cpu ${SOURCES} ${HEADERS})
add_library(sub::cpu ALIAS cpu)

target_include_directories( cpu
        PUBLIC ${PROJECT_SOURCE_DIR}/include
)
