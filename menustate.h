#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "state.h"

class MenuState : public State
{
public:
    MenuState();
    virtual int Loop(sf::RenderWindow &w);

};

#endif // MENUSTATE_H
