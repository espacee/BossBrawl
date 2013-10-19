#include "Game/Entity.hpp"

Entity::Entity()
{

    texture.loadFromFile("res/img/GAME/Default.png");
    sprite.setTexture(texture);
    center = sf::Vector2f(texture.getSize().x / 2, texture.getSize().y / 2);
    movement = sf::Vector2f(0,0);
    gravitymovement = sf::Vector2f(0,0);

    sprite.move(100,200);

}

void Entity::updateEntity(Layer &mainLayer)
{
        gravitymovement.y+=gravity;
        movement.y+=gravitymovement.y;

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

        sf::FloatRect futureBoundingBox = sf::FloatRect(sprite.getPosition().x+virtualMovement.x,
                                                        sprite.getPosition().y+virtualMovement.y,
                                                        texture.getSize().x,
                                                        texture.getSize().y);

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

        sf::FloatRect boundingBox = sf::FloatRect(sprite.getPosition().x,
                                                  sprite.getPosition().y,
                                                  texture.getSize().x,
                                                  texture.getSize().y);

        sf::FloatRect futureBoundingBox = sf::FloatRect(sprite.getPosition().x+movement.x,
                                                        sprite.getPosition().y+movement.y,
                                                        texture.getSize().x,
                                                        texture.getSize().y);

        sf::FloatRect botArea = sf::FloatRect(sprite.getPosition().x+1,
                                              sprite.getPosition().y+texture.getSize().y/2+movement.y,
                                              texture.getSize().x-2,
                                              texture.getSize().y/2);

        sf::FloatRect topArea = sf::FloatRect(sprite.getPosition().x+1,
                                             sprite.getPosition().y+movement.y,
                                             texture.getSize().x-2,
                                             texture.getSize().y/2);

        sf::FloatRect leftArea = sf::FloatRect(sprite.getPosition().x+movement.x,
                                               sprite.getPosition().y+1,
                                               texture.getSize().x/2,
                                               texture.getSize().y-2);

        sf::FloatRect rightArea = sf::FloatRect(sprite.getPosition().x+texture.getSize().x/2+movement.x,
                                                sprite.getPosition().y+1,
                                                texture.getSize().x/2+1,
                                                texture.getSize().y-2);

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
                            gravitymovement.y = 0;
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
    sprite.move(movement);
    movement = sf::Vector2f(0,0);


}

void Entity::display(sf::RenderWindow &target)
{
    target.draw(sprite);
}

sf::Vector2f Entity::getCenter()
{
    return sprite.getPosition() + center;
}
void Entity::setPosition(int x, int y)
{
 sprite.setPosition(x,y);
}
sf::Vector2f Entity::getPosition()
{
    return sprite.getPosition();
}

