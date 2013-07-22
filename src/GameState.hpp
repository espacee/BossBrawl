#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"

#include "TileMap.hpp"
#include "Camera.hpp"
#include "Button.hpp"

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
    sf::Text fpsText;

    bool showToolbar;
};

#endif // GAMESTATE_HPP
