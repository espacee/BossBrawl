project(BossBrawl)
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
include_directories(src)

add_executable(bossbrawl
src/Core/State.hpp
src/Core/config.cpp
src/Core/config.hpp
src/Core/graphics.cpp
src/Core/graphics.hpp
src/Core/main.cpp
src/Core/stateDriver.cpp
src/Core/stateDriver.hpp
src/Editor/Editor.cpp
src/Editor/Editor.hpp
src/Editor/EditorState.cpp
src/Editor/EditorState.hpp
src/Game/GameState.cpp
src/Game/GameState.hpp
src/Gui/IconButton.cpp
src/Gui/IconButton.hpp
src/Gui/ScrollBar.cpp
src/Gui/ScrollBar.hpp
src/Gui/TextButton.cpp
src/Gui/TextButton.hpp
src/Gui/Widget.cpp
src/Gui/Widget.hpp
src/Map/Layer.cpp
src/Map/Layer.hpp
src/Map/TileMap.cpp
src/Map/TileMap.hpp
src/Menu/MenuState.cpp
src/Menu/MenuState.hpp
src/Util/Camera.cpp
src/Util/Camera.hpp
src/Util/unused.hpp
)

target_link_libraries(bossbrawl ${SFML_LIBRARIES})
