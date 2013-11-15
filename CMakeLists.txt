project(BossBrawl)
cmake_minimum_required(VERSION 2.8.12.1)

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
include_directories(src)

add_library(map
src/Map/Layer.cpp
src/Map/Layer.hpp
src/Map/TileMap.cpp
src/Map/TileMap.hpp
)

add_library(util
src/Util/collision.cpp
src/Util/collision.h
src/Util/math.hpp
src/Util/unused.hpp
src/Util/view.cpp
src/Util/view.hpp
src/Entities/EntityContainer.cpp
src/Entities/EntityContainer.hpp
src/Entities/Entity.cpp
src/Entities/Entity.hpp
src/Entities/Enemy.cpp
src/Entities/Enemy.hpp
src/Entities/DefaultEnemy.cpp
src/Entities/DefaultEnemy.hpp
src/Entities/Player.cpp
src/Entities/Player.hpp
)

include_directories(src/Game)

add_executable(bossbrawl
src/Game/Core/State.hpp
src/Game/Core/config.cpp
src/Game/Core/config.hpp
src/Game/Core/graphics.cpp
src/Game/Core/graphics.hpp
src/Game/Core/main.cpp
src/Game/Core/stateDriver.cpp
src/Game/Core/stateDriver.hpp
src/Game/GameState.cpp
src/Game/GameState.hpp
src/Game/Gui/UI.cpp
src/Game/Gui/UI.hpp
src/Game/Gui/IconButton.cpp
src/Game/Gui/IconButton.hpp
src/Game/Gui/TextButton.cpp
src/Game/Gui/TextButton.hpp
src/Game/Gui/VerticalScrollBar.cpp
src/Game/Gui/VerticalScrollBar.hpp
src/Game/Gui/Widget.cpp
src/Game/Gui/Widget.hpp
src/Game/Menu/MenuState.cpp
src/Game/Menu/MenuState.hpp
src/Game/Menu/OptionsMenuState.cpp
src/Game/Menu/OptionsMenuState.hpp
)

target_link_libraries(bossbrawl map util  ${SFML_LIBRARIES})

if(${BUILD_EDITOR})
    add_subdirectory(src/Editor)
endif()
