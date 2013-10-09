#include "Game/Enemy.hpp"



Enemy::Enemy(int posX, int posY)
{



}

void Enemy::update(Layer &mainLayer)
{
    updateEntity(mainLayer);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        movement.x = -moveSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x = moveSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        movement.y = -jumpSpeed;
}
