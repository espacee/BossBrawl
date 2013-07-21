#include "EditorState.hpp"

#include "graphics.hpp"
#include "stateDriver.hpp"

void EditorState::OnSet()
{
    graphics::window.setTitle("editor");
}

void EditorState::OnUpdate()
{
    using graphics::window;

    window.clear();
}

void EditorState::OnEvent(const sf::Event &event)
{
    using graphics::window;

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::RequestQuit();

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F4)
        stateDriver::SetState("game");
}
