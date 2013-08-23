
#include "Game/GameState.hpp"

#include "Core/graphics.hpp"
#include "Core/stateDriver.hpp"
#include "Core/config.hpp"
#include "Util/view.hpp"

GameState::GameState()
{
    camera = sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y));

    fpsText.setFont(graphics::fontbasiclight);

    for (int i = 0; i < 200; i++)
    {
        map.resizeLayer(i, 5, 3);

        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                map.setTile(i, j, k, (j + k * 5) % 15 + 1);
            }
        }

        map.setLayerDepthIndex(i, (float)(i / 200.f));
        map.addLayer(0);
    }

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
    testTarget.setPosition(0, 0);
    camera.setCenter(testTarget.getPosition());

    fpsText.setPosition(5, graphics::window.getSize().y - 20);


    map.addLayer(0);
    map.addLayer(0);
    map.resizeLayer(0,100,9);
    map.setLayerGridEnabled(0, true);

    for(int i = 0; i < 100; i++)
    {
        map.setTile(0,i,8,6);
    }



}
void GameState::onUpdate()
{
    using graphics::window;

    /*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        testTarget.move(0, -10);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        testTarget.move(10, 0);


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        testTarget.move(0, 10);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        testTarget.move(-10, 0);
        */
    player.playerControls();

    testTarget.rotate(5);

    moveViewTowardsPoint(camera, player.playerSprite.getPosition().x, player.playerSprite.getPosition().y, 0.05f);


    window.clear(sf::Color(120, 0, 0));

    graphics::window.setView(camera);

    map.display(window);
    window.draw(testTarget);

    graphics::window.setView(sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y)));

    fpsText.setString("Fps: " + std::to_string(stateDriver::getFps()));
    window.draw(fpsText);


    player.display(window);
}

void GameState::onEvent(const sf::Event &event)
{
    using graphics::window;

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::setState("menu");

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Numpad8)
        camera.zoom(0.5);

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Numpad5)
        camera.zoom(2);

}
