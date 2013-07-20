#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "State.hpp"

class MenuState : public State
{
public:
    virtual void OnSet();
    virtual void OnUpdate();
    virtual void OnEvent(const sf::Event &event);
};

#endif // MENUSTATE_HPP
