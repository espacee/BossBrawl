#include "Game/Player.hpp"

Player::Player()
{
    moveSpeed = 10;

    playerTexture.loadFromFile("res/img/GAME/Player.png");
    playerSprite.setTexture(playerTexture);
    center = sf::Vector2f(playerTexture.getSize().x / 2, playerTexture.getSize().y / 2);
    movement = sf::Vector2f(0,0);

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

    boundingBox = playerSprite.getGlobalBounds();
    boundingBox.left += -mainLayer.getX();
    boundingBox.top += -mainLayer.getY();

    sf::FloatRect futureBoundingBox;

    futureBoundingBox = boundingBox;
    futureBoundingBox.left += movement.x;
    futureBoundingBox.top += movement.y;
    botArea = futureBoundingBox; botArea.height/=2; botArea.top+=botArea.height;
    leftArea = futureBoundingBox; leftArea.width/=2; leftArea.top+=2; leftArea.height-=4;

    int xmin = boundingBox.left / GRID_SIZE;
    int ymin = boundingBox.top / GRID_SIZE;
    int xmax = (boundingBox.left + boundingBox.width) / GRID_SIZE+1;
    int ymax = (boundingBox.top + boundingBox.height) / GRID_SIZE+1;

    for (int i = 0; i < mainLayer.getHLength(); i++)
    {
        for (int j = 0; j < mainLayer.getVLength(); j++)
        {
            sf::FloatRect currentTile(i * GRID_SIZE, j * GRID_SIZE, GRID_SIZE, GRID_SIZE);

            if (mainLayer.tileExists(i, j))
            {
                if (mainLayer(i, j))
                {

                    futureBoundingBox = boundingBox;
                    futureBoundingBox.left += movement.x;
                    futureBoundingBox.top += movement.y;
                    botArea = futureBoundingBox; botArea.height/=2; botArea.top+=botArea.height; botArea.left+=1; botArea.width-=2;
                    leftArea = futureBoundingBox; leftArea.width/=2; leftArea.top+=1; leftArea.height-=2;
                    if (hitTest(botArea, currentTile))
                    {
                        movement.y = currentTile.top - (boundingBox.top + boundingBox.height);


                        if (mainLayer.tileExists(i, j-1))
                            if (mainLayer(i, j-1))
                                movement.y-=40;
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
