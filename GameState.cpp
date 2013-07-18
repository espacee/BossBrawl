#include "GameState.hpp"

#include "CharacterLoader.hpp"

GameState::GameState()
{

}

int GameState::Loop(sf::RenderWindow &w)
{
    w.setTitle("GAME");

    CharacterLoader player;
    player.LoadPlayer();

    sf::Event event;
    while (w.isOpen())
    {
        while (w.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                w.close();

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                return MENU;

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
                player.Player.move(0, -10);

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
                player.Player.move(10, 0);

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
                player.Player.move(0, 10);

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
                player.Player.move(-10, 0);
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                w.close();

        }

        w.clear(sf::Color(0,255,0));

        w.draw(player.Player);

        w.display();
    }

    return EXIT;
}
