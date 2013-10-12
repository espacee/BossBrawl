#ifndef GAME_PLAYER_HPP
#define GAME_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Map/TileMap.hpp"
#include "Game/Entity.hpp"
#include "Util/collision.h"
#include <iostream>

/**
 * @brief The Player Class
 */
class Player: public Entity
{
public:
    Player();
    void onSet();
    void update(Layer &mainLayer);



private:



};

#endif // GAME_PLAYER_HPP
