#include <SFML/Graphics.hpp>

#include "Core/stateDriver.hpp"
#include "Core/config.hpp"
#include "Core/graphics.hpp"
#include "Menu/MenuState.hpp"
#include "Menu/OptionsMenuState.hpp"
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
