#include "Game/Entity.hpp"

Entity::Entity()
{
    moveSpeed =10;
    jumpSpeed = 30;


    entityTexture.loadFromFile("res/img/GAME/Player.png");
    entitySprite.setTexture(entityTexture);
    center = sf::Vector2f(entityTexture.getSize().x / 2, entityTexture.getSize().y / 2);
    movement = sf::Vector2f(0,0);

    entitySprite.move(100,200);

}

void Entity::updateEntity(Layer &mainLayer)
{



     movement.y+=gravity;



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

        sf::FloatRect futureBoundingBox = sf::FloatRect(entitySprite.getPosition().x+virtualMovement.x,
                                                        entitySprite.getPosition().y+virtualMovement.y,
                                                        entityTexture.getSize().x,
                                                        entityTexture.getSize().y);

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

        sf::FloatRect boundingBox = sf::FloatRect(entitySprite.getPosition().x,
                                                  entitySprite.getPosition().y,
                                                  entityTexture.getSize().x,
                                                  entityTexture.getSize().y);

        sf::FloatRect futureBoundingBox = sf::FloatRect(entitySprite.getPosition().x+movement.x,
                                                        entitySprite.getPosition().y+movement.y,
                                                        entityTexture.getSize().x,
                                                        entityTexture.getSize().y);

        sf::FloatRect botArea = sf::FloatRect(entitySprite.getPosition().x+1,
                                              entitySprite.getPosition().y+entityTexture.getSize().y/2+movement.y,
                                              entityTexture.getSize().x-2,
                                              entityTexture.getSize().y/2);

        sf::FloatRect topArea = sf::FloatRect(entitySprite.getPosition().x+1,
                                             entitySprite.getPosition().y+movement.y,
                                             entityTexture.getSize().x-2,
                                             entityTexture.getSize().y/2);

        sf::FloatRect leftArea = sf::FloatRect(entitySprite.getPosition().x+movement.x,
                                               entitySprite.getPosition().y+1,
                                               entityTexture.getSize().x/2,
                                               entityTexture.getSize().y-2);

        sf::FloatRect rightArea = sf::FloatRect(entitySprite.getPosition().x+entityTexture.getSize().x/2+movement.x,
                                                entitySprite.getPosition().y+1,
                                                entityTexture.getSize().x/2+1,
                                                entityTexture.getSize().y-2);

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
    entitySprite.move(movement);
    movement = sf::Vector2f(0,0);


}

void Entity::display(sf::RenderWindow &target)
{
    target.draw(entitySprite);
}

sf::Vector2f Entity::getCenter()
{
    return entitySprite.getPosition() + center;
}
void Entity::setPosition(int x, int y)
{
 entitySprite.setPosition(x,y);
}
