#ifndef GAME_GAMESTATE_HPP
#define GAME_GAMESTATE_HPP

#include "Core/State.hpp"
#include "Map/TileMap.hpp"
#include "Game/Player.hpp"
#include "Game/Enemy.hpp"
#include "Game/Entity.hpp"
#include "Game/DefaultEnemy.hpp"
#include "Game/EntityContainer.hpp"

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
    sf::View camera;
    TileMap map;
    sf::Text fpsText;
    bool gridEnabled;

    Player player;

    EntityContainer entityContainer;


};

#endif // GAME_GAMESTATE_HPP
