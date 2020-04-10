#set subproject name first
project(renderer)

# Check the platform, so we can set the SFML_DIR correctly
if(APPLE) 
        #Mac....
        #set(SFML_STATIC_LIBRARIES TRUE) # Commented out to allow frameworks instead
        #set(CMAKE_FIND_FRAMEWORK "LAST")
        set(SFML_DIR "../thirdparty/SFML-2.5.1_mac/Frameworks/SFML.framework/Resources/CMake")
else()
        #Technically anything other than mac, but in reality windows
        set(SFML_STATIC_LIBRARIES TRUE)
        set(SFML_DIR "../thirdparty/SFML-2.5.1_win/lib/cmake/SFML")
endif()

#Set the package version and which libraries from there we want
find_package(SFML 2.5.1 COMPONENTS audio graphics window system REQUIRED)


# define source list
set(SOURCES
        src/Display.cpp
)

#define header list
set(HEADERS
        include/renderer/Display.h
)

#create the library
add_library(renderer ${SOURCES} ${HEADERS})
add_library(sub::renderer ALIAS renderer)

# link external libraries into build
target_link_libraries(renderer sfml-graphics sfml-system)

target_include_directories( renderer
        PUBLIC ${PROJECT_SOURCE_DIR}/include ${SFML_SOURCE_DIR}/includes
)
