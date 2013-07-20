#include "EditorState.hpp"

#include "graphics.hpp"
#include "stateDriver.hpp"

void EditorState::OnSet()
{
    graphics::window.setTitle("Level Editor");
}

void EditorState::OnUpdate()
{
    using graphics::window;

    window.clear();
}

void EditorState::OnEvent(const sf::Event &event)
{
    using graphics::window;

    if (event.type == sf::Event::Closed)
        window.close();

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        window.close();

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return) {
        stateDriver::SetState("game");
    }
}
