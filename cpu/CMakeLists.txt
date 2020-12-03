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
    include/instructions/InstBitOp_8XYE.hpp
    include/instructions/InstCond_3XNN.hpp
    include/instructions/InstCond_4XNN.hpp
    include/instructions/InstCond_5XY0.hpp
    include/instructions/InstCond_9XY0.hpp
    include/instructions/InstConst_6XNN.hpp
    include/instructions/InstConst_7XNN.hpp
    include/instructions/InstDisp_DXYN.hpp
    include/instructions/InstDisplay_00E0.hpp
    include/instructions/InstFlow_00EE.hpp
    include/instructions/InstFlow_1NNN.hpp
    include/instructions/InstFlow_2NNN.hpp
    include/instructions/InstFlow_BNNN.hpp
    include/instructions/InstKeyOp_EX9E.hpp
    include/instructions/InstKeyOp_EXA1.hpp
    include/instructions/InstKeyOp_FX0A.hpp
    include/instructions/InstMath_8XY4.hpp
    include/instructions/InstMath_8XY5.hpp
    include/instructions/InstMath_8XY7.hpp
    include/instructions/InstMem_ANNN.hpp
    include/instructions/InstMem_FX1E.hpp
    include/instructions/InstMem_FX29.hpp
    include/instructions/InstMem_FX55.hpp
    include/instructions/InstMem_FX65.hpp
    include/instructions/InstRand_CXNN.hpp
    include/instructions/InstSound_FX18.hpp
    include/instructions/InstTimer_FX07.hpp
    include/instructions/InstTimer_FX15.hpp
)

#create the library
add_library(cpu ${SOURCES} ${HEADERS} ${INST_HEADERS})
add_library(sub::cpu ALIAS cpu)

target_include_directories( cpu
        PUBLIC ${PROJECT_SOURCE_DIR}/include
)
