
#include "Game/GameState.hpp"

#include "Core/graphics.hpp"
#include "Core/stateDriver.hpp"
#include "Core/config.hpp"
#include "Util/view.hpp"

GameState::GameState()
{
    map.addLayer(0);
    map.resizeLayer(0,20,20);
    map.setLayerGridEnabled(0, true);

    for(int i=0;i<20;i++)
    {
        for(int j=0;j<15;j++)
        {
            map.setTile(0,i,20-j,2);
        }
    }

    camera = sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y));

    fpsText.setFont(graphics::fontbasiclight);

    fpsText.setCharacterSize(16);
}

void GameState::onSet()
{
    graphics::window.setTitle("game");
    camera = sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y));
    camera.setCenter(0,0);

    fpsText.setPosition(5, graphics::window.getSize().y - 20);
}

void GameState::onUpdate()
{
    using graphics::window;

    player.update(map.getLayer(0));
    moveViewTowardsPoint(camera, player.getCenter(), 0.05);

    window.clear(sf::Color(200, 240, 150));
    graphics::window.setView(camera);
    map.display(window);
    player.display(window);

    graphics::window.setView(sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y)));
    fpsText.setString("Fps: " + std::to_string(stateDriver::getFps()));
    window.draw(fpsText);
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
