#include "Editor/EditorState.hpp"

#include "Core/graphics.hpp"
#include "Core/stateDriver.hpp"
#include "Core/config.hpp"

EditorState::EditorState() :
    camera(sf::Vector2f(config::windowWidth, config::windowHeight))
{

    map.fillLayer(0,1);
}

void EditorState::onSet()
{
    graphics::window.setTitle("editor");
    camera.setSpeed(0.05f);

}
void EditorState::onUpdate()
{
    using graphics::window;

    window.clear();

    camera.apply(graphics::window);
    map.display();

    graphics::window.setView(graphics::window.getDefaultView());
    editorHUD.display();
}

void EditorState::onEvent(const sf::Event &event)
{
    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::setState("menu");

    editorHUD.processEvents(event);
}
