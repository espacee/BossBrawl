#include "Game/GameState.hpp"
#include "Core/graphics.hpp"
#include "Core/stateDriver.hpp"
#include "Core/config.hpp"
#include "Util/view.hpp"


GameState::GameState() :
    gridEnabled(false)
{
    map.loadFromFile("res/maps/test.map");

    camera = sf::View(sf::FloatRect(0, 0, graphics::window.getSize().x, graphics::window.getSize().y));
    fpsText.setFont(graphics::fontbasiclight);
    fpsText.setCharacterSize(16);


    enemies.push_back(new Enemy());



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

    player.update(map[1]);

    for(int i=0; i < enemies.size(); i++)
            enemies[i]->update(map[1]);



    moveViewTowardsPoint(camera, player.getCenter(), 0.05);

    window.clear(sf::Color(80, 80, 80));
    graphics::window.setView(camera);
    map.draw(window, (gridEnabled ? 0 : -1));
    player.display(window);

    for(int i=0; i < enemies.size(); i++)
        enemies[i]->display(window);



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
            break;

        case sf::Keyboard::P:{
            enemies.push_back(new Enemy());
            int newEnemy = enemies.size();
        }
            break;
        case sf::Keyboard::O:
            break;

        default:
            ;
        }
    }
}
