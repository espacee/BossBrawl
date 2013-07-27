#include <SFML/Graphics.hpp>

#include "Core/stateDriver.hpp"
#include "Core/config.hpp"
#include "Core/graphics.hpp"
#include "Menu/MenuState.hpp"
#include "Game/GameState.hpp"
#include "Editor/EditorState.hpp"
#include "Options/OptionsState.hpp"

int main()
{
    config::load();
    graphics::init();

    stateDriver::addState(new MenuState, "menu");
    stateDriver::addState(new GameState, "game");
    stateDriver::addState(new EditorState, "editor");
    stateDriver::addState(new OptionsState, "options");
    stateDriver::setState("menu");

    int ret = stateDriver::exec();

    config::save();
    stateDriver::deleteStates();

    return ret;
}
