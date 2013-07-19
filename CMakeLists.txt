project(BossKiller)
cmake_minimum_required(VERSION 2.8)

# Add additional flags to gcc and clang
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_definitions("-std=c++11 -pedantic -Wall -Wextra -Wshadow")
endif()

# Find packages
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake/Modules" ${CMAKE_MODULE_PATH})

# SFML
find_package(SFML 2 COMPONENTS graphics window audio system REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

add_executable(bosskiller
src/GameState.cpp
src/GameState.hpp
src/MenuState.cpp
src/MenuState.hpp
src/State.hpp
src/StateManager.cpp
src/StateManager.hpp
src/TileMap.cpp
src/TileMap.hpp
src/config.cpp
src/config.hpp
src/main.cpp
)

target_link_libraries(bosskiller ${SFML_LIBRARIES})
