#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"

#include "TileMap.hpp"
#include "Camera.hpp"

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

#endif // GAMESTATE_HPP
