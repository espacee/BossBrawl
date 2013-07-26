#ifndef GAME_GAMESTATE_HPP
#define GAME_GAMESTATE_HPP

#include "Core/State.hpp"

#include "Map/TileMap.hpp"
#include "Util/Camera.hpp"

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
private:
    Camera camera;
    TileMap map;
    sf::Text fpsText;
    sf::Texture testTargetTexture;
    sf::Sprite testTarget;
};

#endif // GAME_GAMESTATE_HPP
