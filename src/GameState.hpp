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
    void onSet();
    void onUpdate();
    void onEvent(const sf::Event &event);

private:
    Camera camera;
    TileMap map;
    sf::Texture playerTexture;
    sf::Sprite player;
};

#endif // GAMESTATE_HPP
