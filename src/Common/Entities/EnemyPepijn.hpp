#ifndef ENTITIES_ENEMYPEPIJN_HPP
#define ENTITIES_ENEMYPEPIJN_HPP

#include <SFML/Graphics.hpp>
#include "Map/TileMap.hpp"
#include "Util/collision.hpp"
#include <iostream>
#include "Util/math.hpp"
#include "Entities/Enemy.hpp"

/**
 * @brief The Enemy Class
 */
class EnemyPepijn : public Enemy
{
public:
    EnemyPepijn(float posX, float posY);

    void update(Layer &mainLayer);
};

#endif // ENTITIES_ENEMYPEPIJN_HPP
