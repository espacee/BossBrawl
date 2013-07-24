#ifndef EDITOR_HPP
#define EDITOR_HPP

#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include "TileMap.hpp"

class Editor
{
public:
    Editor();
    void init();
    void display();
    void processEvents(const sf::Event &event);
    void setEnabled(bool enable);
    bool getEnabled() const;
    void tileSelection();

    int selection;

    sf::Text layerText;



    Button penButton;
    Button eraserButton;
    Button fillButton;
    Button handButton;

    Button selectTile;
    Button tile1;
    Button tile2;
    Button addLayer;
    Button removeLayer;

private:
    sf::RectangleShape topPanel;
    sf::RectangleShape sidePanel;
    TileMap map;
    bool enabled;

};

#endif //!EDITOR_HPP
