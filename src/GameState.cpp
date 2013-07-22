#include "GameState.hpp"

#include "Editor.hpp"
#include "graphics.hpp"
#include "stateDriver.hpp"


Editor toolbar;

void GameState::onSet()
{
    graphics::window.setTitle("game");

    showToolbar = false;

    map.fillLayer(0,1);

    toolbar.toolBar();
}

void GameState::onUpdate()
{
    using graphics::window;

    camera.update();

    window.clear(sf::Color(0,0,0));
        
    camera.cameraMode();
    map.display();


    camera.hudMode();
    if (showToolbar == true){
        window.draw(toolbar.Toolbar);
        toolbar.displayToolbarButtons();
        
     }
        
    
}

void GameState::onEvent(const sf::Event &event)
{
    using graphics::window;

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::requestQuit();

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
        stateDriver::setState("menu");

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tab){
        showToolbar = !showToolbar;

    }

    toolbar.Draw.processEvents(event);
    toolbar.Eraser.processEvents(event);
    toolbar.Fill.processEvents(event);
    toolbar.SelectTile.processEvents(event);
    toolbar.Layer.processEvents(event);
    toolbar.RemoveLayer.processEvents(event);
    toolbar.AddLayer.processEvents(event);
   

}
