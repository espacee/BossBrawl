#ifndef GAME_ENTITY_HPP
#define GAME_ENTITY_HPP

#include <SFML/Graphics.hpp>
#include "Map/TileMap.hpp"
#include "Util/collision.h"
#include <iostream>

/**
 * @brief The Entity Class
 */
class Entity
{
public:
    Entity();
    void updateEntity(Layer &mainLayer);
    void display(sf::RenderWindow &target);
    sf::Vector2f getCenter();

    void setPosition(int x, int y);

protected:

    sf::Vector2f movement;
    float moveSpeed, jumpSpeed;

    float gravity = 16;

    sf::Vector2f center;

    sf::Texture entityTexture;
    sf::Sprite entitySprite;


};

#endif // GAME_ENTITY_HPP
