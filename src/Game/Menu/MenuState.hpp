#ifndef MENU_MENUSTATE_HPP
#define MENU_MENUSTATE_HPP

#include "Game/Core/State.hpp"
#include "Game/Gui/TextButton.hpp"
#include "Game/Gui/IconButton.hpp"

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
    TextButton optionButton;
    TextButton quitButton;
};

#endif // MENU_MENUSTATE_HPP

