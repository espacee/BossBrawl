#include "MenuState.hpp"

#include "graphics.hpp"
#include "stateDriver.hpp"

void MenuState::OnSet()
{
    graphics::window.setTitle("menu");
    testButton.Create("Button");
    testButton.SetGeometry(200,200,400,130);

}

void MenuState::OnUpdate()
{
    using graphics::window;

    window.clear(sf::Color(60,60,60));

    testButton.Display();
}

void MenuState::OnEvent(const sf::Event &event)
{
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::RequestQuit();

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
        stateDriver::SetState("game");

    testButton.ProcessEvents(event);
}
