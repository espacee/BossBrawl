include_directories(.)

add_executable(bossbrawl
Core/State.hpp
Core/config.cpp
Core/config.hpp
Core/graphics.cpp
Core/graphics.hpp
Core/main.cpp
Core/stateDriver.cpp
Core/stateDriver.hpp
States/GameState.cpp
States/GameState.hpp
Gui/IconButton.cpp
Gui/IconButton.hpp
Gui/TextButton.cpp
Gui/TextButton.hpp
Gui/UI.cpp
Gui/UI.hpp
Gui/VerticalScrollBar.cpp
Gui/VerticalScrollBar.hpp
Gui/Widget.cpp
Gui/Widget.hpp
States/MenuState.cpp
States/MenuState.hpp
States/OptionsMenuState.cpp
States/OptionsMenuState.hpp
)

target_link_libraries(bossbrawl map entities util ${SFML_LIBRARIES})
