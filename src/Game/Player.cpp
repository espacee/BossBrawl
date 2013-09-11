#include "Game/Player.hpp"

Player::Player()
{
    moveSpeed = 10;
    jumpSpeed = 10;


    playerTexture.loadFromFile("res/img/GAME/Player.png");
    playerSprite.setTexture(playerTexture);
    center = sf::Vector2f(playerTexture.getSize().x / 2, playerTexture.getSize().y / 2);
    velocity = sf::Vector2f(0,0);

}

void Player::update(Layer &mainLayer)
{
/*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        playerSprite.move(-moveSpeed, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        playerSprite.move(moveSpeed, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        playerSprite.move(0, -moveSpeed);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        playerSprite.move(0, moveSpeed);
        */

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        velocity.x = -moveSpeed;


    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                velocity.x = moveSpeed;
    else
        velocity.x = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
         velocity.y = -jumpSpeed;

    if(inAir == true)
        velocity.y+=gravity;

    playerSprite.move(velocity.x, velocity.y);


    boundingBox = playerSprite.getGlobalBounds();
    boundingBox.left -= mainLayer.getX();
    boundingBox.top -= mainLayer.getY();

    botArea = boundingBox;
    botArea.height /= 2;
    botArea.top += botArea.height;

    rightArea = boundingBox;
    rightArea.width /= 2;
    rightArea.left += rightArea.width;

    leftArea = boundingBox;
    leftArea.width /= 2;

    topArea = boundingBox;
    topArea.height /= 2;

    int xmin = boundingBox.left / GRID_SIZE;
    int ymin = boundingBox.top / GRID_SIZE;
    int xmax = (boundingBox.left + boundingBox.width) / GRID_SIZE;
    int ymax = (boundingBox.top + boundingBox.height) / GRID_SIZE;

    for (int i = 0; i < mainLayer.getHLength(); i++)
    {
        for (int j = 0; j < mainLayer.getVLength(); j++)
        {
            sf::FloatRect currentTile(i * GRID_SIZE, j * GRID_SIZE, GRID_SIZE, GRID_SIZE);

            if (mainLayer.tileExists(i, j))
            {
                if (mainLayer(i, j))
                {

                   if (hitTest(botArea, currentTile))
                    {
                     inAir = false;
                     velocity.y = 0;
                    }
                   else
                       inAir = true;

                    if (hitTest(rightArea, currentTile))
                    {
                      //  playerSprite.move(-moveSpeed, 0);

                    }
                    if (hitTest(leftArea, currentTile))
                    {
                     //   playerSprite.move(moveSpeed, 0);

                    }
                    if (hitTest(topArea, currentTile))
                    {
                       // playerSprite.move(0, moveSpeed);
                    }
                }
            }
        }
    }
}

void Player::display(sf::RenderWindow &target)
{
    target.draw(playerSprite);
}

sf::Vector2f Player::getCenter()
{
    return playerSprite.getPosition() + center;
}
