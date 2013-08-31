
#include "Game/GameState.hpp"

#include "Core/graphics.hpp"
#include "Core/stateDriver.hpp"
#include "Core/config.hpp"
#include "Util/view.hpp"

GameState::GameState() :
    gridEnabled(false)
{
    map.addLayer(0);
    map[0]->resize(20, 20);

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            map.setTile(0, i, 20 - j, 2);
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
    camera.setCenter(0, 0);

    fpsText.setPosition(5, graphics::window.getSize().y - 20);
}

void GameState::onUpdate()
{
    using graphics::window;

    player.update(map[0]);
    moveViewTowardsPoint(camera, player.getCenter(), 0.05);

    window.clear(sf::Color(80, 80, 80));
    graphics::window.setView(camera);
    map.display(window, (gridEnabled ? 0 : -1));
    player.display(window);

    graphics::window.setView(sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y)));
    fpsText.setString("Fps: " + std::to_string(stateDriver::getFps()));
    window.draw(fpsText);
}

void GameState::onEvent(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Escape:
            stateDriver::setState("menu");
            break;

        case sf::Keyboard::Numpad8:
            camera.zoom(0.5);
            break;

        case sf::Keyboard::Numpad5:
            camera.zoom(2);
            break;

        case sf::Keyboard::G:
            gridEnabled = !gridEnabled;

        default:
            ;
        }
    }
}
