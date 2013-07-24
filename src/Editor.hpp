#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <SFML/Graphics.hpp>
#include "TileMap.hpp"

#include "Widget.hpp"
#include "TextButton.hpp"
#include "IconButton.hpp"

class Editor
{
public:
    Editor();
    void init();
    void display();
    void processEvents(const sf::Event &event);


private:

};

#endif //!EDITOR_HPP
