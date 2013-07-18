#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameState : public State
{
public:
    GameState();
    virtual int Loop(sf::RenderWindow &w);

};

#endif // GAMESTATE_H
