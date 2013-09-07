#ifndef GAME_PLAYER_HPP
#define GAME_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Map/TileMap.hpp"
#include "Util/collision.h"

/**
 * @brief The Player Class
 */
class Player
{
public:
    Player();
    void update(Layer &mainLayer);
    void display(sf::RenderWindow &target);
    sf::Vector2f getCenter();

private:
    sf::Vector2f center;
    sf::Vector2f velocity;

    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    sf::FloatRect topArea, rightArea, botArea, leftArea;
};

#endif // GAME_PLAYER_HPP
