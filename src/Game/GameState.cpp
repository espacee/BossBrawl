#include "Game/GameState.hpp"

#include "Core/graphics.hpp"
#include "Core/stateDriver.hpp"
#include "Core/config.hpp"
#include "Util/view.hpp"

GameState::GameState()
{
    camera = sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y));

    fpsText.setFont(graphics::font);

    map.resizeLayer(0,20,20);
    map.fillLayer(0,1);
    map.setLayerDepthIndex(0,0.6);

    map.addLayer();
    map.resizeLayer(1,18,18);
    map.fillLayer(1,2);
    map.setLayerDepthIndex(1,0.8);
    map.setLayerPosition(1,40,40);

    map.addLayer();
    map.resizeLayer(2,16,16);
    map.fillLayer(2,3);
    map.setLayerPosition(2,80,80);


    fpsText.setCharacterSize(16);

    testTargetTexture.loadFromFile("res/img/target.png");
    testTargetTexture.setSmooth(true);
    testTarget.setTexture(testTargetTexture);
    testTarget.setOrigin(15, 15);
}
void GameState::onSet()
{
    graphics::window.setTitle("game");
    camera = sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y));
    camera.setCenter(0,0);
    testTarget.setPosition(0,0);

    fpsText.setPosition(5, graphics::window.getSize().y - 20);
}
void GameState::onUpdate()
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

    window.clear(sf::Color(0, 0, 0));

    graphics::window.setView(camera);

    map.display();

    window.draw(testTarget);

    graphics::window.setView(sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y)));

    fpsText.setString("Fps: " + std::to_string(stateDriver::getFps()));
    window.draw(fpsText);
}

void GameState::onEvent(const sf::Event &event)
{
    using graphics::window;

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::setState("menu");
}
