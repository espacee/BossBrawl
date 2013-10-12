project(BossBrawl)
cmake_minimum_required(VERSION 2.8.8)

option(BUILD_EDITOR "Build the editor. Requires Qt" OFF)

# Find SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 COMPONENTS graphics window audio system REQUIRED)
include_directories(${SFML_INCLUDE_DIR})
include_directories(src)

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    add_definitions(-DBRAWL_DEBUG)
endif()

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
src/Game/Enemy.cpp
src/Game/Enemy.hpp
src/Game/Entity.cpp
src/Game/Entity.hpp
src/Game/GameState.cpp
src/Game/GameState.hpp
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
src/Game/Player.cpp
src/Game/Player.hpp
)

target_link_libraries(bossbrawl map util ${SFML_LIBRARIES})

# Add additional flags to gcc and clang
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set_target_properties(bossbrawl map PROPERTIES COMPILE_FLAGS "-std=c++11 -pedantic -Wall -Wextra -Wshadow")
endif()

if(${BUILD_EDITOR})
    add_subdirectory(src/Editor)
endif()
