cmake_minimum_required (VERSION 2.8)
project (walksim)

# The version number.
set (GAME_VERSION_MAJOR 0)
set (GAME_VERSION_MINOR 0)

# Set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# Taken from this tutorial, way more useful than the official one
# http://derekmolloy.ie/hello-world-introductions-to-cmake/#Example_2_A_Project_with_Directories
file(GLOB SOURCES "src/*.cpp")
include_directories("${PROJECT_SOURCE_DIR}/include")

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/include/GameConfig.h.in"
  "${PROJECT_BINARY_DIR}/GameConfig.h"
)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# add the executable
add_executable(walksim ${SOURCES})

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

include_directories(
    ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS}
)
target_link_libraries(
    ${PROJECT_NAME}
    ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2TTF_LIBRARIES}
)
