#include "MenuState.hpp"

#include "graphics.hpp"
#include "stateDriver.hpp"

void MenuState::onSet()
{
    graphics::window.setTitle("menu");
    gameButton.create("Play");
    gameButton.setWidth(200);
    gameButton.setPosition(50,50);

    quitButton.create("Quit");
    quitButton.setWidth(200);
    quitButton.setPosition(50,gameButton.getY()+gameButton.getHeight()+10);

}

void MenuState::onUpdate()
{
    using graphics::window;

    window.clear(sf::Color(60,60,60));

    if(gameButton.released)
        stateDriver::setState("game");
    if(quitButton.released)
        stateDriver::requestQuit();

    gameButton.display();
    quitButton.display();

}

void MenuState::onEvent(const sf::Event &event)
{
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::requestQuit();

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
        stateDriver::setState("game");

    gameButton.processEvents(event);
    quitButton.processEvents(event);

}
