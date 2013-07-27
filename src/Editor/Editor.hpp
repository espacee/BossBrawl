#ifndef EDITOR_EDITOR_HPP
#define EDITOR_EDITOR_HPP

#include <SFML/Graphics.hpp>
#include "Map/TileMap.hpp"
#include "Util/Camera.hpp"
#include "Core/config.hpp"

#include "Gui/Widget.hpp"
#include "Gui/TextButton.hpp"
#include "Gui/IconButton.hpp"
#include "Gui/VerticalScrollBar.hpp"

/**
 * @brief Map editor
 */
class Editor
{
public:
    Editor();
    void display();
    void processEvents(const sf::Event &event);

private:
    Widget topPanel;
    Widget rightPanel;

    IconButton penButton;
    IconButton eraserButton;
    IconButton fillButton;
    IconButton handButton;
    TextButton tileSetButton;

    VerticalScrollBar test;

};

#endif // EDITOR_EDITOR_HPP
