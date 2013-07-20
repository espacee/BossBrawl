#include "MenuState.hpp"

#include "graphics.hpp"
#include "stateDriver.hpp"

void MenuState::OnSet()
{
    graphics::window.setTitle("MENU");
}

void MenuState::OnUpdate()
{
    using graphics::window;

    window.clear(sf::Color::Red);
    window.display();
}

void MenuState::OnEvent(const sf::Event &event)
{
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::RequestQuit();

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
        stateDriver::SetState("game");
}
