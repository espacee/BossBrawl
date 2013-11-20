#include <SFML/Graphics.hpp>

#include "Core/stateDriver.hpp"
#include "Core/config.hpp"
#include "Core/graphics.hpp"
#include "States/MenuState.hpp"
#include "States/OptionsMenuState.hpp"
#include "States/GameState.hpp"

int main(int argc, char* argv[])
{
    config::load();
    graphics::init();
    stateDriver::addState(new MenuState, "menu");
    stateDriver::addState(new GameState, "game");
    stateDriver::addState(new OptionsMenuState, "options");
    std::string initialState = "menu";

    if (argc > 1 && std::string(argv[1]) == "skipmenu")
        initialState = "game";

    stateDriver::setState(initialState);
    int ret = stateDriver::exec();
    config::save();
    stateDriver::deleteStates();
    return ret;
}
