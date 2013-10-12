#include "Game/Enemy.hpp"


Enemy::Enemy()
{
    onSet();
}
void Enemy::onSet()
{

entityTexture.loadFromFile("res/img/GAME/Monster.png");

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
        movement.y = -jumpSpeed; 
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
