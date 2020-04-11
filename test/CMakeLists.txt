# create project name
project(test)

#Test file list
set(SOURCES
    src/unit_test.cpp
    src/main.cpp
)

#Find the GTest package
#find_package(Gtest REQUIRED)

#add unit tests executable
add_executable(tests ${SOURCES})

target_link_libraries(tests
    sub::renderer
    sub::cpu
    gmock
    gtest
)

target_include_directories(tests PUBLIC ${gtest_build_include_dirs})

#add test commands
add_test(test_all tests)