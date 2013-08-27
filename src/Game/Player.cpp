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

    tilerect.setSize(sf::Vector2f(40,40));


    playerTexture.loadFromFile("res/img/GAME/Player.png");
    playerSprite.setTexture(playerTexture);


}
void Player::update(TileMap &map)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        velocity.x = -moveSpeed;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        velocity.x = moveSpeed;
    }
    else
        velocity.x = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
       velocity.y = -jumpSpeed;
    }

    posX = playerSprite.getPosition().x;
    posY = playerSprite.getPosition().y;

    pSizeX = playerSprite.getGlobalBounds().width;
    pSizeY = playerSprite.getGlobalBounds().height;

    tileX = tilerect.getPosition().x;
    tileY = tilerect.getPosition().y;


    if(posY < tileY || velocity.y < 0 )
        velocity.y += gravity;
    else if(playerSprite.getGlobalBounds().intersects(tilerect.getGlobalBounds()))
    {
        velocity.y = 0;
    }


    playerSprite.move(velocity.x, velocity.y);


    for(unsigned int  x = 0; x < map.getLayer(0)->getHLength(); x++)
    {
        for (unsigned int y = 0; y < map.getLayer(0)->getVLength(); y++)

        {


            if(map.getLayer(0)->getTile(x,y) != 0)
            {

                    tilerect.setPosition(x*40, y*40);






            }
          }
       }




/*
    if(playerSprite.getPosition().y + playerTexture.getSize().y < groundHeight || velocity.y < 0  )
    {
    velocity.y += gravity;
    }

    else
    {
    playerSprite.setPosition(playerSprite.getPosition().x, groundHeight -playerTexture.getSize().y );
    velocity.y = 0;
    }
    */



}
void Player::display(sf::RenderWindow &target)
{
    target.draw(playerSprite);
    target.draw(tilerect);


}
int Player::round40(int nb)
{
    return ((int)nb / 40) * 40;
}
