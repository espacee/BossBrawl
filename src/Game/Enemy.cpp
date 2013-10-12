#include "Game/Enemy.hpp"


Enemy::Enemy()
{
    onSet();
}
void Enemy::onSet()
{

entityTexture.loadFromFile("res/img/GAME/Enemy.png");
enemyState = "Seek";


}
void Enemy::update(Layer &mainLayer)
{
    updateEntity(mainLayer);

    //AI

    if(enemyState == "Seek"){
        std::cout <<"Seed mode"<<std::endl;
        Seek();
    }
    else if(enemyState == "Follow"){
        std::cout << "Follow mode"<<std::endl;
        Follow();
    }
    else if(enemyState == "Attack"){
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

void Enemy::Seek()
{
math::getRandomValue(10,10);
}
void Enemy::Follow()
{


}
void Enemy::Attack()
{


}
