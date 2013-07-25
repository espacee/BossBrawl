#ifndef EDITOR_EDITORSTATE_HPP
#define EDITOR_EDITORSTATE_HPP

#include "Core/State.hpp"

#include "Map/TileMap.hpp"
#include "Core/Camera.hpp"
#include "Editor/Editor.hpp"

/**
 * @brief The Editor state
 */
class EditorState : public State
{
public:
    EditorState();
    virtual void onSet();
    virtual void onUpdate();
    virtual void onEvent(const sf::Event &event);

private:

    Camera camera;
    TileMap map;
    Editor editorHUD;
};

#endif // EDITOR_EDITORSTATE_HPP
