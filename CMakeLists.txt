project(BossBrawl)
cmake_minimum_required(VERSION 2.8.12.1)

option(BUILD_GAME   "Build the game." ON)
option(BUILD_EDITOR "Build the editor. Requires Qt" OFF)

# Detect compiler
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(USING_GCC 1)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(USING_CLANG 1)
endif()

# For GCC and Clang, enable C++11 support and add some other flags
if(USING_GCC OR USING_CLANG)
  add_compile_options(-std=c++11 -pedantic -Wall -Wextra -Wshadow)
endif()

# Disable Clang warnings about nested anon types
if(USING_CLANG)
  add_compile_options(-Wno-nested-anon-types)
endif()

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    add_definitions(-DBRAWL_DEBUG)
endif()

# Find SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 COMPONENTS graphics window audio system REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

add_subdirectory(src)
