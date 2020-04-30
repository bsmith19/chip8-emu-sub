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
