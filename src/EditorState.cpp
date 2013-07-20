#include "EditorState.hpp"
#include "GameState.hpp"
#include "graphics.hpp"

GameState gamestate;

EditorState::EditorState()
{
    
}

int EditorState::Loop()
{
    
    using graphics::window;
    window.setTitle("Level Editor");

    sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return){
                return GAME;   
            }
        }
        window.clear();
        window.display();  
    }
    return EXIT;
}
