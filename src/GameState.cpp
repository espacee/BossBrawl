#include "GameState.hpp"

#include "graphics.hpp"

GameState::GameState()
{

}

int GameState::Loop()
{
    using graphics::window;
    window.setTitle("GAME");

    sf::Texture playerTexture;
    playerTexture.loadFromFile("res/img/player.png", sf::IntRect(32 ,0,32 , 32));
    sf::Sprite player(playerTexture);

    TileMap map;
    map.ResizeLayer(0,5,5);
    map.FillLayer(0,2);

    map.AddLayer();
    map.ResizeLayer(1,2,2);
    map.FillLayer(1,20);

    map.AddLayer();
    map.ResizeLayer(2,10,10);
    map.SetTile(2,9,9,4);

    sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();

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

		window.clear(sf::Color(0,0,0));
        map.Display();
		window.draw(player);
		window.display();
    }

    return EXIT;
}
