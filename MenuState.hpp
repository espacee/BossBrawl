#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "State.hpp"

class MenuState : public State
{
public:
    MenuState();
    virtual int Loop(sf::RenderWindow &w);

};

#endif // MENUSTATE_H
