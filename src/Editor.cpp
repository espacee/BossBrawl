#include "Editor.hpp"
#include "GameState.hpp"
#include "graphics.hpp"


Editor::Editor()
{
    init();
    enabled = false;
}

void Editor::init()
{
    topPanel.setPosition(0,0);
    topPanel.setSize(sf::Vector2f((graphics::window.getSize().x), 32));
    topPanel.setFillColor(sf::Color(60,60,60));

    penButton.setIcon("res/img/icons/pen.png");
    penButton.setPosition(1,1);
    eraserButton.setIcon("res/img/icons/eraser.png");
    eraserButton.setPosition(penButton.getX()+penButton.getWidth()+2,1);
    fillButton.setIcon("res/img/icons/fill.png");
    fillButton.setPosition(eraserButton.getX()+eraserButton.getWidth()+2,1);
    handButton.setIcon("res/img/icons/hand.png");
    handButton.setPosition(fillButton.getX()+fillButton.getWidth()+2,1);

    selectTile.create("Select Tile");
    selectTile.setPosition(handButton.getX()+handButton.getWidth()+2, 1);
    selectTile.setHeight(handButton.getHeight());
    addLayer.create(("Add Layer"));
    addLayer.setPosition(selectTile.getX()+ selectTile.getWidth() + 2, 1);
    addLayer.setHeight(handButton.getHeight());
    removeLayer.create("Remove Layer");
    removeLayer.setPosition(addLayer.getX(), addLayer.getY() + addLayer.getHeight() + 2);
    removeLayer.setHeight(handButton.getHeight());
}

void Editor::display()
{
    graphics::window.draw(topPanel);
    penButton.display();
    eraserButton.display();
    fillButton.display();
    handButton.display();

    selectTile.display();
    addLayer.display();

    if(addLayer.hovered || removeLayer.hovered)
        removeLayer.display();
}

void Editor::processEvents(const sf::Event &event)
{
    penButton.processEvents(event);
    eraserButton.processEvents(event);
    fillButton.processEvents(event);
    handButton.processEvents(event);

    selectTile.processEvents(event);
    addLayer.processEvents(event);
    removeLayer.processEvents(event);
}

void Editor::setEnabled(bool enable)
{
    enabled = enable;
}

bool Editor::getEnabled() const
{
    return enabled;
}
