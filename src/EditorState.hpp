#ifndef EDITORSTATE_HPP
#define EDITORSTATE_HPP

#include "State.hpp"

#include "TileMap.hpp"
#include "Camera.hpp"
#include "Editor.hpp"

class EditorState : public State
{
public:
    virtual void onSet();
    virtual void onUpdate();
    virtual void onEvent(const sf::Event &event);

private:

    Camera camera;
    TileMap map;
    Editor editorHUD;
};

#endif // EDITORSTATE_HPP
