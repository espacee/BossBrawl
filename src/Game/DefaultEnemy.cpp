#include "Game/DefaultEnemy.hpp"


DefaultEnemy::DefaultEnemy()
{
    texture.loadFromFile("res/img/GAME/Monster.png");
}

void DefaultEnemy::update(Layer &mainLayer)
{
    updateEnemy(mainLayer);

}

