#include <SFML/Graphics.hpp>

#include "stateDriver.hpp"
#include "config.hpp"
#include "graphics.hpp"
#include "MenuState.hpp"
#include "GameState.hpp"

int main()
{
    config::load();
    graphics::init();

    stateDriver::addState(new MenuState, "menu");
    stateDriver::addState(new GameState, "game");
    stateDriver::setState("menu");

    int ret = stateDriver::exec();

    config::save();
    return ret;
}
