#ifndef EDITOR_EDITORSTATE_HPP
#define EDITOR_EDITORSTATE_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "Core/State.hpp"

#include "Map/TileMap.hpp"
#include "Core/config.hpp"

#include "Gui/Widget.hpp"
#include "Gui/TextButton.hpp"
#include "Gui/IconButton.hpp"
#include "Gui/layerSettings.hpp"

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

    void tileSelector();
    void penTool();
    void eraserTool();
    void fillTool();
    void handTool();

private:
    int  cx, cy, tx, ty;
    int currentTool, currentTile;


    bool buttonPressed;

    sf::View camera;
    TileMap map;


    sf::Texture testTargetTexture;
    sf::Sprite testTarget;

    sf::Texture iconTexture;
    sf::Sprite icon;


};
#endif // EDITOR_EDITORSTATE_HPP
