# create project name
project(test)

#Test file list
set(SOURCES
    src/unit_test.cpp
    src/memory-test.cpp
    src/main.cpp
)

#Find the GTest package
#find_package(Gtest REQUIRED)

#add unit tests executable
add_executable(tests ${SOURCES})

#copy test data to project dir
configure_file(data/invaders.c8 ${CMAKE_CURRENT_BINARY_DIR}/invaders.c8 COPYONLY)
configure_file(data/pong2.c8 ${CMAKE_CURRENT_BINARY_DIR}/pong2.c8 COPYONLY)
configure_file(data/tetris.c8 ${CMAKE_CURRENT_BINARY_DIR}/tetris.c8 COPYONLY)

target_link_libraries(tests
    sub::renderer
    sub::cpu
    gmock
    gtest
)

target_include_directories(tests PUBLIC ${gtest_build_include_dirs})

#add test commands
add_test(test_all tests)
