#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <SFML/Graphics.hpp>
#include "Button.hpp"

class Editor
{
public:
    Editor();
    void toolBar();
    void displayToolbarButtons();
    void processToolbarButtons();


    Button Draw;
    Button Eraser;
    Button Fill;
    Button SelectTile;
    Button Layer;
    Button AddLayer;
    Button RemoveLayer;

    sf::RectangleShape Toolbar;

};


#endif //!EDITOR_HPP