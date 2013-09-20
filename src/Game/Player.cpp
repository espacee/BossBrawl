#include "Game/Player.hpp"

Player::Player()
{
    moveSpeed =50;

    playerTexture.loadFromFile("res/img/GAME/Player.png");
    playerSprite.setTexture(playerTexture);
    center = sf::Vector2f(playerTexture.getSize().x / 2, playerTexture.getSize().y / 2);
    movement = sf::Vector2f(0,0);

    playerSprite.move(-40,-80);

}

void Player::update(Layer &mainLayer)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        movement.x-=moveSpeed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        movement.x+=moveSpeed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        movement.y-=moveSpeed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        movement.y+=moveSpeed;

    int maxStepLength = sqrt(movement.x*movement.x+movement.y*movement.y);
    if(maxStepLength>20) maxStepLength = 20;
    int stepLength;
    if(abs(movement.x)>abs(movement.y)) stepLength =abs(movement.x); else stepLength = abs(movement.y);
    if(stepLength>maxStepLength) stepLength = maxStepLength;
    int hSteps = abs(movement.x / stepLength);
    int vSteps = abs(movement.y / stepLength);
    int steps;
    if(hSteps>vSteps) steps = hSteps; else steps = vSteps;
    float hStepsLength = movement.x / steps;
    float vStepsLength = movement.y / steps;
    int firstHitStep = -1;
    bool collisionDetected = false;

    sf::Vector2f virtualMovement;

    for(int k=0;k<=steps;k++)
    {
        virtualMovement = sf::Vector2f(k*hStepsLength, k*vStepsLength);

        sf::FloatRect futureBoundingBox = sf::FloatRect(playerSprite.getPosition().x+virtualMovement.x,
                                                        playerSprite.getPosition().y+virtualMovement.y,
                                                        playerTexture.getSize().x,
                                                        playerTexture.getSize().y);

        int xmin = futureBoundingBox.left / GRID_SIZE;
        int ymin = futureBoundingBox.top / GRID_SIZE;
        int xmax = (futureBoundingBox.left + futureBoundingBox.width) / GRID_SIZE+1;
        int ymax = (futureBoundingBox.top + futureBoundingBox.height) / GRID_SIZE+1;

        for(int i=xmin;i<xmax;i++)
        {
            for(int j=ymin;j<ymax;j++)
            {
                sf::FloatRect currentTile(i * GRID_SIZE, j * GRID_SIZE, GRID_SIZE, GRID_SIZE);
                if (mainLayer.tileExists(i, j))
                {
                    if (mainLayer(i, j))
                    {
                        if (hitTest(futureBoundingBox, currentTile))
                        {
                            if(collisionDetected == false)
                            {
                                firstHitStep = k;
                                collisionDetected = true;
                                goto label_exit;
                            }
                        }
                    }
                }
            }
        }
    }

    label_exit:

    if(collisionDetected)
    {
        movement = sf::Vector2f(firstHitStep*hStepsLength, firstHitStep*vStepsLength);

        sf::FloatRect boundingBox = sf::FloatRect(playerSprite.getPosition().x,
                                                  playerSprite.getPosition().y,
                                                  playerTexture.getSize().x,
                                                  playerTexture.getSize().y);

        sf::FloatRect futureBoundingBox = sf::FloatRect(playerSprite.getPosition().x+movement.x,
                                                        playerSprite.getPosition().y+movement.y,
                                                        playerTexture.getSize().x,
                                                        playerTexture.getSize().y);

        sf::FloatRect botArea = sf::FloatRect(playerSprite.getPosition().x+1,
                                              playerSprite.getPosition().y+playerTexture.getSize().y/2+movement.y,
                                              playerTexture.getSize().x-2,
                                              playerTexture.getSize().y/2);

        sf::FloatRect topArea = sf::FloatRect(playerSprite.getPosition().x+1,
                                             playerSprite.getPosition().y+movement.y,
                                             playerTexture.getSize().x-2,
                                             playerTexture.getSize().y/2);

        sf::FloatRect leftArea = sf::FloatRect(playerSprite.getPosition().x+movement.x,
                                               playerSprite.getPosition().y+1,
                                               playerTexture.getSize().x/2,
                                               playerTexture.getSize().y-2);

        sf::FloatRect rightArea = sf::FloatRect(playerSprite.getPosition().x+playerTexture.getSize().x/2+movement.x,
                                                playerSprite.getPosition().y+1,
                                                playerTexture.getSize().x/2+1,
                                                playerTexture.getSize().y-2);

        int xmin = futureBoundingBox.left / GRID_SIZE;
        int ymin = futureBoundingBox.top / GRID_SIZE;
        int xmax = (futureBoundingBox.left + futureBoundingBox.width) / GRID_SIZE+1;
        int ymax = (futureBoundingBox.top + futureBoundingBox.height) / GRID_SIZE+1;

        for (int i = xmin; i < xmax; i++)
        {
            for (int j = ymin; j < ymax; j++)
            {
                sf::FloatRect currentTile(i * GRID_SIZE, j * GRID_SIZE, GRID_SIZE, GRID_SIZE);

                if (mainLayer.tileExists(i, j))
                {
                    if (mainLayer(i, j))
                    {

                        if (hitTest(botArea, currentTile))
                        {
                            movement.y = currentTile.top - (boundingBox.top + boundingBox.height);
                        }

                        if (hitTest(rightArea, currentTile))
                        {
                            movement.x = currentTile.left - (boundingBox.left + boundingBox.width);
                        }

                        if (hitTest(leftArea, currentTile))
                        {
                            movement.x = (currentTile.left+currentTile.width) - boundingBox.left;
                        }

                        if (hitTest(topArea, currentTile))
                        {
                            movement.y = (currentTile.top+currentTile.height) - boundingBox.top;
                        }
                    }
                }
            }
        }
    }
    playerSprite.move(movement);
    movement = sf::Vector2f(0,0);
}

void Player::display(sf::RenderWindow &target)
{
    target.draw(playerSprite);
}

sf::Vector2f Player::getCenter()
{
    return playerSprite.getPosition() + center;
}
