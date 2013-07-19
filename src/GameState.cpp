#include "GameState.hpp"

GameState::GameState()
{

}

int GameState::Loop(sf::RenderWindow &w)
{
    w.setTitle("GAME");

    sf::Texture playerTexture;
    playerTexture.loadFromFile("res/img/player.png", sf::IntRect(32 ,0,32 , 32));
    sf::Sprite player(playerTexture);

    TileMap map;

    sf::Event event;
    while (w.isOpen())
    {
        while (w.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                w.close();

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                w.close();

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                return MENU;

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
                player.move(0, -10);

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
                player.move(10, 0);

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
                player.move(0, 10);

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
                player.move(-10, 0);

        }

        w.clear(sf::Color(0,0,0));

        w.draw(player);

        w.display();
    }

    return EXIT;
}
