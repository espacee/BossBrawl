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
    void onSet();
    void onUpdate();
    void onEvent(const sf::Event &event);



private:
    Camera camera;
    TileMap map;

    bool showToolbar;
};

#endif // GAMESTATE_HPP
