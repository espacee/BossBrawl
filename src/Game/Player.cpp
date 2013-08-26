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
void Player::update(TileMap &map)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
      //  velocity.y = -jumpSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
      //  velocity.x = -moveSpeed;
        playerSprite.move(-10,0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
       // velocity.x = moveSpeed;
        playerSprite.move(10,0);
    }
   // else
      //  velocity.x = 0;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
       // velocity.x = moveSpeed;
        playerSprite.move(0,-10);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        //velocity.x = moveSpeed;
        playerSprite.move(0,10);
    }




    for(unsigned int  x = 0; x < map.getLayer(0)->getHLength(); x++)
    {
        for (unsigned int y = 0; y < map.getLayer(0)->getVLength(); y++)

        {
            int posX = playerSprite.getPosition().x;
            int posY = playerSprite.getPosition().y;

            int pSizeX = playerSprite.getGlobalBounds().width;
            int pSizeY = playerSprite.getGlobalBounds().height;

            tilerect.setSize(sf::Vector2f(40,40));


            if(map.getLayer(0)->getTile(x,y) != 0)
            {

                tilerect.setPosition(x*40, y*40);




                    int tileX = tilerect.getPosition().x;
                    int tileY = tilerect.getPosition().y;


                    if(posX + pSizeX > tileX && posX < tileX + 40 && posX + pSizeX < tileX + 40 && posY + pSizeY > tileY  && posY < tileY +40 )
                    {


                    }




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


//playerSprite.move(velocity.x, velocity.y);

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
