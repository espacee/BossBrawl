project(BossBrawl)
cmake_minimum_required(VERSION 2.8.8)

option(BUILD_EDITOR "Build the editor. Requires Qt" OFF)

# Find SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake/Modules" ${CMAKE_MODULE_PATH})
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
src/Game/GameState.cpp
src/Game/GameState.hpp
src/Gui/IconButton.cpp
src/Gui/IconButton.hpp
src/Gui/TextButton.cpp
src/Gui/TextButton.hpp
src/Gui/VerticalScrollBar.cpp
src/Gui/VerticalScrollBar.hpp
src/Gui/Widget.cpp
src/Gui/Widget.hpp
src/Map/Layer.cpp
src/Map/Layer.hpp
src/Map/TileMap.cpp
src/Map/TileMap.hpp
src/Menu/MenuState.cpp
src/Menu/MenuState.hpp
src/Menu/OptionsMenuState.cpp
src/Menu/OptionsMenuState.hpp
src/Util/math.hpp
src/Util/unused.hpp
src/Util/view.cpp
src/Util/view.hpp
)

target_link_libraries(bossbrawl ${SFML_LIBRARIES})

# Add additional flags to gcc and clang
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set_target_properties(bossbrawl PROPERTIES COMPILE_FLAGS "-std=c++11 -pedantic -Wall -Wextra -Wshadow")
endif()

if(${BUILD_EDITOR})
    add_subdirectory(src/Editor)
endif()
