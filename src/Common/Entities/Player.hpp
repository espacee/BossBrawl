#ifndef ENTITIES_PLAYER_HPP
#define ENTITIES_PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Map/TileMap.hpp"
#include "Entities/Entity.hpp"
#include "Util/collision.hpp"
#include <iostream>

/**
 * @brief The Player Class
 */
class Player: public Entity
{
public:
    Player();
    void onSet();
    void updatePlayer(Layer &mainLayer);
private:
};

#endif // ENTITIES_PLAYER_HPP
