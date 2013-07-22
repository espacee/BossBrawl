#include "GameState.hpp"

#include "graphics.hpp"
#include "stateDriver.hpp"

void GameState::onSet()
{
    graphics::window.setTitle("game");

    map.fillLayer(0,1);
}

void GameState::onUpdate()
{
    using graphics::window;

    camera.update();

    window.clear(sf::Color(0,0,0));

    camera.cameraMode();
    map.display();
    camera.hudMode();

}

void GameState::onEvent(const sf::Event &event)
{
    using graphics::window;

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::requestQuit();

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
        stateDriver::setState("menu");
}
