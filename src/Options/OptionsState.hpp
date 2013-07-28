#ifndef OPTIONSSTATE_HPP
#define OPTIONSSTATE_HPP

#include "Core/State.hpp"
#include "Gui/TextButton.hpp"
#include "Gui/IconButton.hpp"

class OptionsState : public State
{
public:
    OptionsState();
    virtual void onSet();
    virtual void onUpdate();
    virtual void onEvent(const sf::Event &event);

private:

    sf::Text windowLabel;
    std::vector<TextButton> resoButtons;
    void addResoButtons();

    TextButton backButton;
};

#endif // OPTIONSSTATE_HPP
