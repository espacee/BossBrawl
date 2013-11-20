#ifndef GAME_GAMESTATE_HPP
#define GAME_GAMESTATE_HPP

#include "Core/State.hpp"
#include "Map/TileMap.hpp"
#include "Entities//Player.hpp"
#include "Entities/Enemy.hpp"
#include "Entities/Entity.hpp"
#include "Entities/DefaultEnemy.hpp"
#include "Entities/EntityContainer.hpp"
#include "Gui/UI.hpp"

#include <SFML/Graphics.hpp>

#include <vector>

/**
 * @brief The Game state
 */
class GameState : public State
{
public:
    GameState();
    void onSet();
    void onUpdate();
    void onEvent(const sf::Event &event);

private:
    UI ui;

    sf::View camera;
    TileMap map;
    sf::Text fpsText;
    bool gridEnabled;

    Player player;

    EntityContainer entityContainer;
};

#endif // GAME_GAMESTATE_HPP
