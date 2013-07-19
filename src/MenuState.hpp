#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "State.hpp"

class MenuState : public State
{
public:
    MenuState();
    virtual int Loop(sf::RenderWindow &w);

};

#endif // MENUSTATE_HPP
