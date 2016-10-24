#include "Entities/EnemyPepijn.hpp"

EnemyPepijn::EnemyPepijn(float posX, float posY)
{
    texture.loadFromFile("res/img/GAME/pepijn.png");
    setPosition(posX, posY);
}

void EnemyPepijn::update(Layer &mainLayer)
{
    updateEnemy(mainLayer);
}

