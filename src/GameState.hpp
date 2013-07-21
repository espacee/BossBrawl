#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"

#include "TileMap.hpp"
#include "Camera.hpp"

#include <SFML/Graphics.hpp>

class GameState : public State
{
public:
    GameState();
    void OnSet();
    void OnUpdate();
    void OnEvent(const sf::Event &event);

private:
    Camera camera;
    TileMap map;
    sf::Texture playerTexture;
    sf::Sprite player;
};

#endif // GAMESTATE_HPP
