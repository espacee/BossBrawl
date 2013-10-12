#ifndef GAME_GAMESTATE_HPP
#define GAME_GAMESTATE_HPP

#include "Core/State.hpp"

#include "Map/TileMap.hpp"
#include "Game/Player.hpp"
#include "Game/Enemy.hpp"

#include <SFML/Graphics.hpp>

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

    Player player;
    Enemy enemy;
private:
    sf::View camera;
    TileMap map;
    sf::Text fpsText;
    bool gridEnabled;

};

#endif // GAME_GAMESTATE_HPP
