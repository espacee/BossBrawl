#include "Editor/EditorState.hpp"

#include "Core/graphics.hpp"
#include "Core/stateDriver.hpp"
#include "Core/config.hpp"
#include "Util/view.hpp"

EditorState::EditorState() :
    camera(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y))
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

}
void EditorState::onUpdate()
{
    using graphics::window;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        testTarget.move(0, -10);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        testTarget.move(10, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        testTarget.move(0, 10);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        testTarget.move(-10, 0);


    testTarget.rotate(5);
    moveViewTowardsPoint(camera, testTarget.getPosition().x, testTarget.getPosition().y, 0.05f);



    window.clear(sf::Color(200, 200, 200));

    graphics::window.setView(camera);
    map.display();
    window.draw(testTarget);

    graphics::window.setView(sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y)));

    editorHUD.display();
}
void EditorState::onEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::setState("menu");

    /*if (event.type == sf::Event::MouseWheelMoved && event.mouseWheel.delta == 1)
        camera.zoom(1.20);

    if (event.type == sf::Event::MouseWheelMoved && event.mouseWheel.delta == -1)
        camera.zoom(0.80);*/

    editorHUD.processEvents(event);
}
