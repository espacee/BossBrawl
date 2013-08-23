#include "Game/Player.hpp"

Player::Player()
{
    onSet();

}
void Player::onSet()
{
    health = 100;

    playerTexture.loadFromFile("res/img/GAME/Player.png");
    playerSprite.setTexture(playerTexture);


}
void Player::display(sf::RenderWindow &target)
{
    target.draw(playerSprite);



}
void Player::playerControls()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        playerSprite.move(0, -5);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        playerSprite.move(5, 0);


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        playerSprite.move(0, 5);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        playerSprite.move(-5, 0);



}
