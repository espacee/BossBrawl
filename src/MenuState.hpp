#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "State.hpp"
#include "TextButton.hpp"
#include "IconButton.hpp"

class MenuState : public State
{
public:
    virtual void onSet();
    virtual void onUpdate();
    virtual void onEvent(const sf::Event &event);

private:
    TextButton playButton;
    TextButton editorButton;
    TextButton quitButton;
};

#endif // MENUSTATE_HPP
