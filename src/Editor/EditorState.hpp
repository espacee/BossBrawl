#ifndef EDITOR_EDITORSTATE_HPP
#define EDITOR_EDITORSTATE_HPP

#include <SFML/Graphics.hpp>

#include "Core/State.hpp"

#include "Map/TileMap.hpp"
#include "Core/config.hpp"

#include "Gui/Widget.hpp"
#include "Gui/TextButton.hpp"
#include "Gui/IconButton.hpp"

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
    int currentTool;

    sf::View camera;
    TileMap map;

    sf::RectangleShape backgroundTop, backgroundRight, backgroundBot, backgroundLeft;
    sf::RectangleShape topPanel;
    sf::RectangleShape leftPanel;
    sf::RectangleShape botBar;
    sf::RectangleShape rightPanel;

    IconButton backButton;

    sf::Texture testTargetTexture;
    sf::Sprite testTarget;

    sf::Texture iconTexture;
    sf::Sprite icon;

    TextButton newButton;
    TextButton openButton;
    TextButton saveButton;

     //_____Tools____________//
    IconButton penButton;
    IconButton eraserButton;
    IconButton fillButton;
    IconButton handButton;
};

#endif // EDITOR_EDITORSTATE_HPP
