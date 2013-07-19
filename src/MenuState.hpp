#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "State.hpp"

class MenuState : public State
{
public:
    MenuState();
    virtual int Loop();

};

#endif // MENUSTATE_HPP
