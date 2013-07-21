#ifndef EDITORSTATE_HPP
#define EDITORSTATE_HPP

#include "State.hpp"

class EditorState : public State
{
public:
    virtual void onSet();
    virtual void onUpdate();
    virtual void onEvent(const sf::Event &event);
};

#endif //!EDITORSTATE_HPP
