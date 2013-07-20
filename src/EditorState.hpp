#ifndef EDITORSTATE_HPP
#define EDITORSTATE_HPP

#include "State.hpp"

class EditorState : public State
{
public:
    virtual void OnSet();
    virtual void OnUpdate();
    virtual void OnEvent(const sf::Event &event);
};

#endif //!EDITORSTATE_HPP
