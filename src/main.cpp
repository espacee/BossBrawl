#include <SFML/Graphics.hpp>

#include "stateDriver.hpp"
#include "config.hpp"
#include "graphics.hpp"
#include "MenuState.hpp"
#include "GameState.hpp"
#include "EditorState.hpp"

int main()
{
    config::Load();
    graphics::Init();

    stateDriver::AddState(new MenuState, "menu");
    stateDriver::AddState(new GameState, "game");
    stateDriver::AddState(new EditorState, "editor");
    stateDriver::SetState("menu");

    int ret = stateDriver::Exec();

    config::Save();
    return ret;
}
