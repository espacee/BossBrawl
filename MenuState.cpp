#include "MenuState.hpp"

MenuState::MenuState()
{

}

int MenuState::Loop(sf::RenderWindow &w)
{
    w.setTitle("MENU");

    sf::Event event;
    while (w.isOpen())
    {
        while (w.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                w.close();

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
                return GAME;

        }

        w.clear(sf::Color(255,0,0));
        w.display();
    }

    return EXIT;
}
