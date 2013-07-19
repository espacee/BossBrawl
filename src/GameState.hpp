#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"

#include "TileMap.hpp"

class GameState : public State
{
public:
    GameState();
    virtual int Loop(sf::RenderWindow &w);

};

#endif // GAMESTATE_HPP
