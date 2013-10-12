#ifndef GAME_ENEMY_HPP
#define GAME_ENEMY_HPP

#include <SFML/Graphics.hpp>
#include "Map/TileMap.hpp"
#include "Util/collision.h"
#include <iostream>
#include "Util/math.hpp"

#include "Game/Entity.hpp"

/**
 * @brief The Enemy Class
 */
class Enemy: public Entity
{
public:
    Enemy();
    void onSet();
    void update(Layer &mainLayer);
    void Seek();
    void Follow();
    void Attack();


private:

    std::string enemyState;



};

#endif // GAME_ENEMY_HPP
