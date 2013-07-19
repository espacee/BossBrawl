#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"

#include "TileMap.hpp"

class GameState : public State
{
public:
    GameState();
    virtual int Loop();

};

#endif // GAMESTATE_HPP
