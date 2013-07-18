#include "ScreenGameLoop.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "CharacterLoader.h"

CharacterLoader Player;

void ScreenGameLoop::Gameloop()
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

				//resize to 1024x768
				else  if (event.key.code == sf::Keyboard::R){
					 Screen.create(sf::VideoMode(1024, 768, 32), "1024x768 Screen!");}


				// PLAYER MOVEMENT
				else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S ){
						Player.Player.move(0, 10);

				}
				else if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Q){
						Player.Player.move(-10,0);
				}
					
				else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D ){
						Player.Player.move(10, 0);
				}
					
				else if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Z){
						Player.Player.move(0, -10);
				}
					
				
			}
        }

        Screen.clear();
		Screen.draw(Player.Player);
        Screen.display();
    }
}


ScreenGameLoop::ScreenGameLoop()
{
    Screen.create(sf::VideoMode(1280, 720), "1280x720 Screen!");
	Player.LoadPlayer();
}
