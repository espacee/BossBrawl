#include "CharacterLoader.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


void CharacterLoader::LoadPlayer()
{
	if(!PlayerText.loadFromFile("player.png",sf::IntRect(32 ,0,32 , 32)))
	{
	std::cout << "Could not load player.png" << std::endl;
	}

	Player.setTexture(PlayerText);



}





CharacterLoader::CharacterLoader()
{




}


