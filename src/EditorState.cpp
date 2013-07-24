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

    editorHUD.display();
}

void EditorState::onEvent(const sf::Event &event)
{
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::setState("menu");

    editorHUD.processEvents(event);
}
