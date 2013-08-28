#ifndef GAME_PLAYER_HPP
#define GAME_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Map/TileMap.hpp"
#include <iostream>

/**
 * @brief The Player Class
 */
class Player
{
public:
    Player();
    void update(Layer *mainLayer);
    void display(sf::RenderWindow &target);
    sf::Vector2f getCenter();

private:

    sf::Vector2f center;

    sf::Texture playerTexture;
    sf::Sprite playerSprite;
};

#endif // GAME_PLAYER_HPP
