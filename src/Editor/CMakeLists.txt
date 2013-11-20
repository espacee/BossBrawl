find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
qt5_wrap_ui(UIS_HDRS
LayerSettingsDialog.ui
)

add_executable(brawledit
EditorWidget.cpp
EditorWidget.hpp
LayerItemWidget.cpp
LayerItemWidget.hpp
LayerListWidget.cpp
LayerListWidget.hpp
LayerSettingsDialog.cpp
LayerSettingsDialog.hpp
SFMLWidget.cpp
SFMLWidget.hpp
TileSelectionWidget.cpp
TileSelectionWidget.hpp
main.cpp
${UIS_HDRS}
)

find_package(X11)

if(X11_FOUND)
    add_definitions(-DBRAWL_X11)
endif()

qt5_use_modules(brawledit Widgets)

target_link_libraries(brawledit map entities util ${SFML_LIBRARIES})
