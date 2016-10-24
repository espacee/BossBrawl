#include "Entities/DefaultEnemy.hpp"

DefaultEnemy::DefaultEnemy(float posX, float posY)
{
    texture.loadFromFile("res/img/GAME/pepijnHoofd.png");
    setPosition(posX, posY);
}

void DefaultEnemy::update(Layer &mainLayer)
{
    updateEnemy(mainLayer);
}

