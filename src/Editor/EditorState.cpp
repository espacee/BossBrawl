#include "Editor/EditorState.hpp"

#include "Core/graphics.hpp"
#include "Core/stateDriver.hpp"
#include "Core/config.hpp"

EditorState::EditorState() :
    camera(sf::Vector2f(config::windowWidth, config::windowHeight))
{

    map.fillLayer(0, 1);

    /** camera **/

    testTargetTexture.loadFromFile("res/img/target.png");
    testTargetTexture.setSmooth(true);
    testTarget.setTexture(testTargetTexture);
    testTarget.setOrigin(15, 15);

}

void EditorState::onSet()
{
    graphics::window.setTitle("editor");
    camera.setSpeed(0.05f);

}
void EditorState::onUpdate()
{
    using graphics::window;

    /** CAMERA **/

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        testTarget.move(0, -10);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        testTarget.move(10, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        testTarget.move(0, 10);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        testTarget.move(-10, 0);


    testTarget.rotate(5);
    camera.setTarget(testTarget.getPosition());
    camera.update();



    window.clear();

    camera.apply(graphics::window);
    map.display();
    window.draw(testTarget);

    graphics::window.setView(graphics::window.getDefaultView());

    map.display();

    editorHUD.display();
}
void EditorState::onEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::setState("menu");
    if(event.type == sf::Event::MouseWheelMoved && event.mouseWheel.delta == 1)
       camera.m_view.zoom(1.20);
    if(event.type == sf::Event::MouseWheelMoved && event.mouseWheel.delta == -1)
       camera.m_view.zoom(0.80);

    editorHUD.processEvents(event);
}
