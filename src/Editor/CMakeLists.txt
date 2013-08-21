# Find Qt

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)

qt5_wrap_ui(UIS_HDRS
layersettings.ui
)

add_executable(brawledit
editor.cpp
layersettings.cpp
layertab.cpp
layerwidget.cpp
main.cpp
sfmlwidget.cpp
tilewidget.cpp
../Map/TileMap.cpp
../Map/Layer.cpp
${UIS_HDRS}
)

find_package(X11)

if(X11_FOUND)
    set_target_properties(brawledit PROPERTIES COMPILE_DEFINITIONS BRAWL_X11)
endif()

qt5_use_modules(brawledit Widgets)

target_link_libraries(brawledit ${QT_LIBRARIES} ${SFML_LIBRARIES})

# Add additional flags to gcc and clang
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    # Don't add -Wshadow, as Qt has some inherent shadowing problems
    set_target_properties(brawledit PROPERTIES COMPILE_FLAGS "-std=c++11 -pedantic -Wall -Wextra")
endif()
