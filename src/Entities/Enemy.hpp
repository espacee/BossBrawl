#ifndef ENTITIES_ENEMY_HPP
#define ENTITIES_ENEMY_HPP

#include <SFML/Graphics.hpp>
#include "Map/TileMap.hpp"
#include "Util/collision.h"
#include <iostream>
#include "Util/math.hpp"

#include "Entities/Entity.hpp"

/**
 * @brief The Enemy Class
 */
class Enemy: public Entity
{
public:
    Enemy();
    void onSet();
    void updateEnemy(Layer &mainLayer);
    void SeekLeft();
    void SeekRight();
    void Follow();
    void Attack();


private:

    std::string entityState;



};

#endif // ENTITIES_ENEMY_HPP
