#include "EditorState.hpp"

#include "graphics.hpp"
#include "stateDriver.hpp"

void EditorState::onSet()
{
    graphics::window.setTitle("editor");
}

void EditorState::onUpdate()
{
    using graphics::window;

    window.clear();
}

void EditorState::onEvent(const sf::Event &event)
{
    using graphics::window;

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::requestQuit();

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F4)
        stateDriver::setState("game");
}
