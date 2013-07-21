#include "MenuState.hpp"

#include "graphics.hpp"
#include "stateDriver.hpp"

void MenuState::onSet()
{
    graphics::window.setTitle("menu");
    testButton.create("Button");

}

void MenuState::onUpdate()
{
    using graphics::window;

    window.clear(sf::Color(60,60,60));

    testButton.display();
}

void MenuState::onEvent(const sf::Event &event)
{
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::requestQuit();

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
        stateDriver::setState("game");

    testButton.processEvents(event);
}
