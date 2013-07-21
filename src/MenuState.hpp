#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "State.hpp"
#include "Button.hpp"

class MenuState : public State
{
public:
    virtual void onSet();
    virtual void onUpdate();
    virtual void onEvent(const sf::Event &event);

private:
    Button testButton;
};

#endif // MENUSTATE_HPP
