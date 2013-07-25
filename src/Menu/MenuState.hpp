#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "Core/State.hpp"
#include "Gui/TextButton.hpp"
#include "Gui/IconButton.hpp"

/**
 * @brief The Main menu state
 */
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
