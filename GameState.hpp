#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"

class GameState : public State
{
public:
    GameState();
    virtual int Loop(sf::RenderWindow &w);

};

#endif // GAMESTATE_HPP
