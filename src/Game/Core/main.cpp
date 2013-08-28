#include <SFML/Graphics.hpp>

#include "Game/Core/stateDriver.hpp"
#include "Game/Core/config.hpp"
#include "Game/Core/graphics.hpp"
#include "Game/Menu/MenuState.hpp"
#include "Game/Menu/OptionsMenuState.hpp"
#include "Game/GameState.hpp"

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
