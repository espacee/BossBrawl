#include "Entities/Enemy.hpp"

Enemy::Enemy()
{
    onSet();
}
void Enemy::onSet()
{
    moveSpeed = 10;
    jumpSpeed = 20;
    texture.loadFromFile("res/img/GAME/Enemy.png");
    entityState = "Idle";
}
void Enemy::updateEnemy(Layer &mainLayer)
{
    update(mainLayer);

    //AI

    if (entityState == "Idle")
        Idle();

// CONTROLS
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        movement.x = -moveSpeed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x = moveSpeed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        isJumping = true;

//CONTROLS
}

void Enemy::Follow()
{
}
void Enemy::Attack()
{
}
void Enemy::Idle()
{
}
