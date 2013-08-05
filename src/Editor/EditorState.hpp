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
    int currentTool, cx, cy, tx, ty, tabs;
    int totalLayers, currentLayer;
    int currentTile;

    bool buttonPressed;

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

    //_____ Right Panel______//
    TextButton objectsTab;
    TextButton layersTab;

    layerSettings totalLayerSettings;

    std::vector < layerSettings *> layersettings;
    layerSettings *layerinfo = new layerSettings[10];
    //______ Right Panel ________//
    //_______ Top Panel _________//
    TextButton selecttile;

    //_________ Top Panel _________//
};
#endif // EDITOR_EDITORSTATE_HPP
