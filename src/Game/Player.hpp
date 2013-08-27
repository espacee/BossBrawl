#ifndef GAME_PLAYER_HPP
#define GAME_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Map/TileMap.hpp"

/**
 * @brief The Player Class
 */
class Player
{
public:
    Player();
    void onSet();
    void update(TileMap &map);
    void display(sf::RenderWindow &target);
    int round40(int nb);


 sf::Sprite playerSprite;

private:


    int health;
    const float gravity = 1;
    float moveSpeed,jumpSpeed;
    int groundHeight;
    sf::Vector2f velocity;

    sf::Texture playerTexture;
    sf::RectangleShape tilerect;

    int posX,posY, pSizeX, pSizeY, tileX, tileY;



};

#endif // GAME_PLAYER_HPP
