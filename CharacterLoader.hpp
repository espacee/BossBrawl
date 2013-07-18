#ifndef CHARACTERLOADER_HPP
#define CHARACTERLOADER_HPP

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

#endif // CHARACTERLOADER_HPP
