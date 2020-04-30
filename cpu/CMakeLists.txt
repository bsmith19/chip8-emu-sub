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
    include/cpu/CpuData.h
)

#define instruction headers
set(INST_HEADERS
    include/instructions/Inst.h
    include/instructions/InstAssign_8XY0.hpp
    include/instructions/InstBcd_FX33.hpp
    include/instructions/InstBitOp_8XY1.hpp
    include/instructions/InstBitOp_8XY2.hpp
    include/instructions/InstBitOp_8XY3.hpp
    include/instructions/InstBitOp_8XY6.hpp
)

#create the library
add_library(cpu ${SOURCES} ${HEADERS} ${INST_HEADERS})
add_library(sub::cpu ALIAS cpu)

target_include_directories( cpu
        PUBLIC ${PROJECT_SOURCE_DIR}/include
)
