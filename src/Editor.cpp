#include "Editor.hpp"

#include "graphics.hpp"

Editor::Editor()
{
    topPanel.setSize(graphics::window.getSize().x,32);
    topPanel.setPosition(0,0);
    topPanel.setBackgroundColor(sf::Color(40,40,40));

    penButton.setIcon("res/img/GUI/pen.png");
    penButton.setPosition(5,1);

    eraserButton.setIcon("res/img/GUI/eraser.png");
    eraserButton.setPosition(40,1);

    fillButton.setIcon("res/img/GUI/fill.png");
    fillButton.setPosition(75,1);

    handButton.setIcon("res/img/GUI/hand.png");
    handButton.setPosition(110,1);

    rightPanel.setSize(200,graphics::window.getSize().y);
    rightPanel.setPosition(graphics::window.getSize().x-rightPanel.getWidth(),0);
    rightPanel.setBackgroundColor(sf::Color(70,70,70));

    tileSetButton.setText("TileSet >>");
    tileSetButton.setGeometry(rightPanel.getX()+2,topPanel.getY()+topPanel.getHeight()+2,rightPanel.getWidth()-4,50);

}

void Editor::init()
{

}

void Editor::display()
{
    rightPanel.display(graphics::window);
    tileSetButton.display(graphics::window);

    topPanel.display(graphics::window);
    penButton.display(graphics::window);
    eraserButton.display(graphics::window);
    fillButton.display(graphics::window);
    handButton.display(graphics::window);
}
void Editor::processEvents(const sf::Event &event)
{
    rightPanel.processEvents(event);
    topPanel.processEvents(event);
    penButton.processEvents(event);
    eraserButton.processEvents(event);
    fillButton.processEvents(event);
    handButton.processEvents(event);
    tileSetButton.processEvents(event);
}
