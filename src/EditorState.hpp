#ifndef EDITORSTATE_HPP
#define EDITORSTATE_HPP

#include "State.hpp"
#include "Button.hpp"

class EditorState : public State
{
public:
    virtual void onSet();
    virtual void onUpdate();
    virtual void onEvent(const sf::Event &event);

private:


};

#endif // EDITORSTATE_HPP
