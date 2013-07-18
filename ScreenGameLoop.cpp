#include "ScreenGameLoop.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

sf::RenderWindow Screen(sf::VideoMode(1280, 720), "1280x720 Screen!");







void Gameloop()
{

	
    while (Screen.isOpen())
    {
        sf::Event event;
        while (Screen.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Screen.close();
			else if( event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Escape)
					Screen.close();
				else if (event.key.code == sf::Keyboard::R)
					Screen.create(sf::VideoMode(1024, 768, 32), "1024x768 Screen!");
				
			}
        }

        Screen.clear();
        
        Screen.display();
    }


}


ScreenGameLoop::ScreenGameLoop()
{

	Gameloop();
    

	



    






}
