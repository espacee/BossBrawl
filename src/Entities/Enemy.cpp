#include "Entities/Enemy.hpp"


Enemy::Enemy()
{
    onSet();
}
void Enemy::onSet()
{

    moveSpeed =10;
    jumpSpeed = 20;

texture.loadFromFile("res/img/GAME/Enemy.png");

int Seek = math::getRandomValue(1,2);

if(Seek == 1)
    entityState = "SeekLeft";
else
    entityState = "SeekRight";


}
void Enemy::updateEnemy(Layer &mainLayer)
{
    updateEntity(mainLayer);

    //AI
    if(entityState == "SeekLeft"){ 
        SeekLeft();
    }
    else if(entityState == "SeekRight"){
        SeekRight();
    }
    else if(entityState == "Follow"){   
        Follow();
    }
    else if(entityState == "Attack"){ 
        Attack();
    }



// CONTROLS
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        movement.x = -moveSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x = moveSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        isJumping = true;
//CONTROLS
}

void Enemy::SeekLeft()
{

}
void Enemy::SeekRight()
{

}
void Enemy::Follow()
{


}
void Enemy::Attack()
{


}
