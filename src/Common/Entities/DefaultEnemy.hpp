#ifndef ENTITIES_DEFAULTENEMY_HPP
#define ENTITIES_DEFAULTENEMY_HPP

#include <SFML/Graphics.hpp>
#include "Map/TileMap.hpp"
#include "Util/collision.hpp"
#include <iostream>
#include "Util/math.hpp"
#include "Entities/Enemy.hpp"

/**
 * @brief The Enemy Class
 */
class DefaultEnemy: public Enemy
{
public:
    DefaultEnemy(float posX, float posY);

    void update(Layer &mainLayer);
};

#endif // ENTITIES_DEFAULTENEMY_HPP
