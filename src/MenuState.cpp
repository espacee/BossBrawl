#include "MenuState.hpp"

#include "graphics.hpp"

MenuState::MenuState()
{

}

int MenuState::Loop()
{
    using graphics::window;
    window.setTitle("MENU");

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
                return GAME;
            

        }

        window.clear(sf::Color(255,0,0));
        window.display();
    }

    return EXIT;
}
