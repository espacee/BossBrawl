#include <SFML/Graphics.hpp>

#include "Game/Core/stateDriver.hpp"
#include "Game/Core/config.hpp"
#include "Game/Core/graphics.hpp"
#include "Game/Menu/MenuState.hpp"
#include "Game/Menu/OptionsMenuState.hpp"
#include "Game/GameState.hpp"

int main()
{
    config::load();
    graphics::init();

    stateDriver::addState(new MenuState, "menu");
    stateDriver::addState(new GameState, "game");
    stateDriver::addState(new OptionsMenuState, "options");
    stateDriver::setState("menu");

    int ret = stateDriver::exec();

    config::save();
    stateDriver::deleteStates();

    return ret;
}
