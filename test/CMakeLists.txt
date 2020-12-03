# create project name
project(test)

#Test file list
set(SOURCES
    src/unit_test.cpp
    src/memory-test.cpp
    src/stack-test.cpp
    src/cpu-test.cpp
    src/main.cpp
)

set(INST_SOURCES
    src/instructions/InstAssign_8XY0-test.cpp
    src/instructions/InstBcd_FX33-test.cpp
    src/instructions/InstBitOp_8XY1-test.cpp
    src/instructions/InstBitOp_8XY2-test.cpp
    src/instructions/InstBitOp_8XY3-test.cpp
    src/instructions/InstBitOp_8xy6-test.cpp
    src/instructions/InstBitOp_8xye-test.cpp
    src/instructions/InstCond_3xnn-test.cpp
    src/instructions/InstCond_4xnn-test.cpp
    src/instructions/InstCond_5xy0-test.cpp
    src/instructions/InstCond_9xy0-test.cpp
    src/instructions/InstConst_6xnn-test.cpp
    src/instructions/InstConst_7xnn-test.cpp
    src/instructions/InstDisp_DXYN-test.cpp
    src/instructions/InstDisplay_00E0-test.cpp
    src/instructions/InstFlow_00EE-test.cpp
    src/instructions/InstFlow_1NNN-test.cpp
    src/instructions/InstFlow_2NNN-test.cpp
    src/instructions/InstFlow_BNNN-test.cpp
    src/instructions/InstKeyOp_EX9E-test.cpp
    src/instructions/InstKeyOp_EXA1-test.cpp
    src/instructions/InstKeyOp_FX0A-test.cpp
    src/instructions/InstMath_8XY4-test.cpp
    src/instructions/InstMath_8XY5-test.cpp
    src/instructions/InstMath_8XY7-test.cpp
    src/instructions/InstMem_ANNN-test.cpp
    src/instructions/InstMem_FX1E-test.cpp
    src/instructions/InstMem_FX29-test.cpp
    src/instructions/InstMem_FX55-test.cpp
    src/instructions/InstMem_FX65-test.cpp
    src/instructions/InstRand_CXNN-test.cpp
    src/instructions/InstSound_FX18-test.cpp
    src/instructions/InstTimer_FX07-test.cpp
    src/instructions/InstTimer_FX15-test.cpp
)

#Find the GTest package
#find_package(Gtest REQUIRED)

#add unit tests executable
add_executable(tests ${SOURCES} ${INST_SOURCES})

#copy test data to project dir
if (APPLE)
    configure_file(data/invaders.c8 ${CMAKE_CURRENT_BINARY_DIR}/Debug/invaders.c8 COPYONLY)
    configure_file(data/pong2.c8 ${CMAKE_CURRENT_BINARY_DIR}/Debug/pong2.c8 COPYONLY)
    configure_file(data/tetris.c8 ${CMAKE_CURRENT_BINARY_DIR}/Debug/tetris.c8 COPYONLY)
else()
    configure_file(data/invaders.c8 ${CMAKE_CURRENT_BINARY_DIR}/invaders.c8 COPYONLY)
    configure_file(data/pong2.c8 ${CMAKE_CURRENT_BINARY_DIR}/pong2.c8 COPYONLY)
    configure_file(data/tetris.c8 ${CMAKE_CURRENT_BINARY_DIR}/tetris.c8 COPYONLY)
endif()

target_link_libraries(tests
    sub::renderer
    sub::cpu
    gmock
    gtest
)

target_include_directories(tests PUBLIC ${gtest_build_include_dirs})

#add test commands
add_test(test_all tests)
