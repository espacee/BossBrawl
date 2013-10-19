#ifndef GAME_DEFAULTENEMY_HPP
#define GAME_DEFAULTENEMY_HPP

#include <SFML/Graphics.hpp>
#include "Map/TileMap.hpp"
#include "Util/collision.h"
#include <iostream>
#include "Util/math.hpp"
#include "Game/Enemy.hpp"

/**
 * @brief The Enemy Class
 */
class DefaultEnemy: public Enemy
{
public:
    DefaultEnemy(float posX, float posY);

    void update(Layer &mainLayer);

};

#endif // GAME_DEFAULTENEMY_HPP
