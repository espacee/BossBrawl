#include "Game/Player.hpp"

Player::Player()
{

    playerTexture.loadFromFile("res/img/GAME/Player.png");
    playerSprite.setTexture(playerTexture);
    center = sf::Vector2f(playerTexture.getSize().x/2,playerTexture.getSize().y/2);
}

void Player::update(Layer *mainLayer)
{
    int playerX, playerY, playerWidth, playerHeight, playerXmax, playerYmax;
    playerX = playerSprite.getPosition().x;
    playerY = playerSprite.getPosition().y;
    playerWidth = playerTexture.getSize().x;
    playerHeight = playerTexture.getSize().y;
    playerXmax = playerX + playerWidth;
    playerYmax = playerY + playerHeight;

    int layerX, layerY, layerWidth, layerHeight, layerXmax, layerYmax;
    layerX = mainLayer->getPosition().x;
    layerY = mainLayer->getPosition().y;
    layerWidth = mainLayer->getWidth();
    layerHeight = mainLayer->getHeight();
    layerXmax = layerX + layerWidth;
    layerYmax = layerY + layerHeight;

    int relX, relY, relXmax, relYmax;
    relX = playerX - layerX;
    relY = playerY - layerY;
    relXmax = playerXmax - layerX;
    relYmax = playerYmax - layerY;

    if(relX<0) relX=0;
    if(relY<0) relY=0;
    if(relXmax<0) relXmax=0;
    if(relYmax<0) relYmax=0;

    if(relX>layerWidth) relX=layerWidth;
    if(relY>layerHeight) relY=layerHeight;
    if(relXmax>layerWidth) relXmax=layerWidth;
    if(relYmax>layerHeight) relYmax=layerHeight;

    int xmin,ymin,xmax,ymax;
    xmin = relX/GRID_SIZE;
    ymin = relY/GRID_SIZE;
    xmax = relXmax/GRID_SIZE;
    ymax = relYmax/GRID_SIZE;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        playerSprite.move(-10,0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        playerSprite.move(10,0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        playerSprite.move(0,-10);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        playerSprite.move(0,10);

    for(int i=xmin; i<=xmax;i++)
    {
        for(int j=ymin;j<=ymax;j++)
        {
            mainLayer->setTile(i,j,5);
        }
    }
}

void Player::display(sf::RenderWindow &target)
{
    target.draw(playerSprite);
}

sf::Vector2f Player::getCenter()
{
    return playerSprite.getPosition()+center;
}
