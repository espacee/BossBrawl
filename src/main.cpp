#include <SFML/Graphics.hpp>

#include "StateManager.hpp"
#include "config.hpp"
#include "graphics.hpp"

int main()
{
    StateManager m;
    m.SetCurrentState(MENU);
    config::Load();
    graphics::Init();

    while (m.GetCurrentState() != EXIT)
    {
        m.Loop();
    }

    config::Save();
    return 0;
}
