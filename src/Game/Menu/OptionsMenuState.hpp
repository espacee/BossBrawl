#ifndef MENU_OPTIONSMENUSTATE_HPP
#define MENU_OPTIONSMENUSTATE_HPP

#include "Game/Core/State.hpp"
#include "Game/Gui/TextButton.hpp"
#include "Game/Gui/IconButton.hpp"

class OptionsMenuState : public State
{
public:
    OptionsMenuState();
    virtual void onSet();
    virtual void onUpdate();
    virtual void onEvent(const sf::Event &event);

private:

    sf::Text windowLabel;
    std::vector<TextButton> resoButtons;
    void addResoButtons();
    TextButton screenSizeButton;

    TextButton backButton;
};

#endif // MENU_OPTIONSMENUSTATE_HPP
