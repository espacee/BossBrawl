#ifndef EDITORSTATE_HPP
#define EDITORSTATE_HPP

#include "State.hpp"

class EditorState : public State
{
public:
    EditorState();
    virtual int Loop();


};

#endif //!EDITORSTATE_HPP