#include "Entities/DefaultEnemy.hpp"


DefaultEnemy::DefaultEnemy(float posX, float posY, bool editmode)
{
    texture.loadFromFile("res/img/GAME/Monster.png");
    setPosition(posX, posY);
    editorMode = editmode;
}

void DefaultEnemy::update(Layer &mainLayer)
{
    updateEnemy(mainLayer);

}

