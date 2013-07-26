#include "Game/GameState.hpp"

#include "Core/graphics.hpp"
#include "Core/stateDriver.hpp"
#include "Core/config.hpp"


GameState::GameState() :
    camera(sf::Vector2f(config::windowWidth, config::windowHeight))
{
    fpsText.setFont(graphics::font);
    map.fillLayer(0, 1);

    fpsText.setCharacterSize(16);
    fpsText.setPosition(5, graphics::window.getSize().y - 20);

    testTargetTexture.loadFromFile("res/img/target.png");
    testTargetTexture.setSmooth(true);
    testTarget.setTexture(testTargetTexture);
    testTarget.setOrigin(15, 15);
}
void GameState::onSet()
{
    graphics::window.setTitle("game");
    camera.setSpeed(0.05f);
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
    camera.setTarget(testTarget.getPosition());
    camera.update();

    window.clear(sf::Color(0, 0, 0));

    camera.apply(graphics::window);
    map.display();
    window.draw(testTarget);

    graphics::window.setView(graphics::window.getDefaultView());

    fpsText.setString("Fps: " + std::to_string(stateDriver::getFps()));
    window.draw(fpsText);
}

void GameState::onEvent(const sf::Event &event)
{
    using graphics::window;

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::setState("menu");
}
