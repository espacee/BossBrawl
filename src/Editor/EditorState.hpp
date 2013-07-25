#ifndef EDITORSTATE_HPP
#define EDITORSTATE_HPP

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
    virtual void onSet();
    virtual void onUpdate();
    virtual void onEvent(const sf::Event &event);

private:

    Camera camera;
    TileMap map;
    Editor editorHUD;
};

#endif // EDITORSTATE_HPP
