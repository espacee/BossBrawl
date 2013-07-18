#include "gamestate.h"

GameState::GameState()
{

}

int GameState::Loop(sf::RenderWindow &w)
{
    w.setTitle("GAME");

    sf::Event event;
    while (w.isOpen())
    {
            while (w.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    w.close();

                if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
                    return MENU;

            }

            w.clear(sf::Color(0,255,0));
            w.display();
    }

    return EXIT;
}
