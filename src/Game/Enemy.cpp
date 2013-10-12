#include "Game/Enemy.hpp"


Enemy::Enemy()
{
    onSet();
}
void Enemy::onSet()
{

entityTexture.loadFromFile("res/img/GAME/Enemy.png");

int Seek = math::getRandomValue(1,2);

if(Seek == 1)
    entityState = "SeekLeft";
else
    entityState = "SeekRight";


}
void Enemy::update(Layer &mainLayer)
{
    updateEntity(mainLayer);

    //AI

    if(entityState == "SeekLeft"){
        std::cout <<"Seek Left mode"<<std::endl;
        SeekLeft();
    }
    else if(entityState == "SeekRight"){
        std::cout <<"Seek Right mode"<<std::endl;
        SeekRight();
    }
    else if(entityState == "Follow"){
        std::cout << "Follow mode"<<std::endl;
        Follow();
    }
    else if(entityState == "Attack"){
        std::cout << "Attack mode"<<std::endl;
        Attack();
    }



// CONTROLS
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        movement.x = -moveSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x = moveSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        movement.y = -jumpSpeed; 
//CONTROLS
}

void Enemy::SeekLeft()
{

        movement.x-=10;

        if(entityLeft == true)
            entityState = "SeekRight";


}
void Enemy::SeekRight()
{
        movement.x+=10;

        if(entityRight == true)
            entityState = "SeekLeft";
}
void Enemy::Follow()
{


}
void Enemy::Attack()
{


}
