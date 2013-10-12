#ifndef GAME_ENEMY_HPP
#define GAME_ENEMY_HPP

#include <SFML/Graphics.hpp>
#include "Map/TileMap.hpp"
#include "Util/collision.h"
#include <iostream>

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


private:




};

#endif // GAME_ENEMY_HPP
