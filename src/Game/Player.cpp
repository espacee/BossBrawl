#include "Game/Player.hpp"

Player::Player()
{
    onSet();

}
void Player::onSet()
{
    health = 100;
    moveSpeed = 10.0f;
    jumpSpeed = 10.0f;
    groundHeight = 160;
    velocity = sf::Vector2f(0,0);

    playerTexture.loadFromFile("res/img/GAME/Player.png");
    playerSprite.setTexture(playerTexture);


}
void Player::display(sf::RenderWindow &target)
{
    target.draw(playerSprite);



}
void Player::playerControls()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        velocity.y = -jumpSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        velocity.x = -moveSpeed;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        velocity.x = moveSpeed;
    }
    else
        velocity.x = 0;


if(playerSprite.getPosition().y + playerTexture.getSize().y < groundHeight || velocity.y < 0  )
{
velocity.y += gravity;
}
else
{
playerSprite.setPosition(playerSprite.getPosition().x, groundHeight -playerTexture.getSize().y );
velocity.y = 0;
}


playerSprite.move(velocity.x, velocity.y);

}

