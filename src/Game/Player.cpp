#include "Game/Player.hpp"

Player::Player()
{
    onSet();
}
void Player::onSet()
{

    moveSpeed =10;
    jumpSpeed = 30;

}
void Player::update(Layer &mainLayer)
{
    updateEntity(mainLayer);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        movement.x += -moveSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        movement.x += moveSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        movement.y += -jumpSpeed;

}


