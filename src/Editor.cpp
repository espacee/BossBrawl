#include "Editor.hpp"
#include "GameState.hpp"
#include "config.hpp"


Editor::Editor()
{
    

}

void Editor::toolBar()
{
    Toolbar.setPosition(0,0);
    Toolbar.setSize(sf::Vector2f((config::windowWidth), 43));
    Toolbar.setFillColor(sf::Color(205,201,165));


    // Please Leave order like this or we'll get Bugs with the buttons. <3

    Layer.create("Layer");
    SelectTile.create("Select Tile");
    Draw.create("Draw");
    Eraser.create("Eraser");
    Fill.create("Fill");
    
    Layer.setPosition(10, 5);
    SelectTile.setPosition(( 10 + Layer.getWidth() + 5), 5);
    Draw.setPosition(( 10+ Layer.getWidth() + 5 + SelectTile.getWidth() + 5), 5);
    Eraser.setPosition(( 10+ Layer.getWidth() + 5 + SelectTile.getWidth() + 5 + Draw.getWidth() + 5), 5);
    Fill.setPosition(( 10+ Layer.getWidth() + 5 + SelectTile.getWidth() + 5 + Draw.getWidth() + 5 + Eraser.getWidth() + 5), 5);

    Layer.setHeight(SelectTile.getHeight());

    
 
}

void Editor::displayToolbarButtons()
{
    Draw.display();
    Eraser.display();
    Fill.display();
    SelectTile.display();
    Layer.display();

}

void Editor::processToolbarButtons()
{
    

}



