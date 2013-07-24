#include "EditorState.hpp"

#include "graphics.hpp"
#include "stateDriver.hpp"

void EditorState::onSet()
{
    graphics::window.setTitle("Level Editor");

}
void EditorState::onUpdate()
{
    using graphics::window;

    window.clear(sf::Color(60,60,60));


}

void EditorState::onEvent(const sf::Event &event)
{
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::requestQuit();

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
        stateDriver::setState("game");


}
