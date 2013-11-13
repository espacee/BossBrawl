#ifndef ENTITIES_ENTITY_HPP
#define ENTITIES_ENTITY_HPP

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
    sf::Vector2f getPosition();
    void toggleEditorMode();

    bool contains(float posX, float posY);
    sf::Vector2f getSize();
    float getHealth();
    void damage(float dmg);
    void heal(float healed);



protected:

    sf::Vector2f movement, gravitymovement;

    float health, maxHealth;

    float gravity = 1;
    bool isJumping;
    float moveSpeed, jumpSpeed;

    bool editorMode;

    sf::Vector2f center;

    sf::Texture texture;
    sf::Sprite sprite;

};

#endif // ENTITIES_ENTITY_HPP
