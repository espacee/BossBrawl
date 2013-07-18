#ifndef CHARACTERLOADER_H
#define CHARACTERLOADER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class CharacterLoader
{
public:
	CharacterLoader();
	void LoadPlayer();


	//sprites
	sf::Sprite Player;

private:
	sf::Texture PlayerText;
	
	


};

#endif //!CHARACTERLOADER_H