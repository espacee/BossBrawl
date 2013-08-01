#ifndef EDITOR_EDITORSTATE_HPP
#define EDITOR_EDITORSTATE_HPP

#include <SFML/Graphics.hpp>

#include "Core/State.hpp"

#include "Map/TileMap.hpp"
#include "Core/config.hpp"

#include "Gui/Widget.hpp"
#include "Gui/TextButton.hpp"
#include "Gui/IconButton.hpp"
#include "Gui/ScrollArea.hpp"

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

    int getTool();
    void consoleCommands();

    void penEnabled();
    void eraserEnabled();
    void fillEnabled();
    void handEnabled();

private:
    int currentTool;
    int cx, cy, tx, ty;

    sf::View camera;
    TileMap map;

    sf::Texture testTargetTexture;
    sf::Sprite testTarget;

    Widget topPanel;
    Widget rightPanel;

    IconButton penButton;
    IconButton eraserButton;
    IconButton fillButton;
    IconButton handButton;
    TextButton tileSetButton;

    ScrollArea layerList;


};

#endif // EDITOR_EDITORSTATE_HPP
